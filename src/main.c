#include <stdio.h>
#include "../include/models.h"
int main()
{
    Salle s = creer_salle("salle A", 10, 22.5, "wifi");
    afficher_salle(&s);
    Reservation r = creer_reservation(11, "louay", "salle A", "11-11-2026", 570, 660, 9, 50.5);
    afficher_reservation(&r);

    return 0;
}