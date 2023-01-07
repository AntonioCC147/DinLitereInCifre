#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOLD "\e[1m"
#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define BLUE "\e[1;34m"
#define COLOR_OFF "\e[m"

void credite(){
    printf(COLOR_OFF BOLD "-- Program C realizat de" GREEN " Crantea Antonio Cristian" COLOR_OFF BOLD ", student la " BLUE "UPB - ACS - IS" COLOR_OFF BOLD ", Ianuarie 2023 --\n\n" COLOR_OFF);
}

void manual(){
    system("cls"); credite(); printf(BOLD "-- " BLUE "MANUAL (Exemple)" COLOR_OFF BOLD " --" COLOR_OFF);

    printf(BOLD "\nCifre:\n" COLOR_OFF);
        printf("\t1 - unu"); printf("\n\t7 - sapte");
    printf(BOLD "\nNumere formate din 2 cifre:\n" COLOR_OFF);
        printf("\t11 - unsprezece"); printf("\n\t14 - paisprezece");
    printf(BOLD "\nNumere formate din 3 cifre:\n" COLOR_OFF);
        printf("\t509 - cinci sute noua"); printf("\n\t147 - o suta patruzeci si sapte");
    printf(BOLD "\nNumere formate din 4 cifre:\n" COLOR_OFF);
        printf("\t1029 - o mie douazeci si noua"); printf("\n\t5836 - cinci mii opt sute treizeci si sase");
    printf(BOLD "\nNumere formate din 5 cifre:\n" COLOR_OFF);
        printf("\t23005 - douazeci si trei de mii cinci"); printf("\n\t69720 - saizeci si noua de mii sapte sute douazeci");
    printf(BOLD "\nNumere formate din 6 cifre:\n" COLOR_OFF);
        printf("\t520095 - cinci sute douazeci de mii nouazeci si cinci"); printf("\n\t784391 - sapte sute optzeci si patru de mii trei sute nouazeci si unu");
    printf(BOLD "\nNumar format din 7 cifre:\n" COLOR_OFF);
        printf("\t1000000 - un milion\n\n");

    int valoare;
    do{
        printf(COLOR_OFF "Tastati " BOLD "1" COLOR_OFF " daca doriti sa continuati introducerea numarului.\n");
        printf("Tastati " BOLD "0" COLOR_OFF " daca doriti sa inchideti programul.\n");
        printf(BOLD "Raspuns (1 / 0): "); scanf("%d", &valoare);
        if(valoare != 0 && valoare != 1){ system("cls"); credite(); }
    }while(valoare != 0 && valoare != 1); getchar();
    if(valoare == 1) principal();
    else{ system("cls"); credite(); printf(RED "Executia programului s-a terminat cu succes! Apasati orice tasta pentru a inchide consola!\n" COLOR_OFF); exit(1); }
}

void eroare(){
    printf("\n" RED "(!) " COLOR_OFF "Ceva nu a mers bine! Esti sigur ca ai scris corect numarul?\n");
    printf(RED "(!) " COLOR_OFF "Verifica daca ai scris corect numarul si daca acesta face parte din intervalul [1, 1.000.000]!\n\n");
    printf(RED "Executia programului s-a terminat cu esec! Apasati orice tasta pentru a inchide consola!\n" COLOR_OFF); exit(1);
}

void raspuns(int raspuns){
    system("cls"); credite();
    printf(RED "(!) " COLOR_OFF "Numarul pe care l-ai tastat este: " RED "%d." COLOR_OFF "\n\n", raspuns);

    int valoare;
    do{
        printf(COLOR_OFF "Tastati " BOLD "1" COLOR_OFF " daca doriti sa introduceti un nou numar.\n");
        printf("Tastati " BOLD "2" COLOR_OFF " daca doriti sa deschideti manualul.\n");
        printf("Tastati " BOLD "0" COLOR_OFF " daca doriti sa inchideti programul.\n");
        printf(BOLD "Raspuns (1 / 2 / 0): "); scanf("%d", &valoare);
        if(valoare != 0 && valoare != 1 && valoare != 2){ system("cls"); credite(); }
    }while(valoare != 0 && valoare != 1 && valoare != 2); getchar();
    if(valoare == 1) principal();
    else if(valoare == 2) manual();
    else{ system("cls"); credite(); printf(RED "Executia propgramului s-a terminat cu succes! Apasati orice tasta pentru a inchide consola!\n" COLOR_OFF); exit(1); }
}

int verificareCifra(char cifra[15]){
    if(stricmp(cifra, "unu") == 0 || stricmp(cifra, "un") == 0 || stricmp(cifra, "o") == 0 || stricmp(cifra, "O") == 0) return 1;
    else if(stricmp(cifra, "doi") == 0 || stricmp(cifra, "doua") == 0) return 2;
    else if(stricmp(cifra, "trei") == 0) return 3;
    else if(stricmp(cifra, "patru") == 0 || stricmp(cifra, "pai") == 0) return 4;
    else if(stricmp(cifra, "cinci") == 0) return 5;
    else if(stricmp(cifra, "sase") == 0 || stricmp(cifra, "sai") == 0) return 6;
    else if(stricmp(cifra, "sapte") == 0) return 7;
    else if(stricmp(cifra, "opt") == 0) return 8;
    else if(stricmp(cifra, "noua") == 0) return 9;
    else verificareNumarSprezece(cifra);
}

int verificareNumarSprezece(char numar[15]){
    if(stricmp(numar, "zece") == 0) return 10;
    else if(stricmp(numar + (strlen(numar) - strlen("sprezece")), "sprezece") == 0){
        numar[strlen(numar) - strlen("sprezece")] = '\0';
        return 10 + verificareCifra(numar);
    }
    else verificareNumarZeci(numar);
}

int verificareNumarZeci(char numar[15]){
    if(stricmp(numar + (strlen(numar) - strlen("zeci")), "zeci") == 0){
        numar[strlen(numar) - strlen("zeci")] = '\0';
        return 10 * verificareCifra(numar);
    }
    else eroare();
}

void principal(){
    char textNumar[250], cuvinteNumar[20][15], *p; int i, nrCuv = 0, raspuns_initial = 0;

    system("cls"); credite();
	printf(RED "(!) " COLOR_OFF "Introduceti un numar de la tastatura, numar din intervalul " BOLD "[1, 1.000.000]" COLOR_OFF ".\n");
	printf(RED "(!) " COLOR_OFF "Atentie: Acesta trebuie sa fie scris corect gramatical, folosind litere mici / mari ale alfabetului englez.\n");
	printf(RED "# Numarul: "); gets(textNumar);

	p = strtok(textNumar, " ");
	while(p){
        strcpy(cuvinteNumar[nrCuv++], p); p = strtok(NULL, " ");
	}

	for(i = 0; i < nrCuv; i++){
        if(stricmp(cuvinteNumar[i+1], "sute") == 0 || stricmp(cuvinteNumar[i+1], "suta") == 0){
            raspuns_initial = raspuns_initial + (verificareCifra(cuvinteNumar[i]) * 100); i++;
        }
        else if(stricmp(cuvinteNumar[i+1], "mie") == 0 || stricmp(cuvinteNumar[i+1], "mii") == 0){
            if(stricmp(cuvinteNumar[i], "de") == 0){
                raspuns_initial = raspuns_initial * 1000; i++;
            }
            else{ raspuns_initial = (raspuns_initial + verificareCifra(cuvinteNumar[i])) * 1000; i++; }
        }
        else if(nrCuv == 2 && stricmp(cuvinteNumar[i], "un") == 0 && stricmp(cuvinteNumar[i+1], "milion") == 0){
                raspuns_initial = 1000000; i++;
        }
        else if(stricmp(cuvinteNumar[i], "si") != 0)
            raspuns_initial = raspuns_initial + verificareCifra(cuvinteNumar[i]);
	}

    raspuns(raspuns_initial);
}

int main()
{
	char textNumar[250]; int valoare;

	do{
            credite();
            printf("Tastati " BOLD "1" COLOR_OFF " daca doriti sa introduceti direct numarul.\n");
            printf(COLOR_OFF "Tastati " BOLD "2" COLOR_OFF " daca doriti sa accesati un manual explicativ inainte de a introduce numarul.\n");
            printf(BOLD "Raspuns (1 / 2): "); scanf("%d", &valoare);
            if(valoare != 1 && valoare != 2) system("cls");
   	}while(valoare != 1 && valoare != 2); getchar();

	if(valoare == 2) manual();
	else principal();

	return 0;
}
