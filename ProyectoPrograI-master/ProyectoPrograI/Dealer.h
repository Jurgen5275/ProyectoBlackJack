#ifndef DEALER_H
#define DEALER_H
#include"JugadorGenerico.h"

class Dealer:public JugadorGenerico {
public:
	Dealer() : JugadorGenerico("Dealer") {}
	~Dealer();
	Carta* pedirCarta();
	void volteaSegunda();
private:
	bool bocaAbajo;
};

#endif