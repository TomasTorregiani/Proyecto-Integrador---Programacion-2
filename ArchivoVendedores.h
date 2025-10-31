#pragma once

class ArchivoVendedores{
private:
    char _nombre[50];
    int _tamanioRegistro;
public:
    ArchivoVendedores(const char *n, int tamanioRegistro);
    int agregarVendedor(Vendedor vendedor);
    Vendedor buscarVendedorPorId(int idVendedor);
};

