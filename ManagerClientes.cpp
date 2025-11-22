#include <iostream>
#include "ManagerClientes.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"

using namespace std;

ManagerClientes::ManagerClientes()
    : _archivoCliente("clientes.dat")
{
}

Cliente ManagerClientes::crearNuevoCliente()
{
    string nombre, apellido, email, direccion;
    int cuil, tipoCliente, numeroTelefono;
    Cliente nuevoCliente;
    int idNuevoCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
    nuevoCliente.setIdCliente(idNuevoCliente);
    cout << "Ingresar nombre cliente nuevo: " << endl;
    cin >> nombre;
    nuevoCliente.setNombre(nombre);
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin >> apellido;
    nuevoCliente.setApellido(apellido);
    cout << "Ingresar cuit cliente nuevo: " << endl;
    cin >> cuil;
    nuevoCliente.setCuilCliente(cuil);
    cout << "Ingresar tipo cliente nuevo: " << endl;
    cin >> tipoCliente;
    nuevoCliente.setTipoCliente(tipoCliente);
    cout << "Ingresar numero de telefono: " << endl;
    cin >> numeroTelefono;
    nuevoCliente.setNumeroTelefono(numeroTelefono);
    cout << "Ingresar email cliente nuevo: " << endl;
    cin >> email;
    nuevoCliente.setEmail(email);
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin >> direccion;
    nuevoCliente.setDireccion(direccion);
    nuevoCliente.setActivo(true);
    return nuevoCliente;
}

void ManagerClientes::crearCliente()
{
    Cliente nuevoCliente = crearNuevoCliente();
    int clienteAgregado = _archivoCliente.agregarCliente(nuevoCliente);
    if(clienteAgregado == 1){
        cout << "Cliente agregado correctamente" << endl;
    }else{
        cout << "Error al agregar cliente" << endl;
    }
}

Cliente ManagerClientes::pedirNuevosDatos()
{
    string nombre, apellido, email, direccion;
    int cuil, tipoCliente, numeroTelefono;
    Cliente clienteModificado;
    cout << "Ingresar nombre cliente nuevo: " << endl;
    cin >> nombre;
    clienteModificado.setNombre(nombre);
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin >> apellido;
    clienteModificado.setApellido(apellido);
    cout << "Ingresar cuit cliente nuevo: " << endl;
    cin >> cuil;
    clienteModificado.setCuilCliente(cuil);
    cout << "Ingresar tipo cliente nuevo: " << endl;
    cin >> tipoCliente;
    clienteModificado.setTipoCliente(tipoCliente);
    cout << "Ingresar numero de telefono: " << endl;
    cin >> numeroTelefono;
    clienteModificado.setNumeroTelefono(numeroTelefono);
    cout << "Ingresar email cliente nuevo: " << endl;
    cin >> email;
    clienteModificado.setEmail(email);
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin >> direccion;
    clienteModificado.setDireccion(direccion);
    clienteModificado.setActivo(true);
    return clienteModificado;
}

void ManagerClientes::modificarCliente()
{
    int idClienteAModificar;
    cout << "Ingrese el id del cliente que quiere modificar: " << endl;
    cin >> idClienteAModificar;
    Cliente registro = _archivoCliente.archivoBuscarClientePorId(idClienteAModificar);
    int idOriginal = registro.getIdCliente();
    int posicion = _archivoCliente.obtenerPosicionCliente(idClienteAModificar);
    int datosModificados = 0;
    if(posicion == -1)
    {
        cout << "Error al encontrar el cliente" << endl;
    }
    else
    {
        if(registro.getIdCliente() != 0)
        {
            registro = pedirNuevosDatos();
            registro.setIdCliente(idOriginal);//Para mantener el id, porque al cambiar el objeto completo este se perdia.
            datosModificados = _archivoCliente.modificarDatosCliente(registro, posicion);
        }
    }
    if(datosModificados > 0)
    {
        cout << "Se modificaron los datos correctamente" << endl;
    }
    else
    {
        cout << "Hubo un error al actualizar los datos" << endl;
    }
}


void ManagerClientes::buscarClientePorId()
{
    int idCliente;
    cout << "Ingresar id de cliente: " << endl;
    cin >> idCliente;
    Cliente clienteObtenido = _archivoCliente.archivoBuscarClientePorId(idCliente);
    if(clienteObtenido.getIdCliente() != 0){
        cout << "Cliente encontrado" << endl;
        clienteObtenido.mostrarCliente();
    }else{
        cout << "No se encontro el cliente" << endl;
    }
}

void ManagerClientes::eliminarCliente()
{
    int idClienteAEliminar;
    cout << "Ingrese id cliente a eliminar: " << endl;
    cin >> idClienteAEliminar;
    int posicionClienteAEliminar = _archivoCliente.obtenerPosicionCliente(idClienteAEliminar);
    if(posicionClienteAEliminar == -1)
    {
        cout << "No se encontro el cliente" << endl;
    }
    Cliente clienteAEliminar = _archivoCliente.archivoBuscarClientePorId(idCliente);
    clienteAEliminar.eliminarCliente();
    int clienteEliminado = _archivoCliente.modificarDatosCliente(clienteAEliminar, posicionClienteAEliminar);
    if(clienteEliminado != 0){
        cout << "Cliente eliminado exitosamente" << endl;
    }else{
        cout << "Error al eliminar el cliente" << endl;
    }
}

void ManagerClientes::activarCliente()
{
    int idClienteAActivar;
    cout << "Ingrese el id del cliente a activar nuevamente: " << endl;
    cin >> idClienteAActivar;
    int posicionCliente = _archivoCliente.obtenerPosicionCliente(idClienteAActivar);
    if(posicionCliente == -1)
    {
        cout << "No se encontro el cliente: " << endl;
    }
    Cliente clienteAActivar = _archivoCliente.buscarClientePorId(idCliente);
    clienteAActivar.activarCliente();
    int clienteActivado = _archivoCliente.modificarDatosCliente(clienteAActivar, posicionCliente);
    if(clienteActivado != 0){
        cout << "Cliente activado correctamente" << endl;
    }else {
        cout << "Error al activar el cliente" << endl;
    }
}

void ManagerClientes::listarClientes(
    int cantidadClientes = contarRegistros("clientes.dat", sizeof(Cliente));
    Cliente* arrayclientes = _archivoCliente.obtenerClientes(cantidadClientes);
    if(arrayClientes == nullptr){
        cout << "No se abrio correctamente el archivo" << endl;
        return;
    }
    for(int i = 0; i < cantidadClientes; i++){
        if(arrayclientes[i].getActivo() == true){
        arrayclientes[i].mostrarCliente();
        }
    }
    delete[] arrayclientes;
)



