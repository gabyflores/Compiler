#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
#include "lexico.h"


  Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente;
  }

  Lexico::Lexico(){
    ind= 0;
  }

  string Lexico::tipoAcad(int tipo){
         string cad= "";

         switch (tipo){//Muestra tipos
           case TipoSimbolo::IDENTIFICADOR:
                cad= "Identificador";
                break;

           case TipoSimbolo::OPADIC:
                cad= "Op. Adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "Op. Multiplicacion";
                break;

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;

           case TipoSimbolo::ENTERO:
                cad= "Entero";
                break;
           case TipoSimbolo::OPASIG:
                cad= "Op. Asignacion";
                break;
           case TipoSimbolo::OPRELAC:
                cad= "Op. Relacional";
                break;
           case TipoSimbolo::OPAND:
                cad= "Op. AND";
                break;
           case TipoSimbolo::OPOR:
                cad= "Op. OR";
                break;
           case TipoSimbolo::OPNOT:
                cad= "Op. NOT";
                break;
           case TipoSimbolo:: PARENTESIS1:
                cad= "Parentesis Inicial";
                break;
           case TipoSimbolo:: PARENTESIS2:
                cad= "Parentesis Final";
                break;
           case TipoSimbolo:: LLAVE1:
                cad="Llave Inicial";
                break;
           case TipoSimbolo:: LLAVE2:
                cad= "Llave final";
                break;
           case TipoSimbolo::PUNTCOM:
                cad= "Punto y coma";
                break;
           case TipoSimbolo:: REAL:
                cad= "Real";
                break;
           case TipoSimbolo::TIPO:
                cad="Tipo";
                break;
           case TipoSimbolo::SI:
                cad="Palabra Reservada";
                break;
           case TipoSimbolo::MIENTRAS:
                cad="Palabra Reservada";
                break;
           case TipoSimbolo::REGRESA:
                cad="Palabra Reservada";
                break;
           case TipoSimbolo::SINO:
                cad="Palabra Reservada";
                break;
           case TipoSimbolo::CADENA:
                cad="Cadena";
                break;
           case TipoSimbolo::COMA:
                cad="Coma";
                break;
           case TipoSimbolo::OPIGUALDAD:
                cad="Op. Igualdad";
                break;


           default:
                cad="Error";

         }

         return cad;
  }

  void Lexico::entrada(string fuente){//este metodo asigna el valor correspondiente a la fuente
       ind= 0;
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){

    estado=0;
    continua= true;
    simbolo= "";//se inicializa simbolo

    //Inicio del Automata
    while (continua){

      c= sigCaracter();

      switch (estado){
        case 0:
           if(c=='$')aceptacion(2);//fin de la entrada
            else
             if ( c == '+' || c=='-') aceptacion(3);//operadores de adicion
              else
                if(c=='*' || c=='/')aceptacion(4);//operadores de Multiplicacion
                 else
                  if(c=='=')sigEstado(5);//operador de Asignacion
                   else
                    if(c=='<' || c=='>') sigEstado(6);//operadores relacionales
                      else
                       if(c=='&') sigEstado(7);//operador logicoAND
                        else
                         if(c=='|')sigEstado(8);//operador logicoOR
                          else
                           if(c=='!') sigEstado(9);//operador logicoNOT
                           else
                            if(c=='(') aceptacion(10);//Parentesis Inicial
                             else
                              if(c==')')aceptacion(11);//Parentesis Final
                               else
                                if(c=='{')aceptacion(12);//Llave Inicial
                                 else
                                 if(c=='}')aceptacion(13);//Lave Final
                                  else
                                   if(c==';')aceptacion(14);//Punto y coma
                                    else
                                     if(esDigito(c)){
                                       banFloat=0;
                                       sigEstado(15);}//enteros y flotantes
                                     else
                                      if(esLetra(c))sigEstado(17);//ids y reservadas
                                       else
                                        if(c=='"') sigEstado(19); //cadenas
                                          //else
                                           //if(c=='.'){//flotante que empieza con punto
                                            //banFloat=0;
                                             //sigEstado(16);
                                              //}
                                             else
                                             if(c==',')aceptacion(20);//coma
                                              else
                                               if(!esEspacio(c)) aceptacion(1);//tofo lo diferente de espacio


             break;

             case 5:         if(c!='='){
                                c='\0'; retroceso();
                             aceptacion(5);//operador de Asignacion
                           }else aceptacion(21);//operador Igualdad
                             break;

             case 6:         if(c!='=')//operadores relacionales
                              {  c='\0'; retroceso();}
                             aceptacion(6);
                             break;

             case 7:         if(c!='&'){
                                c='\0'; retroceso();
                             aceptacion(1);//ERROR
                             }else
                             aceptacion(7);//operador logicoAND
                             break;

             case 8:        if(c!='|'){
                                c='\0';retroceso();
                             aceptacion(1);//ERROR
                             }else
                             aceptacion(8);//operador logicoOR
                             break;

             case 9:         if (c!='=') {
                                c='\0'; retroceso();
                             aceptacion(9);//operador logicoNOT
                             }else
                             if(c=='=')
                             aceptacion(21);//operador de Igualdad !=
                             break;

              case 15:       if(esDigito(c))sigEstado(15);//entero
                             else if(c=='.')sigEstado(16);//real
                             else{//cualquier otro simbolo
                             c='\0'; retroceso();
                             aceptacion(15);//se queda en entero
                             }
                             break;

              case 16:
                             if(esDigito(c)){//flotante
                             banFloat=1;//ya hay algo despues del punto
                             sigEstado(16);//sigue concatenando
                             }
                             else if(banFloat==0 && !esDigito(c)){//no hay nada despues del punto y el siguiente c no es digito
                             c='\0';
                             retroceso();
                             aceptacion(1);//error
                             }
                             else if(!esDigito(c)){//ya hay algo despues del punto pero no mas digitos
                             c='\0'; retroceso();
                             aceptacion(16);//real
                             }
                             break;

              case 17:       if(esLetra(c))sigEstado(17);//Identificadores
                             else if(esDigito(c))sigEstado(17);
                             else{
                             c='\0'; retroceso();
                             if(esReservada(simbolo)==1)
                             aceptacion(18);//reservadas
                             else
                             aceptacion(17);//Identificadores
                             }
                             break;

                case 19:    if(c!='"' && c!='$')//permite que se pase a la tercera condicion con el $
                            sigEstado(19);
                            else if(c=='"')aceptacion(19);//cadena
                            else if(terminado() && c=='$')aceptacion(1);//error toma el $ como fin de cadena
                            else sigEstado(19);//toma el $ como un caracter
                            break;



      }

   }
    //Fin del Automata

      switch (estado){//asigna Tipos
         case 1:
              tipo=TipoSimbolo::ERROR;
              break;
         case 2:
              tipo=TipoSimbolo::PESOS;
              break;
         case 3:
              tipo= TipoSimbolo::OPADIC;
              break;
         case 4:
              tipo=TipoSimbolo::OPMULT;
              break;
         case 5:
              tipo=TipoSimbolo::OPASIG;
              break;
         case 6:
              tipo=TipoSimbolo::OPRELAC;
              break;
         case 7:
              tipo=TipoSimbolo::OPAND;
              break;
         case 8:
              tipo=TipoSimbolo::OPOR;
              break;
         case 9:
              tipo=TipoSimbolo::OPNOT;
              break;
         case 10:
              tipo=TipoSimbolo::PARENTESIS1;
              break;
         case 11:
              tipo=TipoSimbolo::PARENTESIS2;
              break;
         case 12:
              tipo=TipoSimbolo::LLAVE1;
              break;
         case 13:
              tipo=TipoSimbolo::LLAVE2;
              break;
         case 14:
              tipo=TipoSimbolo::PUNTCOM;
              break;
         case 15:
             tipo=TipoSimbolo::ENTERO;
             break;
        case 16:
             tipo=TipoSimbolo::REAL;
             break;
        case 17:
              tipo=TipoSimbolo::IDENTIFICADOR;
              break;
       case 18:

              simbolo.resize(simbolo.size()-1);

              if(simbolo.compare("int")==0)tipo=TipoSimbolo::TIPO;
              else if(simbolo.compare("float")==0)tipo=TipoSimbolo::TIPO;
              else if(simbolo.compare("void")==0)tipo=TipoSimbolo::TIPO;
              else if(simbolo.compare("if")==0)tipo=TipoSimbolo::SI;
              else if(simbolo.compare("while")==0)tipo=TipoSimbolo::MIENTRAS;
              else if(simbolo.compare("return")==0)tipo=TipoSimbolo::REGRESA;
              else if(simbolo.compare("string")==0)tipo=TipoSimbolo::TIPO;
              else tipo=TipoSimbolo::SINO;
              break;

        case 19:
             tipo=TipoSimbolo::CADENA;
             break;
        case 20:
             tipo=TipoSimbolo::COMA;
             break;
        case 21:
             tipo=TipoSimbolo::OPIGUALDAD;
             break;

        default:
              tipo= TipoSimbolo::ERROR;
      }

	return tipo;
}

 char Lexico::sigCaracter(){//recorre las posiciones en el string
      if (terminado()) return '$';

      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){//asigna el estado actualizado
       this->estado= estado;
       simbolo+= c;
  }

  void Lexico::aceptacion(int estado){//deja de pasar a otros estados y manda asignar estado nuevo
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){
        return isalpha(c) || c=='_';
   }


   bool Lexico::esDigito(char c){
        return isdigit(c);
   }

   bool Lexico::esEspacio(char c){
        return c== ' ' || c== '\t';
   }

   int Lexico::esReservada(string simbolo){
         bool ban=0;

         if(simbolo=="int")         ban=1;
         else if(simbolo=="float")  ban=1;
         else if(simbolo=="void")   ban=1;
         else if(simbolo=="if")     ban=1;
         else if(simbolo=="while")  ban=1;
         else if(simbolo=="return") ban=1;
         else if(simbolo=="else")   ban=1;
         else if(simbolo=="string") ban=1;

         return ban;
       }



   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
