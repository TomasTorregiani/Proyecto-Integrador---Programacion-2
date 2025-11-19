#include <iostream>
#include <cstring>
#include "ArchivoVentas.h"
#include "Venta.h"
#include "FuncionesGlobales.h"

using namespace std;

ArchivoVentas::ArchivoVentas(const char* n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Venta);
}

int ArchivoVentas::agregarVenta(Venta& venta){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "El archivo 'archivo_ventas.dat' no se abrio correctamente" << endl;
        return -1;
    }

    int escribio = fwrite(&venta, _tamanioRegistro, 1, p);
    if(escribio > 0){
        fclose(p);
        return 1;
    }
    fclose(p);
    return 0;
}

int ArchivoVentas::buscarPosicionPorID(int idVenta){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se leyo correctamente el archivo" << endl;
        return -1;
    }

    Venta registro;

    int cantidad = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidad; i++){
        fread(&registro, _tamanioRegistro, 1, p);
        if(registro.getIdVenta() == idVenta){
            fclose(p);
            return i;
        }
    }
    fclose(p);
    return -1;
}

Venta ArchivoVentas::obtenerVenta(int idVenta){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se abrio correctamente el archivo 'ventas.dat'" << endl;
        return Venta();  // Constructor por defecto (debería setear id = -1 o 0)
    }

    Venta registro;
    int cantidad = contarRegistros(_nombre, _tamanioRegistro);
    for(int i = 0; i < cantidad; i++){
        fread(&registro, _tamanioRegistro, 1, p);
        if(registro.getIdVenta() == idVenta){
            fclose(p);
            return registro;
        }
    }
    fclose(p);
    return Venta(); //No encontrado
}

/*int ArchivoVentas::anularVenta(int idVenta){ //Este metodo entonces no se usa?
    FILE* p = nullptr;                         //Y lo manejamos directamente con actualizarVentaEnPosicion
    p = fopen(_nombre, "rb+");

    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return 0;
    }

    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    Venta registro;
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&registro, _tamanioRegistro, 1, p);
        if(registro.getIdVenta() == idVenta){

        }
    }
}*/

int ArchivoVentas::actualizarVentaEnPosicion(int posicion, Venta& venta){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb+");
    if(p == nullptr){
        cout << "El archivo no se abrio correctamente" << endl;
        return 0;
    }
    int desplazamiento = _tamanioRegistro*posicion;
    fseek(p, desplazamiento, SEEK_SET);
    int sobreEscribio = fwrite(&venta, _tamanioRegistro, 1, p);
    if(sobreEscribio == 0){
        fclose(p);
        cout << "No se pudo sobreescribir el registro" << endl;
    }else{
        fclose(p);
        return sobreEscribio;
    }
}

Venta *ArchivoVentas::obtenerTodasLasVentas(int cantidadVentas){
    FILE *p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr){
        return nullptr;
    }
    Venta registroVenta;
    Venta *arrayVentas;
    arrayVentas = new Venta[cantidadVentas]();
    for(int i = 0; i < cantidadVentas; i++){
        fread(&registroVenta, _tamanioRegistro, 1, p);
        arrayVentas[i] = registroVenta;
    }
    fclose(p);
    return arrayVentas;
}

