// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : mars 2025
// Version 1
// Here is a header of the functions needed to compute LFSR
#ifndef __LFSR_H__
#define __LFSRH__

#include "Dependencies/listes.h"
#include "Dependencies/queue.h"

//calcule le prochain élément
bool LFSR_calculateNextEntry(Queue Register, bool* feedbackCoeffs);
//Retourne le résultat du LFSR sous forme de tableau
bool* LFSR_computeLFSR(Queue Register, bool* feedbackCoeffs, int iterations);

#endif