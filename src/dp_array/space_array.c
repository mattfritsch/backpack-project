#include "space_array.h"
#include <assert.h>

void init_opt_chm(struct states_array_t *states);

void free_states_array(struct states_array_t *states)
{
  assert(states);
  free(states);
  states = NULL;
}

struct states_array_t *new_states_array(const int num_objects, const int Vmax)
{
  struct states_array_t *NS = (struct states_array_t *)calloc(1, sizeof(struct states_array_t)); // On fait un calloc
  assert(NS != NULL);

  NS->num_obj = num_objects; // On defini le nombre d'objets du tableau avec celui passe en parametre
  NS->Vmax = Vmax;           // On defini le volume max du tableau avec celui passe en parametre
  init_opt_chm(NS);
  return NS;
}
