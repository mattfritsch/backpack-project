#include "bag.h"

struct retained_t *new_bag()
{
  struct retained_t *bagpack = (struct retained_t *)calloc(1, sizeof(struct retained_t)); // Fais un calloc
  bagpack->objects_list = new_list();                                                     // Declare une nouvelle liste
  assert(bagpack->objects_list);
  return bagpack;
}

void bagcpy(struct retained_t *duplicata, const struct retained_t *bagpack)
{
  duplicata->objects_list = listcpy(bagpack->objects_list);
  duplicata->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t **bagpack)
{
  assert(bagpack);
  del_list((*bagpack)->objects_list, &rmObject); // Appelle del_list avec comme argument la liste du sac et la fonction rmObject
  free(*bagpack);                                // Free le sac
  *bagpack = NULL;                               // Puis on le met a NULL
}

void clean_bag(struct retained_t *bagpack)
{
  del_list(bagpack->objects_list, &rmObject); // Appelle del_list avec comme argument la liste du sac et la fonction rmObject
  bagpack->objects_list = new_list();         // Declare une nouvelle liste pour la liste du sac
  assert(bagpack->objects_list);
  bagpack->utilities_sum = 0; // Remet a 0 la somme des utilites
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object)
{
  cons(bagpack->objects_list, ptr_object);       // Envoie l'objet donne dans la liste
  bagpack->utilities_sum += ptr_object->utility; // Incremente la somme des utilites avec celle de l'objet donne en argument
}

void view_bagpack(struct retained_t *bagpack, const char *title)
{
  void (*ptr_view_fct)(const struct object_t *) = &view_object;
  printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
  view_list(bagpack->objects_list, ptr_view_fct);
  printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}