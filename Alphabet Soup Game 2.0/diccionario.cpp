#include <map>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "diccionario.h"

using namespace std;

void Avanzar(istream& is){
	// lee mientras que el siguiente caracter a leer del flujo sea un espacio o '%'
  while (isspace(is.peek()) || is.peek()==';') {
  	// si es ';' (delimitador), extrae los caracteres que lleva leidos y los ignora
    if (is.peek()==';')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}

void Diccionario::insertar( const string &clave, const string &definicion ){
	diccionario.insert( make_pair( clave, definicion ) );
}

Diccionario Diccionario::ObtainPalabrasconDeficionContiene( string &tema ){
	Diccionario aux;

	for(iterator ite = begin(); ite != end(); ++ite){
		//string aux = 
		if((*ite).second.find(tema) != std::string::npos)
			aux.diccionario.insert(std::pair<const string, string>((*ite).first, (*ite).second));
	}

	/*for(auto ite:diccionario){
		d.insertar((*ite).first, (*ite).second);
	}*/
	//for(auto ite:diccionario)
	//for (ite = begin(); ite != end(); ++ite){			
		//if(ite->second.find(tema) != std::string::npos)
		//if((*ite).it->second.find(tema) != std::string::npos)
		//string palabra = (*ite).second.find(tema);
			//		pair<string,string> intermedio = *ite;
		//if((*ite).second.find(tema) != std::string::npos)
		//		if(intermedio.second.find(tema) != std::string::npos)
			//d.insertar(intermedio.first, (*ite).second);
			//		d.insertar(intermedio.first, intermedio.second);
			//d.diccionario.insert(make_pair((*ite).first,(*ite).second));
	
	return aux;
	//You can use the count function for this, which returns 
	//the number of entries in the multimap with the the given
	// key. In your example, writing

	//diccionario.count(tema);
}

bool Diccionario::Esta_Clave(string clave, iterator &it_out){
	if(diccionario.size() >0){
		int inicio = 0, fin = diccionario.size();
		iterator it;

		// busqueda binaria
		while(inicio < fin){
			int mitad = (inicio + fin)/2;
			it = begin();
			it.advance( mitad);

			if((*it).first == clave){
				it_out = it;
				return true;
			}
			else if ((*it).first > clave){
				fin =mitad;
			}
			else {
			    inicio = mitad+1;
			}
		}

		it_out = begin();
		it_out.advance( inicio);
		return false;
	}
	else{
		return false;
	}
}
	
// ver si una clave está
bool Diccionario::Esta( string clave ){
	const_iterator ite = cbegin();
	//auto search = diccionario.find(clave);
	while(ite != cend()){
		if((*ite).first == clave)
			return true;
		++ite;
	}
	return false;
	/*if(search != end()){
		return true;
	}
	else
		return false;*/
}

// devolver una definición de una posición
//string Diccionario::Definicion(multimap<string, string>::iterator iter)const{
string Diccionario::Definicion(iterator iter)const{
	return (*iter).second;
}

istream &operator>>(istream &is, Diccionario &d){
	
	string clave, definicion;

	d.clear();

	while(getline(is,clave,';')){
		getline(is,definicion);
		d.insertar(clave, definicion);
	}

	return is;
}

ostream &operator<<(ostream&os, const Diccionario &d){
	Diccionario::const_iterator t;
	
	for(t = d.cbegin(); t != d.cend(); ++t){
		os << (*t).first << ": " << (*t).second << endl;
	}
	return os;
}

Diccionario Diccionario::DiccionarioTema(string tema, int numero){
	Diccionario aleatorio;
	int random, i=0;
	vector<int> nuevo;
	//auto iter = nuevo.begin();

	aleatorio = ObtainPalabrasconDeficionContiene(tema);
	// ahora tenemos un iterador apuntando el principio del
	// diccionario "filtrado"
	//auto iterador_aleatorio = aleatorio.begin();
	const_iterator it = cbegin();

	srand(time(NULL));
	// lista con las posiciones aleatorias del tema
	while(i < numero){
		random = 0 + rand()%(diccionario.size()+1-0);
		nuevo[i]=(random);
		i++;
	}
	
	i = 0;
	
	while(i < numero){
		// problema
		it.advance(nuevo[i]);
		//advance(iterador_aleatorio, nuevo[i]);
		aleatorio.insertar((*it).first, (*it).second);
	}

	/*for(list<int>::iterator ite = nuevo.begin(); ite != nuevo.end(); ite++){

	}*/
		/*for(it = aleatorio.begin(); it != aleatorio.end(); ++it){
			it.advance();
		}*/
	return aleatorio;
}