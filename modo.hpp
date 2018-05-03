#include <vector> 

using namespace std;

bool en_banco(vector<DNI> banco, DNI eldni) {
    for (int i = 0; i < banco.size(); i++) {
        if (banco[i] == eldni)
            return true;
    }
    return false;
}


int  demostracion( arbolBB& A, int clave, int op){
    cout << " Ha elegido modo demostracion" << endl;
    cout << "1.Insertar clave " << endl;
    cout << "2.Eliminar clave " << endl;
    cout << "0.Salir" << endl;
    cin >> op;
                        
        switch(op){
            case 1: {
                cout << "Introduzca una clave: ";
                cin >> clave;
                DNI eldni(clave);
                A.insercion(eldni);
                break;
            }
            case 2: {
                cout << "Introduzca una clave: ";
                cin >> clave;
                A.eliminacion(clave);
                break;
            }
             return op;
        }
   
}

int estadistica (arbolBB& A){
    int N;// tamaño del arbol
    int P; // numero de pruebas
    int min,max,media,acumulado;
    cout << " Ha elegido modo estadisticas" << endl;
    A.set_verbose(false);
    cout << "Tamaño de arbol: ";
    cin >> N;
    cout << "Nº de pruebas: ";
    cin >> P;
    vector<DNI> banco;
    for(int j = 0; j < (2 * N); j++){
        bool exito = false;
        DNI aux;
        while (!exito) {
            int ndni = (rand()% (MAX - MIN)) + MIN;
            aux.set_dni(ndni);
            if (!en_banco(banco, aux))
                exito = true;
            }
            banco.push_back(aux);
    }
    min = 99999;
    max = 0;
    acumulado = 0;
    for (int i = 0; i < N; i++) {
        A.insercion(banco[i]);
    }
    for (int i = 0; i < P; i++) {
        int randindex = (rand()% N);
        A.busqueda(banco[randindex]);
        int counter = A.get_comparaciones();
        acumulado = acumulado + counter;
        if (counter > max) max = counter;
        if (counter < min) min = counter;
    }
    media = acumulado/P;
    cout << endl;
    cout << "                      N   P   Min    Medio   Max   " << endl;
    cout << "Claves Insertadas   : " <<  N <<" "<< P << " " << min <<" "<< media << " " << max << endl;
    min = 99999;
    max = 0;
    acumulado = 0;
    for (int i = 0; i < P; i++) {
            int randindex = (rand()% N) + N;
            A.busqueda(banco[randindex]);
            int counter = A.get_comparaciones();
            acumulado = acumulado + counter;
            if (counter > max)   max = counter;
            if (counter < min)   min = counter;
    }
    cout << "Claves no Insertadas: " <<  N <<"   "<< P << "   " << min <<"   "<< media << " " << max << endl;
    cout << endl;
 
              
}