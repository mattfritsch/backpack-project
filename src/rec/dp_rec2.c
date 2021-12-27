#include "bag.h"

void prec(int Vmax, struct objects_t *obj_set, struct retained_t *bag)
{
  const int nb_objects = obj_set->nb_objects;
  struct retained_t *duplicata = (struct retained_t *)calloc(1, sizeof(struct retained_t));
  bagcpy(duplicata, bag);
  struct retained_t *best_bagpack = (struct retained_t *)calloc(1, sizeof(struct retained_t));
  bagcpy(best_bagpack, bag);
  // Pred: best bag is bag
  for (int obj_idx = obj_set->first_idx; obj_idx < nb_objects; obj_idx++) // Verif: Try new objects
  {
    //printf("first idx : %d\n", obj_idx);
    struct object_t *ptr_object = obj_set->objects + obj_idx;
    //view_object(ptr_object);
    int curr_volume = Vmax - ptr_object->volume;
    if (curr_volume >= 0)
    {
      bagcpy(best_bagpack, bag); // *
      push_object_in_bag(bag, ptr_object);
      //printf("id : %d", obj_set->first_idx);
      obj_set->first_idx = obj_idx + 1; //*
      //printf("idx : %d\n", obj_idx);
      //printf("vol : %d\n", curr_volume);
      //printf("---------------------------\n");
      prec(curr_volume, obj_set, bag);      //*
      if (curr_volume < ptr_object->volume) //*
      {
        clean_bag(bag);
        bagcpy(bag, duplicata);
      }
    }
  }
  clean_bag(bag);
  bagcpy(bag, best_bagpack);
  free_bag(best_bagpack);
}
