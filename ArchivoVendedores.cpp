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
    cout << "DEBUG: Intentando agregar vendedor con ID: " << vendedor.getIdVendedor() << endl;

    FILE* p = nullptr;
    p = fopen(_nombre, "ab"); //_nombre es el nombre como atributo de ArchivoVendedores, es decir "vendedores.dat"
    if(p == nullptr){
        cout << "ERROR: No se pudo abrir 'vendedores.dat'. " << endl;
        return 0;
    }

    cout << "DEBUG: Tamaño registro: " << _tamanioRegistro << endl;
    int escribio = fwrite(&vendedor, _tamanioRegistro, 1, p);
    cout << "DEBUG: fwrite devolvió: " << escribio << endl;

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
        cout << "ERROR: No se pudo abrir 'vendedores.dat'. " << endl;
        cout << "Asegurese de que el archivo existe y tiene productos cargados." << endl;
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
            return i;
        }
    }
    fclose(p);
    return -1;
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

/*void ArchivoVendedores::listarVendedores(){ //Este archivo no deberia listar. Deberia devolver y el listado deberia verse en el manager.
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fseek(p, 0, SEEK_SET);
    int cantidadDeRegistros = contarRegistros(_nombre, _tamanioRegistro);
    Vendedor registroVendedor;

    if(cantidadDeRegistros > 0){
        for(int i = 0; i < cantidadDeRegistros; i++){
            fread(&registroVendedor, _tamanioRegistro, 1, p);
            cout << "Id Vendedor: " << registroVendedor.getIdVendedor() << endl;
            cout << "Nombre Vendedor: " << registroVendedor.getNombre() << " " << registroVendedor.getApellido() << endl;
        }
    }else{
        cout << "No se encontraron vendedores" << endl;
    }
    fclose(p);
}*/

Vendedor* ArchivoVendedores::obtenerVendedores(int cantidadVendedores){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        cout << "No se abrio correctamente el archivo" << endl;
        return nullptr;
    }

    fseek(p, 0, SEEK_SET);

    Vendedor* arrayVendedores;
    arrayVendedores = new Vendedor[cantidadVendedores]();
    Vendedor registroVendedor;
    for(int i = 0; i < cantidadVendedores; i++){
        fread(&registroVendedor, _tamanioRegistro, 1, p);
        arrayVendedores[i] = registroVendedor;
    }
    fclose(p);
    return arrayVendedores;
}
