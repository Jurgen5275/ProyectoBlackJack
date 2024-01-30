#ifndef NODO_H
#define NODO_H

#include "JugadorGenerico.h"

struct Nodo {
public:
	JugadorGenerico* dato;
	Nodo* next;
	Nodo();
	~Nodo();
	Nodo* getNext();
};
#endif