#include <iostream>
#include <cstring>
#include <string>
#include "ArchivoClientes.h"
#include "Cliente.h"
#include "FuncionesGlobales.h"

using namespace std;

ArchivoClientes::ArchivoClientes(const char* nombreArchivo) //constructor, recibe nombre del archivo
{

}

bool ArchivoClientes::guardarCliente(Cliente registro)  //recibre el registro de un cliente.
{
    FILE *pFile;
    bool escribio; //uso booleano porque solo vamos a escribir de un cliente a la vez.

    pFile = fopen(_nombreArchivo, "ab"); //abre el archivo en la última posición. Si no existe, lo crea.

    if (pFile == nullptr)
    {
        return false;
    }

    escribio = fwrite(&registro, sizeof(Cliente), 1, pFile); //graba 1 registro de Cliente.

    if(escribio == true){
			fclose(pFile);
			return true;
    }
        
    fclose(pFile);

    return false;
}

//FIXME:

Cliente ArchivoClientes::buscarClientePorId(int idCliente)
{

    Cliente cliente;
		
    FILE *pFile;
    pFile = fopen(_nombreArchivo, "rb"); //ok

    if(pFile == nullptr)
    {
			return Cliente(); //devuelvo un cliente vacío. El manager despues arma el cartelito. 
    }

    while(fread(&cliente, sizeof(Cliente), 1, pFile))
    {
        if(cliente.getIdCliente() == idCliente)
        {
            int pos = ftell(pFile)/sizeof(Cliente) - 1; //Y qué hace después?
            break;
        }
    }

    int cantidadRegistros = contarRegistros(_nombreArchivo, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&cliente, _tamanioRegistro,1,pFile);
        if(cliente.getIdCliente() == idCliente)
        {
        	fclose(pFile);
					return Cliente();
        }
    }
    fclose(pFile);
    return Cliente(); //devuelve el constructor inicializado en cero.  
}

int ArchivoClientes::obtenerPosicionCliente(int idCliente)
{
    FILE* pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
    {
        cout << "El archivo no se abrio correctamente" << endl;
        return -1;
    }
    fseek(pFile, 0, SEEK_SET);
    int cantidadRegistros = contarRegistros("clientes.dat", _tamanioRegistro);
    Cliente registro;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&registro, _tamanioRegistro, 1, pFile);
        if(registro.getIdCliente() == idCliente)
        {
            cout << "Registro encontrado correctamente";
            fclose(pFile);
            return i;
        }
    }
    cout << "Registro no encontrado" << endl;
    fclose(pFile);
    return -1;
}

bool ArchivoClientes::modificarDatosCliente(Cliente registro, int posicion)
{
    FILE *p = nullptr;
    p = fopen(_nombreArchivo, "rb+");

    if(p == nullptr)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    fseek(p, posicion*_tamanioRegistro, SEEK_SET);
    bool escribio = fwrite(&registro, _tamanioRegistro, 1, p);
		
		fclose(p);
    return escribio;
}

int ArchivoClientes::agregarCliente(Cliente registro){

	//TODO//

}

/*void ArchivoClientes::listarClientes()
{
    FILE* p = nullptr;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        cout << "El archivo no se abrio correctamente" << endl;
    }
    fseek(p, 0, SEEK_SET);
    int cantidadRegistros = contarRegistros(_nombre, _tamanioRegistro);
    Cliente registro;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&registro, _tamanioRegistro, 1, p);
        registro.mostrarCliente(); //?? <<< aca tira error.
    }
}*/

void ArchivoClientes::listarClientes(){
	//TODO//
}

bool ArchivoClientes::eliminarCliente(Cliente registro){
    FILE *p = nullptr;
    p = fopen(_nombreArchivo, "rb+");

   if(p == nullptr){
       cout << "No se logro leer el archivo" << endl;
        return -1;
    }

    /*int cantidadRegistros = contarRegistros(_nombreArchivo, _tamanioRegistro);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&cliente, _tamanioRegistro, 1, p);
        if(cliente.getIdCliente() == idCliente){
           int sobreEscribio = fwrite(&cliente, _tamanioRegistro, 1, p);
            if(sobreEscribio == 0){
              cout << "Error al eliminar el archivo" << endl;
                fclose(p);
                return -1;
           }else {
               cout << "El archivo se anulo correctamente" << endl;
               fclose(p);
                return sobreEscribio;
            }
        }
   }*/
}









































