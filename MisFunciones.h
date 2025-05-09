#include <stdbool.h>

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

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


char ARCHIVO_PRODUCTOS[] = "Productos.dat";
char ARCHIVO_VENTAS[] = "Ventas.dat";



int ImpMenu();
void AdmonInventario();
int ImpSubMenuInventario();
int ObtenerNumProductos();

#endif // MISFUNCIONES_H_INCLUDED
