#include "Jugador.h"

Jugador::~Jugador() {

}

Carta* Jugador::pedirCarta(Mazo* mazo) {
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			mano->agregarCarta((Mazo*)&nuevaCarta);
			return nuevaCarta;
		}
		else {
			std::cout << "No hay mas cartas en el mazo\n" << std::endl;
			return nullptr;
		}
	}
	else {
		std::cout << "No se puede pedir mas cartas\n" << std::endl;
		return nullptr;
	}
}