#ifndef ELEMENTOPILA_H_INCLUDED
#define ELEMENTOPILA_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;
class Nodo;

class ElementoPila{
protected:

public:
  Nodo *nodo;
  virtual void muestra(){}
  virtual int getEnteroT(){return -1999;}
};

class Terminal:public ElementoPila{
  protected:
  int enteroT;

  public:
  string eTerminal;
  Terminal(string eTerminal,int enteroT){
     this->eTerminal=eTerminal;
     this->enteroT=enteroT;
  }

  void muestra(){
   cout<<" "<<eTerminal;

  }


  int getEnteroT(){
         return this->enteroT;
  }





};

class NoTerminal:public ElementoPila{
protected:
  int enteroNT;
  //string eNoTerminal;
public:
  string eNoTerminal;
  NoTerminal(string eNoTerminal,int enteroNT){
     this->eNoTerminal=eNoTerminal;
     this->enteroNT=enteroNT;
  }

   void muestra(){
   cout<<" "<<eNoTerminal;

  }


  int getEnteroT(){
         return this->enteroNT;
  }




};

class Estado:public ElementoPila{
protected:
  int EstadoP;
public:
  Estado(int EstadoP){
      this->EstadoP=EstadoP;
  }

   void muestra(){

   cout<<" "<<EstadoP;

  }


  int getEnteroT(){
         return this->EstadoP;
  }




};


#endif // ELEMENTOPILA_H_INCLUDED
