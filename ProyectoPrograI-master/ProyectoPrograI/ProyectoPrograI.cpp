#include <iostream>
#include <string>
#include"Juego.h"

int main() {
    std::cout << "¡Bienvenido al juego de Blackjack!\n" << std::endl;
    Juego j;
    int opcion;
    do {
        std::cout << "Seleccione una opción:" << std::endl;
        std::cout << "1) Nuevo Juego" << std::endl;
        std::cout << "2) Cargar Partida" << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            j.jugar();
            break;
        }
        case 2: {
            std::string nombreArchivo;
            std::cout << "Ingrese el nombre del archivo de partida: ";
            std::cin >> nombreArchivo;
            j.cargarPartida(nombreArchivo);
            break;
        }
        case 3: {
            std::cout << "¡Gracias por jugar al Blackjack!" << std::endl;
            break;
        }
        default: {
            std::cout << "Opción no válida. Inténtelo de nuevo." << std::endl;
            break;
        }
        }
    } while (opcion != 3);

    return 0;
}