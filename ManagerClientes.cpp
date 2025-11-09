#include <iostream>
#include "ManagerClientes.h"

using namespace std;

ManagerClientes::ManagerClientes()
{

}

void ManagerClientes::nuevoCliente()  //crea clase, pide datos, valida y graba.
{
    Cliente cliente;
    
    _idCliente = contarRegistros("clientes.dat", sizeof(Cliente)) + 1;
    
    cout << "Ingresar nombre cliente nuevo: " << endl;
    cin >> _nombre; //con cliente.setNombre();
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin >> _apellido; //con cliente.setApellido();
    cout << "Ingresar cuit cliente nuevo: " << endl;
    cin >> _cuil;  //con cliente.setCuil();
    cout << "Ingresar numero de telefono: " << endl;
    cin >> _numeroTelefono;  //con cliente.setTelefono();
    cout << "Ingresar email cliente nuevo: " << endl;
    cin >> _email;  //con cliente.setEmail();
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin >> _direccion;  //con cliente.setDireccion();
    
    _activo = true;

    if(ArchivoClientes.guardarCliente(cliente))  //se está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }
}

void ManagerClientes::eliminarCliente(int idCliente)
{
	_activo = false;
	/*if(ArchivoClientes.eliminarCliente(int idCliente))  //se está todo okey, graba.
    {
        cout << "El cliente se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El cliente no se guardo correctamente === " << endl;
    }*/
}


/*void ManagerClientes::modificarCliente()
{
	cout << "Ingresar nombre cliente nuevo: " << endl;
    cin >> _nombre;
    cout << "Ingresar apellido cliente nuevo: " << endl;
    cin >> _apellido;
    cout << "Ingresar cuit cliente nuevo: " << endl;
    cin >> _cuil;
    cout << "Ingresar tipo cliente nuevo: " << endl;
    cin >> _tipoCliente;
    cout << "Ingresar numero de telefono: " << endl;
    cin >> _numeroTelefono;
    cout << "Ingresar email cliente nuevo: " << endl;
    cin >> _email;
    cout << "Ingresar direccion cliente nuevo: " << endl;
    cin >> _direccion;


}*/

void ManagerClientes::mostrarCliente(int idCliente){
	
    cout << "=== DATOS DEL CLIENTE ===" << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero de telefono: " << _numeroTelefono << endl;
    cout << "Email: " << _email << endl;
}
