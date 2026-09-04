#include <iostream>
#include <string>
#include"ColeccionClientes.h"

// Constructor: Reserva espacio para el arreglo dinámico de punteros
ColeccionClientes::ColeccionClientes() {
    // Inicialización de punteros en nullptr por seguridad
    for (int i = 0; i < capacidad; i++) {
        this->clientes[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria consumida por los objetos y el arreglo
ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < cantidad; i++) {
        delete clientes[i]; // Borra el objeto Cliente individual
        clientes[i] = nullptr;
    }
}

void coleccionClientes::agregarCliente(Cliente cliente) {
    if (cantidad < capacidad) {
        clientes[cantidad] = new Cliente(cliente);
        cantidad++;
    }
}

// Busca un cliente por su número de identificación
Cliente* ColeccionClientes::buscarPorId(string id) {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getId() == id) {
            return clientes[i];
        }
    }
    return nullptr; // No se encontró el cliente
}

// Muestra en consola la lista de clientes registrados
void ColeccionClientes::listarClientes() const {
    cout << "Cantidad de clientes: " << cantidad << endl;
    for (int i = 0;i < cantidad;i++) {
        clientes[i]->mostrar();
        cout << endl;
    }
}

int ColeccionClientes::getCantidad() const {
    return this->cantidad;
}

int ColeccionClientes::getCapacidad() const {
    return this->capacidad;
}