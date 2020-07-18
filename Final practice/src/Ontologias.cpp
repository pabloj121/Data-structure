#include <iostream>
#include "Ontologias.h"
using namespace std;

pair<bool, Ontologias::const_iterator> Ontologias::Esta(const string &o) const{
  /*auto search = significados.find(o);
  
  if(search != significados.end()){ */
    for(const_iterator it = begin(); it != end(); ++it){      
      for(set<string>::const_iterator itset = (*it).first.cbegin(); itset != (*it).first.end(); ++itset){
        
        if(*itset == o)
          return pair<bool, const_iterator>(true, it);
      }
    }
    return pair<bool, const_iterator>(false, end());
}

void Ontologias::clear(){
    ab.clear();
    significados.clear();
}

map<string, set<string>> Ontologias::GetSinonimos(const string &palabra) const{
    map<string, set<string>> sinonimos; 
    //map<int, string>::const_iterator itmap;
    string significado;
    const_iterator it;
    set<string>::iterator itset;
    map<int, string>::const_iterator itmap;

    for(it = begin(); it!= end(); ++it){
      if((*it).second != -1){
        for(itset = (*it).first.begin(); itset != (*it).first.end(); ++itset){
          if(*itset == palabra){
            for(itmap = significados.begin(); itmap != significados.end(); ++itmap){
              if((*itmap).first == (*it).second)
                significado = (*itmap).second;
            }
            sinonimos.insert(pair<string, set<string>>(significado, (*it).first));
          }
        }
      }
    }
    return sinonimos;
}

list<set<string>> Ontologias::GetSuperPalabra(const string &palabra, const string &signifi) const{
  list<set<string>> superpalabra;
  iterator iterador;

  for(const_iterator it = begin(); it != end(); ++it){
    if((*it).second != -1){
      for(set<string>::const_iterator itset = (*it).first.begin(); itset != (*it).first.end(); ++itset){
        if ((*itset) == palabra)
          superpalabra = iterador.GetJerarquia();        
      }
    }
  }
  return superpalabra;
}

string Ontologias::GetDefinicion(int pos){
    map<int, string>::iterator it;

    it = significados.find(pos);
    return it->second;
}

// NO COMPLETA
bool Ontologias::lee_significados(const char *fich_sig){
    ifstream f(fich_sig, ios::in);
    int numero;
    char c;
    string definicion;

    if(f){
      while(!f.eof()){
        f >> numero;
        f >> c;
        getline(f, definicion, '\n');
        pair<int,string> p = make_pair(numero, definicion);
        significados.insert(p);
        return true;
      }
    }
    else{
        cerr << "Error al cargar el fichero significados\n";        
    }

    return !f.fail();
}

bool Ontologias::Lee(const char *fich_jerarquia, const char *fic_significados){
    ifstream f(fich_jerarquia, ios::in);
    bool significados = lee_significados(fic_significados);

    if(f){
        f >> ab;
    }
    else   
        cerr << "Error intentando leer el fichero que contiene el arbol\n";

    return f.good() and significados;    
}

    // ? COMPLETAR IOS:: OUT Y DEMAS...
bool Ontologias::Escribe(const char *fich_jerarquia, const char *fic_significados){
    ofstream f(fich_jerarquia, ios::out);
    ofstream f2(fic_significados, ios::out);

    if(f and f2){
      f << ab;
      for(map<int, string>::iterator it = significados.begin(); it!= significados.end(); ++it){
        f2 << (*it).first << "  " << (*it).second << flush;
      }
    }
    //f2 << significados;
    return f.good() and f2.good(); // !f.fail();
}