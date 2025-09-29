#include "stdio.h"
#include "string.h"
#include "menu.h"
#include "../util/display.h"

void menuTitle(char *name)
{
    // border top
    printLine("=", DISPLAY_WIDTH, COLOR_CYAN);

    int padding = (DISPLAY_WIDTH - strlen(name)) / 2;

    // cente Tetx
    for (int i = 0; i < padding; i++)
        printf(" ");

    displayByColor(name, COLOR_YELLOW);
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
    displayByColor(" [4]\tAfficher la liste", COLOR_GREEN);
    printf("\n\n");
}

void handleMainChoice(int choice)
{
    switch(choice) {
            case 1:
                printf("Choice %d", choice);
                break;
            case 2:
                printf("Choice %d", choice);
                break;
            case 3:
                printf("Choice %d", choice);
                break;
            case 4:
               printf("Choice %d", choice);
                break;
            case 0:
                displayClear();
                displayByColor("Merci d'utiliser notre application!\n",COLOR_BLUE);
                displayByColor("Au revoir!\n",COLOR_BLUE);
                break;
            default:
                displayByColor("\nChoix invalide! Appuyez sur Entrée pour continuer ...\n", COLOR_RED);
                getchar(); // read last Entre from scanf.
                getchar(); // waiting user to Entre.
        }
}