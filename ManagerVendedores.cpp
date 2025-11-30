#include <iostream>
#include "ManagerVendedores.h"
#include "FuncionesGlobales.h"
#include "ArchivoVendedores.h"

using namespace std;

ManagerVendedores::ManagerVendedores():_archivoVendedores("vendedores.dat"){
	
}

void ManagerVendedores::crearVendedor(){

    Vendedor nuevoVendedor;

    string nombre, apellido, email, direccion;
    int idVendedor, cuilVendedor, telefonoVendedor;
    bool estado;
    
    idVendedor = contarRegistros("vendedores.dat", sizeof(Vendedor)) + 1;
    nuevoVendedor.setIdVendedor(idVendedor);

    cin.ignore(10000, '\n');
    
    cout << "Ingresar nombre vendedor nuevo: " << endl;
    getline(cin, nombre);


    while(nombre == "") //o puedo usar nombre.empty() 
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

    cout << "Ingresar numero de telefono (sin guiones): " << endl;
    cin >> telefonoVendedor;

    while(cin.fail() || telefonoVendedor < 0 || cin.peek() == '.' || cin.peek() == '-') //si "falla" el cin, si el nro es menor a "0", si se ingresa un "." o un "-"
    {
        cout << "Error. Ingrese un telefono valido: ";
        cin.clear();  //limpia el error de cin
        cin.ignore(10000, '\n');
        cin >> telefonoVendedor;
    }
    cin.ignore(10000, '\n');

    nuevoVendedor.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    getline(cin, email);

    while(email.empty())
    {
        cout << "Error. Ingrese un email: " << endl;
        getline(cin, email);
    }

    nuevoVendedor.setEmail(email);

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    getline(cin, direccion);

    while(direccion == "")
    {
        cout << "Error. Ingrese una direccion: " << endl;
        getline(cin, direccion);
    }

    nuevoVendedor.setDireccion(direccion);

    nuevoVendedor.setActivo(true);
    
    int agregoVendedor = _archivoVendedores.agregarVendedor(nuevoVendedor);
    if(agregoVendedor != 0){
        cout << "El vendedor se agrego correctamente" << endl;
    }else{
        cout << "Error al agregar el vendedor" << endl;
    }
}


Vendedor ManagerVendedores::pedirNuevosDatos(){
    Vendedor vendedorModificado;

    string nombre, apellido, email, direccion;
    int idVendedor, cuilVendedor, telefonoVendedor;
    bool estado;

    cin.ignore(10000, '\n');
    
    cout << "Ingresar nombre vendedor nuevo: " << endl;
    getline(cin, nombre);

    while(nombre == "")
    {
        cout << "Error. Ingrese un nombre: " << endl;
        getline(cin,nombre);
    }

    vendedorModificado.setNombre(nombre);

    cout << "Ingresar apellido vendedor nuevo: " << endl;
    getline(cin, apellido);

    while(apellido == "")
    {
        cout << "Error. Ingrese un apellido: " << endl;
        getline(cin, apellido);
    }

    vendedorModificado.setApellido(apellido);

    cout << "Ingresar numero de telefono (sin guiones): " << endl;
    cin >> telefonoVendedor;

    while(cin.fail() || telefonoVendedor < 0 || cin.peek() == '.' || cin.peek() == '-')
    {
        cout << "Error. Ingrese un telefono valido: ";
        cin.clear();  //limpia el error de cin
        cin.ignore(10000, '\n');
        cin >> telefonoVendedor;
    }
    cin.ignore(10000, '\n');

    vendedorModificado.setNumeroTelefono(telefonoVendedor);

    cout << "Ingresar email vendedor nuevo: " << endl;
    cin.ignore();
    getline(cin, email);

    while(email == "")
    {
        cout << "Error. Ingrese un email: " << endl;
        getline(cin, email);
    }

    vendedorModificado.setEmail(email);

    cout << "Ingresar direccion vendedor nuevo: " << endl;
    getline(cin, direccion);

    while(direccion == "")
    {
        cout << "Error. Ingrese un email: " << endl;
        getline(cin, direccion);
    }

    vendedorModificado.setDireccion(direccion);

    vendedorModificado.setActivo(true);
    
    return vendedorModificado;
}
void ManagerVendedores::modificarVendedor(){
	
    int idVendedorAModificar;
    
    cout << "Ingrese id del vendedor a modificar: " << endl;
    cin >> idVendedorAModificar;

    Vendedor registro = _archivoVendedores.buscarVendedorPorId(idVendedorAModificar);
    
    cout << "Vendedor ("<< idVendedorAModificar << ") = " << registro.getNombre() << " " << registro.getApellido() << endl << endl;
    
    int idOriginal = registro.getIdVendedor();
    int posicion = _archivoVendedores.buscarPosicionDelVendedor(idVendedorAModificar);
    int datosModificados = 0;
    if(posicion == -1)
    {
        cout << "Error al encontrar el vendedor" << endl;
    }
    else
    {
        if(registro.getIdVendedor() != 0)
        {
            registro = pedirNuevosDatos(); //acá se piden todos los datos de nuevo (menos el id)
            registro.setIdVendedor(idOriginal);//Para mantener el id, porque al cambiar el objeto completo este se perdia.
            datosModificados = _archivoVendedores.modificarDatosVendedor(registro, posicion);
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

void ManagerVendedores::obtenerVendedorPorId(){
    int idVendedor;
    cout << "Ingrese id del vendedor: " << endl;
    cin >> idVendedor;

    Vendedor registroVendedor = _archivoVendedores.buscarVendedorPorId(idVendedor);
    if(registroVendedor.getIdVendedor() == 0){
        cout << "No se encontro el vendedor" << endl;
    }else {																																
        cout << "Vendedor encontrado:" << endl;
        cout << "Nombre: " << registroVendedor.getNombre() << endl;
        cout << "Apellido: " << registroVendedor.getApellido() << endl;
        cout << "Estado: " << (registroVendedor.getActivo() == 1 ? "Activo" : "Inactivo") << endl;
    }
}

void ManagerVendedores::eliminarVendedor(){
    int idVendedor;
    cout << "Ingrese el id del vendedor: " << endl; 
    cin >> idVendedor;

    int posicionVendedor = _archivoVendedores.buscarPosicionDelVendedor(idVendedor);
    if(posicionVendedor != -1){
        cout << "Registro encontrado exitosamente" << endl;
        Vendedor vendedorAEliminar = _archivoVendedores.buscarVendedorPorId(idVendedor);
        vendedorAEliminar.setActivo(false);

        int eliminoVendedor = _archivoVendedores.modificarDatosVendedor(vendedorAEliminar, posicionVendedor);
        if(eliminoVendedor != 0){
            cout << "Vendedor eliminado correctamente" << endl;
        }else{
            cout << "Error al eliminar el vendedor" << endl;
            }
        }else {
            cout << "No se encontro el registro" << endl;
        }
}

void ManagerVendedores::listarVendedores(){
	
    int cantidadVendedores = contarRegistros("vendedores.dat", sizeof(Vendedor));
    
    Vendedor* arrayVendedores = _archivoVendedores.obtenerVendedores(cantidadVendedores);
    if(arrayVendedores == nullptr){
        cout << "No se abrio correctamente el archivo" << endl;
        return;
    }
    for(int i = 0; i < cantidadVendedores; i++){
        if(arrayVendedores[i].getActivo() == true){
        arrayVendedores[i].mostrarVendedor();
        cout << endl; 
        }
    }
    delete[] arrayVendedores;
}
