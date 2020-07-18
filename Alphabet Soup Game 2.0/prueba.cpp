
//Este fichero te permite probar el modulo matriz dispersa.

#include "matriz_dispersa.h"
#include <cstring>
int main(){
 
 Matriz_Dispersa<char> P('a');
 int r,c;
 r=2;c=2;

 //La Ponemos horizontal
 const char * cad="hola";
 cout << P.size() << endl;

 cout << "antes del for" << endl;
 for (unsigned int i=0;i<strlen(cad);i++,c++){
     //cout << "primera llamada" << endl;
     P.Set(r,c,cad[i]);
     cout << P.size() << endl;
     cout << P.ValorPorDefecto() << endl;
 }

 /*r=2;c=2;
 cout << "despues del primer for" << endl;
 for (unsigned int i=0;i<strlen(cad);i++,r++)
     P.Set(r,c,cad[i]);*/
 //cout << P << endl;	
}     