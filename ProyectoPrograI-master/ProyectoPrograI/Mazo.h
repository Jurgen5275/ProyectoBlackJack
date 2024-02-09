#ifndef MAZO_H
#define MAZO_H
#include"Carta.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>    
#include <cstdlib> 

class Mazo {
protected:
	Carta* carta[52];

public:
	Mazo();
	~Mazo();
	void inicializar();
	void barajar();
	Carta* tomarCarta();
};
#endif