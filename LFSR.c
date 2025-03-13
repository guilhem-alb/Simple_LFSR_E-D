// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : mars 2025
// Version 1.1
// Here is an implementation of useful functions to calculate LFSR

#include "LFSR.h"

#include <stdlib.h>
#include <assert.h>


// Calcule la prochaine valeur à ajouter dans le registre
bool LFSR_calculateNextEntry(Queue Register, bool* feedbackCoeffs){
    int nextEntry = 0, i;
    List tmp = Register->out;  // Pointeur temporaire pour éviter les effets de bord

    for(i = Register->size - 1; i >= 0; i--){
        nextEntry += feedbackCoeffs[i] * tmp->elt;
        tmp = tmp->next; 
    }
    return (nextEntry % 2);
}

// Boucle principale pour calculer les valeurs renvoyée par le registre sous forme de liste
// ! modifie le registre par effet de bord
bool* LFSR_computeLFSR(Queue Register, bool* feedbackCoeffs, int iterations){
    bool* res = malloc(iterations * sizeof(bool));
    int i;
    bool nextEntry;

    for(i = 0; i < iterations; i++){
        nextEntry = LFSR_calculateNextEntry(Register, feedbackCoeffs);
        //range la sortie dans le tableau résultat
        res[i] = qtop(Register);
        //actualise le registre
        pop_front(Register);
        push_back(nextEntry, Register);
    }
    return res;
}