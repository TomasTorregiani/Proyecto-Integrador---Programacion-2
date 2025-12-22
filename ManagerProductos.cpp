#include <iostream>
#include <string>
#include "ManagerProductos.h"
#include "FuncionesGlobales.h"
#include "ArchivoProductos.h"

using namespace std;

ManagerProductos::ManagerProductos():_archivo("productos.dat"){

}

void ManagerProductos::crearNuevoProducto()
{
    Producto nuevoProducto;

    int idProducto, cantidad;
    string descripcion, marca, tipo;
    float precio;

    cout << "Ingrese la descripcion: " << endl;
    cin.ignore();
    getline(cin, descripcion);

    while(descripcion == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese la descripcion del producto: " << endl;
        getline(cin, descripcion);
    }

    nuevoProducto.setDescripcion(descripcion);

    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);

    while(marca == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese la marca del producto: " << endl;
        getline(cin, marca);
    }

    nuevoProducto.setMarca(marca);

    cout << "Ingrese el tipo de producto: " << endl;
    getline(cin, tipo);

    while(tipo == "")
    {
        cout << "Este campo no puede estar vacio. Ingrese el tipo de producto: " << endl;
        getline(cin, tipo);
    }

    nuevoProducto.setTipoProducto(tipo);

    cout << "Ingrese la cantidad: " << endl;

    while (!(cin >> cantidad) || cantidad < 0 || cin.peek() == '.') //si cin no guarda correctamente un int o si guarda pero el int es menor a 0.
    {
        cout << "Error: Ingrese un numero entero valido (no decimal): " << endl;
        cin.clear();						//limpia el error de cin después de que falló al leer, para que cin pueda leer de nuevo.
        cin.ignore(10000, '\n');	//Borra lo que guardó el buffer de entrada hasta 10000 caracteres (o hasta encontrar un salto de línea \n)
    }
    cin.ignore(10000, '\n');

    nuevoProducto.setCantidadDisponible(cantidad);

    cout << "Ingrese el precio final: " << endl;

    while(!(cin >> precio) || precio < 0)
    {
        cout << "Error: ingrese un precio final valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    nuevoProducto.setPrecio(precio);

    nuevoProducto.setActivo(true);

    idProducto = contarRegistros("productos.dat", sizeof(Producto)) + 1;

    nuevoProducto.setIdProducto(idProducto);

    cout << "El Id del Producto es: " << nuevoProducto.getIdProducto() << endl;


    //***** fin de los ingresos *****//

    int agregoArchivo = _archivo.agregarNuevoProducto(nuevoProducto);
    if(agregoArchivo == 1)
    {
        cout << "Archivo agregado correctamente" << endl;
    }
    else
    {
        cout << "No se agrego el archivo" << endl;
    }
}
Producto ManagerProductos::pedirNuevosDatos(){
    Producto productoModificado;
    string descripcion, marca, tipoProducto;
    int cantidadDisponible;
    float precio;

    cout << "Ingresar descripcion producto a modificar: " << endl;
    cin.ignore();
    getline(cin, descripcion);
    while(descripcion == "")
    {
        cout << "Error. Ingrese una descripcion: " << endl;
        getline(cin, descripcion);
    }
    productoModificado.setDescripcion(descripcion);

    cout << "Ingresar marca producto nuevo: " << endl;
    getline(cin, marca);
    while(marca == "")
    {
        cout << "Error. Ingrese una marca: " << endl;
        getline(cin, marca);
    }
    productoModificado.setMarca(marca);

    cout << "Ingresar tipo producto: " << endl;
    getline(cin, tipoProducto);
    while(tipoProducto == "")
    {
        cout << "Error. Ingrese un tipo producto valido: " << endl;
        getline(cin, tipoProducto);
    }
    productoModificado.setTipoProducto(tipoProducto);

    cout << "Ingresar cantidad disponible: " << endl;
    cin >> cantidadDisponible;
    while(cin.fail() || cantidadDisponible < 0)
    {
        cout << "Error. Ingrese una cantidad disponible valida: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidadDisponible;
    }
    cin.ignore(10000, '\n');
    productoModificado.setCantidadDisponible(cantidadDisponible);

    cout << "Ingresar precio nuevo: " << endl;
    cin >> precio;
    while(cin.fail() || precio < 0)
    {
        cout << "Error. Ingrese un precio valido: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> precio;
    }
    cin.ignore(10000, '\n');
    productoModificado.setPrecio(precio);

    productoModificado.setActivo(true);
    return productoModificado;
}

void ManagerProductos::modificarProducto()
{
    int idProductoAModificar;
    cout << "Ingrese id del producto a modificar: " << endl;
    cin >> idProductoAModificar;

    int posicionProductoAModificar = _archivo.buscarPosicionPorId(idProductoAModificar);

    if(posicionProductoAModificar != -1)
    {
        cout << "Producto Encontrado" << endl;
        Producto productoAModificar = _archivo.buscarProductoPorId(idProductoAModificar);
        int idOriginal = productoAModificar.getIdProducto();

        productoAModificar = pedirNuevosDatos();
        productoAModificar.setIdProducto(idOriginal);

        int agregoProducto = _archivo.agregarProductoModificado(productoAModificar, posicionProductoAModificar);
        if(agregoProducto == 1)
        {
            cout << "Producto modificado correctamente" << endl;
        }
        else
        {
            cout << "No se pudo modificar el producto" << endl;
        }
    }
    else
    {
        cout << "Producto no encontrado" << endl;
    }
}

void ManagerProductos::eliminarProducto()
{
    int idProductoAEliminar;
    cout << "Ingrese id del producto a eliminar: " << endl;
    cin >> idProductoAEliminar;

    int posicionProductoAEliminar = _archivo.buscarPosicionPorId(idProductoAEliminar);

    if(posicionProductoAEliminar != -1)
    {
        cout << "Producto Encontrado" << endl;
        Producto productoAEliminar = _archivo.buscarProductoPorId(idProductoAEliminar);
        productoAEliminar.setActivo(false);
        int eliminoProducto = _archivo.agregarProductoModificado(productoAEliminar, posicionProductoAEliminar);
        if(eliminoProducto == 1)
        {
            cout << "Producto eliminado correctamente" << endl;
        }
        else
        {
            cout << "No se pudo eliminar el producto" << endl;
        }
    }
}

void ManagerProductos::activarProducto()
{
    int idProductoAActivar;
    cout << "Ingrese id del producto a activar: " << endl;
    cin >> idProductoAActivar;

    int posicionProductoAActivar = _archivo.buscarPosicionPorId(idProductoAActivar);

    if(posicionProductoAActivar != -1)
    {
        cout << "Producto Encontrado" << endl;
        Producto productoAActivar = _archivo.buscarProductoPorId(idProductoAActivar);
        productoAActivar.setActivo(true);
        int activoProducto = _archivo.agregarProductoModificado(productoAActivar, posicionProductoAActivar);
        if(activoProducto == 1)
        {
            cout << "Producto activado correctamente" << endl;
        }
        else
        {
            cout << "No se pudo activar el producto" << endl;
        }
    }
}


void ManagerProductos::verStockProducto()
{
    int idProducto;
    cout << "Ingrese id del producto: " << endl;
    cin >> idProducto;

    Producto producto = _archivo.buscarProductoPorId(idProducto);
    if(producto.getIdProducto() != 0){
        cout << "Producto encontrado correctamente" << endl;
        cout << "Stock del producto " << producto.getDescripcion() <<": " << producto.getCantidadDisponible() << endl;
    }else{
        cout << "Error al encontrar el producto" << endl;
    }
}

bool ManagerProductos::modificarStock()
{
		int idProducto;
		int nuevoStock;
		
		cout << "Ingrese el id del producto a modificar: " << endl; 
		cin >> idProducto;
		
		cout << "Ingrese el nuevo stock: " << endl; 
		cin >> nuevoStock;  
		
    bool stockModificado = _archivo.modificarStock(idProducto, nuevoStock);
    if(stockModificado == true){
        cout << "Stock modificado correctamente" << endl;
        return true;
    }else{ cout << "Error al modificar el stock" << endl;
        return false;
        }
}

bool ManagerProductos::modificarStock(int idProducto, int nuevoStock)
{		
    bool stockModificado = _archivo.modificarStock(idProducto, nuevoStock);
    if(stockModificado == true){
        cout << "Stock modificado correctamente" << endl;
        return true;
    }else{ cout << "Error al modificar el stock" << endl;
        return false;
        }
}
