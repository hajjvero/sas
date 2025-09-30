#include "stdio.h"
#include "string.h"
#include "menu.h"
#include "../util/display.h"
#include "../model/aeroport.h"

void menuTitle(char *name)
{
    // border top
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);

    int padding = (DISPLAY_WIDTH - strlen(name)) / 2;

    // center Tetx
    for (int i = 0; i < padding; i++)
        printf(" ");

    displayByColor(name, COLOR_YELLOW);
    printf("\n");

    // border bottom
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);
}

void menuSubTitle(char *title) {
    printf("\n");
    int padding = (DISPLAY_WIDTH - strlen(title)) / 2;

     // center Tetx
    for (int i = 0; i < padding; i++)
        printf(" ");

    displayByColor(title, COLOR_YELLOW);
    printf("\n");

    // border bottom
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);
}

void showMainMenu()
{
    // clear console
    displayClear();

    // menu title
    menuTitle("Gestion");

    displayByColor("\n [0]\tQuitter\n", COLOR_RED);
    displayByColor(" [1]\tAjouter\n", COLOR_GREEN);
    displayByColor(" [2]\tModifier\n", COLOR_GREEN);
    displayByColor(" [3]\tSupprimer\n", COLOR_GREEN);
    displayByColor(" [4]\tAfficher la liste\n", COLOR_GREEN);
    displayByColor(" [5]\tRechercher\n", COLOR_GREEN);
    printf("\n\n");
}

void handleMainChoice(int choice, AeroportNode **list)
{
    switch (choice)
    {
    case 1:
        // Add
        menuSubTitle("Ajouter");
        addAeroport(&(*list));
        break;
    case 2:
        // Edit
        menuSubTitle("Modifier");
        editAvion(*list);
        break;
    case 3:
        // Delete 
        menuSubTitle("Supprimer");
        deleteAeroport(&(*list));
        break;
    case 4:
        // List
        menuSubTitle("Afficher la liste");
        allAeroports(*list);
        break;
    case 5:
        // Search
        menuSubTitle("Rechercher");
        searchAeroport(*list);
        break;    
    case 0:
        displayClear();
        displayByColor("Merci d'utiliser notre application!\n", COLOR_BLUE);
        displayByColor("Au revoir!\n", COLOR_BLUE);
        break;
    default:
        displayByColor("\nChoix invalide!\n", COLOR_RED);
    }

    // this tis if not exit programe.
    if (choice != 0)
    {
        displayByColor("\nAppuyez sur Entree pour continuer ...\n", COLOR_CYAN);
        getchar(); // read last Entre from scanf.
        getchar(); // waiting user to Entre.F
    }
}