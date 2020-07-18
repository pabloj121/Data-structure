// SopaLetras.cpp

#include <iostream>
#include <vector>
using namespace std;

// Métodos de consulta

template<class T>
bool SopaLetras<T>::NoDescubierta(string p)const{
	for (int i = 0; i < sin_descubrir.size(); ++i){
		if(descubiertas[i] == p)
			return true;
	}
	return false;
}

template<class T>
bool SopaLetras<T>::PuedoPoner(string palabra, string direccion, int fila, int columna)const{
	int i;
	int fil = fila;
	int col = columna;

	if(direccion=="vu"){//vertical arriba
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(matriz[Posicion(fila, columna)].valor != matriz.ValorPorDefecto())
					return false;
				else{
					fila--;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;		
	}
	else if(direccion=="vd"){//vertical abajo
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(Posicion(fila, columna).valor != matriz.ValorPorDefecto())
					return false;
				else{
					fila++;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;
	}
	else if(direccion=="hi"){//horizontal izquierda
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(Posicion(fila, columna).valor != matriz.ValorPorDefecto())
					return false;
				else{
					columna--;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;
	}
	else if(direccion=="hd"){//horizontal derecha
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(Posicion(fila, columna).valor != matriz.ValorPorDefecto())
					return false;
				else{
					columna++;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;
	}
	else if(direccion=="dd"){//diagonal abajo derecha
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(Posicion(fila, columna).valor != matriz.ValorPorDefecto())
					return false;
				else{
					fila++; columna++;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;
	}
	else if(direccion=="di"){//diagonal abajo izquierda
		int i = 0;
		while(i < palabra.size()){
			if(Posicion(fila,columna) != -1){
				if(Posicion(fila, columna).valor != matriz.ValorPorDefecto())
					return false;
				else{
					fila++; columna--;
				}
			}
			// sino existe la posicion, es que la puede crear
			i++;
		}
		
		//cout << "La palabra se encuentra en esa posicion" << endl;
		return true;
	}
}

template<class T>
int SopaLetras<T>::Posicion(int fil, int col)const{
	for (int i = 0; i < matriz.size(); ++i){
		if(matriz[i].fila == fil and matriz[i].columna == col)
			return i;	
	}
	return -1;
}

template<class T>
bool SopaLetras<T>::SeEncuentra(string palabra, string dir, int fil, int col){
	//int posicion;
	int fila = fil;
	int columna = col;
	int posicion;

	if(dir=="vu"){//vertical arriba
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//posicion = Posicion(fila, columna);
			//if(v[Posicion(fila, columna)].valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				fila--;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}	
	else if(dir=="vd"){//vertical abajo
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//posicion = Posicion(fila, columna);
			//if(Posicion(fila, columna).valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				fila++;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}
	else if(dir=="hi"){//horizontal izquierda
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//posicion = Posicion(fila, columna);
			//if(v[Posicion(fila, columna)].valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				columna--;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}
	else if(dir=="hd"){//horizontal derecha
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//posicion = Posicion(fila, columna);
			//if(v[Posicion(fila, columna)].valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				columna--;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}
	else if(dir=="dd"){//diagonal abajo derecha
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//posicion = Posicion(fila, columna);
			//if(v[Posicion(fila, columna)].valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				fila++; columna++;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}
	else if(dir=="di"){ //diagonal abajo izquierda
		int i = 0;
		posicion = Posicion(fila,columna);
		while(Posicion(fila,columna)!=-1 and i < palabra.size()){ // existe el elemento (fil,col) en la matriz			
			//if(v[Posicion(fila, columna)].valor != palabra[i])
			if(matriz.getElemento(fila, columna) != palabra[i])
				return false;
			else{
				fila++; columna--;
			}
			i++;
		}
		
		if(i < palabra.size()-1){ // no ha llegado a comprobarse la palabra entera
			cout << "La palabra no se encuentra en esa posicion" << endl;
			return false;
		}
	}
}

// Métodos de modificación
template<class T>
void SopaLetras<T>::ColocarPalabra(string palabra, string direccion, int fil, int col){
	if(PuedoPoner(palabra, direccion, fil, col)){

		//ColocarPalabra(palabra, direccion, fil, col);
		return true;
	}
	else
		return false;
}

template<class T>
void SopaLetras<T>::Descubrimiento(string p){
	// veo en que posicion esta la palabra
	// la meto en descubiertas, la borro de sin descubrir
	bool encontrado = false;
	int i = 0;
	while(!encontrado || i < sin_descubrir.size()){
		if(sin_descubrir[i] == p)
			encontrado = true;
		else
			i++;
	}
	if(encontrado){
		descubiertas.Insertar(sin_descubrir[i], i);
		sin_descubrir.Borrar(i);
	}
}


template<class T>
void SopaLetras<T>::EliminaPalabra(string palabra){

}

template <class T>
string SopaLetras<T>::Titulo()const{
	return titulo;
}

// Operaciones de lectura y escritura de flujo
template<class T>
istream& operator>>(istream &is, SopaLetras<T> &sopa){
	string titulo, direccion, palabra;
	int fila, columna;
	is >> titulo;
	SopaLetras<T> s(titulo);
	
	while(is){
		// leemos cada fila de la sopa letras
		is >> fila;
		Avanzar(is);
		is >> columna;
		Avanzar(is);
		is >> direccion;
		Avanzar(is);
		is >> palabra;
		
		if(s.PuedoPoner(palabra, direccion, fila, columna)){
			s.ColocarPalabra(palabra, direccion, fila, columna);
		}

		s.sin_descubrir.Insertar(palabra, s.sin_descubrir.size()-1);
	}
	if(!is.fail())
    	sopa = s;

	return is;
}

template<class T>
ostream& operator<<(ostream &os, const SopaLetras<T> &sopa){
	string titulo;

	os << "titulo   :" << sopa.Titulo() << "	" << "Numero de palabras ocultas: " << sopa.PalabrasSinDescubrir() << endl;
	os << "Numero de palabras descubiertas: " << sopa.PalabrasDescubiertas() << endl; 	
	os << "*******************************" << endl;
	os << sopa.matriz;

	return os;
}