#include <cstring>
#include <fstream>
#include <list>
#include <stdlib.h>
#include "../include/sopa_letras.h"
#include "../include/diccionario.h"

string toUpper(string str){
  for(int i=0;str[i]!=0;i++){
    if(str[i]<=122 && str[i]>=97){
      str[i]-=32;
    }
  }
  return str;
}

map<string,vector<string> > extraerPalabras(Diccionario &D){
  Diccionario::iterator it;
  map<string,vector<string> > palabras;
  for (it=D.begin(); it!=D.end();++it){
    string aux = toUpper((*it).first);
    palabras[aux]=(*it).second;
  //  for(int i = 0;i<int((*it).second.size());i++){
    //}
  }
  return palabras;
}

int main(int argc, char * argv[]){
  srand (time(NULL));
  if (argc!=4){
    cout<<"\nDime el nombre del fichero con las palabras de la sopa de letras, el tema y el número máximo de palabras."<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No se pudo abrir "<<argv[1]<<endl;
    return 0;
  }

  Sopa_letras Sl;
  Diccionario T;
  string word(argv[2]);
  int maxPalabras = atoi(argv[3]);
  int indiceActual = 0;
  f>>T; // Cargamos en memoria el diccionario

  Diccionario Dtema = T.ObtainPalabrasconDeficionContiene(word);
  Diccionario::iterator it;
  map<string,vector<string> > palabras = extraerPalabras(Dtema);
  map<string,vector<string> >::iterator listIterator;

  for(listIterator=palabras.begin();listIterator!=palabras.end() and indiceActual<maxPalabras;++listIterator){
    cout << "una definición: " << (*listIterator).second[0] << endl;
    string dir;
    int randomDir = rand()%5;
    switch(randomDir){
      case 0: dir = "vd"; break;
      case 1: dir = "vu"; break;
      case 2: dir = "hd"; break;
      case 3: dir = "hi"; break;
      case 4: dir = "dd"; break;
      case 5: dir = "di"; break;
    }
    Sl.addPalabra(rand()%20,rand()%20,(*listIterator).first,dir);
    indiceActual++;
  }
  // El usuario ahora tiene que ir descubriendo las palabras
  // en la sopa de letras
  while (Sl.NumPalabras()!=0){
    cout<<Sl<<endl;
    string pal;
    cout<<"Dime una palabra :";
    cin>>pal;
    cout<<"Dime la fila :";
    int row;
    cin>>row;
    cout<<"Dime la columna :";
    int col;
    cin>>col;

    cout<<"Direccion Arriba (vu), Abajo (vd), Izquierda (hi) , Derecha (hd), Diagonal abajo derecha (dd),Diagonal abajo izquierda (di) :";

    string direccion;
    cin>>direccion;
    if (!Sl.Comprobar_Palabra(pal,row,col,direccion)){
      cout<<"La palabra "<<pal << " no esta"<<endl;
    } else{
      cout << "¡Correcto!" << endl;
      // La pone en negrita. Ademas la pone dentro de la lista de palabras descubiertas.
      Sl.Poner_Acertada(pal,row,col,direccion);
    }
  }
}