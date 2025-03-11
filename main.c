// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : mars 2025
// Version 1
// This is the main loop of the program

#include "LFSR.h"
#include "Dependencies/queue.h"

#include <stdio.h>
#include <stdlib.h>

void printArray(int* ,int);

int main(){
    Queue LFSR = create_empty_queue();
    //char option;
    bool* feedBackCoeffs; bool* resultat;
    int i, taille, valeur, iterations;
   // while(option != 'q'){

        printf("entrez la taille du registre\n");
        scanf("%d", &taille);
        printf("entrez les états initiaux\n");
        for(i = 0; i < taille; i++){
            printf("s%d : ", i);
            scanf("%d", &valeur);
            push_back(valeur, LFSR);
        }

        printf("entrez les feedback coefficents\n");
        feedBackCoeffs = malloc(taille * sizeof(bool));
        for(i = 0; i < taille; i++){
            printf("c%d : ", (i + 1));
            scanf("%d", &feedBackCoeffs[i]);
        }

        printf("entrez le nombre d'itérations souhaité\n");
        scanf("%d", &iterations);

        resultat = LFSR_computeLFSR(LFSR, feedBackCoeffs, taille, iterations);
        printArray(resultat, iterations);
   // }

    return 0;
}

void printArray(int* array,int arraySize){
    int i;

    for(i = 0; i < arraySize; i++){
        printf("%d", array[i]);
    }    
}