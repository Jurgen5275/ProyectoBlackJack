#ifndef MANO_H
#define MANO_H

#include"Carta.h"
#include"Mazo.h"

class Mano {
private:
	Carta** cartas;
	int tam;
	int cant;

public:
	Mano();
	~Mano();
	Carta* agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
	int getCant();
	Carta* getCarta(int);
	void agregarCarta2(Carta*);
};
#endif 