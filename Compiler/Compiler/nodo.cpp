#include "nodo.h"



void Nodo::sangria(){
      for (int i=0; i< tamSangria; i++) cout << " ";
}

char Nodo::dimeTipo(string simbolo){

      if(simbolo.compare("int")==0)return 'i';
      if(simbolo.compare("float")==0)return 'f';
      if(simbolo.compare("string")==0)return 's';
      if(simbolo.compare("void")==0)return 'v';

      return 'u';
}

Definiciones::Definiciones(Pila *pila){
    pila->pop();
    this->aux=(Definiciones*)((pila->pop())->nodo);

    pila->pop();
    this->aux2=(Definicion*)((pila->pop())->nodo);
}

void Definiciones::muestra(){
            tamSangria=0;
            
             cout <<"<Definicion>"<<endl;
             if(aux2!= NULL){
               aux2->tamSangria=tamSangria+1;
               aux2 -> muestra();
             }

             cout <<"<Definiciones>" <<endl;
             if(aux != NULL){
               aux->tamSangria=tamSangria+1;
               aux->muestra();
             }
}

void Definiciones::validaTipo(){
            tipoDato='v';
            cout<<"Valido Tipo Definiciones"<<endl;
            if(aux2!=NULL){aux2->validaTipo();}
            if(aux!=NULL){aux->validaTipo();}

}

void Definiciones::generaCodigo(){
            cout<<"Definiciones"<<endl;
        
            numPrintf=0;

            if(aux2!=NULL){
              aux2->generaCodigo();
             
            }
            if(aux!=NULL){
              aux->generaCodigo();
              
            }

}

 DefinicionLocales::DefinicionLocales(Pila *pila){
      pila->pop();
      this->DF=(DefinicionLocales*)((pila->pop())->nodo);

      pila->pop();
      this->df=(DefLocal*)((pila->pop())->nodo);
}

void DefinicionLocales::muestra(){

     sangria();
     cout<<"<DefLocal>"<<endl;
            if(df != NULL){
               df->tamSangria=tamSangria+1;
               df -> muestra();
            }

     sangria();
     cout <<"<DefLocales>"<<endl;
            if(DF != NULL){
            DF->tamSangria=tamSangria+1;
            DF -> muestra();
            }

}

void DefinicionLocales::validaTipo(){
          cout<<"Definiciones Locales validaTipo"<<endl;
          tipoDato='v';
          if(df!=NULL){df->validaTipo();}
          if(DF!=NULL){DF->validaTipo();}
}

void DefinicionLocales::generaCodigo(){
          cout<<"DefinicionLocales"<<endl;

          if(df!=NULL){
            df->generaCodigo();
          }
          if(DF!=NULL){
            DF->generaCodigo();
          }
}


BloqFuc::BloqFuc(Pila *pila){
        pila->pop();
        this->cierra=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->DF=(DefinicionLocales*)((pila->pop())->nodo);

        pila->pop();
        this->abre=((Terminal*)pila->pop())->eTerminal;

}

void BloqFuc::muestra(){

            sangria();
            cout <<"<Llave Abre>"<<" "<<abre<<endl;

            sangria();
            cout <<"<DefLocales>"<<endl;
            if(DF != NULL){
            DF->tamSangria=tamSangria+1;
            DF -> muestra();
            }

            sangria();
            cout <<"<Llave Cierra>  "<<cierra<<endl;
}


void BloqFuc::validaTipo(){
            tipoDato='v';
            cout<<"Valido Tipo BloqFuc"<<endl;
            if(DF!=NULL){
              DF->validaTipo();

            }
}

void BloqFuc::generaCodigo(){

             cout<<"BloqFuc"<<endl;
            if(DF!=NULL){
              DF->generaCodigo();
            }
}

Sentencias::Sentencias(Pila *pila){
        pila->pop();
        this->St=(Sentencias*)((pila->pop())->nodo);

        pila->pop();
        this->st=(Sentencia*)((pila->pop())->nodo);
      }

void Sentencias::muestra(){


      sangria();
      cout<<"<Sentencia>"<<endl;
            if(st !=NULL){
              st->tamSangria=tamSangria+1;
              st->muestra();
            }

      sangria();
      cout<<"<Sentencias>"<<endl;
            if(St !=NULL){
              St->tamSangria=tamSangria+1;
              St->muestra();
            }



}

void Sentencias::validaTipo(){
          cout<<"Valida Tipo Sentencias"<<endl;
          tipoDato='v';
          if(st!=NULL)st->validaTipo();
          if(St!=NULL)St->validaTipo();


}

void Sentencias::generaCodigo(){
          cout<<"Sentencias"<<endl;
          if(st!=NULL){
            st->validaTipo();
        
          }
          if(St!=NULL){
            St->generaCodigo();
        
          }
}

Bloque::Bloque(Pila *pila){
    pila->pop();
    this->cierra=((Terminal*)pila->pop())->eTerminal;

    pila->pop();
    this->sent=(Sentencias*)((pila->pop())->nodo);

    pila->pop();
    this->abre=((Terminal*)pila->pop())->eTerminal;
}


void Bloque::muestra(){

      sangria();
      cout<<"<Llave Abre> "<<abre<<endl;

      sangria();
      cout<<"<Sentencias> "<<endl;
      if(sent != NULL){
      sent ->tamSangria=tamSangria+1;
      sent -> muestra();
      }

      sangria();
      cout<<"<Llave Cierra>"<<cierra<<endl;

}

void Bloque::validaTipo(){
     tipoDato='v';
     cout<<"Valida Tipo Bloque"<<endl;

     if(sent!=NULL)sent->validaTipo();

}

void Bloque::generaCodigo(){

     cout<<"Bloque"<<endl;
     if(sent!=NULL){
      sent->generaCodigo();
  
    }
}

ValorRegresa::ValorRegresa(Pila *pila){
      pila->pop();
      this->puntocoma=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->vR=(ValorRegresa*)((pila->pop())->nodo);

      pila->pop();
      this->palabra=((Terminal*)pila->pop())->eTerminal;

}

void ValorRegresa::muestra(){

      sangria();
      cout<<"<Valor Regresa> "<<palabra<<endl;

      sangria();
      cout<<"<Valores>"<<endl;
      if(vR != NULL){
      vR->tamSangria=tamSangria+1;
      vR -> muestra();
      }

      sangria();
      cout<<"<PuntoComa> "<<puntocoma<<endl;

}

void ValorRegresa::validaTipo(){
      tipoDato='v';
      cout<<"Valida Tipo Valor regresa"<<endl;
      //cout<<"Funcion pertenezco"<<this->ambito<<endl;
      if(vR!=NULL){
            vR->validaTipo();
      }

       tablaSimbolos->buscaFuncion(this->ambito);

           if(tablaSimbolos->varGlobal!=NULL){
              this->tipoDato=tablaSimbolos->varGlobal->tipo;
           }else if(tablaSimbolos->varLocal!=NULL){
              this->tipoDato=tablaSimbolos->varLocal->tipo;
           }else{
              this->tipoDato=tablaSimbolos->funcion->tipo;
           }

       if(this->tipoDato=='i' && vR->tipoDato==this->tipoDato){ this->tipoDato='i';}
        else if(this->tipoDato=='i' && vR->tipoDato==this->tipoDato){ this->tipoDato='f';}
         else if(this->tipoDato=='s' && vR->tipoDato==this->tipoDato){ this->tipoDato='s';}
          else {  this->tipoDato='u';
                  Nodo::tablaSimbolos->listaErrores->push_back("Error: en tipo de retorno de la funcion \""+this->ambito+"\"");
               }


}

void ValorRegresa::generaCodigo(){

        cout<<"ValorRegresa"<<endl;
        if(vR!=NULL){
          vR->generaCodigo();
          
        }

}

Defvar::Defvar(Pila *pila){
        pila->pop();
        this->puntComa=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->lista=(ListaVar*)((pila->pop())->nodo);

        pila->pop();
        this->identificador=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->tipo=((Terminal*)pila->pop())->eTerminal;

}

void Defvar::muestra() {

        sangria();
        cout<<"<DefVar>"<<endl;
        sangria();
        cout<<"<Tipo>"<<" "<<tipo<<endl;
        sangria();
        cout<<"<Identificador>"<<" "<<identificador<<endl;
        sangria();
        cout<<"<ListaVar>"<<endl;
        if (lista != NULL) {
        lista->tamSangria=tamSangria+1;
        lista -> muestra();
        }
        sangria();
        cout<<"<PuntComa> "<<puntComa<<endl;
}


void Defvar::validaTipo(){
            cout<<"Valida Tipo Defvar"<<endl;
            tipoDato=this->dimeTipo(this->tipo);//o solo tomarlo del tipo
            //tablaSimbolos->agrega(this);esto no

        if(this->ambito.compare("")==0){
        //cout<<"Entro"<<endl;
            if(tablaSimbolos->varGlobalDefinida(this->identificador)==false)
                tablaSimbolos->agrega(this);
            else{
            Nodo::tablaSimbolos->listaErrores->push_back("Error: variable Global Repetida \"" + this->identificador + "\" redefinida");
                }
        }else{
          if(tablaSimbolos->varLocalDefinida(this->identificador,this->ambito)==false)
            tablaSimbolos->agrega(this);
            else{ //cout<<"Variable Local Repetida"<<endl;
             Nodo::tablaSimbolos->listaErrores->push_back("Error: variable Local Repetida \"" + this->identificador + "\" redefinida");
            }
        }

            if(lista!=NULL){
                    lista->tipoDato=this->tipoDato;
                    lista->validaTipo();
            }

}

void Defvar::generaCodigo(){

            cout<<"Defvar"<<endl;

            if(lista!=NULL){
              lista->generaCodigo();
          
            }
}


Wh::Wh(Pila *pila){
      pila->pop();
      this->bloque=(Bloque*)((pila->pop())->nodo);

      pila->pop();
      this->cierra=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->expresion=(Expresion*)((pila->pop())->nodo);

      pila->pop();
      this->abre=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->palabra=((Terminal*)pila->pop())->eTerminal;


}


void Wh::muestra(){
     sangria();
     cout<<"<Sentencia> "<<palabra<<endl;
     sangria();
     cout<<"<Parentesis Abre> "<<abre<<endl;
     sangria();
     cout<<"<Expresion>"<<endl;
     if(expresion !=NULL){
       expresion->tamSangria=tamSangria+1;
       expresion->muestra();
     }
     sangria();
     cout<<"<Parentesis Cierra> "<<cierra<<endl;
     sangria();
     cout<<"<Bloque>"<<endl;
     if(bloque !=NULL){
       bloque -> tamSangria= tamSangria+1;
       bloque -> muestra();
     }

}

void Wh::validaTipo(){
      tipoDato='v';
      cout<<"Valida Tipo While"<<endl;
      if(expresion!=NULL){
            expresion->validaTipo();
            //cout<<"Tipo Expresion"<<expresion->tipoDato<<endl;
      }

       if(expresion->tipoDato=='u')
             Nodo::tablaSimbolos->listaErrores->push_back("Error: Variables de diferente tipo el while");
      if(bloque!=NULL)bloque->validaTipo();

}

void Wh::generaCodigo(){


      cout<<"While"<<endl;

      if(expresion!=NULL){
        expresion->generaCodigo();
        
      }

      if(bloque!=NULL){
        bloque->generaCodigo();
        
      }

}

Otro:: Otro(Pila *pila){
      pila->pop();
      this->SB=(SentenciaBloque*)((pila->pop())->nodo);

      pila->pop();
      this->palabra = ((Terminal*)pila->pop())->eTerminal;
    }

void Otro::muestra() {

      sangria();
      cout<<"<Sentencia> "<<palabra<<endl;
      sangria();
      cout<<"<SentenciaBloque> "<<endl;
      if(SB != NULL){
       SB->tamSangria=tamSangria+1;
       SB->muestra();
    }
}

void Otro::validaTipo(){
      tipoDato='v';
      cout<<"Valida Tipo Otro"<<endl;
      if(SB!=NULL)SB->validaTipo();

}

void Otro::generaCodigo(){

      cout<<"Otro"<<endl;
      if(SB!=NULL){
        SB->generaCodigo();
        
      }
}

Condicional::Condicional(Pila *pila){

      pila->pop();
      this->otro = (Otro*)((pila->pop())->nodo);

      pila->pop();
      this->SB = (SentenciaBloque*)((pila->pop())->nodo);

      pila->pop();
      this->cierra=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->expresion = (Expresion*)((pila->pop())->nodo);

      pila->pop();
      this->abre=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->condicion=((Terminal*)pila->pop())->eTerminal;


}


 void Condicional::muestra() {

        sangria();
        cout<<"<Condicion> "<<condicion<<endl;
        sangria();
        cout<<"<Abre> "<<abre<<endl;
        sangria();

        cout<<"<Expresion>"<<endl;
        if(expresion != NULL){
        expresion->tamSangria=tamSangria+1;
        expresion->muestra();
        }

        sangria();
        cout<<"<Cierra> "<<cierra<<endl;

        sangria();
        cout<<"<SentenciaBloque>"<<endl;
        if(SB != NULL){
        SB -> tamSangria= tamSangria+1;
        SB -> muestra();
        }

        sangria();
        cout<<"<Otro>"<<endl;
        if(otro != NULL){
        otro -> tamSangria=tamSangria+1;
        otro -> muestra();
        }
}

void Condicional::validaTipo(){
      tipoDato='v';
      cout<<"Valida Tipo Condicional"<<endl;
      if(expresion!=NULL){

            expresion->validaTipo();
            //cout<<"Tipo Dato Expresion"<<expresion->tipoDato<<endl;
      }

      if(expresion->tipoDato=='u')
             Nodo::tablaSimbolos->listaErrores->push_back("Error: Variables de diferente tipo en Condicional");

      if(SB!=NULL)SB->validaTipo();
      if(otro!=NULL)otro->validaTipo();



}

void Condicional::generaCodigo(){

     cout<<"Condicional"<<endl;

     if(expresion!=NULL){
      expresion->generaCodigo();
  
    }
     if(SB!=NULL){
      SB->generaCodigo();
  
    }
     if(otro!=NULL){
      otro->generaCodigo();
    
    }
}


ListaArgumentos::ListaArgumentos(Pila *pila){
      pila->pop();
      this->LA=(ListaArgumentos*)((pila->pop())->nodo);

      pila->pop();
      this->expresion=(Expresion*)((pila->pop())->nodo);

      pila->pop();
      this->coma=((Terminal*)pila->pop())->eTerminal;
    }

void ListaArgumentos::muestra(){
      sangria();
      cout<<"<Coma> "<<coma<<endl;
      sangria();
      cout<<"<Expresion>"<<endl;
      if(expresion != NULL){
      expresion->tamSangria=tamSangria+1;
      expresion->muestra();
      }
      sangria();
      cout<<"<ListaArgumentos>"<<endl;
      if(LA != NULL){
      LA -> tamSangria=tamSangria+1;
      LA -> muestra();
      }

}

void ListaArgumentos::validaTipo(){
    tipoDato='v';
    cout<<"ListaArgumentos"<<endl;
    if(expresion!=NULL){
            //cout<<"Expresion Lista Arumentos"<<endl;
            expresion->validaTipo();
            this->aux=expresion->tipoDato;
            //cout<<"Aux"<<this->aux<<endl;
    }
    if(LA!=NULL){
            LA->validaTipo();
            this->aux+=LA->aux;
    }
}

void ListaArgumentos::generaCodigo(){

      cout<<"ListaArgumentos"<<endl;

      if(expresion!=NULL){

        if(expresion->esTer()){
            Termino *T = (Termino*)expresion;
          
            cout<<"Termino Recuperado:"<<T->retTer()<<endl;


            text<<"mov eax,4"<<endl;
            text<<"mov ebx,1"<<endl;
            text<<"mov ecx, res"<<endl;
            text<<"mov edx, 1"<<endl;
            text<<"int 0x80"<<endl;

            //text<<"mov eax,1;system pause"<<endl;
            //text<<"int 0x80"<<endl;

         }else{
             expresion->generaCodigo();
         }
      }
      if(LA!=NULL){LA->generaCodigo();}
}

Argumentos::Argumentos(Pila *pila){
      pila->pop();
      this->LA=(ListaArgumentos*)((pila->pop())->nodo);

      pila->pop();
      this->expresion=(Expresion*)((pila->pop())->nodo);

}

void Argumentos::muestra() {

       sangria();
       cout<<"<Expresion> "<<endl;
       if(expresion != NULL){
       expresion -> tamSangria=tamSangria+1;
       expresion -> muestra();
       }
       sangria();
       cout<<"<ListaArgumentos>"<<endl;
       if(LA != NULL){
       LA -> tamSangria=tamSangria+1;
       LA -> muestra();
       }
}

void Argumentos::validaTipo(){
      tipoDato='v';
      cout<<"Valida Argumentos"<<this->ambito<<endl;
       if(expresion!=NULL){
            //cout<<"Expresion Argumentos"<<endl;

            expresion->validaTipo();
            this->aux=expresion->tipoDato;
            //cout<<"Tipo Dato Ex"<<expresion->tipoDato<<endl;
       }
       if(LA!=NULL){
            //cout<<"LA Argumentos"<<endl;
            LA->validaTipo();
            this->aux+=LA->aux;

       }
       //cout<<"Tipo Dato Ex Final"<<this->aux<<endl;

}

void Argumentos::generaCodigo(){


      cout<<"Argumentos"<<endl;
      
  

      if(expresion->esTer()){
            Termino *T = (Termino*)expresion;
          
            cout<<"Termino Recuperado:"<<T->retTer()<<endl;
            
            
            datos<<"msg1"<<numPrintf<<" db 0xA,0xD,"<<T->retTer()<<endl;;
            datos<<"len1"<<numPrintf<<" equ $ - msg1"<<numPrintf<<endl;
            


            text<<";-----------imprime mensajes"<<endl;

            text<<"mov eax,4"<<endl;
            text<<"mov ebx,1"<<endl;
            text<<"mov ecx, msg1"<<numPrintf<<endl;
            text<<"mov edx, len1"<<numPrintf<<endl;
            text<<"int 0x80"<<endl;

            numPrintf+=1;

         }else{
             expresion->generaCodigo();
         }
      
      if(LA!=NULL){
        LA->generaCodigo();
      }
}

ListaParametros:: ListaParametros(Pila *pila){
        pila->pop();
        this->lista=(ListaParametros*)((pila->pop())->nodo);

        pila->pop();
        this->id=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->tipo=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->coma=((Terminal*)pila->pop())->eTerminal;

}

void ListaParametros::muestra() {
        sangria();
        cout<<"<Coma> "<<coma<<endl;
        sangria();
        cout<<"<Tipo>"<<tipo<<endl;
        sangria();
        cout<<"<Identificador>"<<endl;
        cout<<id<<endl;
        sangria();
        cout<<"<ListaParametros>"<<endl;
        if(lista != NULL){
        lista -> tamSangria=tamSangria+1;
        lista->muestra();
        }
}

void ListaParametros::validaTipo(){
       tipoDato='v';

       cout<<"Valida Tipo Lista Parametros1"<<endl;
       this->aux+=this->tipo[0];
       //fcout<<"Tipo Para Lista"<<this->aux<<endl;

       //cout<<"PTipo listaAntes"<<this->tipo<<endl;
       //cout<<"PId listaAntes"<<this->id<<endl;

       tipoDato=this->dimeTipo(this->tipo);//o solo tomarlo del tipo

       Parametros *n= new Parametros(this->tipo,this->id,this->ambito);
       //cout<<"PTipo lista"<<n->tipo<<endl;
       //cout<<"PId lista"<<n->id<<endl;
       //cout<<"lista"<<n->lista<<endl;
       //cout<<"coma"<<n->coma<<endl;
       tablaSimbolos->agrega(n);

       if(lista!=NULL){
            lista->aux=this->aux;
            lista->validaTipo();
            this->aux=lista->aux;
       }


}

void ListaParametros::generaCodigo(){
      cout<<"ListaParametros"<<endl;

      if(lista!=NULL){lista->generaCodigo();}

}

Parametros:: Parametros(Pila *pila){
        pila->pop();
        this->lista=(ListaParametros*)((pila->pop())->nodo);

        pila->pop();
        this->id=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->tipo=((Terminal*)pila->pop())->eTerminal;

}

Parametros::Parametros(string tipo, string id, string ambito){

       this->tipo=tipo;
       this->id=id;
       this->lista=NULL;
       this->ambito=ambito;

}

void Parametros::muestra() {
        sangria();
        cout<<"<Parametros>"<<endl;
        sangria();
        cout<<"<Tipo> "<<tipo<<endl;
        sangria();
        cout<<"<Identificador>"<<id<<endl;
        sangria();
        cout<<"<ListaParametros>"<<endl;
        if(lista != NULL){
        lista-> tamSangria=tamSangria+1;
        lista-> muestra();
        }

}




void Parametros::validaTipo(){
       cout<<"Valida Tipo Parametros"<<endl;
       this->aux="";

       this->aux+=this->tipo[0];
       //cout<<"Tipo Para"<<this->aux<<endl;
       tipoDato=this->dimeTipo(this->tipo);//o solo tomarlo del tipo
       tablaSimbolos->agrega(this);
       //this->aux+=this->tipo[0];
       //cout<<"Tipo Para"<<this->aux<<endl;

       if(lista!=NULL){
            lista->aux=this->aux;
            lista->validaTipo();
            this->aux=lista->aux;
       }

       //cout<<"Tipo Para2"<<this->aux<<endl;

}

void Parametros::generaCodigo(){
      cout<<"Parametros"<<endl;

      if(lista!=NULL){lista->generaCodigo();}

}

DefFun::DefFun(Pila *pila){


        pila->pop();
        this->bloque=(BloqFuc*)((pila->pop())->nodo);

        pila->pop();
        this->cierra=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->parametros=(Parametros*)((pila->pop())->nodo);

        pila->pop();
        this->abre=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        //this->identificador=(Identificador*)((pila->pop())->nodo);
        this->identificador=((Terminal*)pila->pop())->eTerminal;


        pila->pop();
        this->tipo=((Terminal*)pila->pop())->eTerminal;
}


void DefFun::muestra(){

         sangria();
         cout<<"<DefFun>"<<endl;

         sangria();
         cout<<"<Tipo>"<<" "<<tipo<<endl;
         sangria();
         cout<<"<Identificador>"<<" "<<identificador<<endl;
         sangria();
         cout<<"<Parentesis Abre>"<<"  "<<abre<<endl;
         sangria();
         cout<<"<Parametros>"<<endl;
         if(parametros != NULL){
         parametros->tamSangria=tamSangria+1;
         parametros -> muestra();
         }
         sangria();
         cout<<"<Parentesis Cierra>"<<" "<<cierra<<endl;
         sangria();
         cout<<"<BloqFunc>"<<endl;
         if(bloque != NULL)
         bloque->tamSangria=tamSangria+1;
         bloque -> muestra();

}


void DefFun::validaTipo(){
        this->ambito="";
        cout<<"Valida Tipo DefFun"<<this->identificador<<"ambito"<<this->ambito<<endl;

        tipoDato=this->dimeTipo(this->tipo);//o solo tomarlo del tipo

        /*if(this->ambito.compare("")==0){
           if(tablaSimbolos->funcionDefinida(this->identificador)==0)
               tablaSimbolos->agrega(this);
               else cout<<"Funcion Previamente Definida"<<endl;

        }*/

        if(parametros!=NULL){
                parametros->ambito=this->identificador;
                parametros->validaTipo();
                this->aux=parametros->aux;
                //cout<<"Parametros Defun:"<<this->aux<<endl;
        }

        //cout<<"Ambito Funcion"<<this->ambito<<endl;
        this->ambito="";
        if(this->ambito.compare("")==0){

           if(tablaSimbolos->funcionDefinida(this->identificador)==0)
               tablaSimbolos->agrega(this);
               else{ //cout<<"Funcion Previamente Definida"<<endl;
                Nodo::tablaSimbolos->listaErrores->push_back("Error: Funcion previamente definida \"" + this->identificador + "\" redefinida");
               }

        }

        if(bloque!=NULL){
                bloque->ambito=this->identificador;
                bloque->validaTipo();
        }

        //tablaSimbolos->agrega(this);

        this->ambito="";


}

void DefFun::generaCodigo(){
     cout<<"DefFun"<<endl;

     if(parametros!=NULL){parametros->generaCodigo();}
     if(bloque!=NULL){bloque->generaCodigo();}

}

ListaVar::ListaVar(Pila *pila){

      pila->pop();
      this->lista=(ListaVar*)((pila->pop())->nodo);

      pila->pop();
      this->identificador=((Terminal*)pila->pop())->eTerminal;

      pila->pop();
      this->coma=((Terminal*)pila->pop())->eTerminal;

}

void ListaVar::muestra(){


        sangria();
        cout<<"<Coma> "<<coma<<endl;

        sangria();
        cout<<"<Identificador> "<<identificador<<endl;

        sangria();
        cout<<"<ListaVar>"<<endl;
        if(lista != NULL){
        lista -> tamSangria=tamSangria+1;
        lista -> muestra();
        }
}

void ListaVar::validaTipo(){
      cout<<"Valida Tipo ListaVar"<<endl;

      //cout<<this->tipoDato<<endl;
      //cout<<this->identificador<<endl;

      Defvar *n=(Defvar*)this;
      if(n->ambito.compare("")==0){
        //cout<<"Entro"<<endl;
        if(tablaSimbolos->varGlobalDefinida(n->identificador)==false)
            tablaSimbolos->agrega(n);
        else{
        Nodo::tablaSimbolos->listaErrores->push_back("Error: variable Global Repetida \"" + n->identificador + "\" redefinida");
            }
        }else{
          if(tablaSimbolos->varLocalDefinida(n->identificador,n->ambito)==false)
            tablaSimbolos->agrega(n);
            else{ //cout<<"Variable Local Repetida"<<endl;
             Nodo::tablaSimbolos->listaErrores->push_back("Error: variable Local Repetida \"" + n->identificador + "\" redefinida");
            }
        }

      if(lista!=NULL){
            lista->tipoDato=this->tipoDato;
            lista->validaTipo();
      }

}

void ListaVar::generaCodigo(){

      cout<<"ListaVar"<<endl;
      if(lista!=NULL){lista->generaCodigo();}

}

LlamadaFuncion::LlamadaFuncion(Pila *pila){
        pila->pop();
        this->cierra=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->Ar=(Argumentos*)((pila->pop())->nodo);

        pila->pop();
        this->abre=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->Id=((Terminal*)pila->pop())->eTerminal;
        //this->Id=(Identificador*)((pila->pop())->nodo);


}

void LlamadaFuncion::muestra(){
        sangria();
        cout<<"<Identificador> "<<Id<<endl;
        sangria();
        cout<<"<Parentesis Abre> "<<abre<<endl;
        sangria();
        cout<<"<Argumentos> "<<endl;
        if(Ar != NULL){
        Ar -> tamSangria=tamSangria+1;
        Ar -> muestra();
        }

        sangria();
        cout<<"<Parentesis Cierra>"<<cierra<<endl;

}

void LlamadaFuncion::validaTipo(){
        cout<<"Valida Tipo LlamadaFuncion"<<endl;
        tipoDato='v';


        if(Ar!=NULL){
                cout<<"Entro a Argumentos"<<endl;
                Ar->validaTipo();
               //cout<<"Tipo Recuperado"<<Ar->aux<<endl;
        }

        this->Id.resize(this->Id.size()-1);
        if(this->Id.compare("printf")==0 || this->Id.compare("scanf")==0){

         cout<<"EStoy en printf o scanf"<<endl;
        
        }else{

        if(Ar!=NULL){
        tablaSimbolos->buscaFuncion(this->Id);

        if(tablaSimbolos->funcion!=NULL){
            cout<<"Parametros Recuperados"<<tablaSimbolos->funcion->parametros<<endl;
            this->aux=tablaSimbolos->funcion->parametros;


        }else{
           Nodo::tablaSimbolos->listaErrores->push_back("Error: Funcion No Definida \""+this->Id+"\"");
        }

        if(this->aux==Ar->aux){
            //cout<<"Correcto"<<endl;
            this->tipoDato=tablaSimbolos->funcion->tipo;
        }else{
            this->tipoDato='u';
            Nodo::tablaSimbolos->listaErrores->push_back("Error: el tipo de parametros no coincide en la llamada a funcion \""+this->Id+"\"");
        }

        this->msn="Llamada a Funcion "+this->Id;

       }else{

         tablaSimbolos->buscaFuncion(this->Id);

        if(tablaSimbolos->funcion!=NULL){
            cout<<"Funcion Encontrada"<<endl;
            

        }else{
           Nodo::tablaSimbolos->listaErrores->push_back("Error: Funcion No Definida \""+this->Id+"\"");
        }

        this->msn="Llamada a Funcion "+this->Id;

       }
    }
}

void LlamadaFuncion::generaCodigo(){
   cout<<"LlamadaFuncion"<<endl;

   //this->Id.resize(Id.size()-1);
  
   if(this->Id.compare("printf")==0){ 
    cout<<"Soy llamada a printf"<<endl;    
   
   if(Ar!=NULL){
           Ar->generaCodigo();
     
    }
  }else if(this->Id.compare("scanf")==0){ 
    cout<<"Soy llamada a scanf"<<endl;    
   
  /* if(Ar!=NULL){
           Ar->generaCodigo();
     
  }*/
    //Nodo::bss<<"num"<<numPrintf-1<<" resb 5"<<endl;

    text<<"mov eax,3"<<endl;
    text<<"mov ebx,2;leer"<<endl;
    //text<<"mov ecx,num"<<numPrintf-1<<endl; 
    text<<"mov ecx,res"<<endl;
    text<<"mov edx,5;lecturas"<<endl;
    text<<"int 0x80"<<endl;

  }


   
   //if(Ar!=NULL){Ar->generaCodigo();}
}


LlamaFun::LlamaFun(Pila *pila)
{
       pila->pop();
       this->puntocoma=((Terminal*)pila->pop())->eTerminal;

       pila->pop();
       this->llama=(LlamadaFuncion*)((pila->pop())->nodo);
}


void LlamaFun::muestra(){

    sangria();
    cout<<"<LlamadaFuncion> "<<endl;
    if(llama != NULL){
    llama -> tamSangria=tamSangria+1;
    llama -> muestra();
    }

    sangria();
    cout<<"<PuntoComa> "<<puntocoma<<endl;
}


void LlamaFun::validaTipo(){

     //cout<<"Valida Tipo LlamaFun"<<endl;
     tipoDato='v';

    if(llama!=NULL)llama->validaTipo();
}

void LlamaFun::generaCodigo(){

    cout<<"LlamaFun"<<endl;
    if(llama!=NULL)llama->generaCodigo();
}


idEx::idEx(Pila *pila){

       pila->pop();
       this->puntComa=((Terminal*)pila->pop())->eTerminal;

       pila->pop();
       this->expresion=(Expresion*)((pila->pop())->nodo);

       pila->pop();
       this->asignacion=((Terminal*)pila->pop())->eTerminal;

       pila->pop();
       this->id=((Terminal*)pila->pop())->eTerminal;

}

void idEx::muestra() {

        sangria();
        cout<<"<Identificador> "<<id<<endl;
        sangria();
        cout<<"<Asignacion> "<<asignacion<<endl;

        sangria();
        cout<<"<Expresion> "<<endl;
        if(expresion != NULL){
        expresion -> tamSangria=tamSangria+1;
        expresion -> muestra();
        }
        sangria();
        cout<<"<PuntComa> "<<puntComa<<endl;
}

void idEx::validaTipo(){
       string auxMsn;
       expresion->msn="Asignacion";
       //cout<<"Valida Tipo Exp"<<endl;
       if(expresion!=NULL){

            expresion->validaTipo();
       }

      // if(expresion->tipoDato=='u'){
             //this->auxError=expresion->auxError;
        //     Nodo::tablaSimbolos->listaErrores->push_back("Error: Variables de diferente tipo redefinida");
       //}

       tablaSimbolos->buscaIdentificador(this->id,this->ambito);

       if(tablaSimbolos->varGlobal!=NULL){

             this->tipoDato=tablaSimbolos->varGlobal->tipo;

       }else if(tablaSimbolos->varLocal!=NULL){
             //cout<<"Tipo Int b "<<tablaSimbolos->varLocal->tipo<<endl;
             this->tipoDato=tablaSimbolos->varLocal->tipo;

       }else if(tablaSimbolos->funcion!=NULL){

             this->tipoDato=tablaSimbolos->funcion->tipo;
       }else if(tablaSimbolos->parametro!=NULL){

             this->tipoDato=tablaSimbolos->parametro->tipo;
       }else{
             tablaSimbolos->buscaIdentificador(this->id,"");

             if(tablaSimbolos->varGlobal!=NULL){
              this->tipoDato=tablaSimbolos->varGlobal->tipo;
              }else{
                  Nodo::tablaSimbolos->listaErrores->push_back("Error: Variable no Definida \""+this->id+"\"");
                  this->tipoDato='u';
              }
       }

       if(this->tipoDato!=expresion->tipoDato || expresion->tipoDato=='u'){
        //cout<<"Tipo Dato Expresion "<<this->tipoDato<<"Tipo Dato Asigna "<<expresion->tipoDato<<endl;
        //this->tipoDato='u';
        //Nodo::tablaSimbolos->listaErrores->push_back("Error: Variables de diferente tipo en "+expresion->msn);

        if(this->tipoDato=='i')
        auxMsn=" a un entero \""+this->id+"\"";
        else if(this->tipoDato=='s')
        auxMsn=" a un string \""+this->id+"\"";
        else if(this->tipoDato=='f')
        auxMsn=" a un flotante \""+this->id+"\"";
        else //u
        auxMsn=" a un no definido \""+this->id+"\"";

        Nodo::tablaSimbolos->listaErrores->push_back("Error: Variables de diferente tipo en "+expresion->msn+auxMsn);

        this->tipoDato='u';

       }

}

void idEx::generaCodigo(){

      
     
     cout<<"idEx"<<endl;

     //bss<<"res resb 1"<<endl;

    

    if(expresion != NULL){
        if(expresion->esTer()){
            Termino *T = (Termino*)expresion;

            cout<<"Elemento Recuperado:"<<T->retTer()<<endl;
            //text<<"mov ["<<this->id<<"],"<<T->retTer()<<endl;
        }
        else{
            expresion->generaCodigo();
        }
    }
  
}


 Exp::Exp(Pila *pila){
        pila->pop();
        this->cierra=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);

        pila->pop();
        this->abre=((Terminal*)pila->pop())->eTerminal;

}



void Exp::muestra() {
        sangria();
        cout<<"<Parentesis Abre> "<<abre<<endl;

        sangria();
        cout<<"<Expresion>"<<endl;
        if(exp2 != NULL){
        exp2-> tamSangria=tamSangria+1;
        exp2 -> muestra();
        }
        sangria();
        cout<<"<Parentesis Cierra> "<<cierra<<endl;
}


void Exp::validaTipo(){
       // cout<<"Valida Tipo Exp()"<<endl;
       if(exp2!=NULL)exp2->validaTipo();

}

void Exp::generaCodigo(){

      cout<<"Exp";
      if(exp2!=NULL){exp2->generaCodigo();}
}

Acum:: Acum(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);

        pila->pop();
        this->simbolo=((Terminal*)(pila->pop()))->eTerminal;

}

void Acum::muestra() {
         sangria();
         cout<<"<opSuma> "<<simbolo<<endl;
         sangria();
         cout<<"<Expresion> "<<endl;
         if(exp2 != NULL){
         exp2 -> tamSangria=tamSangria+1;
         exp2 -> muestra();
         }
}

void Acum::validaTipo(){

        //cout<<"Valida Tipo Acum"<<endl;
        if(exp2!=NULL){
                exp2->validaTipo();
                this->tipoDato=exp2->tipoDato;
        }
        this->msn="Acumulador";

}

void Acum::generaCodigo(){

       cout<<"Acum"<<endl;

     //bss<<"res resb 1"<<endl;

    if(exp2 != NULL){
        if(exp2->esTer()){
            Termino *T = (Termino*)exp2;

            text<<"mov eax,"<<T->retTer()<<endl;
        }
        else{
            exp2->generaCodigo();
        }
    }

  
    text<<"inc eax"<<endl;
    text<<"add eax,'0'"<<endl;
    text<<"mov [res],eax"<<endl;
  
}

opeNot::opeNot(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);

        pila->pop();
        this->simbolo=((Terminal*)(pila->pop()))->eTerminal;

}

void opeNot::muestra(){
          sangria();
          cout<<"<opDecremento> "<<simbolo<<endl;
          sangria();
          cout<<"<Expresion>"<<endl;
          if(exp2 != NULL){
          exp2 -> tamSangria=tamSangria+1;
          exp2 -> muestra();
      }
}

void opeNot::validaTipo(){

      //cout<<"Valida Tipo OpNot"<<endl;
      if(exp2!=NULL){
            exp2->validaTipo();
            this->tipoDato=exp2->tipoDato;
      }
      this->msn="Op Not";
}

void opeNot::generaCodigo(){


      cout<<"OpNot"<<endl;
      if(exp2!=NULL){exp2->generaCodigo();}
}


opSuma::opSuma(Pila *pila){
          pila->pop();
          this->exp2=(Expresion*)((pila->pop())->nodo);

          pila->pop();
          this->simbolo=((Terminal*)(pila->pop()))->eTerminal;

          pila->pop();
          this->exp1=(Expresion*)((pila->pop())->nodo);

}

void opSuma::muestra(){
             sangria();
             cout << "<Expresion>" << endl;
             if(exp1 != NULL){
                exp1->tamSangria=tamSangria+1;
                exp1->muestra();
            }

            sangria();
            cout<<"<OpSuma:>"<<simbolo<<endl;

            sangria();
            cout << "<Expresion> "<< endl;
            if(exp2 != NULL){
                exp2->tamSangria = tamSangria+1;
                exp2->muestra();
            }
}

void opSuma::validaTipo(){
    //cout<<"Valido Tipo Suma"<<endl;

     if(exp1!=NULL){

    exp1->validaTipo();
      //cout<<"Error1 "<<exp1->auxError<<endl;
      //cout<<"Tipo der"<<exp1->tipoDato<<endl;
     }


      if(exp2!=NULL){
      exp2->validaTipo();
      //cout<<"Tipo izq"<<exp2->tipoDato<<endl;
      //cout<<"Error2 "<<exp2->auxError<<endl;
     }



     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if(exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){

        this->tipoDato= exp1->tipoDato;
     }else{
     //cout<<"AUX ERRORq"<<exp2->auxError<<endl;
     this->msn="suma";
     this->tipoDato='u';

     }




}

void opSuma::generaCodigo(){

     if(this->simbolo.compare("+")==0){
     cout<<"opSuma"<<endl;

     //bss<<"res resb 1"<<endl;

     if(exp1 != NULL){
        if(exp1->esTer()){
            Termino *T = (Termino*)exp1;

            //datos<<"EXP1"<<endl;
            text<<"mov eax,"<<T->retTer()<<endl;
         }else{
             exp1->generaCodigo();
         }
     }

    if(exp2 != NULL){
        if(exp2->esTer()){
            Termino *T = (Termino*)exp2;

            //datos<<"EXP2"<<endl;
            text<<"mov ebx,"<<T->retTer()<<endl;
        }
        else{
            exp2->generaCodigo();
        }
    }

  
    text<<"add eax,ebx"<<endl;
    text<<"add eax,'0'"<<endl;
    text<<"mov [res],eax"<<endl;
  }else
     if(this->simbolo.compare("-")==0){
     cout<<"opResta"<<endl;

     //bss<<"res resb 1"<<endl;

     if(exp1 != NULL){
        if(exp1->esTer()){
            Termino *T = (Termino*)exp1;

            //datos<<"EXP1"<<endl;
            text<<"mov eax,"<<T->retTer()<<endl;
         }else{
             exp1->generaCodigo();
         }
     }

    if(exp2 != NULL){
        if(exp2->esTer()){
            Termino *T = (Termino*)exp2;

            //datos<<"EXP2"<<endl;
            text<<"mov ebx,"<<T->retTer()<<endl;
        }
        else{
            exp2->generaCodigo();
        }
    }

  
    text<<"sub eax,ebx"<<endl;
    text<<"add eax,'0'"<<endl;
    text<<"mov [res],eax"<<endl;
  }

}


opMulti::opMulti(Pila *pila){
          pila->pop();
          this->exp2=(Expresion*)((pila->pop())->nodo);


          pila->pop();
          this->operador=((Terminal*)pila->pop())->eTerminal;

          pila->pop();
          this->exp1=(Expresion*)((pila->pop())->nodo);
}

void opMulti::muestra(){

            sangria();
            cout << "<Expresion>" << endl;
            if(exp1 != NULL){
            exp1->tamSangria = tamSangria+1;
            exp1->muestra();
            }

            sangria();
            cout<<"<OpMulti>"<<operador<<endl;

            sangria();
            cout << "<Expresion>" << endl;
            if(exp2 != NULL){
                exp2->tamSangria = tamSangria+1;
                exp2->muestra();
            }


}

void opMulti::validaTipo(){
    //cout<<"Valida Tipo opMulti"<<endl;
    if(exp1!=NULL){

            exp1->validaTipo();
            //cout<<"Tipo der"<<exp1->tipoDato<<endl;
     }

     if(exp2!=NULL){
            exp2->validaTipo();
            //cout<<"Tipo izq"<<exp2->tipoDato<<endl;
    }


     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if (exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato=exp1->tipoDato;
     }else{
        this->tipoDato='u';
        this->msn="Multiplicacion";
     }
}

void opMulti::generaCodigo(){

    if(this->operador.compare("*")==0){
      cout<<"opMulti"<<endl;
      if(exp1 != NULL){
        if(exp1->esTer()){
            Termino *T = (Termino*)exp1;

            //datos<<"EXP1"<<endl;
            text<<"mov eax,"<<T->retTer()<<endl;
         }else{
             exp1->generaCodigo();
         }
     }

    if(exp2 != NULL){
        if(exp2->esTer()){
            Termino *T = (Termino*)exp2;

            //datos<<"EXP2"<<endl;
            text<<"mov ebx,"<<T->retTer()<<endl;
        }
        else{
            exp2->generaCodigo();
        }
    }

  
    text<<"mul ebx"<<endl;
    text<<"add eax,'0'"<<endl;
    text<<"mov [res],eax"<<endl;

  }else if(this->operador.compare("/")==0){
      cout<<"opDivision"<<endl;
      if(exp1 != NULL){
        if(exp1->esTer()){
            Termino *T = (Termino*)exp1;

            //datos<<"EXP1"<<endl;
            text<<"mov eax,"<<T->retTer()<<endl;
         }else{
             exp1->generaCodigo();
         }
     }

    if(exp2 != NULL){
        if(exp2->esTer()){
            Termino *T = (Termino*)exp2;

            //datos<<"EXP2"<<endl;
            text<<"mov ebx,"<<T->retTer()<<endl;
        }
        else{
            exp2->generaCodigo();
        }
    }

    text<<"mov edx,0"<<endl;
    text<<"div ebx"<<endl;
    text<<"add eax,'0'"<<endl;
    text<<"mov [res],eax"<<endl;

  }

}


 opRelac::opRelac(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);


        pila->pop();
        this->operador=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->exp1=(Expresion*)((pila->pop())->nodo);

}

void opRelac::muestra(){


            sangria();
            cout << "<Expresion>" << endl;
            if(exp1 != NULL){
            exp1 -> tamSangria=tamSangria+1;
            exp1 -> muestra();
            }

            sangria();
            cout<<"<OpRelac>"<<operador<<endl;

            sangria();
            cout << "<Expresion>" << endl;
            if(exp2 != NULL){
                exp2->tamSangria = tamSangria+1;
                exp2->muestra();
            }


}

void opRelac::validaTipo(){
     //cout<<"Valida Tipo Oprelac"<<endl;
     if(exp1!=NULL){

            exp1->validaTipo();
     }

     if(exp2!=NULL){
            exp2->validaTipo();
     }

     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if (exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
     }else{
        this->tipoDato='u';
        //this->msn="Operacion Relacional";
        //Nodo::tablaSimbolos->listaErrores->push_back("Error: El tipo de las variables no coincide en la opRelac\"");
     }

}

void opRelac::generaCodigo(){

    cout<<"opRelac"<<endl;

    if(exp1!=NULL)exp1->generaCodigo();
    if(exp2!=NULL)exp2->generaCodigo();

}


 opOr::opOr(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);


        pila->pop();
        this->operador=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->exp1=(Expresion*)((pila->pop())->nodo);
}


void opOr::muestra(){


            sangria();
            cout << "<Expresion>" << endl;
            if(exp1 != NULL){
            exp1->tamSangria = tamSangria+1;
            exp1->muestra();
            }

            sangria();
            cout<<"<opOr>"<<operador<<endl;

            sangria();
            cout << "<Expresion>" << endl;
            if(exp2 != NULL){
                exp2->tamSangria=tamSangria+1;
                exp2->muestra();
            }


}

void opOr::validaTipo(){
       //cout<<"Valida Tipo Opor"<<endl;
           if(exp1!=NULL){

            exp1->validaTipo();
     }

     if(exp2!=NULL){
            exp2->validaTipo();
     }

     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if (exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){
         this->tipoDato=exp1->tipoDato;
     }else{
        this->tipoDato='u';
     }

}

void opOr::generaCodigo(){

    cout<<"opOr"<<endl;
    if(exp1!=NULL)exp1->generaCodigo();
    if(exp2!=NULL)exp2->generaCodigo();
}

opIgualdad::opIgualdad(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);


        pila->pop();
        this->operador=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->exp1=(Expresion*)((pila->pop())->nodo);

}

void opIgualdad::muestra(){

            sangria();
            cout << "<Expresion>" << endl;
            if(exp1 != NULL){

            exp1->tamSangria = tamSangria+1;
            exp1->muestra();

            }

            sangria();
            cout<<"<opIgualdad>"<<operador<<endl;

            sangria();
            cout << "<Expresion>" << endl;
            if(exp2 != NULL){
            exp2->tamSangria=tamSangria+1;
            exp2->muestra();
            }
       }


void opIgualdad::validaTipo(){


        if(exp1!=NULL){

            exp1->validaTipo();
     }

     if(exp2!=NULL){
            exp2->validaTipo();
     }

     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if (exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato=exp1->tipoDato;
     }else{
        this->tipoDato='u';
     }


}

void opIgualdad::generaCodigo(){

     cout<<"opIgualdad"<<endl;

     if(exp1!=NULL)exp1->generaCodigo();
     if(exp2!=NULL)exp2->generaCodigo();
}

opAnd:: opAnd(Pila *pila){
        pila->pop();
        this->exp2=(Expresion*)((pila->pop())->nodo);


        pila->pop();
        this->operador=((Terminal*)pila->pop())->eTerminal;

        pila->pop();
        this->exp1=(Expresion*)((pila->pop())->nodo);

}

void opAnd::muestra(){

            sangria();
            cout << "<Expresion>" << endl;
            if(exp1 != NULL){
            exp1->tamSangria = tamSangria+1;
            exp1->muestra();
            }

            sangria();
            cout<<"<opAnd>"<<operador<<endl;

            sangria();
            cout << "<Expresion>" << endl;
            if(exp2 != NULL){
                exp2->tamSangria = tamSangria+1;
                exp2->muestra();
            }


        }

void opAnd::validaTipo(){

    if(exp1!=NULL){

            exp1->validaTipo();
     }

     if(exp2!=NULL){
            exp2->validaTipo();
     }

     if (exp1->tipoDato == 'i' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;

     }else if (exp1->tipoDato == 'f' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
        //cout<<"El Tipo es:"<<exp1->tipoDato<<endl;
     }else if(exp1->tipoDato == 's' && exp1->tipoDato == exp2->tipoDato){
        this->tipoDato= exp1->tipoDato;
     }else{
        this->tipoDato='u';
     }


}

void opAnd::generaCodigo(){

     cout<<"opAnd"<<endl;
     if(exp1!=NULL){exp1->generaCodigo();}
     if(exp2!=NULL){exp2->generaCodigo();}
}


Identificador::Identificador(Pila *pila){
           pila->pop();//estados
           this->simbolo=((Terminal*)pila->pop())->eTerminal;
}


void Identificador::muestra(){

          sangria();
          cout<<"<ID:>"<<simbolo<<endl;
}

void Identificador::validaTipo(){
          //cout<<"Valida Tipo Identificador"<<this->simbolo<<"ambito"<<this->ambito<<endl;
           this->auxError=this->simbolo;
           tablaSimbolos->buscaIdentificador(this->simbolo,this->ambito);
           //this->auxId=this->simbolo;
           if(tablaSimbolos->varGlobal!=NULL){
            //cout<<"Entro a busca Var Global"<<endl;
              this->tipoDato=tablaSimbolos->varGlobal->tipo;
           }else if(tablaSimbolos->varLocal!=NULL){
              this->tipoDato=tablaSimbolos->varLocal->tipo;
           }else if(tablaSimbolos->funcion!=NULL){
              this->tipoDato=tablaSimbolos->funcion->tipo;
           }else if(tablaSimbolos->parametro!=NULL){
              this->tipoDato=tablaSimbolos->parametro->tipo;
           }else{
              //cout<<"Entro al else de global"<<endl;
              tablaSimbolos->buscaIdentificador(this->simbolo,"");
              //cout<<"VarGlobaL"<<tablaSimbolos->varGlobal->tipo<<endl;
              if(tablaSimbolos->varGlobal!=NULL){
              this->tipoDato=tablaSimbolos->varGlobal->tipo;
              }else{
              //cout<<"Entro al 2 else de global"<<endl;
              Nodo::tablaSimbolos->listaErrores->push_back("Error: Variable no Definida \""+this->simbolo+"\"");
              this->tipoDato='u';
              }
           }

}

void Identificador::generaCodigo(){

      cout<<"Identificador"<<endl;
}

Entero::Entero(Pila *pila){
          pila->pop();
          this->simbolo=((Terminal*)pila->pop())->eTerminal;
}


void Entero::muestra(){
            sangria();
            cout<<"<Entero:>"<<simbolo<<endl;

}

void Entero::validaTipo(){
          //cout<<"Valida Tipo Entero"<<this->simbolo<<this->ambito<<endl;
           this->tipoDato='i';
           //this->msn="Asignacion a Entero"+this->simbolo;

}

void Entero::generaCodigo(){

          cout<<"Entero"<<endl;
          string num=this->simbolo;

          //fprintf(f,"%s\n",num.c_str());
          //f.close();
          //datos<<num<<endl;
          //datos.close();
}

Real::Real(Pila *pila){
          pila->pop();
          this->simbolo=((Terminal*)pila->pop())->eTerminal;
}

void Real::muestra(){
            sangria();
            cout<<"<Real:>"<<simbolo<<endl;
}

void Real::validaTipo(){
        //cout<<"Valida Tipo Real"<<this->simbolo<<endl;
        this->tipoDato='f';

}

void Real::generaCodigo(){

        cout<<"Real"<<endl;
}

Cadena:: Cadena(Pila *pila){
          pila->pop();
          this->simbolo=((Terminal*)pila->pop())->eTerminal;
}

void Cadena::muestra(){
            sangria();
            cout<<"<Cadena:>"<<simbolo<<endl;
}

void Cadena::validaTipo(){

          //cout<<"Valida Tipo Cadena"<<simbolo<<endl;
           this->tipoDato='s';
           //this->msn="Asignacion a Cadena"+this->simbolo;
}

void Cadena::generaCodigo(){

        cout<<"Cadena"<<endl;
}
