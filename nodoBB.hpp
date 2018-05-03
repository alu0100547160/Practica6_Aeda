#pragma once 
#include <iostream>
#include <stdlib.h>
#include "Dni.hpp"
class nodoBB{
    private:
        DNI dato;
        nodoBB* izq;
        nodoBB* dch;
        
    public:
        nodoBB();
        nodoBB(DNI dat);
        ~nodoBB();
        void set_dato(DNI d);
	    DNI get_dato();
		void set_izq(nodoBB* next_izq);
		nodoBB* get_izq();
		void set_dch(nodoBB* next_dch);
		nodoBB* get_dch();
		
};     
    
nodoBB::nodoBB(){
    dato = 0;
    dch = NULL;
    izq = NULL;
    
}
nodoBB::nodoBB(DNI dat){
    dato = dat;
    dch = NULL;
    izq = NULL;
}
nodoBB::~nodoBB(){
   delete izq;
   delete dch;
}
void nodoBB::set_dato(DNI d){
    dato = d;
}
DNI nodoBB::get_dato(){
    return dato;
}
void nodoBB::set_izq(nodoBB* next_izq){
   izq = next_izq;
}
nodoBB* nodoBB::get_izq(){
    return izq;
}

void nodoBB::set_dch(nodoBB* next_dch){
    dch = next_dch;
}

nodoBB* nodoBB::get_dch(){
    return dch;
}