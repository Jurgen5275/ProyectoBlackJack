#ifndef DEALER_H
#define DEALER_H
#include"JugadorGenerico.h"

class Dealer : public JugadorGenerico {
public:
	Dealer() : JugadorGenerico("Dealer") {}
	~Dealer();
	Carta* pedirCarta(Mazo*);
	void volteaSegunda();
	bool sePaso();
	std::string getNombre();
private:

};

#endif