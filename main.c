#include <stdio.h>
#include "menu/menu.h"
#include "util/display.h"

int main()
{
    AeroportNode *list = NULL;

    int choice;
    do {
        showMainMenu();

        displayByColor("Entrez votre choix: ", COLOR_MAGENTA);
        scanf("%d", &choice);

        handleMainChoice(choice, &list);
    } while (choice != 0);

    return 0;
}
