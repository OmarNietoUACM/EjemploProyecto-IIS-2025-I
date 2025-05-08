#include <stdio.h>

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
    printf("     MENU \n");
    printf("1. Ventas \n");
    printf("2. Admin Inventarios \n");
    printf("3. Listar Inventario\n");
    printf("4. Lista de bajo stock\n");
    printf("5. Salir\n");
    printf("Ingresa tu opcion: ");
    scanf("%d", &op);

    return op;
}
