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
#include "ManagerVentas.h"
#include <string>
#include <ctime>

using namespace std;


void listadoClientes()
{
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

    ArchivoProductos archivoProducto("productos.dat");
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

    cout << endl;

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

    int contVentas = 0;

    for(int i = 0; i < cantidadVentas; i++)
    {
        Fecha fecha = vectorVentas[i].getFecha();

        if(fecha.getAnio() == anio)
        {
						int idVentaActual = vectorVentas[i].getIdVenta();
            cout << "Fecha: " << vectorVentas[i].getFechaString() << endl;
            cout << "ID Venta: " << vectorVentas[i].getIdVenta() << endl;
            cout << "ID Cliente: " << vectorVentas[i].getIdCliente() << endl;
            cout << "ID Vendedor: " << vectorVentas[i].getIdVendedor() << endl;
            
            ManagerVentas ventaActual;
            
            cout << "Total : $" << ventaActual.calcularTotal(idVentaActual) << endl; 
            cout << endl;
            
            contVentas ++;
        }
    }
    if(contVentas == 0)
    {
        cout << "No se registraron ventas en el anio " << anio << "." << endl;
    }
    else
    {
        cout << "Se registraron " << contVentas << " ventas en el anio " << anio << ". " << endl;
    }

    delete[]vectorVentas;
}

void ventasPorMes()
{
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    int anioActual = tiempoLocal->tm_year + 1900;
    int anio;

    cout << "Primero ingrese un anio: " << endl;
    cin >> anio;

    while(cin.fail() || anio > anioActual || anio < 2000)
    {
        cout << "Error. Ingres un anio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> anio;
    }

    int mes;
    cout << "Ingrese un mes: " << endl;
    cin >> mes;

    cout << endl;

    while(mes < 1 || mes > 12)
    {
        cout << "Error. Ingese un mes valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> mes;
    }

    ArchivoVentas archivoV("ventas.dat");
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

    Venta* vectorVentas = archivoV.obtenerTodasLasVentas(cantidadVentas);

    int contVentas = 0;

    for(int i = 0; i < cantidadVentas; i++)
    {

        Fecha fechaRegistro = vectorVentas[i].getFecha();
        if(fechaRegistro.getAnio() == anio && fechaRegistro.getMes() == mes)
        {
						int idVentaActual = vectorVentas[i].getIdVenta();
            cout << "Fecha: " << vectorVentas[i].getFechaString() << endl;
            cout << "ID Venta: " << vectorVentas[i].getIdVenta() << endl;
            cout << "ID Cliente: " << vectorVentas[i].getIdCliente() << endl;
            cout << "ID Vendedor: " << vectorVentas[i].getIdVendedor() << endl;
            
            ManagerVentas ventaActual;
            
            cout << "Total : $" << ventaActual.calcularTotal(idVentaActual) << endl; 
            cout << endl;

            contVentas ++;
        }
    }
    if(contVentas == 0)
    {
        cout << "No se registraron ventas en el mes " << mes << "." << endl;
    }
    else
    {
        cout << "Se registraron " << contVentas << " ventas en el mes " << mes << " del anio " << anio << ". " << endl;
    }

    delete[]vectorVentas;
}

void ventasPorFechaExacta()
{
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    int anioActual = tiempoLocal->tm_year + 1900;
    int anio;

    cout << "Primero ingrese un anio: " << endl;
    cin >> anio;
    cout << endl; 

    while(cin.fail() || anio > anioActual || anio < 2000)
    {
        cout << "Error. Ingres un anio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> anio;
    }

    int mes;
    cout << "Ingrese un mes: " << endl;
    cin >> mes;

    cout << endl;

    while(mes < 1 || mes > 12)
    {
        cout << "Error. Ingese un mes valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> mes;
    }

    int dia;
    cout << "Ingrese un dia: " << endl;
    cin >> dia;
    cout << endl; 

    int cantDiasMes = diasDelMes(mes,anio); //chequea si es bisiesto

    while (dia < 1 || dia > cantDiasMes)
    {
        cout << "Error. Ingrese un dia valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> dia;
    }

    ArchivoVentas archivoV("ventas.dat");
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

    Venta* vectorVentas = archivoV.obtenerTodasLasVentas(cantidadVentas);

    int contVentas = 0;

    for(int i = 0; i < cantidadVentas; i++)
    {

        Fecha fechaRegistro = vectorVentas[i].getFecha();
        if(fechaRegistro.getAnio() == anio && fechaRegistro.getMes() == mes && fechaRegistro.getDia()== dia)
        {
						int idVentaActual = vectorVentas[i].getIdVenta();
            cout << "Fecha: " << vectorVentas[i].getFechaString() << endl;
            cout << "ID Venta: " << vectorVentas[i].getIdVenta() << endl;
            cout << "ID Cliente: " << vectorVentas[i].getIdCliente() << endl;
            cout << "ID Vendedor: " << vectorVentas[i].getIdVendedor() << endl;
            
            ManagerVentas ventaActual;
            
            cout << "Total : $" << ventaActual.calcularTotal(idVentaActual) << endl; 
            cout << endl;
						
            contVentas ++;
        }
    }

    if(contVentas == 0)
    {
        cout << "No se registraron ventas en la fecha solicitada." << endl;
    }
    else
    {
        cout << "Se registraron " << contVentas << " ventas en la fecha ingresada." << endl;
    }
    delete[]vectorVentas;
}

void ventasPorIntervaloDeFecha()
{
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    int anioActual = tiempoLocal->tm_year + 1900;

    int anio, anio2;
    int mes, mes2;
    int dia, dia2;
    int cantidadDiasMes = 0;
    
    //-------------------------- INGRESO DE 1º FECHA  --------------------------------//

    cout << "**** PRIMERA FECHA ****" <<  endl << endl;
    cout << "Ingrese un anio: " << endl;
    cin >> anio;

    while(cin.fail() || anio > anioActual || anio < 2000)
    {
        cout << "Error. Ingres un anio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> anio;
    }

    cout << "Ingrese un mes: " << endl;
    cin >> mes;

    cout << endl;

    while(mes < 1 || mes > 12)
    {
        cout << "Error. Ingese un mes valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> mes;
    }

    cout << "Ingrese un dia: " << endl;
    cin >> dia;

    cantidadDiasMes = diasDelMes(mes, anio);

    while((dia < 1 || dia > cantidadDiasMes))
    {
        cout << "Error. Ingese un dia valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> dia;
    }
    
	
    ///------------------------  INGRESO DE 2º FECHA  ----------------------------//
    

    cout << "**** SEGUNDA FECHA ****" <<  endl << endl;
    cout << "Ingrese un anio: " << endl;
    cin >> anio2;

    while(cin.fail() || anio2 > anioActual || anio2 < 2000)
    {
        cout << "Error. Ingres un anio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> anio2;
    }

    cout << "Ingrese un mes: " << endl;
    cin >> mes2;

    cout << endl;

    while(mes2 < 1 || mes2 > 12)
    {
        cout << "Error. Ingese un mes valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> mes2;
    }

    cout << "Ingrese un dia: " << endl;
    cin >> dia2;

    cantidadDiasMes = diasDelMes(mes2, anio2);

    while((dia2 < 1) || (dia2 > cantidadDiasMes))
    {
        cout << "Error. Ingrese un dia valido: " << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> dia2;
    }    
    
    int fechaInicio = anio * 10000 + mes * 100 + dia;
    
    //cout << " DEBUG: La fecha de incio es: " << fechaInicio << endl; 
    
    int fechaFin = anio2 * 10000 + mes2 * 100 + dia2;
    
    //cout << " DEBUG: la fecha de fin es: " << fechaFin << endl; 
    
    if(fechaFin < fechaInicio){
			cout << "Error: la segunda fecha debe ser mayor o igual a la primera" << endl; 
			return;
    }
    
    //------------------------  BUSCAR VENTAS EN EL INTERVALO ------------------------//
    
    
    ArchivoVentas archivoV("ventas.dat");
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

    Venta* vectorVentas = archivoV.obtenerTodasLasVentas(cantidadVentas);

    int contVentas = 0;

    for(int i = 0; i < cantidadVentas; i++)
    {

        Fecha fechaRegistro = vectorVentas[i].getFecha();
        
        int fechaVenta = fechaRegistro.getAnio() * 10000 + fechaRegistro.getMes() * 100 + fechaRegistro.getDia();
					
        if(fechaVenta >= fechaInicio && fechaVenta <= fechaFin)
        {
						int idVentaActual = vectorVentas[i].getIdVenta();
            cout << "Fecha: " << vectorVentas[i].getFechaString() << endl;
            cout << "ID Venta: " << vectorVentas[i].getIdVenta() << endl;
            cout << "ID Cliente: " << vectorVentas[i].getIdCliente() << endl;
            cout << "ID Vendedor: " << vectorVentas[i].getIdVendedor() << endl;
            
            ManagerVentas ventaActual;
            
            cout << "Total : $" << ventaActual.calcularTotal(idVentaActual) << endl; 
            cout << endl;

            contVentas ++;
        }
        
    }
    if(contVentas == 0){
			cout << "No se registraron ventas en el periodo solicitado." << endl; 
    }else
			{
				cout << "Se registraron " << contVentas << " ventas en el periodo ingresado." << endl;
			}
    
    delete[]vectorVentas;
}




