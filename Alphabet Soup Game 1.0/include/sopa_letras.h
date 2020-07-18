#ifndef _SOPA_LETRAS_
#define _SOPA_LETRAS_

#include "matriz_dispersa.h"
#include <iostream>

using namespace std;

// g++ -c matrizdispersa.cpp -o matrizdispersa.o -I.

/**
  *  @brief TDA Sopa de Letras
  *
  * Una instancia @e c del tipo de datos abstracto @c Sopa de Letras es un objeto
  * compuestos por una matriz dispersa, dos arrays y un string que representan,
  * respectivamente, matriz, sin_descurbrir, descubiertas y titulo. Lo representamos
  *
  * matriz, sin_descubrir, descubiertas, titulo
  *
  * Un ejemplo de su uso:
  * @include usoRacional.cpp
  *
  * @author Pablo J. Jiménez Ortiz
  * @date Noviemebre 2017
  */
template<class T>
class SopaLetras{
private:

	/**
	  * @page repConjunto Rep del TDA Sopa de Letras
	  *
	  * @section invConjunto Invariante de la representación
	  *
	  * El invariante es \e rep.titulo != " ", al inicio del programa y una vez
	  * inicializada la matriz el tamaño de sin_descubrir debe ser mayor que 0
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Sopa de Letras representa al valor
	  *
	  * (rep.matriz,rep.sin_descubrir, rep.descubiertas, rep.titulo)
	  *
	  */
	Matriz_Dispersa<T> matriz; /**< matriz */
	Vector_Dinamico<string> sin_descubrir; /**< sin_descubrir */
	Vector_Dinamico<string> descubiertas; /**< descubiertas */
	string titulo; /**< titulo */
public:
	/**
	  * @brief Constructor de la clase por parámetro
	  * @param t string que contendrá el título de nuestra sopa de letras
	  * @return Crea una Sopa de Letras con titulo t
	  */
	SopaLetras(string t): titulo(t){}

	/**
	  * @brief Devuelve si una palabra está en la lista de palabras no descubiertas
	  * @param p palabra objeto de la consulta, se pretende saber si ha sido descubierta
	  * @returnval True si aún no ha sido encontrada, False en caso contrario
	  * @pre p Debe ser una palabra contenida en la sopa de letras
	  */
	bool NoDescubierta(string p)const;
	
	/**
	  * @brief Posicion en la que se encuentra el elemento (fil, col)
	  * @param fil fila en la que vamos a buscar si existe el elemento (fil, col)
	  * @param col columna en la que vamos a buscar si existe el elemento (fil, col)
	  * @retval En caso de existir el elemento devuelve la posición que ocupa dentro de
	  * la matriz. En caso contrario, devuelve -1
	  * @pre Tanto fil como col deben ser mayor o iguales que la menor fila y menor columna
	  * de la matriz, y menor o iguales que la mayor fila y menor columna de la matriz del
	  * objeto implícito
	  */
	int Posicion(int fil, int col)const;

	/**
	  * @brief Comprueda si puedo poner una palabra en la sopa de letras con una dirección concreta
	  * y una fila y columna de inicio
	  * @param p palabra que queremos introducir en la sopa de letras
	  * @param direccion direccion en la que iremos colocando la palabra
	  * @param fila fila de inicio de modificación
	  * @param columna columna de inicio de modificación
	  * @retval True si todos los elementos de la matriz en los que iría insertada la palabra tienen 
	  * valor por defecto o aún no existen, False en caso contrario
	  * @pre pre debe de ser una de las 6 direcciones posibles: vertical arriba y abajo, horizontal 
	  * izquierda y derecha, diagonal izquierda abajo y diagonal derecha abajo.
	  */
	bool PuedoPoner(string p, string direccion, int fila, int columna)const;
	
	/**
	  * @brief Devuelve el número de palabras que han sido descubiertas
	  * @retval Número de palabras descubiertas
	  */
	inline int PalabrasDescubiertas()const{
		return descubiertas.size();
	}

	/**
	  * @brief Devuelve el número de palabras que no han sido descubiertas
	  * @retval Número de palabras sin descubrir
	  */
	inline int PalabrasSinDescubrir()const{
		return sin_descubrir.size();
	}

	/**
	  * @brief Devuelve el título de la sopa de letras
	  * @retval Título de la sopa de letras
	  */
	string Titulo()const;

	/**
	  * @brief Devuelve el título de la sopa de letras
	  * @param palabra Es la palabra que queremos conocer si se encuentra en la matriz
	  * @param dir direccion en la que se encuentra la palabra
	  * @param fil fila en la que empieza la palabra
	  * @param col columna en la que empieza la palabra
	  * @retval Título de la sopa de letras
	  */
	bool SeEncuentra(string palabra, string dir, int fil, int col);
	
	/**
	  * @brief Devuelve el título de la sopa de letras
	  * @param palabra Es la palabra que queremos conocer si se encuentra en la matriz
	  * @param dir direccion en la que se encuentra la palabra
	  * @param fil fila en la que empieza la palabra
	  * @param col columna en la que empieza la palabra
	  * @retval Título de la sopa de letras
	  */
	void ColocarPalabra(string palabra, string direccion, int fil, int col);
	
	/**
	  * @brief Saca del vector de palabras no descubiertas p y la introduce en el vector de
	  * palabras descubiertas
	  */
	void Descubrimiento(string p);
	
	/**
	  * @brief Esta función solo tendría sentido en el caso de tener 2 matrices, en mi caso y
	  * con la representación que he escogido el borrado sería simbólico por lo que he decidido
	  * no implementar dicho método
	  */
	void EliminaPalabra(string p);
	// Operaciones de lectura y escritura de flujo
}; // fin de la clase
#include "SopaLetras.cpp"

/**
  * @brief Entrada de una Sopa de Letras desde istream
  * @param is stream de entrada
  * @param sopa Sopa de Letras que recibe el valor
  * @retval Sopa de Letras leído en sopa
  * @pre La entrada tiene el formato (matriz, sin_descubrir, descubiertas, titulo) con \e matriz,
  * \e titulo los valores del la matriz que contendrá la sopa de letras y el título de \a sopa
  */
template<class T>
istream& operator>>(istream &os, SopaLetras<T> &sopa);

/**
  * @brief Salida de una Sopa de Letras a ostream
  * @param os stream de salida
  * @param sopa Sopa de Letras a escribir
  * @post Se obtiene en \a os la cadena (matriz, sin_descubrir, descubiertas, titulo) con \e matriz,
  * \e titulo, \e sin_descubrir, \e descubiertas los valores del la matriz que contendrá la sopa de 
  * letras, la cantidad de palabras que no han sido encontradas, las que sí y el título de \a sopa
  */
template<class T>
ostream& operator>>(ostream &os, const SopaLetras<T> &sopa);

#endif