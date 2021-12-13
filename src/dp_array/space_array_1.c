#include "space_array.h"

//void push_object_in_array(struct states_array_t *states, struct objects_t *LO, int i)
void push_object_in_array(struct states_array_t *states, const struct objects_t *objects, int i)
{
  /* Faites attention que les objets dans LO sont rangés à partir de 0
	 * tandis qu'ils sont rangés à partue de 1 dans OPT (et CHM) */
  for (int bag = 0; bag < (states->Vmax + 1); bag += 1)
  {
    // Parcourir chaque état du sac-à-dos
    int pred = ...; // Calculer l'index de l'état pour l'objet (i-1)
    int curr = ...; // Calculer l'index de l'état pour l'objet (i)
    int OPT1 = states->OPT[pred];
    states->CHM[curr] = INFTY; //hyp.: l'objet i n'est pas dans le sac
    if (...)
    {                           // states'il y a de la place dans le sac
      int pred_without_i = ...; // L'index du bag SANS l'objet (i)
      int OPT2 = ...;
      if (...)
      { // Sélectionne la meilleur configuration
        states->OPT[curr] = ...;
        states->CHM[curr] = ...; // Noter que l'objet i est dans le sac
      }
      else
        states->OPT[curr] = ...;
    }
    else
      states->OPT[curr] = ...; // states'il n'y a pas de place
  }
}