#ifndef CARTA_H
#define CARTA_H


#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>

class Carta {
public:
	Carta();
	Carta(int,int);
	int getValor();
	std::string getPalo(); 
	void Voltear();
	~Carta();

private:
	
	bool bocaAbajo;
	int palo;
	int valor;
};

#endif