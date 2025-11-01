#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "FuncionesGlobales.h"

using namespace std;

ArchivoClientes::ArchivoClientes(const char* n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Cliente);
}

int ArchivoClientes::agregarCliente(Cliente registro){
    FILE *p;
    p=fopen(_nombre, "ab");
    if(p==nullptr){
        return -1;
    }

    int escribio = fwrite(&registro, _tamanioRegistro, 1, p);
    fclose(p);
    return escribio;
}

Cliente ArchivoClientes::buscarClientePorId(int idCliente){
    Cliente cliente;
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return Cliente();
    }
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&cliente, _tamanioRegistro,1,p);
        if(cliente.getIdCliente() == idCliente){
            fclose(p);
            return cliente;
        }
    }
    fclose(p);
    return Cliente();
}

int ArchivoClientes::obtenerPosicionCliente(int idCliente){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_SET);
    int cantidadRegistros = contarRegistros("clientes.dat", _tamanioRegistro);
    Cliente registro;
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registro, _tamanioRegistro, 1, p);
        if(registro.getIdCliente() == idCliente){
            cout << "Registro encontrado correctamente";
            fclose(p);
            return i;
        }
    }
    cout << "Registro no encontrado" << endl;
    fclose(p);
    return -1;
}

bool ArchivoClientes::modificarDatosCliente(Cliente registro, int posicion){
    FILE *p = nullptr;
    p = fopen(_nombre, "rb+");

    if(p == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    fseek(p, posicion*_tamanioRegistro, SEEK_SET);
    bool escribio = fwrite(&registro, _tamanioRegistro, 1, p);
    if(escribio){
        cout << "El registro se sobreescribio correctamente" << endl;
    }
    fclose(p);
    return escribio;
}

int ArchivoClientes::eliminarCliente(int idCliente){ //No esta terminado el metodo eliminarCliente()
    Cliente cliente;
    FILE *p = nullptr;
    p = fopen(_nombre, "rb+");

    if(p == nullptr){
        cout << "No se logro leer el archivo" << endl;
        return -1;
    }

    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&cliente, _tamanioRegistro, 1, p);
        if(cliente.getIdCliente() == idCliente){
					cliente.eliminarCliente(); //cambia el _activo a false, hay que implementar la "eliminación" en archivo.
        }

    }
}









































