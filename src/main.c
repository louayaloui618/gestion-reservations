#include <stdio.h>
#include "../include/models.h"

int main(void)
{
    Salle salles[MAX_SALLES];
    int nb = charger_salles("data/tarifs.txt", salles, MAX_SALLES);
    printf("%d salles chargees\n", nb);

    for (int i = 0; i < nb; i++)
        afficher_salle(&salles[i]);

    const Salle *s = trouver_salle(salles, nb, "salle B");
    if (s != NULL)
        printf("Cout salle B (09:30-11:00) : %.2f\n",
               calculer_cout(s, 570, 660));
    else
        printf("Salle introuvable\n");

    sauvegarder_salles("data/tarifs.txt", salles, nb);
    return 0;
}