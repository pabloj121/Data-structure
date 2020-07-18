/**
  * @file matriz_dispersa.h
  * @brief Fichero cabecera del TDA Matriz Dispersa
  *
  */
#ifndef _MATRIZ_DISPERSA_
#define _MATRIZ_DISPERSA_

#include "vd.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstring>
#include <list>

using namespace std;

/**
  * @brief T.D.A Tripleta
  *
  * Una instancia @e del tipo de datos abstracto @c Tripleta es un objeto
  * que representa un struct de tripletas formadas por: fila, columna y el valor
  * asociado de tipo carácter.
  *
  * fila, columna, valor
  *
  * @author Pablo J. Jiménez Ortiz
  * @date Noviembre 2017
  */

template <class T>
struct tripleta{
	int fila; /**<fila */
	int columna; /**<columna */
	T valor; /**<valor */
	
	template<class U>
	friend ostream &operator<<(ostream &os, tripleta<U> const &t);
	template<class U>
	friend istream& operator>>(istream& is, tripleta<U> const &t);

	/**
	  * @brief Operator = de una Tripleta
	  * @param m tripleta que queremos igualar al objeto implícito
	  * @retval  La Tripleta leída en m
	  * @post El objeto implícito de la llamada queda con los valores de la tripleta m recibida
	  * como parámetro
	  */
	
	bool &operator<(tripleta &t){
		return ((*this).fila < t.fila and (*this).columna < columna);
	}

	void operator=(const tripleta<T> &m){
		this->fila = m->fila;
		this->columna = m->columna;
		this->valor = m->valor;
	}
};

template<class U>
ostream &operator<<(ostream &os, const tripleta<U> &t){
	os << t->fila << " " << t->columna << " " << t->valor << endl;
}

/**
  * @brief Entrada de una Tripleta desde istream
  * @param is stream de entrada
  * @param t Tripleta que recibe el valor
  * @retval  La Tripleta leído en t
  * @pre La entrada tiene el formato (fila/columna/valor) con \e fila,\e columna y \e valor los valores
  * de la tripleta t 
  */

template<class U>
istream& operator>>(istream& is, tripleta<U> &t){
	int fila, columna;
	U valor;

	is >> fila >> columna >> valor;
	t.fila = fila;
	t.columna = columna;
	t.valor = valor;
	
	return is;
}

/**
  * @brief T.D.A Matriz Dispersa
  *
  * Una instancia @e del tipo de datos abstracto @c Matriz Dispersa es un objeto
  * que representa un array 1-d de tripletas formadas por: fila, columna y el valor
  * asociado de tipo carácter.
  *
  * v, valor_por_defecto
  *
  * @author Pablo J. Jiménez Ortiz
  * @date Noviembre 2017
  */

template <class T>
class  Matriz_Dispersa{ 
private:
/**
 * @page repMatrizDispersa Rep del TDA Matriz Dispersa
 * @section invConjunto Invariante de la representación
 * El invariante es que el tipo <T> debe ser de tipo tripleta
 *
 * @section faConjunto Funcion de abtracción
 *
 * Un objeto válido @e rep del TDA Matriz Dispersa representa al valor
 *
 * (rep.v, rep.valor_por_defecto)
 *
 */
	list<tripleta<T>> v; /**<v */
	T valor_por_defecto;	/**< valor_por_defecto */
	typename list<tripleta<T>>::iterator it;  /**<it */
public:
	class iterator{
	private:
		typename list<tripleta<T>>::iterator it;
	public:
		iterator &operator++(){
			++it;
			return *this;
		}
		
		iterator &operator--(){
			--it;
			return *this;
		}

		const tripleta<T> &operator*(){
			return *it;
		}

		bool &operator!=(iterator t){
			return it != t.it;
		}
		
		bool &operator==(iterator t){
			return it == t.it;
		}
		
		void advance(int n){
			std::advance(it, n);
		}
		
		friend class Matriz_Dispersa<T>;
	};

	class const_iterator{
	private:
		typename list<tripleta<T>>::const_iterator it;
	public:
		const_iterator &operator++(){
			++it;
			return *this;
		}
		
		const_iterator &operator--(){
			--it;
			return *this;
		}
		
		const tripleta<T> &operator*(){
			return *it;
		}
		
		bool &operator!=(const_iterator t){
			return it != t.it;
		}
		
		bool &operator==(const_iterator t){
			return it == t.it;
		}
		
		void advance(int n){
			std::advance(it, n);
		}
		
		friend class Matriz_Dispersa<T>;
	};

	iterator begin(){ return v.begin(); }
	
	iterator end(){ return v.end(); }
	
	const_iterator cbegin(){ return v.cegin(); }
	
	const_iterator cend(){ return v.cend(); }
	/**
	  * @brief Constructor por defecto de la clase. Define el valor por defecto 
	  * de nuestra matriz a 0
	  */
	Matriz_Dispersa(): valor_por_defecto(0){}
	
  /**
	* @brief Constructor por defecto de la clase. 
	* @param defecto valor por defecto de nuestra matriz
	* @return Crea la matriz dispersa con valor por defecto defecto
	* @pre defecto debe ser de tipo char
	*/
	Matriz_Dispersa(T defecto):valor_por_defecto(defecto){}
	
	/**
	  * @brief Destructor de la clase
	  * @return Libera la memoria asociada al objeto implícito
	  */
	~Matriz_Dispersa();
	
	typename Matriz_Dispersa<T>::iterator& operator[](int posicion)const;

	/**
	  * @brief Elemento 
	  * @param fil fila en la que se encuentra el elemento que queremos obtener
	  * @param col columna en la que se encuentra el elemento que queremos obtener
	  * @return Devuelve el elemento contenido en la posicion (fil, col) de la matriz
	  */
	T getElemento(int fil, int col)const;	
	/**
	  * @brief MayorFila 
	  * @return Devuelve la fila mayor contenida en la matriz
	  */
	int mayorFila()const;
	/**
	  * @brief MayorColumna 
	  * @return Devuelve la columna mayor contenida en la matriz
	  */
	int mayorColumna()const;
	/**
	  * @brief Size 
	  * @return Devuelve el tamaño de la matriz
	  */
	int size()const;
	/**
	  * @brief MenorFila 
	  * @return Devuelve la fila menor contenida en la matriz
	  */
	int menorFila()const;
	/**
	  * @brief MenorColumna 
	  * @return Devuelve la columna menor contenida en la matriz
	  */
	int menorColumna()const;
	/**
	  * @brief ValorPorDefecto 
	  * @return Devuelve el valor por defecto de la matriz
	  */	
	T ValorPorDefecto()const;
	/**
	  * @brief CasillasOcupadas 
	  * @return Devuelve el número de casillas ocupadas de la matriz
	  */
	int casillasOcupadas()const;
	/**
	  * @brief NumeroFilas 
	  * @return Devuelve el número de filas de la matriz
	  */
	int numeroFilas()const;
	/**
	  * @brief NumeroColumnas 
	  * @return Devuelve el número de columnas de la matriz
	  */
	int numeroColumnas()const;
	/**
	  * @brief Esta 
	  * @return Devuelve el número de filas de la matriz
	  */
	bool Esta(int fil, int col)const;

	/**
	  * @brief Set
	  * @param fil fila en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @param col columna en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @valor valor que quieres introducir en el elemento (fil,col)
	  * @return Asigna al elemento (fil,col) del objeto implícito el 
	  * valor recibido como parámetro
	  */
	void Set(int fil, int col, T value);
	/**
	  * @brief Insertar
	  * @param fila fila en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @param columna columna en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @valor tripleta elemento que quieres insertar en la matriz
	  * @return Inserta al elemento (fila,columna) del objeto implícito la tripleta recibida
	  * recibida como parámetro
	  */
	void Insertar(tripleta<T> t);
	/**
	  * @brief Entrada de una Matriz Dispersa desde istream
	  * @param is stream de entrada
	  * @param t Matriz Dispersa que recibe el valor
	  * @retval  La Matriz Dispersa leído en t
	  * @pre La entrada tiene el formato (v/valor_por_defecto) con \e v,\e valor_por_defecto los valores
	  *   de los elementos de la matriz y el valor por defecto
	  */
	friend istream& operator>>(istream& is, Matriz_Dispersa<T> &t){
		T defecto;
		tripleta<T> tri;
		is >> defecto;
		Matriz_Dispersa<T> aux(defecto);
		
		while(is.good()){  // mientras el flujo esté ok
			is >> tri;	// operator >> de tripleta
			aux.Insertar(tri);
		}

		if(is){
			t = aux;
		}
		return is;
	}
	/**
	  * @brief Salida de una matriz dispersa a ostream
	  * @param os stream de salida
	  * @param t Matriz Dispersa a escribir
	  * @post Se obtiene en \a os la cadena (v/valor_por_defecto) con \e num,den los valores
	  *   de los elementos de la matriz y el valor por defecto de las tripletas de \a t
	  */
	friend ostream& operator<<(ostream& os, Matriz_Dispersa<T> &t){
		for(typename Matriz_Dispersa<T>::iterator ite = t.begin(); ite != t.end(); ite++){
			for(int i = 0; i < t.numeroFilas(); i++){
				for(int j = 0; j < t.numeroColumnas(); j++){
					if(t.Esta(i, j))
						os << (*ite).valor << " ";				
					else
						os << t.ValorPorDefecto() << " ";
				}
				os << endl;
			}
		}
		return os;
	}
};	
#include "matriz_dispersa.cpp"

#endif