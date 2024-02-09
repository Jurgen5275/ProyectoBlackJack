#ifndef JUGADOR_H
#define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador:public JugadorGenerico{
public:
	Jugador(std::string& nombre) : JugadorGenerico(nombre) {}
	~Jugador();
	Carta* pedirCarta(Mazo*);
};
#endif