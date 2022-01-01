#include "elmlist.h"

#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct elmlist_t *new_elmlist(void *data)
{
    struct elmlist_t *E;
    E = (struct elmlist_t *)calloc(1, sizeof(struct elmlist_t));
    assert(E);
    E->data = data;
    return E;
}

void del_elmlist(struct elmlist_t **E, void (*ptrf)())
{
    assert(E && *E);
    //(*ptrf)((*E)->data);
    free(*E);
    *E = NULL;
}

struct elmlist_t *get_suc(struct elmlist_t *E)
{
    return E->suc;
}

struct elmlist_t *get_pred(struct elmlist_t *E)
{
    return E->pred;
}

void *get_data(struct elmlist_t *E)
{
    return E->data;
}

void set_suc(struct elmlist_t *E, struct elmlist_t *S)
{
    E->suc = S->suc;
}

void set_pred(struct elmlist_t *E, struct elmlist_t *P)
{
    E->pred = P->pred;
}

void set_data(struct elmlist_t *E, void *data)
{
    E->data = data;
}

void view_elmlist(struct elmlist_t *E, void (*ptrf)())
{
    (*ptrf)(E->data);
}