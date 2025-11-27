#include <iostream>
#include "FuncionesGlobales.h"

using namespace std;

int contarRegistros(const char *nombreArchivo, int tamanioRegistro){

    FILE *p = nullptr;
    p = fopen(nombreArchivo, "rb");

    if(p == nullptr){
        cout << "El archivo no existe todavia" << endl;
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int cantidadDeRegistros = ftell(p)/tamanioRegistro;

    fclose(p);
    return cantidadDeRegistros;
}

bool esAnioBisiesto(int anio)
{

	return (anio % 4 == 0 && anio % 100 != 0) || (anio %400 == 0);

}

int diasDelMes(int mes, int anio)
{

	int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if(mes == 2 && esAnioBisiesto(anio))
	{
		return 29;
	}
	return dias [mes-1];
}
