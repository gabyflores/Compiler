#include "TablaSimbolos.h"
//#include "Nodo.h"


Variable::Variable(char tipo,string simbolo,string ambito){
        this->clase='v';
        this->tipo=tipo;
        this->simbolo=simbolo;
        this->ambito=ambito;
        this->local=(this->ambito.compare("")!=0);

}

void Variable::muestra(){

      cout << "Variable: " << simbolo << " tipo= " << tipo;

      if (local) {cout << " local " <<ambito<<endl;}
       else cout << " global " << endl;

}

Funcion::Funcion(char tipo, string simbolo, string parametros){
        this->clase='f';
        this->simbolo= simbolo;
		this->tipo= tipo;
		this->parametros= parametros;
		this->ambito="";

}

void Funcion::muestra(){

       cout << "Funcion: " << simbolo << " tipo= " << tipo << " Parametros= " << parametros << endl;


}


Parametro::Parametro(char tipo,string simbolo,string ambito){
        this->clase='p';
        this->tipo=tipo;
        this->simbolo=simbolo;
        this->ambito=ambito;
        this->local=(this->ambito.compare("")!=0);

}

void Parametro::muestra(){

      cout << "Parametro: " << simbolo << " tipo= " << tipo;

      if (local) cout << " local " <<ambito<<endl;
       else cout << " global " << endl;

}


TablaSimbolos::TablaSimbolos(list <string> *listaErrores){
        this->listaErrores=listaErrores;
}

void TablaSimbolos::agrega(elementoTabla *elemento){

        int ind=dispersion(elemento->simbolo);
        tabla[ind].push_back(elemento);

}


int TablaSimbolos::dispersion(string simbolo){

    unsigned int h=0,i=0;
	unsigned char c;
	unsigned char alfa= 4;

	for (i=0; i<simbolo.length(); i++){
		c= simbolo[i];
        //h= (h << 4) + c;
		h += alfa*c;
		h= h % TAM;
	}

	return h%TAM;


}

void TablaSimbolos::agrega(Defvar *defvar){

      char tipo=defvar->tipoDato;
      string p=defvar->identificador;
      elementoTabla *elem;

      elem=new Variable(tipo,p,Nodo::ambito);
      agrega(elem);
}



void TablaSimbolos::agrega(DefFun *defFun){

      char tipo= defFun->dimeTipo(defFun->tipo);
      string p=defFun->identificador;
      elementoTabla *elem;

      elem=new Funcion(tipo,p,defFun->aux);
      //elem=new Variable(tipo,p,Nodo::ambito);
      agrega(elem);

}

void TablaSimbolos::agrega(Parametros *parametros){

      char tipo= parametros->dimeTipo(parametros->tipo);
      string p=parametros->id;
      elementoTabla *elem;
      //cout<<"Tipo Pa Agrega"<<tipo<<endl;
      //cout<<"Id Pa Agrega"<<p<<endl;

      elem=new Parametro(tipo,p,Nodo::ambito);
      agrega(elem);


}



void TablaSimbolos::muestra(){

    list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	cout << endl << "*** Tabla de Simbolos ***" << endl;

	for (int i=0; i< TAM; i++){
		if (tabla[i].size() > 0){

			for (it= tabla[i].begin(); it != tabla[i].end(); it++){
				elem= (elementoTabla *)*it;
				cout << "Lista= " << i << endl;
				elem->muestra();
			}
		}
	}





}


bool TablaSimbolos::varGlobalDefinida(string variable){

   	int ind= dispersion(variable);
	list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (elementoTabla *)*it;
		if (elem->esVariable() && !elem->esVarLocal()) {
			if (elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;


}

bool TablaSimbolos::varLocalDefinida(string variable, string funcion){
	int ind= dispersion(variable);
	list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (elementoTabla *)*it;
		if (elem->esVariable() && elem->esVarLocal()) {
			if (((Variable*)elem)->ambito.compare(funcion) ==0  && elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;
}


bool TablaSimbolos::funcionDefinida(string funcion){
	int ind= dispersion(funcion);
	list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (elementoTabla *)*it;
		if (elem->esFuncion()) {
			if (elem->simbolo.compare(funcion) == 0) return true;
		}
	}

	return false;
}




void TablaSimbolos::buscaIdentificador(string simbolo,string ambi){
	int ind= dispersion(simbolo);
	list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;
	parametro=NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (elementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0 && elem->ambito.compare(ambi)==0){
			if (elem->esVariable()){
				if (elem->esVarLocal())  varLocal= (Variable*)elem;
				else
                    varGlobal= (Variable*)elem;
			}
			else if(elem->esFuncion()){
                 funcion= (Funcion*)elem;
            }else
                  parametro=(Parametro*)elem;
		}

	}

}


void TablaSimbolos::buscaFuncion(string simbolo){
	int ind= dispersion(simbolo);
	list<elementoTabla*>::iterator it;
	elementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (elementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0 && elem->esFuncion()){
				funcion= (Funcion*)elem;
				return;
		}
	}

}
