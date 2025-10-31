#include <iostream>
#include <cstring>
#include "ArchivoVendedores.h"
#include "Vendedor.h"

using namespace std;

ArchivoVendedores::ArchivoVendedores(const char *n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Vendedor);
}

int ArchivoVendedores::agregarVendedor(Vendedor vendedor){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return 0;
    }

    int escribio = fwrite(&vendedor, _tamanioRegistro, 1, p);
    if(escribio == 1){
        cout << "El archivo se escribio correctamente" << endl;
        fclose(p);
        return 1;
    }
    fclose(p);
    return 0;
}

Vendedor ArchivoVendedores::buscarVendedorPorId(int idVendedor){
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return Vendedor();
    }

    Vendedor registroVendedor;

    int cantidad = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registroVendedor, _tamanioRegistro, 1, p);
        if(registroVendedor.getIdVendedor() == idVendedor){
            fclose(p);
            return registroVendedor;
        }
    }
    fclose(p);
    cout << "No se encontro el vendedor" << endl;
    return Vendedor();
}
