#ifndef DEALER_H
#define DEALER_H
#include"Carta.h"

class Dealer {
public:
	Dealer();
	~Dealer();
	Carta* pedirCarta();
	void volteaSegunda();
};
#endif