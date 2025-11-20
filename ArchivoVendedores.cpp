#include <iostream>
#include <cstring>
#include <string>
#include "ArchivoVendedores.h"
#include "Vendedor.h"
#include "FuncionesGlobales.h"

using namespace std;

ArchivoVendedores::ArchivoVendedores(const char *nombreArchivo){
	strcpy(_nombre, nombreArchivo); //ojo, nombre archivo ya es un char.
	_tamanioRegistro = sizeof(Vendedor);
}

bool ArchivoVendedores::agregarVendedor(Vendedor registro){

		// TODO // 

}

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

bool ArchivoVendedores::guardarVendedor(Vendedor vendedor){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return false;
    }

    bool escribio = fwrite(&vendedor, _tamanioRegistro, 1, p);
    if(escribio == true){
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

Vendedor ArchivoVendedores::buscarVendedorPorId(int idVendedor){		
    FILE *pFile = nullptr;
    pFile = fopen(_nombre, "rb");

    if(pFile == nullptr){
      return Vendedor();
    }

    Vendedor registroVendedor;

    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registroVendedor, _tamanioRegistro, 1, pFile);
        if(registroVendedor.getIdVendedor() == idVendedor){
						return Vendedor(); 
            fclose(pFile);
        }
    }
    fclose(pFile);
}
int ArchivoVendedores::obtenerPosicionVendedor(int idVendedor){
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

void ArchivoVendedores::listarVendedores(){
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
}


