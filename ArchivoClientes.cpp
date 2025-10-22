#include <iostream>
#include <cstring>
#include "ArchivoClientes.h"
#include "Cliente.h"

using namespace std;

ArchivoClientes()::ArchivoClientes(const char* n){
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

int ArchivoClientes::buscarClientePorId(int idCliente){
    Cliente cliente;
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return -1;
    }
    int cantidadRegistros = contarRegistros();
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&cliente, _tamanioRegistro,1,p);
        if(cliente.getIdCliente() == idCliente){
            return cliente.getApellido(); //Aca tengo el problema de que lo ideal seria
            fclose(p);                    // devolver  nombre y apellido. Pero c++ no me
        }                                 // permite devolver 2 valores
    }
    fclose(p);
    return 0;
}

int ArchivoLibros::eliminarCliente(int idCliente){ //No esta terminado el metodo eliminarCliente()
    Cliente cliente;
    FILE *p = nullptr;
    p = fopen(_nombre, "wb");

    if(p = nullptr){
        cout << "No se logro leer el archivo" << endl;
        return -1;
    }

    int cantidadRegistros = contarRegistros();
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&cliente, _tamanioRegistro, 1, p);
        if(&cliente.getIdCliente() == idCliente){

        }
    }

}

int ArchivoClientes::contarRegistros(){
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "Problemas al leer el archivo" << endl;
        return -1;
    }

    fseek(p, 0, SEEK_END);
    int cantidadRegistros = ftell(p)/_tamanioRegistro;
    fclose(p);

    return cantidadRegistros;
}



















































