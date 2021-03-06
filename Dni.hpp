#pragma once 
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int  MIN = 00000000;
const int  MAX = 99999999;

class DNI{
    
    int dni;
    int letra;
   
public:

    DNI(int dn){
        if((dn < MIN )|| (dn > MAX))
         cout << "error en dni"<<endl;
        else
         dni = dn;
         letra =  rand() % 9;
    
         
    }
     
    DNI(){
         
       srand(time(NULL));
       int dn = MIN + rand() % (MAX - MIN);
       dni = dn;
       letra = rand() % 6;
    
         
    }
    
    ~DNI(){
    }
      
    
    int  get_dni() const{
        
       int result = dni ;//+ letra;
        return result;
    }
    
    
    void set_dni(int dn){
        dni = dn;
      //  letra = l;
    }
    
    
    char getRandomChar()
    {
        static char c = 'H' + rand()% 5;
        return c;    
    }
    bool operator==(const DNI& b){
        
        return (get_dni() == b.get_dni());
    }
    
    
    bool operator<(const DNI& b){
        return (get_dni() < b.get_dni() );
    }
    
    
    bool operator>(const DNI& b){
        return (get_dni() > b.get_dni() );
       
    }
    bool operator<=(const DNI& b){
        return (get_dni() <= b.get_dni());
        
    }
    bool operator>=(const DNI& b){
        return (get_dni() >= b.get_dni());
    }

};