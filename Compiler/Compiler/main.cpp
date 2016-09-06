#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <sstream>


#include "lexico.h"
#include "nodo.h"
#include "Semantico.h"


using namespace std;


ofstream Nodo::datos("datos.asm");
ofstream Nodo::bss("bss.asm");
ofstream Nodo::text("text.asm");
int Nodo::numPrintf=0;
//FILE Nodo::f=fopen("datos.txt","w");

struct elemReglas{
    int id, longitud;
    string nombre;
};



void ejercicio3(string temp);
void cargaTabla();

int tabla[95][46];
struct elemReglas reglas[52];
string temp;
TablaSimbolos *Nodo::tablaSimbolos= NULL;
string Nodo::ambito= "";

int main(int argc, char *argv[]){

    cargaTabla();

    ifstream archivo("Pruebas.txt",ios::in);

    if(!archivo.is_open())
    cout << "Error al abrir el archivo Pruebas.txt" << endl;
    else{
    char c;

    while(!archivo.eof())
    {
        c=archivo.get();
        if(c!='\n' && c!='\r')
         temp+=c;

    }
    }
    archivo.close();
    cout<<temp<<endl<<endl;

    Nodo::datos<<"section .data"<<endl;
    Nodo::bss<<"section .bss"<<endl;
    Nodo::bss<<"res resb 1"<<endl;
    //Nodo::bss<<"num resb 5"<<endl;
    Nodo::text<<"section .text"<<endl;
    Nodo::text<<"global _start"<<endl;
    Nodo::text<<"_start:"<<endl;
    

    ejercicio3(temp);
     
    Nodo::text<<"mov eax,1;system pause"<<endl;
    Nodo::text<<"int 0x80"<<endl;

    
    Nodo::datos.close();
    Nodo::bss.close();
    Nodo::text.close();

    system("cat datos.asm bss.asm text.asm >program.asm");
    system("nasm -f elf program.asm");
    system("ld -m elf_i386 -s -o program program.o");
    system("./program");

    return 0;
}


void ejercicio3(string temp){

      Pila pila;
      ElementoPila *elemento;
      Nodo *nodo;
      NoTerminal *nt;
      Semantico semantico;

      int fila, columna, accion;
      bool aceptacion=false;
      Lexico lexico(temp);

      pila.push(new Terminal("$",2));//2
      pila.push(new Estado(0));

      lexico.sigSimbolo();

while (aceptacion==false) {//verificar si hay errores o el tama�o


      elemento=pila.top();
      fila=elemento->getEnteroT();
      cout<<"Fila:"<<fila<<endl;
      columna=lexico.tipo;
      cout<<"Columna:"<<lexico.tipo<<endl;
      accion=tabla[fila][columna];

      pila.muestra();
      cout << "entrada: " <<lexico.simbolo <<endl;
      cout << "accion: " << accion << endl<<endl;
      //cin.get();


      if(accion>0){

       pila.push(new Terminal(lexico.simbolo,lexico.tipo));
       pila.push(new Estado(accion));

      lexico.sigSimbolo();

      }else if(accion<0){
         if(accion==-1){
           aceptacion=true;
           cout << "aceptacion" << endl;

           pila.pop();
           pila.top()->nodo->muestra();

           semantico.analiza(pila.top()->nodo);
           //semantico.genCode(pila.top()->nodo);
        }else{

        int posArreglo=(accion*-1)-2;
        int reduce=reglas[posArreglo].longitud;

        switch (posArreglo+1) {
          case 1:
             pila.pop();
             nodo=pila.pop()->nodo;
             break;
          case 2:
             nodo=NULL;
             break;
          case 3:
             nodo= new Definiciones(&pila);
             break;
          case 4:
             pila.pop();
             nodo=pila.pop()->nodo;
             break;
          case 5:
             pila.pop();
             nodo=pila.pop()->nodo;
             break;
          case 6:
             nodo = new Defvar(&pila);
             break;
          case 7:
             nodo=NULL;
             break;
          case 8:
             nodo = new ListaVar(&pila);
             break;
          case 9:
             nodo = new DefFun(&pila);
             break;
          case 10:
             nodo=NULL;
             break;
          case 11:
             nodo = new Parametros(&pila);
             break;
          case 12:
             nodo=NULL;
             break;
          case 13:
             nodo = new ListaParametros(&pila);
             break;
          case 14:
              nodo = new BloqFuc(&pila);
              break;
          case 15:
              nodo=NULL;
              break;
          case 16:
              nodo = new DefinicionLocales(&pila);
              break;
          case 17:
              pila.pop();
              nodo=pila.pop()->nodo;
              break;
          case 18:
              pila.pop();
              nodo=pila.pop()->nodo;
              break;
          case 19:
              nodo=NULL;
              break;
          case 20:
              nodo = new Sentencias(&pila);
              break;
          case 21:
              nodo = new idEx(&pila);
              break;
          case 22:
              nodo = new Condicional(&pila);
              break;
          case 23:
              nodo = new Wh(&pila);
              break;
          case 24:
              nodo = new ValorRegresa(&pila);
              break;
          case 25:
              nodo=new LlamaFun(&pila);
              break;
          case 26:
              nodo=NULL;
              break;
          case 27:
             nodo= new Otro(&pila);
             break;
          case 28:
             nodo = new Bloque(&pila);
             break;
          case 29:
             nodo=NULL;
             break;
          case 30:
             pila.pop();
             nodo=pila.pop()->nodo;
             break;
          case 31:
             nodo=NULL;
             break;
          case 32:
             nodo = new Argumentos(&pila);
             break;
          case 33:
             nodo=NULL;
             break;
          case 34:
             nodo = new ListaArgumentos(&pila);
             break;
          case 35:
             pila.pop();
             nodo=pila.pop()->nodo;
             break;
          case 36:
             nodo = new Identificador(&pila);
             break;
          case 37:
             nodo = new Entero(&pila);
             break;
          case 38:
             nodo = new Real(&pila);
             break;
          case 39:
             nodo = new Cadena(&pila);
             break;
          case 40:
             nodo = new LlamadaFuncion(&pila);
             break;
          case 41:
              pila.pop();
              nodo = pila.pop()->nodo;
              break;
          case 42:
              pila.pop();
              nodo = pila.pop()->nodo;
              break;
          case 43://R43 <Expresion> ::= ( <Expresion> ) duda
              nodo = new Exp(&pila);
              break;
          case 44://opSuma <Expresion> duda
              nodo = new Acum(&pila);
              break;
          case 45://duda
              nodo = new opeNot(&pila);
              break;
          case 46:
             nodo = new opMulti(&pila);
             break;
          case 47:
             nodo = new opSuma(&pila);
             break;
          case 48:
             nodo = new opRelac(&pila);
             break;
          case 49:
             nodo = new opIgualdad(&pila);
             break;
          case 50:
             nodo = new opAnd(&pila);
             break;
          case 51:
             nodo = new opOr(&pila);
             break;
          case 52:
             pila.pop();
             nodo = pila.pop()->nodo;
             break;


          default:
          for(int i=0;i<reduce*2;i++)pila.pop();
        }

        cout<<"PILA POP: "<<endl;
        pila.muestra();


        elemento=pila.top();
        fila=elemento->getEnteroT();
        columna=reglas[posArreglo].id;
        accion=tabla[fila][columna];

        nt=new NoTerminal(reglas[posArreglo].nombre,reglas[posArreglo].id);
        nt->nodo=nodo;

        pila.push(nt);//cadena e id de archivo vectores
        pila.push(new Estado(accion));
        cout<<"PILA INSERTADA: "<<endl;
        pila.muestra();

        }
        }else break;//en caso de k sea 0 o error



}



}

void cargaTabla(){

  string str, token;
  stringstream instream;
  int x = 0, y = 0;

  ifstream file("compilador.lr");

  if(file.is_open()){

        getline(file, str);
        instream << str;
        instream >> x; /** cantidad de reglas **/
        instream.clear();


          for(int i = 0; i < x; i++){
          getline(file, str);
          instream << str;
          getline(instream, token, '\t');

          reglas[i].id = atoi(token.c_str());
          getline(instream, token, '\t');

          reglas[i].longitud = atoi(token.c_str());
          getline(instream, token, '\t');

          reglas[i].nombre = token;
          instream.clear();
        }

        getline(file, str);
        instream << str;
        getline(instream, token, '\t');
        x = atoi(token.c_str()); /** cantidad de filas reglas **/
        getline(instream, token, '\t');
        y = atoi(token.c_str()); /** cantidad de columnas reglas **/
        instream.clear();

        for(int i = 0; i < x; i++){
            getline(file, str);
            instream << str;
            for(int j = 0; j < y; j++){
                getline(instream, token, '\t');
                tabla[i][j] = atoi(token.c_str());
            }
            instream.clear();
        }
  }
  file.close();



}
