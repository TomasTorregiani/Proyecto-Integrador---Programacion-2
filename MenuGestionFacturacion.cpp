#include <iostream>
#include "TodosLosMenu.h"

using namespace std;

void MenuGestionFacturacion(){

    int opcion;

    while(true){
        system("cls");
        cout << "**** MENU FACTURACION ****" << endl;
        cout << "1) Nueva venta" << endl;
        cout << "2) Ver detalle de factura" << endl;
        cout << "3) Eliminar Factura" << endl;
        cout << "4) Volver al menu principal" << endl;
        cout << endl;
        cout << "Elige una opcion" << endl;
        cin >> opcion;

        system("cls");
        switch(opcion){
            case 1: cout << "Nueva venta" << endl;
            break;
            case 2: cout << "Ver detalle de venta" << endl;
            break;
            case 3: cout << "Eliminar venta" << endl;
            break;
            case 0: cout << "Volviendo al menu principal" << endl;
            return;
            default: cout << "Ingrese un valor valido" << endl;
            break;
        }
        system("pause");
    }

}
