#ifndef JUEGO_H
#define JUEGO_H
#include"Lista.h"
#include"Mazo.h"
#include"Dealer.h"
#include"Jugador.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

class Juego {
private:
	Lista listaJugadores;
	Mazo baraja;
	Dealer* dealer;

public:
	Juego();
	~Juego();
	void jugar();
	void cargarPartida(std::string&);
};
#endif

