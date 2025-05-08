#include <stdio.h>
#include <stdlib.h>
#include "MisFunciones.h"

int main()
{
    int opcion;

    do{
        printf("Programa para el control de inventarios\n");

        opcion = ImpMenu();
        switch(opcion)
        {
        case 1: printf("Opcion 1\n");
            break;
        case 2: printf("Opcion 2\n");
            break;
        case 3: printf("Opcion 3\n");
            break;
        case 4: printf("Opcion 4\n");
            break;
        case 5: printf("Saliendo...\n");
            break;

        default: printf("Opcion no Valida!\n");
            break;
        }
        printf("\nAprieta una tecla para continuar...");
        getch();
        system("cls");

    }while(opcion!=5);

    return 0;
}
