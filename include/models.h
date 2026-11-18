#ifndef MODELS_H
#define MODELS_H

#define MAX_NOM 50
#define MAX_EQUIP 100
#define TAILLE_DATE 11
typedef enum{
    STATUT_CONFIRMEE=0,
    STATUT_ANNULEE=1,
    STATUT_TERMINEE=2,
}StatutReservation;
typedef struct{
    char nom[MAX_NOM];
    int capacite;
    float tarif_horaire;
    char equipements[MAX_EQUIP];
}Salle;
typedef struct{
    int id;
    char nom_client[MAX_NOM];
    char salle[MAX_NOM];
    char date[TAILLE_DATE];
    int heure_debut;
    int heure_fin;
    int nombre_personnes;
    float tarif;
    StatutReservation statut;
}Reservation;
Salle creer_salle(const char *nom,int capacite,float tarif_horaire,const char *equipements);
void afficher_salle(const Salle *s);
Reservation creer_reservation(int id,const char *nom_client,const char *salle,const char *date,int heure_debut,int heure_fin ,int nombre_personnes, float tarif);
void afficher_reservation(const Reservation *r);
#endif