#ifndef JUGADOR_H
#define JUGADOR_H
#include "Carta.h"

class Jugador {
public:
	Jugador();
	~Jugador();
	Carta* pedirCarta();
};
#endif