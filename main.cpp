#include <iostream>
#include "Cliente.h"

using namespace std;

int main(){
    Cliente cliente1(1,"Tomas","Torre",111,2,4791,"tomitorre","Av maipu");
    cout << cliente1.getIdCliente() <<cliente1.getNombre() << cliente1.getApellido() << cliente1.getCuil()
         << cliente1.getEmail() << cliente1.getDireccion() << endl;

    return 0;
}
