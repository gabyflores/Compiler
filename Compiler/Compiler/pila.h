
//#ifndef PILA_H_INCLUDED
//#define PILA_H_INCLUDED

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <list>
#include <iostream>
#include <string>
#include "elementopila.h"

using namespace std;

class Pila{

    private: list <ElementoPila*>lista;

    public:
        void push(ElementoPila *x);
        ElementoPila* pop();
        ElementoPila* top();
        void muestra();

};


#endif // PILA_H_INCLUDED
