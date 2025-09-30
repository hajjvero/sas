#include "stdio.h"
#include "string.h"
#include "aeroport.h"
#include "stdlib.h"
#include "../util/display.h"
#include "../util/input.h"

void allAeroports(AeroportNode* head) {
    AeroportNode* temp = head;
  
    if (temp == NULL)
    {
        displayByColor("Liste vide.\n", COLOR_BLUE);
        return;
    }
    
    while (temp != NULL)
    {
        infoAeroport(&temp->data);
        temp = temp->next;
    }
}

void addAeroport(AeroportNode** head) {
    // create object 
    Aeroport aeroport;
    
    inputText("Entrer nom", aeroport.nom);


    // create Node of aeroport.
    AeroportNode* node = (AeroportNode *)malloc(sizeof(AeroportNode));

    node->data = aeroport;
    node->next = NULL;

    // check if the head is empty.
    if (*head == NULL)
    {
        // firt element
        node->data.id = 1;

        *head = node;
    } else {
        // start from head of node.
        AeroportNode* temp = *head;

        // set to last id + 1
        int nextId = temp->data.id + 1;

        // go to last node.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        node->data.id = nextId;

        // add new node to last node.
        temp->next = node;
    }
    
    displayByColor("Add success!", COLOR_GREEN);
}

void editAvion(AeroportNode* head) {
    int id;
    inputInteger("Entrer Id", &id);

    AeroportNode *aeroportNode = findAeroport(head, id);

    if (aeroportNode == NULL)
    {
        displayByColor("\nAucun aeroport trouve", COLOR_RED);
    } else {
        // display current data
        infoAeroport(&(aeroportNode->data));

        inputText("Entrer new nom", aeroportNode->data.nom); 
    }
    
    displayByColor("Edit success!", COLOR_GREEN);
}

void deleteAeroport(AeroportNode** head) {
    if (*head == NULL) {
        displayByColor("Liste vide, rien a supprimer.", COLOR_BLUE);
        return;
    }

    AeroportNode* temp = *head; // add first node to temp.
    AeroportNode* prev = NULL; // hada mhtajo bach fach nl9a hadak element li bghit nhayad nhot fih ga" dak chi li 3ando 3la9a m3a element li bghit nhayad.

    // id from user
    int id;
    inputInteger("Entrer Id", &id);

    // If first node is the one to delete
    if (temp != NULL && temp->data.id == id) {
        *head = temp->next;   // just move next to head
        free(temp);           // free memory
        displayByColor("Delete success", COLOR_GREEN);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        displayByColor("\nAucun aeroport trouve", COLOR_RED);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);

    displayByColor("Delete success", COLOR_GREEN);
}

AeroportNode *findAeroport(AeroportNode* head ,int id) {
    AeroportNode* temp = head;
    while (temp->next != NULL)
    {
        if (temp->data.id == id)
        {
            return temp;
        }
        
        temp = temp->next;
    }
    
     return NULL;
}

AeroportNode *findAeroportByNom(AeroportNode* head ,char *nom) {
    AeroportNode* temp =  head;
    while (temp->next != NULL)
    {
        if (strcmp(temp->data.nom, nom) == 0)
        {
            return temp;
        }
        
        temp = temp->next;
    }
    
     return NULL;
}

void infoAeroport(Aeroport *aeroport) {
    printf("\nID  : %d\n", aeroport->id);
    printf("Nom  : %s\n", aeroport->nom);

    printLine("=", DISPLAY_WIDTH / 2, COLOR_CYAN);
}

void searchAeroport(AeroportNode* head) {
    char search[255];

    inputText("Entrer nom", search);

    AeroportNode *aeroportNode = findAeroportByNom(head, search);

    if (aeroportNode == NULL)
    {
        displayByColor("\nAucun aeroport trouve", COLOR_RED);
    } else {
        // display current data
        infoAeroport(&(aeroportNode->data));
    }
}