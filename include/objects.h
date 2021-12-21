#ifndef _OBJECTS_
#define _OBJECTS_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.h"

struct object_t
{
	int volume;
	int utility;
};

struct objects_t
{
	struct object_t *objects;
	int nb_objects;
	int first_idx;
};

struct objects_t *new_objects(const int argc, char **argv, bool utility);
/** @brief Consulter un object */
void view_object(const struct object_t *object);
void view_objet_set(const struct objects_t *set);
#endif
