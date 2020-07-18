template <class T>
Vector_Dinamico<T>::Vector_Dinamico(){
	if(datos!=0)
		delete [] datos;
}

template<class T>
void Vector_Dinamico<T>::Liberar(){
	if(datos!=0)
		delete[] datos;
}

template <class T>
Vector_Dinamico<T>::~ Vector_Dinamico(){
	Liberar();
}

template <class T>
int Vector_Dinamico<T>::size()const{
	return n;
}

template <class T>
T& Vector_Dinamico<T>::operator[](int i)const{
	return datos[i];
}

/*template <class T>
const T& Vector_Dinamico<T>::operator[](int i)const{
	return datos[i];
}*/

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico<T> &v){
	if(this!=v){
		if(datos!=0)
			delete []datos;
		
		reservados = v.reservados;
		n = v.n;
		
		if(v.datos!=0)
			datos = new T[reservados];

		for (int i = 0; i < n; ++i){
			datos[i] = v.datos[i];
		}
	}
	return *this;
}

template <class T>
void Vector_Dinamico<T>::Resize(int nuevotam){
	T* aux= new T[nuevotam];
	int minimo=(n<nuevotam) ? n : nuevotam;

	for (int i = 0; i < minimo; ++i){
		aux[i] = datos[i];
	}

	reservados = nuevotam;
	n = minimo;
	delete[] datos;
	datos = aux;
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
	if(n==0){
		reservados = this->n = 0;
		datos = 0;
	}
	else{
		reservados = n;
		this->n = 0;
		datos = new T[reservados];
	}
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> &original){
	reservados = original.reservados;
	n = original.n;
	if(reservados>0){
		datos = new T[reservados];
	}
	else
		datos = 0;

	for (int i = 0; i < n; ++i){
		datos[i] = original.datos[i];
	}
}

template <class T>
void Vector_Dinamico<T>::Insertar(const T &dato, int pos){
	if(n>reservados)
		Resize(2*reservados);

	for (int i = n; i > pos; ++i){
		datos[i] = datos[i-1];
	}

	datos[pos] = dato;
	n++;
}

template <class T>
void Vector_Dinamico<T>::Borrar(int pos){
	for (int i = 0; i < n-1; ++i){
		datos[i] = datos[i+1];
	}

	n--;

	if(n<reservados)
		Resize(reservados/2);
}

template <class T>
ostream& operator<<(ostream &os, Vector_Dinamico<T> &v){  // const??
	for (int i = 0; i < v.size(); ++i){
		os << v[i];  // operator[]
	}
	return os;
}