#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <fstream>//aqui para que funcionara
#include "pila.h"
#include "TablaSimbolos.h"
//#include "Semantico.h" con este no corre

using namespace std;

class ElementoPila;
class TablaSimbolos;

   class Nodo{
        protected:

        public:
        static ofstream datos;
        static ofstream bss;
        static ofstream text;
      
        char tipoDato;
        static TablaSimbolos *tablaSimbolos;
        static string ambito;
        static int numPrintf;
        string aux;
        string msn;
        string auxError;
        int tamSangria;
        void sangria();
        virtual void muestra(){}
        virtual void validaTipo(){}
        virtual void generaCodigo(){}
        char dimeTipo(string simbolo);


    };



    class Programa: public Nodo{
    };

    class Definicion: public Nodo{
    };

    class Definiciones: public  Nodo{
        
    public:
        Definiciones *aux;
        Definicion *aux2;
        Definiciones(Pila *pila);

    void muestra();
    void validaTipo();
    void generaCodigo();
    };



    class DefLocal: public Nodo{
    };


    class DefinicionLocales: public Nodo{

    public:
        DefinicionLocales *DF;
        DefLocal *df;

        DefinicionLocales(Pila *pila);
        void muestra();
        void validaTipo();
        void generaCodigo();
    };


    class BloqFuc:public Nodo{
    public:
       string abre;
       DefinicionLocales *DF;
       string cierra;

       BloqFuc(Pila *pila);
       void muestra();
       void validaTipo();
       void generaCodigo();
    };





    class Expresion:public Nodo{
    public:
        virtual bool esTer(){return false;}
    protected:
        Expresion *exp1,*exp2;
    };



    class Termino:public Expresion{
       //void validaTipo();
       public:
        bool esTer(){return true;}
        virtual string retTer(){return "GENERIC_STRING";}
       string simbolo;
    };

    class Sentencia:public Nodo{
    };

    class SentenciaBloque:public Nodo{

    };


    class Sentencias:public Nodo{
    public:
      Sentencias *St;
      Sentencia *st;

      Sentencias(Pila *pila);

      void muestra();

      void validaTipo();
      void generaCodigo();

    };

    class Bloque:public Nodo{
    public:
    Sentencias *sent;
    string abre;
    string cierra;

    Bloque(Pila *pila);

    void muestra();

    void validaTipo();

    void generaCodigo();

  };



    class ValorRegresa: public Sentencia{

    public:
      string puntocoma;
      ValorRegresa *vR;
      string palabra;

      ValorRegresa(Pila *pila);

      void muestra();
      void validaTipo();
      void generaCodigo();

    };

    class Wh: public Sentencia{
    public:
      Bloque *bloque;
      string cierra;
      Expresion *expresion;
      string abre;
      string palabra;

      Wh(Pila *pila);

     void muestra();

     void validaTipo();

     void generaCodigo();
    };

    class Otro: public Nodo{
    public:
      SentenciaBloque *SB;
      string palabra;
      Otro(Pila *pila);
      void muestra();
      void validaTipo();
      void generaCodigo();

    };

    class Condicional:public Sentencia{
    public:
      string condicion;
      string abre;
      Expresion *expresion;
      string cierra;
      SentenciaBloque *SB;
      Otro *otro;

      Condicional(Pila *pila);

      void muestra();

      void validaTipo();

      void generaCodigo();

    };





    class ListaArgumentos: public Nodo{
    public:
      ListaArgumentos *LA;
      Expresion *expresion;
      string coma;

      ListaArgumentos(Pila *pila);

      void muestra();
      void validaTipo();
      void generaCodigo();

    };


    class Argumentos:public Nodo{
    public:
      ListaArgumentos *LA;
      Expresion *expresion;


    Argumentos(Pila *pila);
    virtual bool esTer(){return true;}
    void muestra();

    void validaTipo();

    void generaCodigo();

    };

    class Identificador:public Termino{

        protected:


        public:
           string simbolo;
           Identificador(Pila *pila);
           void muestra();
           void validaTipo();
           void generaCodigo();
           string retTer(){return simbolo;}
    };

     class ListaParametros: public Nodo{
    public:
      string coma;
      string tipo;
      string id;
      ListaParametros *lista;

      ListaParametros(Pila *pila);

      void muestra();
      void validaTipo();
      void generaCodigo();

    };

    class Parametros:public Nodo{
    public:
      string tipo;
      string id;
      //Identificador *id;
      ListaParametros *lista;

      Parametros(Pila *pila);
      Parametros(string tipo, string id, string ambito);
      void muestra();
      void validaTipo();
      void generaCodigo();

    };

     class DefFun:public Nodo{
    public:
      string tipo;

      //Identificador *identificador;
      string identificador;
      string abre;
      Parametros *parametros;
      //Nodo *parametros;
      string cierra;
      BloqFuc *bloque;


      DefFun(Pila *pila);

      void muestra();

      void validaTipo();

      void generaCodigo();

    };

     class ListaVar:public Nodo{

    public:
      string coma;
      string identificador;
      ListaVar *lista;
      ListaVar(Pila *pila);

      void muestra();

      void validaTipo();

      void generaCodigo();
    };

    class Defvar: public Nodo{
    public:
      string tipo;
      string identificador;
      ListaVar *lista;
      string puntComa;

      Defvar(Pila *pila);

      void muestra();

      void validaTipo();

      void generaCodigo();
    };


    class Entero:public Termino{
        protected:

        public:
          string simbolo;
          Entero(Pila *pila);

          void muestra();
          void validaTipo();
          void generaCodigo();
          string retTer(){return simbolo;}

        };

     class Real:public Termino{
        protected:

        public:
          string simbolo;
          Real(Pila *pila);
          void muestra();
          void validaTipo();
          void generaCodigo();
          string retTer(){return simbolo;}
        };

      class Cadena:public Termino{
        protected:
        //string simbolo;
        public:
          string simbolo;
          Cadena(Pila *pila);

          void muestra();
          void validaTipo();
          void generaCodigo();
          string retTer(){return simbolo;}

        };

    class LlamadaFuncion:public Nodo{
    public:
    Argumentos *Ar;
    //Identificador *Id;
    string Id;
    string cierra;
    string abre;
         
        
        LlamadaFuncion(Pila *pila);

        void muestra();
        void validaTipo();
        void generaCodigo();
   };

    class LlamaFun: public Sentencia{
    public:
    string puntocoma;
    LlamadaFuncion *llama;

    LlamaFun(Pila *pila);

    void muestra();

    void validaTipo();

    void generaCodigo();

    };

    class idEx: public Sentencia{
    public:
      //Identificador *id;
      string id;
      string asignacion;
      Expresion *expresion;
      string puntComa;

      idEx(Pila *pila);

      void muestra();
      void validaTipo();
      void generaCodigo();

    };


    class Exp: public Expresion{
      public:
      string cierra;
      string abre;

      Exp(Pila *pila);

      void muestra();
      void validaTipo();
      void generaCodigo();
    };

    class Acum: public Expresion{
        protected:

        public:
        string simbolo;
        Acum(Pila *pila);

        void muestra();

        void validaTipo();
        void generaCodigo();
    };

    class opeNot: public Expresion{
        protected:
        //string simbolo;
        public:
        string simbolo;

        opeNot(Pila *pila);

        void muestra();

        void validaTipo();

        void generaCodigo();
    };

    class opSuma:public Expresion{
         protected:
         //string simbolo;
         public:
          string simbolo;
          opSuma(Pila *pila);

      void muestra();

      void validaTipo();

      void generaCodigo();

        };

       class opMulti:public Expresion{
        protected:
        //string operador;
        public:
          string operador;
          opMulti(Pila *pila);
          void muestra();
          void validaTipo();
          void generaCodigo();
        };



    class opRelac:public Expresion{
    protected:
      //string operador;
    public:
      string operador;
      opRelac(Pila *pila);
      void muestra();
      void validaTipo();
      void generaCodigo();
    };

    class opIgualdad:public Expresion{
    protected:
      //string operador;
    public:
      string operador;
      opIgualdad(Pila *pila);

       void muestra();

       void validaTipo();

       void generaCodigo();
    };

    class opAnd:public Expresion{
    protected:
      //string operador;
    public:
      string operador;
      opAnd(Pila *pila);

       void muestra();
       void validaTipo();
       void generaCodigo();

    };

    class opOr:public Expresion{
    protected:
      //string operador;
    public:
      string operador;
      opOr(Pila *pila);

       void muestra();

       void validaTipo();

       void generaCodigo();

    };


#endif // NODO_H
