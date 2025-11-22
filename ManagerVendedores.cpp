#include <iostream>
#include "ManagerVendedores.h"

using namespace std;

ManagerVendedores::ManagerVendedores(){

}

void ManagerVendedores::crearNuevoVendedor(){

    Vendedor vendedor;

    string nombre, apellido, email, direccion;
    int idVendedor, cuilVendedor, telefonoVendedor;

    cout << "Ingresar nombre vendedor nuevo: " << endl;
    cin.ignore();
    cin.getline(nombre, 50);
    vendedor.setNombre(nombre);

    cout << "Ingresar apellido vendedor nuevo: " << endl;
    cin.getline(apellido, 50);
		vendedor.setApellido(apellido);

    cout << "Ingresar cuil vendedor nuevo: " << endl;
    cin >> cuilVendedor;
    vendedor.setCuilVendedor(cuilVendedor);

    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoVendedor;
    vendedor.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    cin.ignore();
    cin.getline(email, 50);

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    cin.getline(direccion, 50);

    vendedor.setEstado(true);
}

Vendedor ManagerVendedores::crearVendedor(){
    Vendedor nuevoVendedor = crearNuevoVendedor();
    int guardoVendedor = _archivoVendedores.agregarVendedor(nuevoVendedor);
    //if...
    return nuevoVendedor;
}


void ManagerVendedores::listarVendedores(){

//TODO

}

void ManagerVendedores::modificarVendedor(){

//TODO

}

/*void ManagerVendedores::eliminarVendedor(int id){

	int pos = _archivo.//FIXME

	_activo = false;
}*/
