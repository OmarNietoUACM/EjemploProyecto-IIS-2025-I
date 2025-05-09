#include <stdio.h>
#include <stdlib.h>
#include "MisFunciones.h"

/*
1. Ventas
2. Admin de Inventario
   2.1 Agregar producto
   2.2 Actualizar producto
   3.3 Eliminar producto
   3.4 regresar el menu previo

3. Listar inventario
4. Imprimir lista de bajo stock
5. Salir

*/


int ImpMenu()
{
    int op;
    system("cls");
    printf("     MENU PRINCIPAL \n");
    printf("1. Ventas \n");
    printf("2. Admin Inventarios \n");
    printf("3. Listar Inventario\n");
    printf("4. Lista de bajo stock\n");
    printf("5. Salir\n");
    printf("Ingresa tu opcion: ");
    scanf("%d", &op);

    return op;
}




int ImpSubMenuInventario()
{
    int op;
    system("cls");
    printf("     SUBMENU INVENTARIO \n");
    printf("1. Agregar producto \n");
    printf("2. Actualizar producto \n");
    printf("3. Eliminar producto\n");
    printf("4. Listar inventario\n");
    printf("5. Regresar al menú principal\n");
    printf("Ingresa tu opcion: ");
    scanf("%d", &op);

    return op;
}

int ObtenerNumProductos()
{
    int numProductos;

    FILE *pf = NULL;
    pf = fopen(ARCHIVO_PRODUCTOS, "r");

    if(pf == NULL)
    {
        printf("ERROR: No se puede abrir el archivo: %s", ARCHIVO_PRODUCTOS);
        return -1;
    }

    fread(&numProductos, sizeof(int), pf);

    fclose(pf);
    return numProductos;
}


void AdmonInventario()
{
    int opcion, numProductos;
    Producto pListaProductos = NULL;


    do{
        opcion = ImpSubMenuInventario();

        numProductos = ObtenerNumProductos();
        if (numProductos < 0 ) return;

        pLustaProductos = LeerProductos(numProductos);



        switch(opcion)
        {
            case 1:   //Agregar producto
                break;
            case 2:   //Actualizar  producto
                 break;
            case 3:   //Eliminar producto
                 break;
            case 4:   //Listar los productos
                 break;
            case 5: // Regresar al menú principal
                printf("regresando al menu principal...\n");
                 break;
            default:
               printf("Opcion No valida");
                break;
        }
       // printf("\nAprieta una tecla para continuar...");
       // getch();


    }while(opcion != 5);


}
