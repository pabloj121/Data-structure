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
#include <cstring>

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

struct tripleta{
	int fila; /**<fila */
	int columna; /**<columna */
	char valor = '0'; /**<valor */
	/**
	  * @brief Operator = de una Tripleta
	  * @param m tripleta que queremos igualar al objeto implícito
	  * @retval  La Tripleta leída en m
	  * @post El objeto implícito de la llamada queda con los valores de la tripleta m recibida
	  * como parámetro
	  */
	void operator=(const tripleta &m){
		this->fila = m.fila;
		this->columna = m.columna;
		this->valor = valor;
	}
};

/**
  * @brief Entrada de una Tripleta desde istream
  * @param is stream de entrada
  * @param t Tripleta que recibe el valor
  * @retval  La Tripleta leído en t
  * @pre La entrada tiene el formato (fila/columna/valor) con \e fila,\e columna y \e valor los valores
  * de la tripleta t 
  */
istream& operator>>(istream& is, tripleta &t){
	int fila, columna, valor;
	tripleta m;

	is >> fila >> columna >> valor;
	m.fila = fila;
	m.columna = columna;
	m.valor = valor;
	if(is)
		t = m;
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
	Vector_Dinamico<tripleta> v; /**<v */
	char valor_por_defecto;	/**< valor_por_defecto */
public:
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
	Matriz_Dispersa(char defecto):valor_por_defecto(defecto){}
	
	/**
	  * @brief Destructor de la clase
	  * @return Libera la memoria asociada al objeto implícito
	  */
	~Matriz_Dispersa();
	
	/**
	  * @brief Elemento 
	  * @param fil fila en la que se encuentra el elemento que queremos obtener
	  * @param col columna en la que se encuentra el elemento que queremos obtener
	  * @return Devuelve el elemento contenido en la posicion (fil, col) de la matriz
	  */
	char getElemento(int fil, int col)const;
	
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
	char valorPorDefecto()const;
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
	// ?
	//bool Esta()const;

	/**
	  * @brief Set
	  * @param fil fila en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @param col columna en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @valor valor que quieres introducir en el elemento (fil,col)
	  * @return Asigna al elemento (fil,col) del objeto implícito el 
	  * valor recibido como parámetro
	  */
	void Set(int fil, int col, char valor);
	/**
	  * @brief Insertar
	  * @param fila fila en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @param columna columna en la que se encuentra el elemento de la matriz que quieres cambiar 
	  * @valor tripleta elemento que quieres insertar en la matriz
	  * @return Inserta al elemento (fila,columna) del objeto implícito la tripleta recibida
	  * recibida como parámetro
	  */
	void Insertar(tripleta t, int fila, int columna);
	//void Insertar(tripleta t,int posicion);?
};	
#include "matriz_dispersa.cpp"

/**
  * @brief Entrada de una Matriz Dispersa desde istream
  * @param is stream de entrada
  * @param t Matriz Dispersa que recibe el valor
  * @retval  La Matriz Dispersa leído en t
  * @pre La entrada tiene el formato (v/valor_por_defecto) con \e v,\e valor_por_defecto los valores
  *   de los elementos de la matriz y el valor por defecto
  */
template <class T>
istream& operator>>(istream& is, Matriz_Dispersa<T> &t);

/**
  * @brief Salida de una matriz dispersa a ostream
  * @param os stream de salida
  * @param t Matriz Dispersa a escribir
  * @post Se obtiene en \a os la cadena (v/valor_por_defecto) con \e num,den los valores
  *   de los elementos de la matriz y el valor por defecto de las tripletas de \a t
  */
template <class T>
ostream& operator<<(ostream& os, Matriz_Dispersa<T> &t);

#endif
