#include "space_array.h"

//void push_object_in_array(struct states_array_t *states, struct objects_t *LO, int i)
void push_object_in_array(struct states_array_t *states, const struct objects_t *objects, int i)
{
  /* Faites attention que les objets dans LO sont rangés à partir de 0
	 * tandis qu'ils sont rangés à partue de 1 dans OPT (et CHM) */
  for (int bag = 0; bag < (states->Vmax + 1); bag += 1)
  {
    // Parcourir chaque état du sac-à-dos
    int pred = (i - 1) * (states->Vmax + 1) + bag; // Calculer l'index de l'état pour l'objet (i-1)
    int curr = i * (states->Vmax + 1) + bag;       // Calculer l'index de l'état pour l'objet (i)
    int OPT1 = states->OPT[pred];
    states->CHM[curr] = INFTY;                 //hyp.: l'objet i n'est pas dans le sac
    if (objects->objects[i - 1].volume <= bag) // s'il y a de la place dans le sac
    {
      int pred_without_i = pred - objects->objects[i - 1].volume; // L'index du bag SANS l'objet (i)
      int OPT2 = states->OPT[pred_without_i] + objects->objects[i - 1].utility;
      if (OPT1 <= OPT2) // Sélectionne la meilleur configuration
      {
        states->OPT[curr] = OPT2;
        states->CHM[curr] = bag - objects->objects[i - 1].volume; // Noter que l'objet i est dans le sac
      }
      else
        states->OPT[curr] = OPT1;
    }
    else
      states->OPT[curr] = OPT1; // s'il n'y a pas de place
  }
}