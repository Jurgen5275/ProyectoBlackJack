#ifndef DEALER_H
#define DEALER_H
#include"JugadorGenerico.h"

class Dealer : public JugadorGenerico {
public:
	Dealer();
	Dealer(std::string nick, Mano* man) : JugadorGenerico(nick, man) {}
	~Dealer();
	Carta* pedirCarta(Mazo*);
	void volteaSegunda();
	bool sePaso();
	std::string getNombre();
	void mostrarMano();

};

#endif