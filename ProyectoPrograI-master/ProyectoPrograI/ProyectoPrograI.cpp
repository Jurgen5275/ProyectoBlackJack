#include <iostream>
#include <string>

int main() {
    std::cout << "�Bienvenido al juego de Blackjack!\n" << std::endl;

    int opcion;
    do {
        std::cout << "Seleccione una opci�n:" << std::endl;
        std::cout << "1) Nuevo Juego" << std::endl;
        std::cout << "2) Cargar Partida" << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cout << "Opci�n: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            
        }
        case 2: {
            // Cargar Partida
            // L�gica para cargar una partida guardada
            break;
        }
        case 3: {
            std::cout << "�Gracias por jugar al Blackjack!" << std::endl;
            break;
        }
        default: {
            std::cout << "Opci�n no v�lida. Int�ntelo de nuevo." << std::endl;
            break;
        }
        }
    } while (opcion != 3);

    return 0;
}