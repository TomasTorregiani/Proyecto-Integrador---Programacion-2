#include "Venta.h"

class ArchivoVentas{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoVentas(const char* n);
    int agregarVenta(Venta& venta);
    Venta obtenerVenta(int idVenta);
    int buscarPosicionPorID(int idVenta);
    int actualizarVentaEnPosicion(int posicion, Venta& venta);
    Cliente obtenerCliente(int idCliente);
};
