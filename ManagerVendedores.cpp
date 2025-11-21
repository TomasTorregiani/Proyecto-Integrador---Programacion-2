#include <iostream>
#include "ManagerVendedores.h"
#include "ArchivoVendedores.h"
#include "FuncionesGlobales.h"

using namespace std;

ManagerVendedores::ManagerVendedores(){

}

void ManagerVendedores::nuevoVendedor()
{

    Vendedor nuevoVendedor;

    char nombre[50], apellido[50], email[50], direccion[100];
    int idVendedor, cuilVendedor, telefonoVendedor;
    bool estado;

    cout << "Ingresar nombre vendedor nuevo: " << endl;
    cin.ignore();
    cin.getline(nombre, 50);
    nuevoVendedor.setNombre(nombre);

    cout << "Ingresar apellido vendedor nuevo: " << endl;
    cin.getline(apellido, 50);
    nuevoVendedor.setApellido(apellido);

    cout << "Ingresar cuil vendedor nuevo: " << endl;
    cin >> cuilVendedor;
    nuevoVendedor.setCuilVendedor(cuilVendedor);

    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoVendedor;
    nuevoVendedor.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    cin.ignore();
    cin.getline(email, 50);

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    cin.getline(direccion, 50);

    nuevoVendedor.setEstado(true);
    
    idVendedor = contarRegistros("vendedores.dat", sizeof(Vendedor)) + 1;
    nuevoVendedor.setIdVendedor(idVendedor);

    ArchivoVendedores archivoVendedor("vendedores.dat");
    int agrego = archivoVendedor.agregarVendedor(nuevoVendedor);
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
