// Funciones de la matriz dispersa
// Métodos de consulta
#include <iostream>
using namespace std;

template<class T>
char Matriz_Dispersa<T>::getElemento(int fil, int col)const{
	bool esta = false;
	int i;
	/*tripleta t; // en caso de no encontrar el elemento
				// devolveremos una tripleta con valor por defecto
	*/
	if(fil <= mayorFila() and fil >= menorFila and col >= menorFila()
	  								and col <= mayorColumna()){
		for (i = 0; i < v.size() and !esta; ++i){
			if(v[i].fila == fil && v[i].columna == col)	
				esta = true;	
		}
		
		if(esta)
			return v[i].valor;
		else 
			return '0';
	}
	else{
		cout << "Posicion erronea introducida" << endl;
		return '0';
	}
}

template<class T>
char Matriz_Dispersa<T>::valorPorDefecto()const{
  return valor_por_defecto;;
}

template<class T>
int Matriz_Dispersa<T>::mayorFila()const{
	int mayor = v[0].fila;
	for(int i=1; i < v.size(); ++i){
		if(v[i].fila > mayor)
			mayor = v[i].fila;
	}
	return mayor;
			
}

template<class T>
int Matriz_Dispersa<T>::mayorColumna()const{
	int mayor = v[0].columna;
	for(int i=1; i < v.size(); ++i){
		if(v[i].columna > mayor)
			mayor = v[i].columna;
	}
	return mayor;
}
	
template<class T>	
int Matriz_Dispersa<T>::menorFila()const{
	int menor = v[0].fila;
	for(int i=1; i < v.size(); ++i){
		if(v[i].fila < menor)
			menor = v[i].fila;
	}
	return menor;
}

template<class T>
int Matriz_Dispersa<T>::menorColumna()const{
	int menor = v[0].columna;
	for(int i=1; i < v.size(); ++i){
		if(v[i].columna < menor)
			menor = v[i].columna;
	}
	return menor;
}

template<class T>
int Matriz_Dispersa<T>::casillasOcupadas()const{
	int ocupadas = 0;
	for(int i=0; i<v.size();++i){
		if(v[i].valor != valorPorDefecto()) //valor_por_defecto)
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
	int filas = mayorFila() - menorFila();

	/*if(menorFila()<0 || mayorFila()<0)
		filas = (menorFila()*-1) + (mayorFila()*-1);*/
	return filas;
}

template<class T>
int Matriz_Dispersa<T>::numeroColumnas()const{
	int columnas = 0;
	columnas = mayorColumna() - menorColumna();
	/*if(menorColumna()<0 || mayorColumna()<0)
		columnas = (menorColumna()*-1) + (mayorColumna()*-1);*/
	return columnas;
}

/*template<class T>
bool Matriz_Dispersa<T>::Esta()const{
	bool esta = false;
	int fin = v.size();
	int inicio = 0;
	int mitad;

	while(inicio < fin and !esta){
		mitad = (inicio+fin)/2;
		if(v[mitad] == valor)
			return true;
		else if(v[mitad].valor > valor){
			fin = mitad-1;
		}
		else if(v[mitad].valor < valor){
			inicio = mitad+1;
		}
	}
	return esta;
}*/

// Operadores de modificacion
template<class T>
void Matriz_Dispersa<T>::Set(int fil, int col, char valor){
	//int i = 0;
	int inicio, mitad, fin;
	bool esta = false;
	inicio = mitad = 0;
	fin = v.size();
	tripleta t;

	// condicion?
	while(inicio < fin and !esta){
		mitad = (inicio+fin)/2;
		
		if(v[mitad].valor == valor){
			esta = true;
		}
		else{
		  if(v[mitad].valor > valor){
			fin = mitad-1;
			}
		  else if(v[mitad].valor < valor){
			inicio = mitad+1;
			}
		}
	}

	if(esta){
		if(valor == valorPorDefecto()){
			v.Borrar(mitad);
		}
		else{
			v[mitad].valor = valor;
		}
	}
	else{
		Insertar(t, fil, col); //v.Insertar(t, fil, col);										
	}
}

template <class T>
void Matriz_Dispersa<T>::Insertar(tripleta t, int fila, int columna){
	int i, j;
	//buscar posicion en la que insertar con dos for con el cuerpo vacío
	for (i = 0; i < v.size() and v[i].fila < fila; ++i)
		for(j=0; v[i].columna < columna; ++j)

	v.Insertar(t, i*numeroColumnas()+j);	
}

// Operadores de entrada y salida
template<class T>
istream& operator>>(istream& is, Matriz_Dispersa<T> &t){
	int i = 0;
	char defecto;
	tripleta tri;
	is >> defecto;
	Matriz_Dispersa<T> aux(defecto);
	
	while(is.good()){  // mientras el flujo esté ok
		is >> tri;	// operator >> de tripleta
		aux.Insertar(tri,i);
		i++;
	}

	if(is)
		t = aux;
	return is;
}

template<class T>
ostream& operator<<(ostream& os, const Matriz_Dispersa<T> &m){	
	for (int i = 0; i < m.size(); ++i){
		tripleta t = m[i].getElemento();

		for (int j = m.menorFila(); j < m.mayorFila(); ++j){
			for (int k = m.menorColumna(); k < m.mayorColumna(); ++k){
				if(t.valor = m.valorPorDefecto())
					os << "0 ";
				else
					os << t.valor;
			}
			os << endl;			
		}
	}
	return os;
}