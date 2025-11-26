#include <iostream>
#include "FuncionesInformesYReportes.h"
#include "ArchivoClientes.h"
#include "ArchivoProductos.h"
#include "ArchivoVendedores.h"
#include "ArchivoVentas.h"
#include "Cliente.h"
#include "Producto.h"
#include "Vendedor.h"
#include "Venta.h"
#include "Fecha.h"
#include "FuncionesGlobales.h"
#include <string>
#include <ctime>

using namespace std;


void listadoClientes()
{
    cout << "**** LISTADO DE CLIENTES ****" << endl;

    int cantidadClientes = contarRegistros("clientes.dat",sizeof(Cliente));
    ArchivoClientes archivoCliente("clientes.dat");
    Cliente* arrayClientes = archivoCliente.obtenerClientes(cantidadClientes);

    for(int i = 0; i < cantidadClientes; i++)
    {
        arrayClientes[i].mostrarCliente();
    }
    delete[] arrayClientes;
}

void listadoProductos()
{

    cout << "**** LISTADO DE PRODUCTOS ****" << endl;  //Este case es identico al anterior,
    ArchivoProductos archivoProducto("productos.dat"); //sin embargo lo encare de una manera
    //mucho mas rebuscada
    int cantidadProductos = contarRegistros("productos.dat", sizeof(Producto));

    Producto* productosObtenidos;
    productosObtenidos = archivoProducto.obtenerProductos(cantidadProductos);

    for(int i = 0; i < cantidadProductos; i++)
    {
        productosObtenidos[i].mostrarProducto();
    }

    delete[] productosObtenidos;

}

void listadoVendedores()
{
    cout << "**** LISTADO DE VENDEDORES ****" << endl;

    int cantidadVendedores = contarRegistros("vendedores.dat",sizeof(Vendedor));
    ArchivoVendedores archivoVendedor("vendedores.dat");
    Vendedor* arrayVendedores = archivoVendedor.obtenerVendedores(cantidadVendedores);

    for(int i = 0; i < cantidadVendedores; i++)
    {
        arrayVendedores[i].mostrarVendedor();
    }
    delete[] arrayVendedores;

}

void ventasPorAnio()
{
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    int anioActual = tiempoLocal->tm_year + 1900;
    int anio;

    cout << "Ingrese un anio para mostrar: " << endl;
    cin >> anio;

    while(cin.fail() || anio > anioActual || anio < 2000)
    {
        cout << "Error. Ingres un anio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> anio;
		}
		
		ArchivoVentas archivoV("ventas.dat");
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

    Venta* vectorVentas = archivoV.obtenerTodasLasVentas(cantidadVentas);

    /*for(int i = 0; i < cantidadVentas; i++)
    {
        // >>> ERROR: >>> Fecha fecha = vectorVentas[i].getFecha();

        if(fecha.getAnio() == anio)
        {
            cout << "Fecha: " << vectorVentas[i].getFecha() << endl;
            cout << "ID Venta: " << vectorVentas[i].getIdVenta() << endl;
            cout << "ID Cliente: " << vectorVentas[i].getIdCliente() << endl;
            cout << "ID Vendedor: " << vectorVentas[i].getIdVendedor() << endl;
        }
    }
    delete[]vectorVentas;*/
}


void ventasPorMes()
{
}

void ventasPorFechaExacta()
{

}

void ventasPorIntervaloDeFecha()
{

}
