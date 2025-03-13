// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : novembre 2024
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

////////////////////////
//Abstract data types
////////////////////////

//type file (lifo)

Queue create_empty_queue()
{
    Queue tmp = malloc(sizeof(Queue));

    tmp->size = 0;
    tmp->in = tmp->out = NULL;

    return tmp;
}

bool is_empty_queue(Queue q)
{
    return((q->out == NULL));
}

void push_back(Data e, Queue q)
{
    //cree une liste vide(fin de file) contenant e
    List tmp = add(e, create_empty_list());
    //regarde si la file est vide
    if(is_empty_queue(q))
    {
        //remplir le in et out
        q->in = q->out = tmp;
    }
    else
    {
        //mettre le nouveau maillon en fin de file :
        q->in->next = tmp;
        // remplacer le nouveau maillon :
        q->in = tmp;
    }
    //mettre la taille à jour
    q->size = q->size + 1;
}

void pop_front(Queue q)
{
    assert(!is_empty_queue(q));

    List tmp = q->out->next;
    free_link(q->out);
    q->out = tmp;
    //Si out est vide, vider in :
    if(q->out == NULL)
    {
        q->in = q->out;
    }
    //mettre la taille à jour
    q->size = q->size -1;
}

Data qtop(Queue q)
{
    assert(!is_empty_queue(q));
    return q->out->elt;
}

//memory management
void free_queue(Queue q)
{
    while (!is_empty_queue(q))
    {
        pop_front(q);
    }
    free(q);
}