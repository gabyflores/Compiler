#ifndef SEMANTICO_H
#define SEMANTICO_H
//#include "Nodo.h"//py se incluye tablaSimbolos
#include "TablaSimbolos.h"//py


class Semantico
{
    public:
        list <string> listaErrores;
        Nodo *arbol;
        //Nodo *arbol1;
        Semantico();
        void analiza(Nodo *arbol);
        TablaSimbolos *tablaSimbolos;
        void muestraErrores();
        void genCode();
    protected:
    private:
};

#endif // SEMANTICO_H
