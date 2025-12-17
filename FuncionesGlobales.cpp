#include <iostream>
#include "FuncionesGlobales.h"
#include <cstring>

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

	if ((anio % 4 == 0 && anio % 100 != 0) || (anio %400 == 0))
	{
		return true;
	}

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

bool validarMail(std::string mail){

	if(mail == "")
	{
		return false;
	}

	int cantCaracteres = mail.length();
	cout << "DEBUG: El mail tiene " << cantCaracteres << " caracteres." << endl;

	int posArroba = -1; //porque al cero lo voy a usar para inciar el i.
	bool arrobaExiste = false;

	for(int i = 0; i < cantCaracteres ; i ++)
	{
		if(mail[i]=='@')
		{
			posArroba = i; //primero encuentro donde esta el @
			arrobaExiste = true;
			cout << "DEBUG: arrobaExixte: " << arrobaExiste << endl;
		}
	}

	bool puntoComExiste = false;

	for(int i = 0; i < cantCaracteres ; i++)
	{
		if( (mail [cantCaracteres-4] == '.' &&
				mail [cantCaracteres-3] == 'c' &&
				mail [cantCaracteres-2] == 'o' &&
				mail [cantCaracteres-1] == 'm' ) ||

				(mail [cantCaracteres-7] == '.' &&
				 mail [cantCaracteres-6] == 'c' &&
				 mail [cantCaracteres-5] == 'o' &&
				 mail [cantCaracteres-4] == 'm' &&
				 mail [cantCaracteres-3] == '.' &&
				 mail [cantCaracteres-2] == 'a' &&
				 mail [cantCaracteres-1] == 'r'))
		{
			puntoComExiste = true;
		}
	}

	cout << "DEBUG: puncoComExiste: " << puntoComExiste << endl;

	if ((arrobaExiste == false) || (posArroba == -1))
	{
		return false;
	}

	if(arrobaExiste && puntoComExiste)
	{
		return true;
	}else{
        return false;
	}
}

bool esUnNumero(int numero){
	if(!(numero == 'a' || numero == 'A' || numero == 'b' || numero == 'B' ||
		 numero == 'c' || numero == 'C' ||
		 numero == 'd' || numero == 'D' ||
		 numero == 'e' || numero == 'E' ||
		 numero == 'f' || numero == 'F' ||
		 numero == 'g' || numero == 'G' ||
		 numero == 'h' || numero == 'H' ||
		 numero == 'i' || numero == 'I' ||
		 numero == 'j' || numero == 'J' ||
		 numero == 'k' || numero == 'K' ||
		 numero == 'm' || numero == 'M' ||
		 numero == 'n' || numero == 'N' ||
		 numero == 'l' || numero == 'L' ||
		 numero == 'o' || numero == 'O' ||
		 numero == 'p' || numero == 'P' ||
		 numero == 'q' || numero == 'Q' ||
		 numero == 'r' || numero == 'R' ||
		 numero == 's' || numero == 'S' ||
		 numero == 't' || numero == 'T' ||
		 numero == 'u' || numero == 'U' ||
		 numero == 'v' || numero == 'V' ||
		 numero == 'w' || numero == 'W' ||
		 numero == 'x' || numero == 'X' ||
		 numero == 'y' || numero == 'Y' ||
		 numero == 'z' || numero == 'Z')){
		return true;
	}
}

/*bool validarDireccion(std::string direccion){

	bool hayUnEspacio = false;
	bool hayUnNumero = false;

	int len = direccion.length();


}*/
