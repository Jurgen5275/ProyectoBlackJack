#ifndef NODO_H
#define NODO_H

#include "JugadorGenerico.h"

struct Nodo {
public:
	JugadorGenerico* dato;
	Nodo* next;
	
	Nodo() {
		dato = nullptr;
		next = nullptr;
	}
	Nodo(JugadorGenerico* jugador) : dato(jugador), next(nullptr) {}
	~Nodo() {
		
	}
	
	Nodo* getNext();
	JugadorGenerico* getDato();
};
#endif