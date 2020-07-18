#ifndef _UTILIDADES_H
#define _UTILIDADES_H
#include <iostream>
#include <set>
using namespace std;

istream &Avanzar(istream &is);

istream &operator>>(istream &is, pair<set<string>, int> &p);

ostream &operator<<(ostream &os, const pair<set<string>, int> &p);

#endif