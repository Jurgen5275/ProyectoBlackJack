#ifndef MANO_H
#define MANO_H

#include"Carta.h"
#include"Mazo.h"

class Mano {
private:
	Carta* cartas[];

public:
	Mano();
	~Mano();
	void agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
};
#endif 