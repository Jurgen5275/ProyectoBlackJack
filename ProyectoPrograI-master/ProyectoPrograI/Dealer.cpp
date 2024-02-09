#include"Dealer.h"

Dealer::~Dealer() {

}

Carta* Dealer::pedirCarta(Mazo* mazo) {
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

void Dealer::volteaSegunda() {
	// Verificar si hay al menos dos cartas en la mano
	if (mano->getCant() >= 2) {
		// Iterar sobre las cartas en la mano
		for (int i = 0; i < 2; ++i) {
			// Voltear la segunda carta
			if (i == 1) {
				mano->getCarta(i)->Voltear();
			}
		}
	}
}
