#pragma once


class Venta{
public:
    //Constructores
    Venta();
    Venta(int idVenta, Cliente cliente,
          Producto producto, std::string fecha,
          int cantidad, float importe);

    //No es necesario ningun setter

    //Getters
    int getIdVenta();
    Cliente getCliente(); //Composicion
    Producto getProducto(); //Composicion
    std::string getFecha(); /*Hacemos una clase para fecha? Quizas podamos
                            implementarla en otras cosas as adelante*/
    int getCantidad();
    float getImporte;

protected:

private:
    int idVenta;
    Cliente cliente;
    Producto producto;
    char fecha[30];
    int cantidad;
    float importe;
};
