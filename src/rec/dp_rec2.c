#include "bag.h"

void prec(int Vmax, struct objects_t *obj_set, struct retained_t *bag)
{
  const int nb_objects = obj_set->nb_objects;
  struct retained_t *duplicata = new_bag();
  bagcpy(duplicata, bag);
  struct retained_t *best_bagpack = new_bag();
  bagcpy(best_bagpack, bag);
  // Pred: best bag is bag
  for (int obj_idx = obj_set->first_idx; obj_idx < nb_objects; obj_idx++) // Verif: Try new objects
  {
    struct object_t *ptr_object = obj_set->objects + obj_idx;
    int curr_volume = Vmax - ptr_object->volume;
    if (curr_volume >= 0)
    {
      bagcpy(duplicata, bag);
      push_object_in_bag(duplicata, ptr_object);
      obj_set->first_idx += 1;
      prec(curr_volume, obj_set, duplicata);
      if (best_bagpack->utilities_sum < duplicata->utilities_sum)
      {
        clean_bag(best_bagpack);
        bagcpy(best_bagpack, duplicata);
      }
    }
  }
  clean_bag(bag);
  bagcpy(bag, best_bagpack);
  free_bag(&best_bagpack);
}