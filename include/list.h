#ifndef _LIST_
#define _LIST_

#include "elmlist.h"
#include "objects.h"
#include <stdbool.h>

/**
Abstract type for double-linked list modeled by
- 2 pointers pointing to the head and the tail of the list
- the number of element the list contains
*/
struct list_t
{
  struct elmlist_t *head, *tail;
  int numelm;
};

/****************
Constructors & co
****************/
/** @brief Créer une liste vide*/
struct list_t *new_list();
/** @brief Copie une liste*/
struct list_t *listcpy(const struct list_t *L);

/** @brief Delete list its elements and possibly the data they hold */
void del_list(struct list_t *L, void (*ptrf)());

/** @brief Is list L empty ? */
bool is_empty(const struct list_t *L);

/********************
Accessors & modifiers
********************/
/** @brief Gimme the head of L*/
struct elmlist_t *get_head(const struct list_t *L);

/** @brief Gimme the tail of L */
struct elmlist_t *get_tail(const struct list_t *L);

/** @brief How many elements does the list contain ? */
int get_numelm(const struct list_t *L);

/***************************
 * Advanced member functions
 ***************************/
/** @brief Add a brand new list element holding data to the head of L */
void cons(struct list_t *L, void *data);

/** @brief Add  a brand new list element holding data to the tail of L */
void queue(struct list_t *L, void *data);

/** @brief Insert data at place localized by cmp_ptr */
void insert_ordered(struct list_t *L, void *data, bool (*cmp_ptrf)());

/** @brief Display list on stdout stream */
void view_list(struct list_t *L, void (*ptrf)());

#endif
