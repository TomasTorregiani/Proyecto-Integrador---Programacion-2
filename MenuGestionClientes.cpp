#include <iostream>
#include "TodosLosMenu.h"

using namespace std;

void MenuGestionClientes(){

    int opcion;

    while(true){
        system("cls");
        cout << "**** GESTION DE CLIENTES ****" << endl;
        cout << "1) Nuevo Cliente" << endl;
        cout << "2) Modificar Datos Cliente" << endl;
        cout << "3) Buscar Cliente por Id" << endl;
        cout << "4) Eliminar Cliente" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion: " << endl;
        cin >> opcion;

        system("cls");
        switch(opcion){
            case 1: {
                cout << "Nuevo Cliente" << endl;
            }
            break;
            case 2: {
                cout << "Modificar Datos Cliente" << endl;
            }
            break;
            case 3:{
                cout << "Buscar Cliente por id" << endl;
            }
            break;
            case 4:{
                cout << "Eliminar Cliente" << endl;
            }
            break;
            case 0:
                cout << "Volver al menu principal" << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
