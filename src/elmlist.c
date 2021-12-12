#include "elmlist.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct elmlist_t *new_lst_elm(void *data)
{
    struct elmlist_t *E;
    E = (struct elmlist_t *)calloc(1, sizeof(struct elmlist_t));
    assert(E);
    E->data = data;
    return E;
}

void del_elmlist_t(struct elmlist_t **ptrE)
{
    assert(ptrE && *ptrE);
    free(*ptrE);
    *ptrE = NULL;
}

void *getdata(struct elmlist_t *E)
{
    return E->data;
}

struct elmlist_t *getSuc(struct elmlist_t *E)
{
    return E->suc;
}

void setdata(struct elmlist_t *E, void *data)
{
    E->data = data;
}

void setSuc(struct elmlist_t *E, struct elmlist_t *S)
{
    E->suc = S->suc;
}