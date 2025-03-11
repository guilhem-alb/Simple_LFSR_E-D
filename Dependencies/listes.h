// Auteur Guilhem ALBALADEJO
// Institut : Polytech Marseille
// Date : novembre 2024
#ifndef __LISTES_H__
#define __LISTES_H__

// Définition des types
typedef long Data ;
typedef int bool ;
struct zmaillon {
    Data elt ;
    struct zmaillon * next ;
} ;
typedef struct zmaillon maillon;
typedef maillon * List ;


// Abstract Data Type
bool is_empty_list (List) ;
List create_empty_list (void) ;
List add (Data, List);
Data head(List) ;
List tail(List) ;

// Toolbox
void print_list(List) ;

// Memory management
List free_link(List) ;
List free_list(List) ;


#endif
