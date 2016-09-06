#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H
#include "nodo.h"

const int TAM=211;

class elementoTabla{

    public:
    char clase;
    string simbolo;
    string ambito;
    char tipo;
    virtual void muestra(){}
    virtual bool esVariable(){
    if(this->clase=='v')
        return true;
         else
            return false;
    }
	virtual bool esVarLocal(){
	     if(this->ambito.compare("")==0)
	       return false;
	     else
           return true;
	     }
	virtual bool esFuncion(){

	     if(this->clase=='f')
        return true;
         else
            return false;

	    }
    virtual bool esParametro(){

        if(this->clase=='p')
        return true;
         else
            return false;
    }
};

class Variable:public elementoTabla{
    public:
        bool local;
        //string ambito;
        Variable(char tipo,string simbolo,string ambito);
        void muestra();

};

class Funcion:public elementoTabla{

    public:
        string parametros;
        bool esFuncion(){return true;}
        Funcion(char tipo, string simbolo, string parametros);
        void muestra();


};

class Parametro:public elementoTabla{

    public:

        bool local;
        //string ambito;
        Parametro(char tipo,string simbolo,string ambito);
        void muestra();

};

class Defvar;
class DefFun;
class Parametros;

class TablaSimbolos{
    public:

        list <elementoTabla*> tabla[TAM];
        list <string> *listaErrores;

        Variable *varLocal;
	    Variable *varGlobal;
	    Funcion *funcion;
	    Parametro *parametro;

        TablaSimbolos(list <string> *listaErrorres);
        void agrega(elementoTabla *elemento);
        int dispersion(string simbolo);
        void agrega(Defvar *defvar);
        void agrega(DefFun *defFun);
        void agrega(Parametros *parametros);
        void muestra();
        bool varGlobalDefinida(string variable);
        bool varLocalDefinida(string variable, string funcion);
        bool funcionDefinida(string simbolo);

        void buscaIdentificador(string simbolo,string ambito);
	    void buscaFuncion(string simbolo);
    protected:
    private:
};


#endif // TABLASIMBOLOS_H
