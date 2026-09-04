#include <iostream>
#include <string>
#include"ColeccionReservas.h"

// Constructor: Reserva espacio para el arreglo dinámico de punteros
ColeccionReservas::ColeccionReservas() {
    // Inicialización de punteros en nullptr por seguridad
    for (int i = 0; i < tam; i++) {
        this->clientes[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria consumida por los objetos y el arreglo
ColeccionReservas::~ColeccionReservas() {
    for (int i = 0; i < tam; i++) {
        delete clientes[i]; // Borra el objeto Cliente individual
        clientes[i] = nullptr;
    }
}

void ColeccionReservas::agregarCliente(Cliente cliente) {
    if (cantidad < tam) {
        clientes[cantidad] = new Cliente(cliente);
        cantidad++;
    }
}

// Busca un cliente por su número de identificación
Cliente* ColeccionReservas::buscarPorId(string id) {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getId() == id) {
            return clientes[i];
        }
    }
    return nullptr; // No se encontró el cliente
}

// Muestra en consola la lista de clientes registrados
void ColeccionReservas::listaClientes(){
    cout << "Cantidad de clientes: " << cantidad << endl;
    for (int i = 0;i < cantidad;i++) {
        clientes[i]->mostrar();
        cout << endl;
    }
}

int ColeccionReservas::getCantidad(){
    return this->cantidad;
}
