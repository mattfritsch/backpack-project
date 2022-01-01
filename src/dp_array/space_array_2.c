#include "space_array.h"

/**
 * Private Function
 **/
void init_opt_chm(struct states_array_t *states)
{
    states->OPT = (state_t *)calloc(1, sizeof(struct states_array_t));
    states->CHM = (state_t *)calloc(1, sizeof(struct states_array_t));

    for (int obj = 1; obj <= states->num_obj; obj += 1)
    {
        for (int bag = 0; bag <= states->Vmax; bag += 1)
        {
            int idx = obj * bag;
            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }

    for (int bag = 0; bag <= states->Vmax; bag += 1)
    {
        states->CHM[bag] = UNDTR;
    }
}