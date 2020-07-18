// Funciones de la matriz dispersa
// Métodos de consulta
#include <iostream>
using namespace std;

// funcion para comparar tripletas y posteriormente ordenarlas en la lista
template<class T>
bool Compare_No_Case(tripleta<T> t, tripleta<T> n){
	return (t->fila < n-> fila ) && (t->columna < n->columna);
}

template<class T>
bool Matriz_Dispersa<T>::Esta(int fil, int col)const{
	typename list<tripleta<T>>::const_iterator aux;

	for(aux = v.begin(); aux != v.end(); ++aux){
		if((*aux).fila == fil and (*aux).columna == col)
			return true;		
	}
	return false;
}

template<class T>
typename Matriz_Dispersa<T>::iterator Matriz_Dispersa<T>::operator[](int i){
	assert(posicion > 0 and posicion < v.size());

	iterator iterador = begin();
	iterador.advance(i);
	
	return iterador;
}

template<class T>
T Matriz_Dispersa<T>::getElemento(int fil, int col)const{	
	assert(fil <= mayorFila() and fil >= menorFila and col >= menorFila()
	  								and col <= mayorColumna());
	bool esta = false;
	it = v.begin();
	
	while(it != v.end() and !esta){
		if((*it).fila == fil && (*it).columna == col)	
			esta = true;
		++it;
	}	

	if(esta)
		return (*it).valor;
	else 
		return valor_por_defecto;
}

template<class T>
T Matriz_Dispersa<T>::ValorPorDefecto()const{
  return valor_por_defecto;;
}

template<class T>
int Matriz_Dispersa<T>::mayorFila()const{
	it = v.begin();
	int mayor = (*it).fila;
	
	for(it = ++it; it != v.end(); ++it){
		if((*it).fila > mayor)
			mayor = (*it).fila;
	}
	return mayor;
}

template<class T>
int Matriz_Dispersa<T>::mayorColumna()const{
	it = v.begin();
	int mayor = (*it).columna;
	
	for(it = ++it; it != v.end(); ++it){
		if((*it).columna > mayor)
			mayor = (*it).columna;
	}
	return mayor;
}
	
template<class T>	
int Matriz_Dispersa<T>::menorFila()const{
	it = v.begin();
	int menor = (*it).fila;
	
	for(it = ++it; it != v.end(); ++it){
		if((*it).fila < menor)
			menor = (*it).fila;
	}
	return menor;
}

template<class T>
int Matriz_Dispersa<T>::menorColumna()const{
	it = v.begin();
	int menor = (*it).columna;
	
	for(it = ++it; it != v.end(); ++it){
		if((*it).columna < menor)
			menor = (*it).columna;
	}
	return menor;
}

template<class T>
int Matriz_Dispersa<T>::casillasOcupadas()const{
	int ocupadas = 0;
	for(it = v.begin(); it != v.end(); ++it){
		if((*it).valor != ValorPorDefecto())
			ocupadas++;
	}
	return ocupadas;
}

template<class T>
int Matriz_Dispersa<T>::size()const{
	return v.size();
}

template<class T>
int Matriz_Dispersa<T>::numeroFilas()const{
	return mayorFila() - menorFila();
}

template<class T>
int Matriz_Dispersa<T>::numeroColumnas()const{
	return mayorColumna() - menorColumna();
}

template<class T>
void Matriz_Dispersa<T>::Set(int fil, int col, T value){
	int inicio, mitad, fin;
	bool esta = false;
	
	inicio = 0;
	fin = v.size();
	tripleta<T> t;
	
	//iterator iterador;
	typename list<tripleta<T>>::iterator iterador;

	for(iterador = v.begin(); iterador != v.end() and !esta; iterador++){
		if((*it).fila == fil and (*it).columna == col)
			esta = true;
			if(value == ValorPorDefecto()){
				v.erase(iterador);
			}
			else{
				(*iterador).valor = value;
			}
	}
	
	if(!esta){
		t.fila = fil;
		t.columna = col;
		t.valor = value;
		Insertar(t);
	}
}

// falta repasar preferencia de operadores
template<class T>
void Matriz_Dispersa<T>::Insertar(tripleta<T> t){

	v.push_back(t);
	v.sort();
}