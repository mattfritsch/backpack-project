#include "list.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

void insert_after(struct list_t *L, void *data, struct elmlist_t *place);

bool is_empty(const struct list_t *L)
{
    assert(L);
    return L->numelm == 0;
}

struct list_t *new_list()
{
    /** @note : calloc fonctionne de manière identique à malloc
		et de surcroît met à NULL(0) tous les octets alloués */
    struct list_t *L = (struct list_t *)calloc(1, sizeof(struct list_t));
    assert(L);
    return L;
}

void cons(struct list_t *L, void *data)
{
    struct elmlist_t *E = (struct elmlist_t *)calloc(1, sizeof(struct elmlist_t));
    E->data = data;
    E->suc = L->head;
    L->head = E;
    L->numelm += 1;
    if (L->numelm == 1)
    {
        L->tail = E;
    }
}

void view_list(struct list_t *L, void (*ptrf)())
{
    printf("[\n");
    for (struct elmlist_t *E = L->head; E; E = E->suc)
    {
        (*ptrf)(E->data);
    }
    printf("]\n\n");
}

void del_list(struct list_t **L, void (*ptrf)())
{
    assert(L && *L);
    if ((*ptrf) == NULL)
    {
        for (struct elmlist_t *E = (*L)->head; E;)
        {
            struct elmlist_t *T = E;
            E = E->suc;
            del_elmlist_t(&T);
        }
    }
    else
    {
        for (struct elmlist_t *E = (*L)->head; E;)
        {
            struct elmlist_t *T = E;
            E = E->suc;
            (*ptrf)(T->data);
        }
    }
    free(*L);
    *L = NULL;
}

void insert_after(struct list_t *L, void *data, struct elmlist_t *place)
{
    if (place == NULL)
        cons(L, data);
    else
    {
        struct elmlist_t *new = new_lst_elm(data);
        assert(new);
        new->suc = place->suc;
        place->suc = new;
        L->numelm++;
        if (place == L->tail)
            L->tail = new;
    }
}

void insert_ordered(struct list_t *L, void *data, bool (*cmp_ptrf)())
{
    if (emptyLst(L))
    {
        cons(L, data);
    }
    else if ((*cmp_ptrf)(data, L->head->data))
    {
        cons(L, data);
    }
    else if ((*cmp_ptrf)(L->tail->data, data))
    {
        insert_after(L, data, L->tail);
    }
    else
    {
        for (struct elmlist_t *E = L->head; E; E = E->suc)
        {
            if ((*cmp_ptrf)(E->data, data) && (*cmp_ptrf)(data, E->suc->data))
            {
                insert_after(L, data, E);
            }
        }
    }
}

struct elmlist_t *get_head(const struct list_t *L)
{
    return L->head;
}

struct elmlist_t *get_tail(const struct list_t *L)
{
    return L->tail;
}

void queue(struct list_t *L, void *data)
{
    L->tail = data;
}

int get_numelm(const struct list_t *L)
{
    return L->numelm;
}

int setNumelm(struct list_t *L, int numElm)
{
    return L->numelm = numElm;
}

struct list_t *listcpy(const struct list_t *L)
{
    /* TODO */
}