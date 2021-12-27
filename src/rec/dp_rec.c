#include "bag.h"

struct retained_t *new_bag()
{
  struct retained_t *bagpack = (struct retained_t *)calloc(1, sizeof(struct retained_t));
  bagpack->objects_list = new_list();
  assert(bagpack->objects_list);
  return bagpack;
}

void bagcpy(struct retained_t *duplicata, const struct retained_t *bagpack)
{
  duplicata->objects_list = listcpy(bagpack->objects_list);
  duplicata->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t *bagpack)
{
  assert(bagpack);
  del_list(&bagpack->objects_list, &rmInteger);
  free(bagpack);
  bagpack = NULL;
}

void clean_bag(struct retained_t *bagpack)
{
  assert(bagpack);
  del_list(&bagpack->objects_list, &rmInteger);
  bagpack->utilities_sum = 0;
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object)
{
  cons(bagpack->objects_list, ptr_object);
  bagpack->utilities_sum += ptr_object->utility;
}

void view_bagpack(struct retained_t *bagpack, const char *title)
{
  void (*ptr_view_fct)(const struct object_t *) = &view_object;
  printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
  view_list(bagpack->objects_list, ptr_view_fct);
  printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}

void rmInteger(int *i)
{
  free(i);
}