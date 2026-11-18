#include <stdio.h>
#include <string.h>
#include "../include/models.h"

Salle creer_salle(const char *nom, int capacite,
                  float tarif_horaire, const char *equipements)
{
    Salle s;
    strncpy(s.nom, nom, MAX_NOM - 1);
    s.nom[MAX_NOM - 1] = '\0';
    strncpy(s.equipements, equipements, MAX_EQUIP - 1);
    s.equipements[MAX_EQUIP - 1] = '\0';
    s.capacite = capacite;
    s.tarif_horaire = tarif_horaire;
    return s;
}

Reservation creer_reservation(int id, const char *nom_client,
                              const char *salle, const char *date,
                              int heure_debut, int heure_fin,
                              int nombre_personnes, float tarif)
{
    Reservation r;
    r.id = id;
    strncpy(r.nom_client, nom_client, MAX_NOM - 1);
    r.nom_client[MAX_NOM - 1] = '\0';
    strncpy(r.salle, salle, MAX_NOM - 1);
    r.salle[MAX_NOM - 1] = '\0';
    strncpy(r.date, date, TAILLE_DATE - 1);
    r.date[TAILLE_DATE - 1] = '\0';
    r.heure_debut = heure_debut;
    r.heure_fin = heure_fin;
    r.nombre_personnes = nombre_personnes;
    r.tarif = tarif;
    r.statut = STATUT_CONFIRMEE;
    return r;
}

void afficher_salle(const Salle *s)
{
    printf("%s\n%d\n%.2f\n%s\n",
           s->nom, s->capacite,
           s->tarif_horaire, s->equipements);
}

void afficher_reservation(const Reservation *r)
{
    printf("%d\n%s\n%s\n%s\n%d\n%.2f\n%02d:%02d\n%02d:%02d\n",
           r->id, r->nom_client, r->salle, r->date,
           r->nombre_personnes, r->tarif,
           r->heure_debut / 60, r->heure_debut % 60,
           r->heure_fin / 60, r->heure_fin % 60);
    printf("Statut : ");
    switch (r->statut)
    {
    case STATUT_CONFIRMEE:
        printf("Confirmée\n");
        break;
    case STATUT_ANNULEE:
        printf("Annulée\n");
        break;
    case STATUT_TERMINEE:
        printf("Terminée\n");
        break;
    }
}