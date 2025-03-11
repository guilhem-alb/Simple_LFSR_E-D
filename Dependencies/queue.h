// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : novembre 2024
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "listes.h"

////////////////////////
// Définition des types
////////////////////////

//type file (fifo)
struct zqueue 
{
 int size ;
 List in, out ; 
};typedef struct zqueue * Queue ; 


////////////////////////
//Abstract data types
////////////////////////

//type file (fifo)
Queue create_empty_queue() ;
bool is_empty_queue(Queue) ;
void push_back(Data, Queue) ;
void pop_front(Queue) ;
Data qtop(Queue) ;

//memory management
void free_queue(Queue) ;

#endif