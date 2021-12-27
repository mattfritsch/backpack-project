#ifndef _ELMLIST_
#define _ELMLIST_

#include <stdbool.h>

/**
Abstract type modeling a list element containing
- a form
- 2 pointers to its predecessor  and successor
*/
struct elmlist_t
{
  void *data;
  struct elmlist_t *suc;
  struct elmlist_t *pred;
};

struct elmlist_t *new_elmlist(void *data);
/** @brief Supprime un élément de la liste*/
void del_elmlist(struct elmlist_t **E);
/** @brief Renvoie le successeur d'un élément de la liste*/
struct elmlist_t *get_suc(struct elmlist_t *E);
/** @brief Renvoie le prédecesseur d'un élément de la liste*/
struct elmlist_t *get_pred(struct elmlist_t *E);
/** @brief Renvoie la data d'un élément de la liste*/
void *get_data(struct elmlist_t *E);
/** @brief Initialise le successeur d'un élément de la liste*/
void set_suc(struct elmlist_t *E, struct elmlist_t *S);
/** @brief Initialise le prédecesseur d'un élément de la liste*/
void set_pred(struct elmlist_t *E, struct elmlist_t *P);
/** @brief Initialise la data d'un élément de la liste*/
void set_data(struct elmlist_t *E, void *data);
/** @brief Consulter un élément de la liste*/
void view_elmlist(struct elmlist_t *E, void (*ptrf)());

#endif
