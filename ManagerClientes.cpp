#include <iostream>
#include <string>
#include <cstring>
#include "ManagerClientes.h"
#include "ArchivoClientes.h"
#include "FuncionesGlobales.h"
#include "Cliente.h"

using namespace std;

ManagerClientes::ManagerClientes()
{
    _archivo = new ArchivoClientes("clientes.dat");
}

void ManagerClientes::nuevoCliente()  //crea clase, pide datos, valida y graba.
{
    Cliente cliente;
    char nombre[50], apellido[50], email[50], direccion[100];
    int idCliente, cuilCliente, telefonoCliente;
    bool estado;

    cout << "Ingresar nombre cliente nuevo: " << endl;
    cin.ignore();
    cin.getline(nombre, 50);

    //validaciones

    cliente.setNombre(nombre);

    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin.getline(apellido, 50);

    //validar

    cliente.setApellido(apellido);

    cout << "Ingresar cuil cliente nuevo: " << endl;
    cin >> cuilCliente;
    cliente.setCuil(cuilCliente);

    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoCliente;
    cliente.setNumeroTelefono(telefonoCliente);

    cout << "Ingresar email cliente nuevo: " << endl;
    cin.ignore();
    cin.getline(email, 50);

    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin.getline(direccion, 50);

    estado = true;
    cliente.setEstado(estado);

    ArchivoClientes registroArchivo;

    bool guardoCliente = registroArchivo.guardarCliente(cliente);

    if(guardoCliente)/*registroArchivo.guardarCliente(cliente))*/  //si está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }
}

void ManagerClientes::eliminarCliente()
{
    int idCliente;
    cout << "Ingrese id cliente a eliminar" << endl;
    cin >> idCliente;

    ArchivoClientes archivo("clientes.dat");
    int posicionClienteAEliminar = archivo.obtenerPosicionCliente(idCliente);

    if(posicionClienteAEliminar == -1)
    {
        cout << "Cliente no encontrado" << endl;
    }
    else
    {
				Cliente registro;
        registro = archivo.buscarClientePorId(idCliente);
				archivo.eliminarCliente(registro);
				
				

        /*if(modificarCliente)
        {
            cout << "Cliente eliminado con exito" << endl;
        }
        else
        {
            cout << "Error al eliminar el cliente" << endl;
        }*/
    }
}


void ManagerClientes::modificarCliente()
{
    int idClienteAModificar;
    cout << "Ingrese el id del cliente que quiere modificar: " << endl;
    cin >> idClienteAModificar;

    char nombre[50], apellido[50], email[50], direccion[100];
    int idCliente, cuilCliente, telefonoCliente;
    bool estado;

    ArchivoClientes clienteAModificar("clientes.dat");
    Cliente registro = clienteAModificar.buscarClientePorId(idClienteAModificar); //registro cliente con ese id
    int posicion = clienteAModificar.obtenerPosicionCliente(idClienteAModificar); //posicion cliente dentro de archivo
    if(posicion == -1)
    {
        cout << "Error al obtener la posicion del archivo" << endl;
    }
    else
    {
        if(registro.getIdCliente() != 0)
        {
            cout << "Ingresar nombre cliente: " << endl;
            cin.ignore();
            cin.getline(nombre, 50);

            //validaciones

            registro.setNombre(nombre);

            cout << "Ingresar apellido cliente: " << endl;
            cin.getline(apellido, 50);

            //validar

            registro.setApellido(apellido);

            cout << "Ingresar cuil cliente: " << endl;
            cin >> cuilCliente;
            registro.setCuil(cuilCliente);

            cout << "Ingresar numero de telefono: " << endl;
            cin >> telefonoCliente;
            registro.setNumeroTelefono(telefonoCliente);

            cout << "Ingresar email cliente nuevo: " << endl;
            cin.ignore();
            cin.getline(email, 50);

            cout << "Ingresar direccion cliente nuevo: " << endl;
            cin.getline(direccion, 50);

            estado = true;
            registro.setEstado(estado);

            bool datosModificados = clienteAModificar.modificarDatosCliente(registro, posicion);
            if(datosModificados)
            {
                cout << "Se modificaron los datos correctamente" << endl;
            }
            else
            {
                cout << "Hubo un error al actualizar los datos" << endl;
            }
        }
    }

    /*ingresar idCliente (lo busca y si lo encuentra muestra:)
    //menu modificar cliente:

    		1. nombre
    				std::string nuevo_nombre = "";
    				Ingrese nuevo nombre:
    				cin >> nuevo_nombre;
    				grabar nuevo nombre en la posición del nombre.
    		2. apellido
    	  3. cuil
    	  4. numero de telefono
    	  5. email
    	  6. direccion*/

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

/*void ManagerClientes::listarClientes(){
		ArchivoClientes.listarClientes();
		//TODO
}*/

ManagerClientes::~ManagerClientes()
{
    if (_archivo != nullptr) {
        delete _archivo;
        _archivo = nullptr;
    }
}
