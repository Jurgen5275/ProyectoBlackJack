#include "Lista.h"


Lista::Lista() : inicio(nullptr) {}

Lista::~Lista() {
    limpiar();
}

void Lista::insertar(JugadorGenerico* jugador) {
    Nodo* nuevoNodo = new Nodo(jugador);
    if (inicio == nullptr) {
        inicio = nuevoNodo;
    }
    else {
        Nodo* temp = inicio;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
}

void Lista::limpiar() {
    Nodo* temp = inicio;
    while (temp != nullptr) {
        Nodo* siguiente = temp->next;
        delete temp;
        temp = siguiente;
    }
    inicio = nullptr;
}

Nodo* Lista::getInicio() {
    return inicio;
}

bool Lista::listaVacia() {


    if (inicio == nullptr) {
        return true;
    }
    else {
        return false;
    }

}
