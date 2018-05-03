#pragma once 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <math.h>
#include "nodoBB.hpp"

class arbolBB {
    private:
        nodoBB* inicio;
        nodoBB* nodo_padre; //padre temporal
        int dir_padre; //0 = hijo por la izquierda, 1 = hijo por la derecha
        bool verbose;
        int comparaciones;
  
    public:
      arbolBB();
      ~arbolBB();
      nodoBB* get_inicio();
      nodoBB* get_nodo_padre();
      int get_dir_padre();
      int get_comparaciones();
      bool is_verbose();
      void set_verbose(bool verb);
      nodoBB* busqueda(DNI elemento);
      void insercion(DNI elemento);
      void eliminacion(DNI elemento);
      bool es_vacio(nodoBB *nodo);
      void mostrar();
      
      
};


arbolBB::arbolBB(){
    inicio = NULL;
    nodo_padre == NULL;
    verbose = true;
    dir_padre = 0;
    comparaciones = 0;
}
arbolBB::~arbolBB(){
    
}
nodoBB* arbolBB::get_inicio(){
    return inicio;
}

bool arbolBB::is_verbose() {
    return verbose;
}

void arbolBB::set_verbose(bool verb) {
    verbose = verb;
}

nodoBB* arbolBB::get_nodo_padre(){
    return nodo_padre;
}

int arbolBB::get_dir_padre() {
    return dir_padre;
}

int arbolBB::get_comparaciones() {
    return comparaciones;
}

void arbolBB::insercion(DNI elemento){
    nodoBB N(elemento);
    nodoBB* aux; 
    bool insertado = false;
    aux = busqueda(elemento);
    if (aux != NULL) {
        if (is_verbose())
            cout << endl << "El Dni insertado ya existe en el arbol" << endl << endl;
    } else {
        aux = inicio;
        
        if(inicio == NULL){
            inicio = new nodoBB(elemento);
        } else{
            while(!insertado){
                
                if(elemento > aux -> get_dato()){ // si el elemento a insertar es mayor q lo q hay
                    if(aux -> get_dch() == NULL){
                        aux -> set_dch(new nodoBB(elemento));
                        //aux = &N;
                        insertado = true;
                    }else{
                        aux = aux -> get_dch();
                    
                    } 
                }else{  
                    if(aux -> get_izq() == NULL){
                        aux -> set_izq(new nodoBB(elemento));
                        //aux = &N;
                        insertado = true;
                    }else{
                        aux = aux -> get_izq();
                        
                    } 
                }
            }
            
        }
        if (is_verbose())
            mostrar();
    }
    mostrar();
}

nodoBB* arbolBB::busqueda(DNI elemento){
    bool terminado = false;
    nodoBB* aux;
    aux = inicio;
    if(inicio == NULL){
        if (is_verbose())
            cout << " el elemento no esta en el arbol" << endl;
        return NULL;
    }
    comparaciones = 0;
    while(!terminado){
        comparaciones++;
        if(elemento == aux -> get_dato()){
             if (aux == inicio)
                nodo_padre = NULL;
             return aux;
        } else if(elemento > aux -> get_dato()){
            if (aux -> get_dch() == NULL)
                terminado = true;
            nodo_padre = aux;
            dir_padre = 1;
            aux = aux -> get_dch();
        } else {
            if (aux -> get_izq() == NULL)
                terminado = true;
            nodo_padre = aux;
            dir_padre = 0;
            aux = aux -> get_izq();
        }
            
    }
    return NULL;
}
bool arbolBB::es_vacio(nodoBB *nodo){
    return nodo == NULL;
}

void arbolBB::eliminacion(DNI elemento){
    nodoBB* aux;
    nodoBB* padre;
    nodoBB* sustituto;
    nodoBB* aux2;
    bool may = false;
    aux = busqueda(elemento);
    if(( aux ->get_dch() == NULL) && (aux -> get_izq() == NULL)){ // nodo hoja
        cout << "Es nodo hoja.." << endl;
        if (get_nodo_padre() == NULL) {
            delete aux;
            inicio = NULL;
        } else {
            if (get_dir_padre() == 0) {//hijo por la izquiera
                padre = get_nodo_padre();
                padre -> set_izq(NULL);
            } else {
                padre = get_nodo_padre();
                padre -> set_dch(NULL);
            }
        }            
            
    } else{ // si el nodo a eliminar tiene solo un hijo por la derecha
            if(( aux -> get_izq() == NULL) && (aux -> get_dch() != NULL)){
                padre = get_nodo_padre();
                if (padre == NULL) {
                    aux = aux -> get_dch();
                    inicio = aux;
                } else {
                    aux2 = aux -> get_dch();
                    padre -> set_dch(aux2); 
                }
             // si el nodo a eliminar solo un hijo por la izquierda
            }else if(( aux -> get_dch() == NULL) && (aux -> get_izq() != NULL)){
                padre = get_nodo_padre();
                if (padre == NULL) {
                    aux = aux -> get_izq();
                    inicio = aux;
                } else {
                    aux2 = aux -> get_izq();
                    padre -> set_izq(aux2);
                }
            } else {
                sustituto = aux -> get_izq();
                bool paraladerecha = false;
                while(sustituto -> get_dch() != NULL){
                    paraladerecha = true;
                    padre = sustituto;
                    sustituto = sustituto -> get_dch();
                }
                if(!paraladerecha){ // nodo hoja
                    DNI intercambio;
                    intercambio = sustituto -> get_dato();
                    aux -> set_dato(intercambio);
                    aux -> set_izq(NULL);
                } else {
                    DNI intercambio;
                    intercambio = sustituto -> get_dato();
                    aux -> set_dato(intercambio);
                    padre -> set_dch(NULL);
                }
            }
    }
    mostrar();
    
}
  
void arbolBB::mostrar(){
    vector<nodoBB*> cola;
    cout << endl;
    if(inicio == NULL){
        cout << "Arbol vacio" << endl;
        cout << "Nivel 0: [.]" << endl;
    } else {
        cola.push_back(inicio);
        int nivel = 0;
        bool nivelvacio = false;
        while (!nivelvacio) {
            nivelvacio = true;
            for (int i = 0; i < cola.size(); i++) {
                if (cola[i] != NULL)
                    nivelvacio = false;
            }
            cout << "Nivel " << nivel << ":";
            for (int i = 0; i < cola.size(); i++) {
                if (cola[i] != NULL)
                    cout << " [" << cola[i] -> get_dato().get_dni() << "]";
                else
                    cout << " [.]";
            }
            cout << endl;
            vector<nodoBB*> actuales;
            for (int i = 0; i < cola.size(); i++) {
                actuales.push_back(cola[i]);
            }
            cola.clear();
            for (int i = 0; i < actuales.size(); i++) {
                if (actuales[i] == NULL) {
                    cola.push_back(NULL);
                    cola.push_back(NULL);
                } else {
                    cola.push_back(actuales[i]->get_izq());
                    cola.push_back(actuales[i]->get_dch());
                }
            }
            nivel++;
        }
    }
    cout << endl;
}