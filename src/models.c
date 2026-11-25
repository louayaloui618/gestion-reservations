#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

int charger_salles(const char *chemin, Salle salles[], int max)
{
    FILE *fichier = fopen(chemin, "r");
    if (fichier == NULL)
        return 0;

    char ligne[256];
    int x = 0;

    while (x < max && fgets(ligne, sizeof(ligne), fichier) != NULL)
    {
        char *nom = strtok(ligne, ";\n");
        char *cap = strtok(NULL, ";\n");
        char *tarif = strtok(NULL, ";\n");
        char *equip = strtok(NULL, ";\n");

        if (nom == NULL || cap == NULL || tarif == NULL || equip == NULL)
            continue;

        salles[x] = creer_salle(nom, atoi(cap), (float)atof(tarif), equip);
        x++;
    }

    fclose(fichier);
    return x;
}

int sauvegarder_salles(const char *chemin, const Salle salles[], int nb)
{
    FILE *fichier = fopen(chemin, "w");
    if (fichier == NULL)
        return 0;

    for (int i = 0; i < nb; i++)
    {
        fprintf(fichier, "%s;%d;%.2f;%s\n",
                salles[i].nom, salles[i].capacite,
                salles[i].tarif_horaire, salles[i].equipements);
    }

    fclose(fichier);
    return 1;
}

const Salle *trouver_salle(const Salle salles[], int nb, const char *nom)
{
    for (int i = 0; i < nb; i++)
    {
        if (strcmp(salles[i].nom, nom) == 0)
            return &salles[i];
    }
    return NULL;
}

float calculer_cout(const Salle *s, int heure_debut, int heure_fin)
{
    float duree = (heure_fin - heure_debut) / 60.0f;
    return s->tarif_horaire * duree;
}