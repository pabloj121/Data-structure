#ifndef _VECTOR_DINAMICO_
#define _VECTOR_DINAMICO_

#include <iostream>

using namespace std;

/**
  * @brief T.D.A Vector Dinamico
  *
  * Una instancia @e del tipo de datos abstracto @c Vector Dinamico es un objeto
  * que representa un array 1-d de tipo T
  *
  * datos, n , reservados
  *
  * @author Pablo J. Jiménez Ortiz
  * @date Noviembre 2017
  */

template <class T>
class Vector_Dinamico{
private:
	/**
	  * @page repConjunto Rep del TDA Vector Dinamico
	  *
	  * @section invConjunto Invariante de la representación
	  *
	  * El invariante es \e rep.n >=0
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Vector Dinamico representa al valor
	  *
	  * (rep.datos,rep.n, rep.reservados)
	  *
	  */
	T *datos; /**< datos */
	int n; /**< n */
	int reservados;	/**< reservados */

	/**
	  * @brief Libera la memoria asociada al objeto implícito
	  */
	void Liberar();
public:
	/**
	  * @brief Constructor por defecto de la clase. Borra la memoria dinámica
	  * asociada al vector de la clase
	  */
	Vector_Dinamico();
	
	/**
	  * @brief Constructor de la clase
	  * @param n número de elementos que va a tener tu vector
	  * @return Crea el vector con tamaño n
	  * @pre n debe ser distinto mayor que cero
	  */
	Vector_Dinamico(int n);
	
	/**
	  * @brief Constructor de copias de la clase
	  * @param original.datos vector a construir
	  * @param c.n número de elementos del vector construir
	  * @param c.reservados número máximo de elementos del vector a construir
	  * en un determinado momento
	  * @return Crea el vector con el valor de los atributos de original
	  */
	Vector_Dinamico(const Vector_Dinamico<T> &original); // falta que llame a copiar
	
	/**
	  * @brief Destructor de la clase
	  * @return Libera la memoria asociada al objeto implícito
	  */
	~Vector_Dinamico();

	/**
	  * @brief Sobrecarga del operador = 
	  * @param v vector a igualar con el objeto implícito 
	  */
	Vector_Dinamico<T> &operator=(const Vector_Dinamico<T> &v);
	
	/**
	  * @brief Devuelve el tamaño del vector
		@retval Tamaño del vector
	  */
	int size()const;
	/**
	  * @brief Reconstruye el vector del objeto implícito dándole un nuevo tamaño
	  * @param nuevotam tamaño deseado en el momento de la llamada para el vector
	  */
	void Resize(int nuevotam);

	/**
	  * @brief Devuelve el elemento contenido en el índice i de nuestro vector
	  * @retval Elemento contenido en la posición i
	  * @pre i debe de ser mayor o igual que 0
	  */
	T &operator[](int i)const;
	//const T &operator[](int i)const;

	/**
	  * @brief Inserta el elemento datos en la posicion pos del vector
	  * @param datos Elemento a insertar en el vector
	  * @param pos Posición en la que vamos a inserar el elemento
	  */
	void Insertar(const T &datos, int pos);

	/**
	  * @brief Borra el elemento contenido en una posición
	  * @param pos Posición del vector que queremos borrar
	  */
	void Borrar(int pos);	
};	
#include "vd.cpp"

/**
  * @brief Salida de un racional a ostream
  * @param os stream de salida
  * @param v Vector Dinamico a escribir
  * @post Se obtiene en \a os la cadena (datos) con \e datos los valores
  *  de los elementos del vector
  */
template<class T>
ostream& operator<<(ostream &os, Vector_Dinamico<T> &v);	// const??

/**
  * @brief Entrada de un racional a istream
  * @param is stream de entrada
  * @post Avanza el flujo mientras el siguiente cáracter a leer sea un espacio
  */
void Avanzar(istream& is)
{
  while (isspace(is.peek())){
    is.ignore();
  }
}

#endif
