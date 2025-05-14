#include <stdbool.h>

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED


#define INC_LISTA 10

//enum Eliminado{ SI, NO};

typedef struct PRODUCTO_STR
{
    char nombre[250];
    char descr[512];
    double precio;
    int enStock;
    bool eliminado;
    //Eliminado eliminado = NO;

} Producto;


typedef struct LISTA_PROD_STR
{
    Producto *pLista;
    int numProd;
    int maxProd;

} ListaProd;


typedef struct VENTA_STR
{
    int idventa;
    int cantidad;
    char nombreProducto[256];
    double precioUnitario;
    double monto;
    //fecha: time
    bool eliminado;
} Venta;


int ImpMenu();
void AdmonInventario();
int ImpSubMenuInventario();
void AgregarProducto(ListaProd *plistaProd);
void ListarProducto(ListaProd listaProd);
ListaProd LeerArchivoProductos();


#endif // MISFUNCIONES_H_INCLUDED
