#ifndef DATA_H
#define DATA_H

// Enum of status
typedef enum
{
    DISPONIBLE = 1,
    MAINTENANCE,
    VOL
} Statut;

// Model of date
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

// Modale of avion
typedef struct
{
    int id;
    char *modele;
    int capacite;
    Statut statut;
    Date dateEntree;
} Avion;

typedef struct
{
    int id;             // ID autoincrement
    char nom[255];      // Nom string
    // Avion *flotte;   // List of avions
    // int count;       // count of avions
} Aeroport;


// Linked list node for Aeroport
typedef struct AeroportNode {
    Aeroport data;
    struct AeroportNode* next;
} AeroportNode;

#endif