#include "objects.h"

void view_object(const struct object_t *object)
{
	printf("(%d , %d) ", object->volume, object->utility);
}

void view_objet_set(const struct objects_t *set)
{
	printf("\n*** View objet set ***\n");
	for (int o = 0; o < set->nb_objects; o += 1)
		view_object(set->objects + o);
	printf("\n**********************\n");
}