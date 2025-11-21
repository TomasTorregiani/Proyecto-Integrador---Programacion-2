#include <iostream>
#include "ManagerVendedores.h"
#include "FuncionesGlobales.h"

using namespace std;

ManagerVendedores::ManagerVendedores():_archivo("vendedores.dat"){
		
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
    
    //validar:
    
    nuevoVendedor.setNombre(nombre);

    cout << "Ingresar apellido vendedor nuevo: " << endl;
    getline(cin, apellido);
    
    //validar:
    
    nuevoVendedor.setApellido(apellido);

    cout << "Ingresar cuil vendedor nuevo: " << endl;
    cin >> cuilVendedor;
    
    //validar:
    
    nuevoVendedor.setCuilVendedor(cuilVendedor);

    cout << "Ingresar numero de telefono: " << endl;
    cin >> telefonoVendedor;
    
    //validar
    
    nuevoVendedor.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    cin.ignore();
    getline(cin, email);
    
    //validar:

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    getline(cin, direccion);
    
    //validacion.
    
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
