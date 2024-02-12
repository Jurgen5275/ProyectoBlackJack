#ifndef JUGADOR_H
#define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador:public JugadorGenerico{
public:
	Jugador();
	Jugador(std::string& nombre, Mano*man) : JugadorGenerico(nombre, man) {}
	~Jugador();
	Carta* pedirCarta(Mazo*);
	bool sePaso();
	std::string getNombre();
	void mostrarMano();
};
#endif