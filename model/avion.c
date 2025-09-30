#include <stdio.h>
#include "../util/display.h"
#include "avion.h"

// void allAvions(Node* head) {
//     Node* temp = head;
//     if (!temp) {
//         displayByColor("Liste vide.\n", COLOR_BLUE);
//         return;
//     }

//     while (temp != NULL) {
//         Avion a = temp->data;
//         printf("ID: %d | Modele: %s | Capacité: %d | Statut: %d | Date: %02d/%02d/%04d\n",
//                a.id, a.modele, a.capacite, a.statut,
//                a.dateEntree.jour, a.dateEntree.mois, a.dateEntree.annee);
//         temp = temp->next;
//     }
// }

// Node* createNode(Avion avion) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (!newNode) {
//         printf("Erreur allocation mémoire!\n");
//         exit(1);
//     }
//     newNode->data = avion;
//     newNode->next = NULL;
//     return newNode;
// }

// void addAvion(Node** head, Avion avion) {
//     // create new node
//     Node* newNode = createNode(avion);

//     // check if the head node is empty
//     if (*head == NULL) {
//         *head = newNode; // add to first node
//     } else {
//         // get first node
//         Node* temp = *head;
//         // got to last node
//         while (temp->next != NULL)
//             temp = temp->next;
//         // add new node in last node.
//         temp->next = newNode;
//     }
// }

// int editAvion(Node* head, int id, Avion newData) {
//     Node* temp = head;

//     while (temp != NULL) {
//         if (temp->data.id == id) {
//             temp->data = newData;  // replace
//             return 1; // success
//         }
//         temp = temp->next;
//     }

//     return 0; // not found
// }

