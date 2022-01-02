#include "bag.h"

void prec(int Vmax, struct objects_t *obj_set, struct retained_t *bag)
{
  const int nb_objects = obj_set->nb_objects;
  struct retained_t *duplicata = new_bag();    // Declare un nouveau sac
  bagcpy(duplicata, bag);                      // Copy le sac dans le duplicata
  struct retained_t *best_bagpack = new_bag(); // Declare un nouveau sac
  bagcpy(best_bagpack, bag);                   // Copy le sac dans le best_bagpack
  // Pred: best bag is bag
  for (int obj_idx = obj_set->first_idx; obj_idx < nb_objects; obj_idx++) // Verif: Try new objects
  {
    struct object_t *ptr_object = obj_set->objects + obj_idx;
    int curr_volume = Vmax - ptr_object->volume; // Soustrais le volume courant avec le volume de l'objet rentre
    if (curr_volume >= 0)                        // Si le volume courant est superieur ou egal a 0 alors..
    {
      bagcpy(duplicata, bag);                                     // ..on peut copier le sac actuel dans le duplicata
      push_object_in_bag(duplicata, ptr_object);                  // Rajoute l'objet dans le duplicata
      obj_set->first_idx += 1;                                    // Incremente l'id de l'objet a traiter en premier
      prec(curr_volume, obj_set, duplicata);                      // On appelle recursivement la fonction
      if (best_bagpack->utilities_sum < duplicata->utilities_sum) // Si la somme des utilites du meilleur sac est inferieure a celle du duplicata alors..
      {
        clean_bag(best_bagpack);         // ..on vide le meilleur sac
        bagcpy(best_bagpack, duplicata); // Copie le duplicata dans le meilleur sac
      }
    }
  }
  clean_bag(bag);
  bagcpy(bag, best_bagpack);
  free_bag(&best_bagpack);
}