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
	
	int cadenaMail = mail.length(); 
	cout << " DEBUG: El mail tiene " << cadenaMail << " caracteres." << endl; 
	
	int posArroba = -1; //porque al cero lo voy a usar para inciar el i.
	bool arrobaExiste = false; 
	bool arrobaBien = false; 

	for(int i = 0; i < cadenaMail ; i ++)
	{
		if(mail[i]=='@')
		{
			posArroba = i; //primero encuentro donde esta el @
			arrobaExiste = true;
		}
	}
	
	bool puntoComExiste = false;
		
	for(int i = 0; i < cadenaMail ; i++) 
	{
		if( (mail [cadenaMail-4] == '.' &&
				mail [cadenaMail-3] == 'c' &&
				mail [cadenaMail-2] == 'o' &&
				mail [cadenaMail-1] == 'm' ) || 
				(mail [cadenaMail-7] == '.' &&
				 mail [cadenaMail-6] == 'c' &&
				 mail [cadenaMail-5] == 'o' &&
				 mail [cadenaMail-4] == 'm' &&
				 mail [cadenaMail-3] == '.' &&
				 mail [cadenaMail-2] == 'a' &&
				 mail [cadenaMail-1] == 'r'))
		{
			puntoComExiste = true;
		}
	}
	
	if ((!arrobaExiste || posArroba == 0))
	{
		return false;
	}else
		{ 
			arrobaBien = true;
		}
	
	if(arrobaBien && puntoComExiste)
	{
		return true; 
	}
}

bool esUnNumero(int numero){
	if((numero == 'a' || numero == 'A' || numero == 'b' || numero == 'B' ||
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
		return false; 
	}
}

/*bool validarDireccion(std::string direccion){
	
	bool hayUnEspacio = false;
	bool hayUnNumero = false;
	
	int len = direccion.length(); 
	
	
}*/
