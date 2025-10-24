
#include <iostream>

#include "ArchivoVentas.h"
#include "Venta.h"

using namespace std;

ArchivoVentas::ArchivoVentas(const char* n){
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Venta)
}

int ArchivoVentas::agregarVenta(DetalleVenta nuevaVenta){
    FILE* p = nullptr;
    p = fopen(_nombre, "ab");

    if(p == nullptr){
        cout << "No se abrio correctamente el archivo" << endl;
        return -1;
    }

    int escribio = fwrite(&nuevaVenta, _tamanioRegistro, 1, p);
    fclose(p);

    if(escribio != 0){
        cout << "El registro se guardo correctamente" << endl;
        return escribio
    } else{
        return 0;
    }
}

DetalleVenta ArchivoVentas::verDetalleVenta(int idVenta){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se pudo leer el archivo" << endl;
    }

    fseek(p, 0, SEEK_SET);

    int cantidadRegistros = contarRegistros(); /*Esta funcion no existe todavia.
                                                Tengo que crearla. La pregunta es,
                                                me conviene hacer una funcion global
                                                ya que se va a utilizar en varios Arhivos?
                                                Hasta ahora la use en archivoclientes y tmb
                                                la voy a necesitar aca.*/

    for(int i = 0; i < )
}

int ArchivoVentas::contarRegistros(){
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");

    if(p == nullptr){
        cout << "No se pudo abrir correctamente el archivo" << endl;
    }

    fseek(p, 0, SEEK_END); // ==> Colocamos el puntero al final del registro para que nos de el tamanio en bytes.
    int cantidadRegistros = ftell(p)/_tamanioRegistro;

    fclose(p);
    return cantidadRegistros;

}
