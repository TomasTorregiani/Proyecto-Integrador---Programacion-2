
#include <iostream>
#include <cstring>
#include "ArchivoDetalles.h"
#include "Venta.h"
#include "FuncionesGlobales.h"

using namespace std;

ArchivoDetalles::ArchivoDetalles(const char* n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(DetalleVenta);
}

int ArchivoDetalles::agregarDetalle(DetalleVenta detalle){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "No se abrio correctamente el archivo" << endl;
        return -1;
    }

    int escribio = fwrite(&detalle, _tamanioRegistro, 1, p);
    fclose(p);

    if(escribio != 0){
        cout << "El registro se guardo correctamente" << endl;
        return escribio;
    } else{
        return 0;
    }
}

int ArchivoDetalles::verDetalleVenta(int idVenta, DetalleVenta *detalles){

    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se pudo leer el archivo" << endl;
        return 0;
    }

    DetalleVenta detalle;
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    int encontrados = 0;

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&detalle, _tamanioRegistro, 1, p);
        if(detalle.getIdVenta() == idVenta){
            detalles[encontrados] = detalle; //
            encontrados++;
        }
    }
    fclose(p);
    return encontrados;
}


