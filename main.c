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
        case 1: printf("1. Ventas\n");
            break;
        case 2: //printf("2. Admin de Inventario 2\n");
                AdmonInventario();
            break;
        case 3: printf("3. Imprimir lista de bajo stock\n");
            break;
        case 4: printf("4. Exportar inventario a CSV\n");
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
