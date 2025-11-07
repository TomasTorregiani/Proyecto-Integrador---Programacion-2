#include <iostream>
#include "ManagerClientes.h"

using namespace std;

bool ManagerClientes::agregarCliente(Cliente cliente){
    ArchivoClientes archivoCliente("clientes.dat");
    int agregado = archivoCliente.agregarCliente(cliente);
    if(agregado == 1){
        cout << "Cliente agregado correctamente" << endl;
    }else{
        cout << "Error al agregar cliente" << endl;
    }
}
