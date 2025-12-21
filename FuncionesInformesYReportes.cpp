#include <iostream>
#include <iomanip>
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "Producto.h"
#include "ArchivoProductos.h"
#include "Venta.h"
#include "ArchivoVentas.h"
#include "ManagerVentas.h"
#include "DetalleVenta.h"
#include "ArchivoDetalles.h"
#include "Vendedor.h"
#include "ArchivoVendedores.h"
#include "TodosLosMenu.h"
#include "FuncionesGlobales.h"
#include "FuncionesInformesYReportes.h"

using namespace std;

void recaudacionMensualYAnual()
{
    int solicitudRecaudacion;
    do
    {
        cout << "Ingrese si quiere solicitud 1.Mensual o 2.Anual: " << endl;
        cin >> solicitudRecaudacion;
        switch(solicitudRecaudacion)
        {
        case 1:{
                int mesSeleccionado, anioSeleccionado;
                cout << "Ingrese el mes: " << endl;
                cin >> mesSeleccionado;
                cout << "Ingrese anio: " << endl;
                cin >> anioSeleccionado;

                int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

                ArchivoVentas archivoV("ventas.dat");
                Venta* arrayVentas = archivoV.obtenerTodasLasVentas(cantidadVentas);

                float totalPeriodoSeleccionado = 0;

                for(int i = 0; i < cantidadVentas; i++){
                    if(arrayVentas[i].getFecha().getAnio() == anioSeleccionado && arrayVentas[i].getFecha().getMes() == mesSeleccionado){
                        totalPeriodoSeleccionado += arrayVentas[i].getTotal();
                    }
                }
                cout << fixed << setprecision(2);
                cout << "Total periodo Seleccionado: " << mesSeleccionado << "/" << anioSeleccionado << " = $" << totalPeriodoSeleccionado << endl;
            }
            break;
        case 2:{
            int anioSeleccionado;
            cout << "Ingrese el anio: " << endl;
            cin >> anioSeleccionado;

            int cantidadRegistros = contarRegistros("ventas.dat", sizeof(Venta));

            ArchivoVentas archivoV("ventas.dat");
            Venta* arrayVentas = archivoV.obtenerTodasLasVentas(cantidadRegistros);

            int totalAcumulado = 0;

            for(int i = 0; i < cantidadRegistros; i++){
                if(arrayVentas[i].getFecha().getAnio() == anioSeleccionado){
                    totalAcumulado += arrayVentas[i].getTotal();
                }
            }

            cout << "Total acumulado en el anio " << anioSeleccionado << " = $" << totalAcumulado << endl;
        }
            break;
        default:
            cout << "Ingrese una opcion correcta" << endl;
            break;
        }
    }
    while(solicitudRecaudacion < 1 && solicitudRecaudacion > 2);

}

void productosMasVendidos()
{
    int cantidadDetallesVendidos = contarRegistros("detalles_venta.dat", sizeof(DetalleVenta));
    ArchivoDetalles archivoDetalles("detalles_venta.dat");

    int tamanio;
    int *detalles = archivoDetalles.obtenerVentasPorProducto(cantidadDetallesVendidos, tamanio);

    int *idsProductos;
    idsProductos = new int[tamanio]();

    for(int i = 0; i < tamanio; i++)
    {
        idsProductos[i] = i;
    }
    //Ordeno los array de mayor a menor. Utilizando burbuja
    for (int i = 0; i < tamanio - 1; i++)
    {
        for (int j = 0; j < tamanio - i - 1; j++)
        {
            if (detalles[j] < detalles[j + 1])
            {
                int aux = detalles[j];
                detalles[j] = detalles[j + 1];
                detalles[j + 1] = aux;
                int auxIds = idsProductos[j];
                idsProductos[j] = idsProductos[j + 1];
                idsProductos[j + 1] = auxIds;
            }
        }
    }
    ArchivoProductos archivoP("productos.dat");
    Producto productoObtenido;

    bool hayVentas = false;
    cout << "Productos de mas vendidos a menos vendidos" << endl;
    for(int i = 0; i < tamanio; i++)
    {
        if(detalles[i] > 0)
        {
            productoObtenido = archivoP.buscarProductoPorId(idsProductos[i]);
            cout << "ID producto: " << idsProductos[i] << ". " << productoObtenido.getDescripcion() << ", cantidad vendida: " << detalles[i] << endl;
            hayVentas = true;
        }
    }
    if(!hayVentas)
    {
        cout << "No se vendio ningun producto" << endl;
    }
    delete[] detalles;
    delete[] idsProductos;
}

void productosConBajoStock() //Podemos cambiar este nombre por "stock por producto" o algo parecido
{
    ArchivoProductos archivoProducto("productos.dat");

    int cantidadProductos = contarRegistros("productos.dat", sizeof(Producto));
    Producto *productos = archivoProducto.obtenerProductos(cantidadProductos);

    int cantidadProductosConStockMenorA10 = 0;
    for(int i = 0; i < cantidadProductos; i++)
    {
        if(productos[i].getCantidadDisponible() <= 10)
        {
            cantidadProductosConStockMenorA10++;
        }
    }

    Producto *arrayProductosConBajoStock;
    arrayProductosConBajoStock = new Producto[cantidadProductosConStockMenorA10];
    int indice = 0;
    for(int i = 0; i < cantidadProductos; i++)
    {
        if(productos[i].getCantidadDisponible() <= 10)
        {
            arrayProductosConBajoStock[indice] = productos[i];
            indice++;
        }
    }

    for(int i = 0; i < cantidadProductosConStockMenorA10; i++)
    {
        for(int j = 0; j < cantidadProductosConStockMenorA10 - i - 1; j++)
        {
            if(arrayProductosConBajoStock[j].getCantidadDisponible() < arrayProductosConBajoStock[j+1].getCantidadDisponible())
            {
                Producto auxiliar = arrayProductosConBajoStock[j];
                arrayProductosConBajoStock[j] = arrayProductosConBajoStock[j+1];
                arrayProductosConBajoStock[j+1] = auxiliar;
            }
        }
    }

    for(int i = 0; i < cantidadProductosConStockMenorA10; i++)
    {
        cout << arrayProductosConBajoStock[i].getDescripcion()
             << " | Stock: " << arrayProductosConBajoStock[i].getCantidadDisponible()
             << endl;
    }

    delete[] productos;
    delete[] arrayProductosConBajoStock;

}

void ventasPorVendedor()
{
    ArchivoVentas archivoVenta("ventas.dat");
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));

    Venta *arrayVentas;
    arrayVentas = archivoVenta.obtenerTodasLasVentas(cantidadVentas);

    int idVendedor;
    cout << "Ingrese id vendedor: " << endl;
    cin >> idVendedor;
    cout << endl;

    ///////

    ArchivoVendedores archivoVendedores("vendedores.dat");

    Vendedor registroVendedor = archivoVendedores.buscarVendedorPorId(idVendedor);
    if(registroVendedor.getIdVendedor() == 0)
    {
        cout << "No se encontro el vendedor" << endl;
    }
    else
    {
        cout << "Vendedor: " << registroVendedor.getNombre() << " " << registroVendedor.getApellido() << endl << endl;
    }

    ///////

    int ventasPorVendedor = 1;
    bool encontroVentas = false;
    for(int i = 0; i < cantidadVentas; i++)
    {
        if(arrayVentas[i].getIdVendedor() == idVendedor)
        {
						int idVentaActual = arrayVentas[i].getIdVenta();

            cout << "Venta ****  " << ventasPorVendedor << "  ****" << endl;
            cout << "Cliente: " << arrayVentas[i].getIdCliente() << endl;

            //Buscamos los detalles en el archivo 'detalles_venta.dat'

            ArchivoDetalles archivoDetalle("detalles_venta.dat");
            DetalleVenta arrayDetalles[50];
            int cantidadDetalles = archivoDetalle.verDetalleVenta(arrayVentas[i].getIdVenta(),arrayDetalles);
            cout << "Detalle de la venta: " << endl;

            for(int j = 0; j < cantidadDetalles; j++)
            {
                cout << j+1 << "." << arrayDetalles[j].getProducto().getDescripcion() << endl;
            }

						ManagerVentas ventaActual;
						cout << fixed << setprecision(2);
            cout << "Total : $" << ventaActual.calcularTotal(idVentaActual) << endl;
            cout << endl;

            encontroVentas = true;
            ventasPorVendedor++;
            cout << endl;
        }
    }
    if(!encontroVentas)
    {
        cout << "No se encontraron ventas para ese vendedor" << endl;
    }
    delete[] arrayVentas;

}

/*void clientesQueMasCompraron()
{

    cout << "**** CLIENTES QUE MAS COMPRARON ****" << endl;

    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));
    ArchivoVentas archivoVenta("ventas.dat");
    Venta* arrayVentasObtenidas = archivoVenta.obtenerTodasLasVentas(cantidadVentas);

    int maximoId = 0;
    for(int i = 0; i < cantidadVentas; i++)
    {
        if(arrayVentasObtenidas[i].getIdCliente() > maximoId)
        {
            maximoId = arrayVentasObtenidas[i].getIdCliente();  // trae el maximo nro de ID, es decir todos los clientes que hay.
        }
    }

    int* arrayIdsClientes;
    arrayIdsClientes = new int[maximoId + 1](); // al tamaño del vector lo define la cantidad de clientes que haya.

    for(int i = 0; i < maximoId; i++)
    {
        arrayIdsClientes[i] = i;		// el array se carga con todos los ids de los clientes.
    }

    float* arrayTotalesClientes;
    arrayTotalesClientes = new float[maximoId + 1]();

    for(int i = 0; i < cantidadVentas; i++)
    {
        arrayTotalesClientes[arrayVentasObtenidas[i].getIdCliente()] +=  arrayVentasObtenidas[i].getTotal();
    }

    for(int i = 0; i < maximoId; i++)
    {
        for(int j = 0; j < maximoId - i - 1; j++)
        {
            if(arrayTotalesClientes[j] < arrayTotalesClientes[j+1])
            {
                float auxiliar = arrayTotalesClientes[j];
                arrayTotalesClientes[j] = arrayTotalesClientes[j+1];
                arrayTotalesClientes[j+1] = auxiliar;
                int auxiliarIds = arrayIdsClientes[j];
                arrayIdsClientes[j] = arrayIdsClientes[j+1];
                arrayIdsClientes[j+1] = auxiliarIds;
            }
        }
    }

    cout << "----  Clientes que mas compraron ----" << endl; //Implementar aca
    for(int i = 0; i < 3; i++){
        cout << "Id Cliente " << arrayIdsClientes[i] << ", total comprado: " << arrayTotalesClientes[i] << endl;
    }

    delete[] arrayVentasObtenidas;
    delete[] arrayIdsClientes;
    delete[] arrayTotalesClientes;

}*/

void clientesQueMasCompraron()
{
    int cantidadVentas = contarRegistros("ventas.dat", sizeof(Venta));
    ArchivoVentas archivoVenta("ventas.dat");
    Venta* arrayVentasObtenidas = archivoVenta.obtenerTodasLasVentas(cantidadVentas);

    int maximoId = 0;
    for(int i = 0; i < cantidadVentas; i++){
        if(arrayVentasObtenidas[i].getIdCliente() > maximoId){
            maximoId = arrayVentasObtenidas[i].getIdCliente();
        }
    }

    float* arrayTotalesClientes = new float[maximoId + 1]();

    Fecha fechaInicio;
    cout << "---- Fecha Inicio ----" << endl;
    fechaInicio.ingresarFecha();

    Fecha fechaFinal;
    cout << "---- Fecha Final ----" << endl;
    fechaFinal.ingresarFecha();

    for(int i = 0; i < cantidadVentas; i++){
        Fecha f = arrayVentasObtenidas[i].getFecha();
				cout << fixed << setprecision(2);
        cout << "DEBUG Venta"
     << " ID Cliente: " << arrayVentasObtenidas[i].getIdCliente()
     << " Total venta: " << arrayVentasObtenidas[i].getTotal()
     << endl;


        bool desdeInicio =
            (f.getAnio() > fechaInicio.getAnio()) ||
            (f.getAnio() == fechaInicio.getAnio() && f.getMes() > fechaInicio.getMes()) ||
            (f.getAnio() == fechaInicio.getAnio() && f.getMes() == fechaInicio.getMes() && f.getDia() >= fechaInicio.getDia());

        bool hastaFinal =
            (f.getAnio() < fechaFinal.getAnio()) ||
            (f.getAnio() == fechaFinal.getAnio() && f.getMes() < fechaFinal.getMes()) ||
            (f.getAnio() == fechaFinal.getAnio() && f.getMes() == fechaFinal.getMes() && f.getDia() <= fechaFinal.getDia());

        if(desdeInicio && hastaFinal){
            arrayTotalesClientes[arrayVentasObtenidas[i].getIdCliente()] += arrayVentasObtenidas[i].getTotal();
        }
    }

    //DEBUG 1
    cout << "\nDEBUG - Totales por ID\n";
for(int i = 0; i <= maximoId; i++){
    cout << "ID " << i << " -> Total: " << arrayTotalesClientes[i] << endl;
}

    int cantidadClientesConCompras = 0;
    for(int i = 0; i <= maximoId; i++){
        if(arrayTotalesClientes[i] > 0){
            cantidadClientesConCompras++;
        }
    }

    if(cantidadClientesConCompras == 0){
        cout << "No hubo ventas en el periodo seleccionado." << endl;
        delete[] arrayVentasObtenidas;
        delete[] arrayTotalesClientes;
        return;
    }

    int* ids = new int[cantidadClientesConCompras];
    float* totales = new float[cantidadClientesConCompras];

    int pos = 0;
    for(int i = 0; i <= maximoId; i++){
        if(arrayTotalesClientes[i] > 0){
            ids[pos] = i;
            totales[pos] = arrayTotalesClientes[i];
            pos++;
        }
    }

    for(int i = 0; i < cantidadClientesConCompras - 1; i++){
        for(int j = 0; j < cantidadClientesConCompras - 1 - i; j++){
            if(totales[j] < totales[j+1]){
                float auxTotal = totales[j];
                totales[j] = totales[j+1];
                totales[j+1] = auxTotal;

                int auxId = ids[j];
                ids[j] = ids[j+1];
                ids[j+1] = auxId;
            }
        }
    }

    cout << "---- Clientes que mas compraron ----" << endl;
    cout << "Periodo: " << fechaInicio.toString() << " a " << fechaFinal.toString() << endl;

    ArchivoClientes archivoCliente("clientes.dat");

    int top = (cantidadClientesConCompras < 3) ? cantidadClientesConCompras : 3;

    for(int i = 0; i < top; i++){
        Cliente c = archivoCliente.buscarClientePorId(ids[i]);
        cout << "Id Cliente " << ids[i]
             << ", Cliente: " << c.getApellido() << ", " << c.getNombre()
             << ", total comprado: $" << totales[i] << endl;
    }

    delete[] arrayVentasObtenidas;
    delete[] arrayTotalesClientes;
    delete[] ids;
    delete[] totales;
}

