#include "Semantico.h"


Semantico::Semantico(){
Nodo::tablaSimbolos=tablaSimbolos=new TablaSimbolos(&listaErrores);
}


void Semantico::analiza(Nodo *arbol){

     this->arbol=arbol;
     cout<<endl<<"Arbol asignado a semantico"<<endl;
     arbol->validaTipo();

     tablaSimbolos->muestra();
     
     if(listaErrores.size()==0)
       {
        cout<<"no hay errores"<<endl; 
        genCode();

       }
     else
        muestraErrores();


}

void Semantico::muestraErrores(){

    	//if (listaErrores.size() == 0) return;

		list<string>::iterator it;
		string cad;
		cout << endl << "Errores Semanticos" << endl << endl;
		for (it= listaErrores.begin(); it != listaErrores.end(); it++){
			cad= *it;
			cout << cad << endl;



}
}

void Semantico::genCode(){
 
        
        cout<<endl<<"Arbol asignado a genCode"<<endl;
        this->arbol->generaCodigo();


}


