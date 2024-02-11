#ifndef LISTA_H
#define LISTA_H
#include"Nodo.h"

class Lista {
public:
	Nodo* inicio;

public:
	Lista();
	~Lista();
	Nodo* getInicio();
	void insertar(JugadorGenerico*);
	bool listaVacia();
	void limpiar();
};
#endif