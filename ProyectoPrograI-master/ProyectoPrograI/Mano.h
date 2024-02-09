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
	Carta* agregarCarta(Mazo*);
	void limpiar();
	int getPuntos(Carta* &);
};
#endif 