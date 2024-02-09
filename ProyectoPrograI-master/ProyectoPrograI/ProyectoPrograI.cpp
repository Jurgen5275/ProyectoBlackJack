#include <iostream>
#include"Lista.h"
#include"Jugador.h"

bool verificarNicknameRepetido(Lista,std::string&);

int main()
{
    Lista l;
    std:: cout << "¡Bienvenido a Blackjack!" << std::endl;

    int opcion;
    do {
        std::cout << "Opciones:" << std::endl;
        std::cout << "1) Nuevo Juego" << std::endl;
        std::cout << "2) Cargar Partida" << std::endl;
        std::cout << "3) Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            // Nuevo Juego
            int cantidadJugadores;
            std::cout << "Ingrese la cantidad de jugadores (máximo 7): ";
            std::cin >> cantidadJugadores;

            if (cantidadJugadores < 1 || cantidadJugadores > 7) {
                std::cout << "Cantidad de jugadores no válida. Debe ser entre 1 y 7." << std::endl;
                break;
            }

            for (int i = 0; i < cantidadJugadores; ++i) {
                    std::string nuevoNickname;
                    std::cout << "Ingrese el nickname para el Jugador " << i + 1 << ": ";
                    std::cin >> nuevoNickname;
                    if (verificarNicknameRepetido(l, nuevoNickname)) {
                        std::cout << "¡Error! Este nickname ya está en uso. Intente con otro." << std::endl;
                    }
                    Jugador* jugador1 = new Jugador(nuevoNickname);
                    Nodo nodo1(jugador1);
                    l.insertar(jugador1);

            }

            // Ahora se pasa a la pantalla de juego
            // y se comienza la lógica del juego, permitiendo que cada jugador juegue su turno, etc.
            break;

        case 2:
            // Lógica para cargar partida
            std::cout << "Cargar Partida: Funcionalidad no implementada todavía." << std::endl;
            break;

        case 3:
            std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
            break;

        default:
            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            break;
        }

    } while (opcion != 3);

    return 0;
}

bool verificarNicknameRepetido(Lista jugadores, std::string& nuevoNickname) {
    Nodo* temp = jugadores.getInicio();
    while (temp->next != nullptr) {
        if (temp->dato == nuevoNickname) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}