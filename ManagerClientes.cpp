#include <iostream>
#include "ManagerClientes.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"

using namespace std;

ManagerClientes::ManagerClientes()
: _archivoCliente("clientes.dat"){
}

Cliente ManagerClientes::crearNuevoCliente(){

    string nombre, apellido, email, direccion;
    int cuil, numeroTelefono;
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
    /*ArchivoClientes registroArchivo;

    bool guardoCliente = registroArchivo.guardarCliente(cliente);

    if(guardoCliente)/*registroArchivo.guardarCliente(cliente))  //si está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }*/
}

int ManagerClientes::crearCliente(){
    Cliente nuevoCliente = crearNuevoCliente();
    int clienteAgregado = _archivoCliente.agregarCliente(nuevoCliente);
    return clienteAgregado;
}
int ManagerClientes::modificarCliente(int idCliente){
    Cliente registro = _archivoCliente.buscarClientePorId(idCliente);
    int posicion = _archivoCliente.obtenerPosicionCliente(idCliente);
    int datosModificados = 0;
    if(posicion == -1){
        cout << "Error al obtener la posicion del archivo" << endl;
    }else {
        if(registro.getIdCliente() != 0){
            registro.modificarCliente();
            datosModificados = _archivoCliente.modificarDatosCliente(registro, posicion);
        }
    }
    return datosModificados;
}
void ManagerClientes::mostrarCliente()
{
    int idCliente;
    cout << "Ingresar id de cliente: " << endl;
    cin >> idCliente;

    ArchivoClientes archivo("clientes.dat");
    Cliente registro = archivo.buscarClientePorId(idCliente);
    if(registro.getIdCliente() == 0)
    {
        cout << "No se encontro ningun cliente con ese id" << endl;
    }
    else
    {
        cout << "================================" << endl;
        cout << "ID Cliente: " << registro.getIdCliente() << endl;
        cout << "CUIL: " << registro.getCuil() << endl;
        cout << "Nombre: " << registro.getNombre() << endl;
        cout << "Apellido: " << registro.getApellido() << endl;
        cout << "Telefono: " << registro.getNumeroTelefono() << endl;
        cout << "Email: " << registro.getEmail() << endl;
        cout << "Direccion: " << registro.getDireccion() << endl;

        if(registro.getEstado()==true)
        {
            cout << "Estado: Activo" << endl;
        }
        else
        {
            cout << "Estado: Inactivo " << endl;
        }
        cout << "================================" << endl;
    }
}
