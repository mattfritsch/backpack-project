#include "outils.h"

void rmObject(struct object_t *o)
{
    free(o);
}