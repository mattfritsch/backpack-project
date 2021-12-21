#include "space_array.h"
#include <assert.h>

void init_opt_chm(struct states_array_t *states);

/* A VERIFIER */
void free_states_array(struct states_array_t *states)
{
  assert(states);
  free(states);
  states = NULL;
}

/* A VERIFIER */
struct states_array_t *new_states_array(const int num_objects, const int Vmax)
{
  struct states_array_t *NS = (struct states_array_t *)calloc(1, sizeof(struct states_array_t));
  assert(NS != NULL);

  NS->num_obj = num_objects;
  NS->Vmax = Vmax;
  init_opt_chm(NS);
  return NS;
}
