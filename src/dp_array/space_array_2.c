#include "space_array.h"

/**
 * Private Function
 **/
void init_opt_chm(struct states_array_t *states)
{
    states->OPT = (state_t *)calloc(1, sizeof(struct states_array_t)); // Fais un calloc
    states->CHM = (state_t *)calloc(1, sizeof(struct states_array_t)); // Fais un calloc

    for (int obj = 1; obj <= states->num_obj; obj += 1)
    {
        for (int bag = 0; bag <= states->Vmax; bag += 1)
        {
            int idx = obj * bag;      // L'indice est l'id de l'obj * l'id de bag
            states->OPT[idx] = UNDTR; // On met l'OPT en indefini
            states->CHM[idx] = UNDTR; // On met lE CHM en indefini
        }
    }

    for (int bag = 0; bag <= states->Vmax; bag += 1)
    {
        states->CHM[bag] = UNDTR; // On met chaque CHM en indefini
    }
}