#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

#include <map>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Diccionario
{
private:
	multimap <string,string> diccionario; // parejas palabra-definicion(+de1def)
public:
	class iterator{
		private:
			multimap <string,string>::iterator it;
		public:
			iterator &operator++(){
				++it;
				return *this;
			}
			iterator &operator--(){
				--it;
				return *this;
			}			
			bool operator==(const iterator &segundo){
				return (it == segundo.it);
			}			
			bool operator!=(const iterator &segundo){
				return (it != segundo.it);
			}			
			// le he quitao el & antes de operator
			pair<const string,string> operator*(){
				return *it;
			}
			void advance(int n){
				std::advance(it, n);
			}
			friend class Diccionario;
			friend class const_iterator;
	};

	class const_iterator{
	private:
		multimap<string, string>::const_iterator it;
	public:
		const_iterator &operator++(){
			++it;
			return *this;
		}
		const_iterator &operator--(){
			--it;
			return *this;
		}
		const pair<const string,string> operator*(){
			return *it;
		}
		bool operator!=(const const_iterator &t)const{
			return it != t.it;
		}
		void operator=(multimap<const string, string>::iterator segundo){
			it = segundo;
		}		
		bool operator==(const const_iterator & t)const{
			return it == t.it;
		}
		void advance(int n){
			std::advance(it, n);
		}
		friend class Diccionario;
	};

	inline iterator begin(){
		iterator iterador;

		iterador.it = diccionario.begin();
		return iterador;
	}

	inline iterator end(){
		iterator iterador;

		iterador.it = diccionario.end();
		return iterador;
	}
	//141
	inline const_iterator cbegin()const {
		const_iterator iterador;

		iterador.it = diccionario.cbegin();
		return iterador;
	}

	inline const_iterator cend()const{
		const_iterator iterador;

		iterador.it = diccionario.end();
		return iterador;
	}

	void insertar( const string &clave, const string &definicion );

	inline void clear(){ diccionario.clear(); }

	Diccionario ObtainPalabrasconDeficionContiene( string &tema );
	
	inline int size(){ return diccionario.size(); }
	
	// operator corchetes
	multimap<string,string>::iterator &operator[](int i);
	
	// saber si está una clave y su posición
	bool Esta_Clave(string clave, iterator &it_out);
	
	// saber si el diccionario tiene una determinada clave
	bool Esta( string clave );

	// devolver una definición de una posición
	string Definicion(iterator iter)const;		
	
	// operador de entrada
	friend istream &operator>>(istream &is, Diccionario &d);

	// operador de salida
	friend ostream &operator<<(ostream &os, const Diccionario &d);
	
	// devolver diccionario con un determinado tema y un determinado
	// numero de palabras, que es con el que haremos la sopaletras
	Diccionario DiccionarioTema(string tema, int numero);
};

#endif