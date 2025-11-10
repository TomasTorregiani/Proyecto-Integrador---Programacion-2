#include <iostream>
#include "ManagerVendedores.h"

using namespace std;

ManagerVendedores::ManagerVendedores(){

}

void ManagerVendedores::nuevoVendedor(){
		
		Vendedor vendedor; 
		
		char nombre[50], apellido[50], email[50], direccion[100];
    int idVendedor, cuilVendedor, telefonoVendedor;
    bool estado;
		
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
     
    estado = true;
    vendedor.setEstado(estado);
		
    /*ArchivoVendedores archivoVendedor("vendedores.dat");
    int agregado = archivoVendedor.nuevoVendedor();
    if(agregado == 1){
        cout << "Vendedor agregado correctamente" << endl;
    }else{
        cout << "Error al agregar el vendedor" << endl;
    }*/
    
    ArchivoVendedores registroVendedor; 
    if(registroVendedor.guardarVendedor(vendedor))  //si está todo okey, graba.
    {
        cout << "El vendedor se guardo correctamente" << endl;
    }
    else
    {
        cout << " === Error: El vendedor no se guardo correctamente === " << endl;
    }
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
