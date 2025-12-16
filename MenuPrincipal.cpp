#include <iostream>
#include <cstdlib>

#include "TodosLosMenu.h"

using namespace std;

void MenuPrincipal(){

    int opcion;

    while(true){
        system("cls");
        cout << "----- BIENVENIDO -----" << endl;
        cout << endl;
        cout << "1) Gestion de facturacion" << endl;
        cout << "2) Gestion de clientes" << endl;
        cout << "3) Gestion de productos" << endl;
        cout << "4) Gestion de vendedores" << endl;
        cout << "5) Listados y consultas" << endl;
        cout << "6) Informes y reportes" << endl;
				cout << "7) Testing" << endl;
        cout << "0) Salir" << endl;
        cout << endl;
        cout << "Elegi una opcion: " << endl;

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1: MenuGestionFacturacion();
            break;
            case 2: MenuGestionClientes();
            break;
            case 3: MenuGestionProductos();
            break;
            case 4: MenuGestionVendedores();
            break;
            case 5: MenuListadosYConsultas();
            break;
            case 6: MenuInformesYReportes();
            break;
            case 7: MenuTesting();
            break;
            case 0: cout << "Saliendo del programa..." << endl;
            exit(0);
            default: cout << "Ingrese una opcion valida" << endl;
            break;
        }
        system("pause");
    }
}
