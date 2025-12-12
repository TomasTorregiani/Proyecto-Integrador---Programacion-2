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

int ArchivoDetalles::agregarDetalle(DetalleVenta& detalle){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "DEBUG: No se abrio correctamente el archivo 'detalles_venta.dat'" << endl;
        return -1;
    }

    int escribio = fwrite(&detalle, _tamanioRegistro, 1, p);
    fclose(p);

    if(escribio != 0){
        return escribio;
    } else{
        return 0;
    }
}

int ArchivoDetalles::verDetalleVenta(int idVenta, DetalleVenta *detalles){

    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "DEBUG: No se pudo leer el archivo 'detalles_venta.dat'" << endl;
        return 0;
    }

    DetalleVenta detalle;
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    int encontrados = 0;

    for(int i = 0; i < cantidadRegistros; i++){
        fread(&detalle, _tamanioRegistro, 1, p);
        if(detalle.getIdVenta() == idVenta){
            detalles[encontrados] = detalle;
            encontrados++;
        }
    }
    fclose(p);
    return encontrados;
}

int *ArchivoDetalles::obtenerVentasPorProducto(int cantidadDetallesVendidos, int &tamanioArray){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        cout << "Error al abrir el archivo" << endl;
        return nullptr;
    }

    DetalleVenta registroDetalle;
    int maximoIdEncontrado = 0;

    for(int i = 0; i < cantidadDetallesVendidos; i++){
        fread(&registroDetalle, sizeof(DetalleVenta), 1, p);
        if(registroDetalle.getProducto().getIdProducto() > maximoIdEncontrado){
            maximoIdEncontrado = registroDetalle.getProducto().getIdProducto();
        }
    }
    tamanioArray = maximoIdEncontrado + 1;

    int* cantidadesPorProducto;
    cantidadesPorProducto = new int[tamanioArray](); //Con los parentesis inicializo el array con memoria dinamica en 0

    fseek(p, 0, SEEK_SET);

    for(int i = 0; i < cantidadDetallesVendidos; i++){
        fread(&registroDetalle, sizeof(DetalleVenta), 1, p);
        cantidadesPorProducto[registroDetalle.getProducto().getIdProducto()] += registroDetalle.getCantidad();
    }

    fclose(p);
    return cantidadesPorProducto;
}

DetalleVenta ArchivoDetalles::leerRegistro(int indice)
{
    DetalleVenta registro;

    FILE* p = fopen(_nombre, "rb");
    if(p == nullptr){
        cout << "Error al abrir el archivo" << endl;
        return registro;
    }

    fseek(p, indice * _tamanioRegistro, SEEK_SET);

    fread(&registro, _tamanioRegistro, 1, p);

    fclose(p);

    return registro;
}



