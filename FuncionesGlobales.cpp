#include <iostream>

#include "FuncionesGlobales.h"
using namespace std;

int contarRegistros(const char *nombreArchivo, int tamanioRegistro){

    FILE *p = nullptr;
    p = fopen(nombreArchivo, "rb");

    if(p == nullptr){
        cout << "El archivo no se leyo correctamente" << endl;
        return -1;
    }

    fseek(p, 0, SEEK_END);
    int cantidadDeRegistros = ftell(p)/tamanioRegistro;

    fclose(p);
    return cantidadDeRegistros;
}
