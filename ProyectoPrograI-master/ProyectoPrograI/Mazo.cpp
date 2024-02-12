#include "Mazo.h"

Mazo::Mazo() {

	tam = 52;
	can = 0;
	carta = new Carta * [tam];

	// Limpiando el vector...
	for (int i = 0; i < tam; i++) {
		carta[i] = nullptr;
	}

}


Mazo::~Mazo() {
	for (int i = 0; i < tam; i++) {
		delete carta[i]; // Liberar la memoria de cada Carta
	}
	delete[] carta; // Liberar la memoria del arreglo de punteros
}

void Mazo::inicializar() {
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int x = 0; x < 13; x++)
			{
				carta[i] = new Carta(x, j);
				i++;
			}

		}
	}
		
}

void Mazo::barajar() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	
	

	// Aplicar el algoritmo de Fisher-Yates
	for (int i = 52 - 1; i > 0; --i) {
		// Generar un índice aleatorio entre 0 e i (inclusive)
		int j = std::rand() % (i + 1);

		// Intercambiar elementos en las posiciones i y j
		std::swap(carta[i], carta[j]);
	}
}

Carta* Mazo::tomarCarta() {
	if (can < tam) {
		Carta* cartaTomada = carta[can];
		carta[can] = nullptr;
		can++;
		return cartaTomada;
	}
	else {
		std::cout << "No hay más cartas en el mazo." << std::endl;
		return nullptr;
	}
}
