#include "objects.h"
#include "stdbool.h"

struct objects_t *new_objects(int argc, char **argv, bool utility)
{
    struct objects_t *set = (struct objects_t *)calloc(1, sizeof(struct objects_t));
    int i, offset = 4;
    set->nb_objects = (utility) ? (argc - offset) / 2 : (argc - offset);
    set->objects = (struct object_t *)calloc(set->nb_objects, sizeof(struct object_t)); // Fais un calloc avec comme taille le nombre d'objet
    if (utility)
    {
        int j;
        for (i = offset, j = 0; i < argc; i += 2, j += 1)
        {
            set->objects[j].volume = atoi(argv[i]);      // Rentre l'argument num i pour le volume
            set->objects[j].utility = atoi(argv[i + 1]); // et l'argument num (i + 1) pour l'utilite
        }
    }
    else
        for (i = offset; i < argc; i += 1)
        {
            set->objects[i - 4].volume = atoi(argv[i]);  // Rentre le meme argument pour le volume
            set->objects[i - 4].utility = atoi(argv[i]); // et l'utilite
        }
    return set;
}
