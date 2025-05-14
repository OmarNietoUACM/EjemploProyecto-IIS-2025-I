#include <stdio.h>
#include <stdlib.h>
#include "MisFunciones.h"



extern char ARCHIVO_PRODUCTOS[];
extern char ARCHIVO_VENTAS[];


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


ListaProd LeerArchivoProductos()
{
    ListaProd productos;
    int numProductos;

    FILE *pf = NULL;
    pf = fopen(ARCHIVO_PRODUCTOS, "r");

    if(pf == NULL)
    {
        printf("ERROR: No se puede abrir el archivo: %s", ARCHIVO_PRODUCTOS);

        productos.pLista = calloc(INC_LISTA, sizeof(Producto));
        if (productos.pLista == NULL ) //No se pudo reservar memoria
        {
            printf("ERROR: No se pudo reservar memoria dinámica\n");
            exit(-1);
        }
        productos.numProd = 0;
        productos.maxProd = INC_LISTA;

        return productos;
    }


    fread(&numProductos, sizeof(int), 1, pf);

    productos.pLista = calloc(numProductos + INC_LISTA, sizeof(Producto));
    if (productos.pLista == NULL ) //No se pudo reservar memoria
    {
        printf("ERROR: No se pudo reservar memoria dinámica\n");
        exit(-1);
    }

    productos.numProd = numProductos;
    productos.maxProd = numProductos + INC_LISTA;

    //Se lee la lista de archivos
    fread(productos.pLista, sizeof(Producto), numProductos, pf);

    fclose(pf);

    return productos;
}



void AgregarProducto(ListaProd *plistaProd)
{
    Producto nuevoProd;

    fflush(stdin);
    printf("Agregar un producto \n\n");
    printf("Ingresa el nombre: ");
    gets(nuevoProd.nombre);
    printf("Ingresa la descripcion: ");
    gets(nuevoProd.descr);
    printf("Ingresa el precio: ");
    scanf("%lf", &nuevoProd.precio);
    printf("Ingresa el stock: ");
    scanf("%d", &nuevoProd.enStock);

    if (plistaProd->numProd < plistaProd->maxProd)
    {
        plistaProd->pLista[plistaProd->numProd] = nuevoProd;
        plistaProd->numProd++;
    }
    else if (plistaProd->numProd == plistaProd->maxProd) // Ya se alcanzó el máximo valor
    {
         Producto *p = NULL;
         p = realloc(plistaProd->pLista, plistaProd->numProd + INC_LISTA);
         if (p == NULL)
         {
            printf("ERROR: No hay memoria suficiente para almacenar el nuevo producto\n");
            return;
         }

         plistaProd->pLista[plistaProd->numProd] = nuevoProd;
         plistaProd->numProd++;
         plistaProd->maxProd = plistaProd->numProd + INC_LISTA;
    }
}




void ListarProducto(ListaProd listaProd)
{
    int i;
    printf("\nLa lista de productos:\n");
    for(i=0; i< listaProd.numProd; i++)
    {
        if (listaProd.pLista[i].eliminado == false)
        {
            printf("\nProducto %d:\n", i+1);
            printf("\tNombre: %s\n", listaProd.pLista[i].nombre);
            printf("\tDescripcion: %s\n", listaProd.pLista[i].descr);
            printf("\tPrecio: %lf\n", listaProd.pLista[i].precio);
            printf("\tEn Stock: %d\n", listaProd.pLista[i].enStock);
        }

    }
}


void EliminarProducto(ListaProd listaProd)
{
     int i;
    ListarProducto(listaProd);

    printf("\nEscribe el índice del producto a eliminar: ");
    scanf("%d", &i);

    //TODO: Falta validar que i esté en el rango correcto 0 <= i < MAX

    listaProd.pLista[i-1].eliminado = true;
    printf("\nEl producto ha sido eliminado");

}


void AdmonInventario()
{
    int opcion;
    ListaProd listaProd;

    listaProd = LeerArchivoProductos();

    do{
        opcion = ImpSubMenuInventario();




        switch(opcion)
        {
            case 1:   //Agregar producto
                    AgregarProducto(&listaProd);

                break;
            case 2:   //Actualizar  producto
                    // ActualizarProducto(listaProd);
                 break;
            case 3:   //Eliminar producto
                    EliminarProducto(listaProd);
                 break;
            case 4:   //Listar los productos
                    ListarProducto(listaProd);
                 break;
            case 5: // Regresar al menú principal
                printf("regresando al menu principal...\n");
                 break;
            default:
               printf("Opcion No valida");
                break;
        }
        printf("\nAprieta una tecla para continuar...");
        getch();


    }while(opcion != 5);


}
