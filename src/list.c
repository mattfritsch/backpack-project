#include "list.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

void insert_after(struct list_t *L, void *data, struct elmlist_t *place);

bool emptyLst(const struct list_t *L)
{
    assert(L);
    return L->numelm == 0;
}

struct list_t *new_lst()
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

void view_lst(struct list_t *L, void (*ptrf)())
{
    printf("[\n");
    for (struct elmlist_t *E = L->head; E; E = E->suc)
    {
        (*ptrf)(E->data);
    }
    printf("]\n\n");
}

void del_lst(struct list_t **ptrL, void (*ptrFct)())
{
    assert(ptrL && *ptrL);
    if ((*ptrFct) == NULL)
    {
        for (struct elmlist_t *E = (*ptrL)->head; E;)
        {
            struct elmlist_t *T = E;
            E = E->suc;
            del_elmlist_t(&T);
        }
    }
    else
    {
        for (struct elmlist_t *E = (*ptrL)->head; E;)
        {
            struct elmlist_t *T = E;
            E = E->suc;
            (*ptrFct)(T->data);
        }
    }
    free(*ptrL);
    *ptrL = NULL;
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

void insert_ordered(struct list_t *L, void *data, bool (*ptrFct)())
{
    if (emptyLst(L))
    {
        cons(L, data);
    }
    else if ((*ptrFct)(data, L->head->data))
    {
        cons(L, data);
    }
    else if ((*ptrFct)(L->tail->data, data))
    {
        insert_after(L, data, L->tail);
    }
    else
    {
        for (struct elmlist_t *E = L->head; E; E = E->suc)
        {
            if ((*ptrFct)(E->data, data) && (*ptrFct)(data, E->suc->data))
            {
                insert_after(L, data, E);
            }
        }
    }
}

struct elmlist_t *getHead(struct list_t *L)
{
    return L->head;
}

struct elmlist_t *getTail(struct list_t *L)
{
    return L->tail;
}

void queue(struct list_t *L, void *data)
{
    L->tail = data;
}

int getNumelm(struct list_t *L)
{
    return L->numelm;
}

int setNumelm(struct list_t *L, int numElm)
{
    return L->numelm = numElm;
}