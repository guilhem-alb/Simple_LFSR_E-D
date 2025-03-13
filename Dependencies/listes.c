// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : novembre 2024
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "listes.h"

// ////////////////////////////////////////////////
// Abstract Data Type
// ////////////////////////////////////////////////

// is_empty_list : tests if l is empty
// return:
//    1 if list is empty
//    0 otherwise
bool is_empty_list (List l)
{
	return (l == NULL) ;
}

// create_empty_list : returns an empty list
// return:
//    empty list structure
List create_empty_list (void)
{
	return NULL ;
}

// add : adds element e to the head of the list
// return:
//    resulting list 
List add (Data e, List l)
{
    maillon * tmp = malloc (sizeof(List)) ;
    tmp->elt = e ;
    tmp->next = l ;
	return tmp ;
}

// head : get the head of the list
// return:
//    head
Data head(List l)
{
	assert(!is_empty_list(l)) ;
    return l->elt ;
}

// tail : get the tail of the list (fresh copy)
// return:
//    tail
List tail(List l)
{
    assert(!is_empty_list(l)) ;
    return l->next ;
}

// ////////////////////////////////////////////////
// Toolbox
// ////////////////////////////////////////////////

void print_list_aux(List l)
{
    if (is_empty_list(l))
    { } // do nothing
    else
    {
        printf("%ld ", head(l)) ;
        print_list_aux(tail(l)) ;
    }
}
    
void print_list(List l)
{
    printf("[") ;
    print_list_aux(l) ;
    printf("]\n") ;
}

// ////////////////////////////////////////////////
// Memory management
// ////////////////////////////////////////////////

List free_link(List l)
{
    maillon * tmp = l->next ; // l->next ===== (*l).next
    free(l) ;
    return tmp ;
}

List free_list(List l)
{
    while(!is_empty_list(l))
        l = free_link(l) ;
    return NULL ;
}
