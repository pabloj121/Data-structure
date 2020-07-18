#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

typedef pair<string,string> Componente;

int main(int argc, char const *argv[])
{
	string linea_diccionario;
	string palabra;
	string significado;
	multimap <string,string> diccionario;
	multimap <string,string>::iterator it;

	if(argc!=2){
		cout << "Dime el nombre del fichero con el diccionario " << endl;
		return 0;
	}

	ifstream f(argv[1]);

	if(!f){
		cout << "No puedo abrir el fichero " << argv[1] << endl;
		return 0;
	}

	while(!f.eof()){
		getline(f,linea_diccionario, '\n');
		// Busco un texto dentro de la cadena y obtengo la posicion
		int pos = linea_diccionario.find(";");

		// Obtengo una subcadena a partir del texto mi
		palabra = linea_diccionario.substr(0, pos);
		significado = linea_diccionario.substr(pos+1);

		// diccionario[palabra] = significado
		diccionario.insert(Componente(palabra, significado));

		// cout << palabra << "---> " << significado << endl;
	}

	for (it = diccionario.begin(); it != diccionario.end(); ++it)
	{
		cout << it->first << "....>"  << it->second << endl;
	}

	cout << diccionario.size();

	f.close();


	return 0;
}