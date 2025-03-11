// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : mars 2025
// Version 1
// Here is an implementation of useful fonctions to calculate LFSR

#include "LFSR.h"

#include <stdlib.h>
#include <assert.h>



bool LFSR_calculateNextEntry(Queue Register, bool* feedbackCoeffs, int registerSize){
    int nextEntry = 0, i;
    for(i = registerSize; i >= 0; i--){
        nextEntry += feedbackCoeffs[i] * qtop(Register);
        push_back(qtop(Register), Register);
        pop_front(Register);
    }
    return (nextEntry % 2);
}

bool* LFSR_computeLFSR(Queue Register, bool* feedbackCoeffs, int registerSize, int iterations){
    bool* res = malloc(iterations * sizeof(bool));
    int i;
    bool nextEntry;

    for(i = 0; i < iterations; i++){
        nextEntry = LFSR_calculateNextEntry(Register, feedbackCoeffs, registerSize);
        //range la sortie dans le tableau résultat
        res[i] = qtop(Register);
        //actualise le registre
        pop_front(Register);
        push_back(nextEntry, Register);
    }
    return res;
}