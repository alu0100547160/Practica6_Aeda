#include "arbolBB.hpp"//#include "modo.hpp"
#include "modo.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main(){

    int opc;
    int op;
    int clave;
    arbolBB A;
    
    do{
        cout << "1.Modo demostracion" << endl;
        cout << "2.Modo estadisticas" << endl;
        cout << "Opcion: ";
        cin >> opc;
        switch(opc){
            case 1: {
                do{
                    op = demostracion( A, clave,op);
                }while(op!=0);
                break;
            }
            case 2:{
                estadistica (A);
                break;   
            }// fin case 2
        }
    }while(opc!=0);
    
return 0;
}