#include <iostream>
#include "ManagerVendedores.h"
#include "FuncionesGlobales.h"

using namespace std;

ManagerVendedores::ManagerVendedores():_archivo("vendedores.dat")
{

}

void ManagerVendedores::nuevoVendedor()
{

    Vendedor nuevoVendedor;

    string nombre, apellido, email, direccion;
    int idVendedor, cuilVendedor, telefonoVendedor;
    bool estado;

    cout << "Ingresar nombre vendedor nuevo: " << endl;
    cin.ignore();
    getline(cin, nombre);


    while(nombre == "")
    {
        cout << "Error. Ingrese un nombre: " << endl;
        getline(cin,nombre);
    }

    nuevoVendedor.setNombre(nombre);

    cout << "Ingresar apellido vendedor nuevo: " << endl;
    getline(cin, apellido);

    while(apellido == "")
    {
        cout << "Error. Ingrese un apellido: " << endl;
        getline(cin, apellido);
    }

    nuevoVendedor.setApellido(apellido);

    cout << "Ingresar cuil vendedor nuevo: " << endl;
    cin >> cuilVendedor;

    while(!(cin >> cuilVendedor || cuilVendedor < 0 || cin.peek() == '.'))
    {
        cout << "Error. Ingrese un cuil valido: ";
        cin.clear();  //limpia el error de cin
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    nuevoVendedor.setCuilVendedor(cuilVendedor);

    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoVendedor;

    while(!(cin >> telefonoVendedor || telefonoVendedor < 0 || cin.peek() == '.'))
    {
        cout << "Error. Ingrese un telefono valido: ";
        cin.clear();  //limpia el error de cin
        cin.ignore(10000, '\n');
    }
    cin.ignore(10000, '\n');

    nuevoVendedor.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    cin.ignore();
    getline(cin, email);

    while(email == "")
    {
        cout << "Error. Ingrese un email: " << endl;
        getline(cin, email);
    }

    nuevoVendedor.setEmail(email);

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    getline(cin, direccion);

    while(direccion == "")
    {
        cout << "Error. Ingrese un email: " << endl;
        getline(cin, direccion);
    }

    nuevoVendedor.setDireccion(direccion);

    nuevoVendedor.setEstado(true);

    //**** fin de ingreso de datos ****//

    idVendedor = contarRegistros("vendedores.dat", sizeof(Vendedor)) + 1;
    nuevoVendedor.setIdVendedor(idVendedor);

    int agrego = _archivo.agregarVendedor(nuevoVendedor); //porque _archivo ya se creó en el constructor de Vendedores.
    if(agrego != 0)
    {
        cout << "El vendedor se agrego correctamente" << endl;
    }
    else
    {
        cout << "Error al agregar el vendedor" << endl;
    }
}

void ManagerVendedores::listarVendedores()
{

//TODO

}

void ManagerVendedores::modificarVendedor()
{

//TODO

}

/*void ManagerVendedores::eliminarVendedor(int id){

	int pos = _archivo.//FIXME

	_activo = false;
}*/
