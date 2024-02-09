#include "Mazo.h"

Mazo::~Mazo() {

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
	// Verificar si el mazo está vacío
	if (carta[0] == nullptr) {
		std::cout << "El mazo está vacío." << std::endl;
		return nullptr;
	}

	// Encontrar la primera carta disponible en el mazo
	int i = 0;
	while (i < 52 && carta[i] == nullptr) {
		i++;
	}

	// Si no se encontró ninguna carta disponible
	if (i == 52) {
		std::cout << "El mazo está vacío." << std::endl;
		return nullptr;
	}

	// Tomar la carta en la posición i
	Carta* cartaTomada = carta[i];
	carta[i] = nullptr; // Marcar la posición como vacía
	return cartaTomada;
}
