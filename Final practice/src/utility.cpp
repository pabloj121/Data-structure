#include <iostream>
#include <set>
#include "utility.h"
using namespace std;

istream &Avanzar(istream&is){
    while(is.eof()){
        if(isspace(is.peek()) || is.peek() == '\n')
            is.get();
    }
    return is;
}

istream &operator>>(istream& is, pair<set<string>, int>& p) {
    int n;
    char palabra[200];

    is >> n;
    Avanzar(is);

    for(int i = 0; i < n; i++){
        // Leemos 100 caracteres o hasta que llegemos a una coma
        is.getline(palabra, 100, ',');
        // Insertamos la cadena leida en el set
        p.first.insert(palabra);
    }

    // Leeemos el entero que será la clave de significados
    is >> p.second;

    return is;
}

ostream &operator<<(ostream &os, const pair<set<string>, int> &p){        
    for (set<string>::const_iterator it = p.first.begin(); it != p.first.end(); ++it){
        os << *it << flush << ",";
    }
    os << p.second << endl;

    return os;
}