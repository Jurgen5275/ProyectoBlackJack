#include "Lista.h"


Lista::~Lista() {
    Nodo* actual = inicio;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        anterior = actual;
        actual = actual->next;
        delete anterior;
    }

}

// Retorna un apuntador al inicio de la lista
Nodo* Lista::getInicio() {
    return inicio;
}

void Lista::insertar(Nodo n) {
    // Inserta el primer elemento si la lista está vacía
    if (inicio == nullptr) {
        inicio = new Nodo;
        inicio->dato = n.dato;
        inicio->next = nullptr;
    }
    else {
        // Recorre la lista hasta el último nodo e inserta
        // un nuevo nodo en la siguiente posición
        Nodo* tmp = inicio;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Nodo;
        tmp->next->dato = n.dato;
        tmp->next->next = nullptr;
    }
}

void Lista::borrar(Nodo n) {

    Nodo* actual = inicio;
    Nodo* anterior = nullptr;
    while (actual != nullptr && actual->dato != n.dato) {
        anterior = actual;
        actual = actual->next;
    }

    if (anterior == nullptr) {
        // El nodo a eliminar es el primero en la lista
        inicio = actual->next;
    }
    else {
        // El nodo a eliminar no es el primero
        anterior->next = actual->next;
    }

    // Liberar la memoria del nodo eliminado
    delete actual;
}

bool Lista::listaVacia() {


    if (inicio == nullptr) {
        return true;
    }
    else {
        return false;
    }

}
