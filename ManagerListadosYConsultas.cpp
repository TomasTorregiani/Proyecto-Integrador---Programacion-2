#include <iostream>
#include "ManagerListadosYConsultas.h"
#include "ArchivoClientes.h"
#include "ArchivoProductos.h"
#include "ArchivoVendedores.h"
#include "ArchivoVentas.h"
#include "Cliente.h"
#include "Producto.h"
#include "Vendedor.h"
#include "Venta.h"
#include "FuncionesGlobales.h"
#include <string>

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
