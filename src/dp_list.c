#include <stdlib.h>
#include <stdbool.h>
#include "dp_list.h"
#include "objects.h"

void dp_list(const int Vmax, const struct objects_t *object_set)
{
    struct states_list_t *states = new_states_array(object_set->nb_objects, Vmax);
    assert(states != NULL);
#ifdef _TRACE_
    view_opt(states);
#endif

    for (int i = 1; i <= object_set->nb_objects; i += 1)
    {
#ifdef _TRACE_
        printf("#%d Object\n", i);
#endif
        push_object_in_array(states, object_set, i);
#ifdef _TRACE_
        view_opt(states);
        view_chm(states);
#endif
    }
    view_path_array(states, object_set);
    free_states_array(states);
}