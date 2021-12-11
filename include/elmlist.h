#ifndef _ELMLIST_
#define _ELMLIST_

#include <stdbool.h>

/**
Abstract type modeling a list element containing
- a form
- 2 pointers to its predecessor  and successor
*/
struct elmlist_t {
  void * data;
  struct elmlist_t * suc;
  struct elmlist_t * pred;
};

struct elmlist_t * new_elmlist(void * data );
void del_elmlist(struct elmlist_t * E, void (*ptrf) ());
struct elmlist_t * get_suc(struct elmlist_t * E);
struct elmlist_t * get_pred(struct elmlist_t * E);
void * get_data(struct elmlist_t * E);
void set_suc(struct elmlist_t * E, struct elmlist_t * S);
void set_pred(struct elmlist_t * E, struct elmlist_t * P);
void set_data(struct elmlist_t * E, void * data);
void view_elmlist(struct elmlist_t * E, void (*ptrf)());

#endif
