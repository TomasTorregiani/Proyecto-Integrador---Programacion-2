#include <iostream>
#include <cstring>
#include "ArchivoVendedores.h"
#include "Vendedor.h"
#include "FuncionesGlobales.h"

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

    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registroVendedor, _tamanioRegistro, 1, p);
        if(registroVendedor.getIdVendedor() == idVendedor){
            fclose(p);
            return registroVendedor;
        }
    }
    fclose(p);
    return Vendedor();
}
int ArchivoVendedores::buscarPosicionDelVendedor(int idVendedor){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return -1;
    }
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    Vendedor vendedor;
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vendedor, _tamanioRegistro, 1, p);
        if(vendedor.getIdVendedor() == idVendedor){
            fclose(p);
            cout << "Registro encontrado exitosamente";
            return i;
        }
    }
    fclose(p);
    cout << "No se encontro el registro" << endl;
}
int ArchivoVendedores::modificarDatosVendedor(Vendedor registroVendedor, int posicion){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb+");
    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return 0;
    }
    fseek(p, (_tamanioRegistro*posicion), SEEK_SET);

    int escribio = fwrite(&registroVendedor, _tamanioRegistro, 1, p);
    if(escribio != 0){
        fclose(p);
        return escribio;
    }else{
        fclose(p);
        return 0;
    }
}
