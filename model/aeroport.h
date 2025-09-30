#ifndef AEROPORT_H
#define AEROPORT_H

#include "data.h"

// Function to display list
void allAeroports(AeroportNode* head);

// Function to Add new
void addAeroport(AeroportNode** head);

// Function to update
void editAvion(AeroportNode* head);

// Function to delete
void deleteAeroport(AeroportNode** head);

// Function to find node by id (liner Search)
AeroportNode *findAeroport(AeroportNode* head, int id); 

// Function to find  node by nom (liner Search)
AeroportNode *findAeroportByNom(AeroportNode* head ,char *nom);

// Function to display information 
void infoAeroport(Aeroport *aeroport);

// Function to search
void searchAeroport(AeroportNode* head);

#endif