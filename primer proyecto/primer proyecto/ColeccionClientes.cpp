#include <iostream>
#include <string>
#include"ColeccionClientes.h"
#include"Cliente.h"

// Constructor: Reserva espacio para el arreglo dinámico de punteros
ColeccionClientes::ColeccionClientes(int capacidad) {
    this->capacidad = capacidad;
    this->cantidad = 0;

    // Asignación de memoria dinámica para el arreglo de punteros
    this->clientes = new Cliente * [this->capacidad];

    // Inicialización de punteros en nullptr por seguridad
    for (int i = 0; i < this->capacidad; i++) {
        this->clientes[i] = nullptr;
    }
}

// Destructor: Libera la memoria consumida por los objetos y el arreglo
ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < this->cantidad; i++) {
        delete this->clientes[i]; // Borra el objeto Cliente individual
    }
    delete[] this->clientes;      // Borra el arreglo de punteros
}

bool ColeccionClientes::agregarCliente(Cliente* cliente) {
    if (cliente == nullptr || this->cantidad >= this->capacidad) {
        return false;
    }

    // Validar que el cliente no exista previamente por id
    if (this->buscarPorId(cliente->getId()) != nullptr) {
        return false;
    }

    this->clientes[this->cantidad] = cliente;
    this->cantidad++;
    return true;
}

// Busca un cliente por su número de identificación
Cliente* ColeccionClientes::buscarPorId(std::string id) {
    for (int i = 0; i < this->cantidad; i++) {
        if (this->clientes[i] != nullptr && this->clientes[i]->getId() == id) {
            return this->clientes[i];
        }
    }
    return nullptr; // No se encontró el cliente
}

// Muestra en consola la lista de clientes registrados
void ColeccionClientes::listarClientes() const {
    if (this->cantidad == 0) {
        std::cout << "No hay clientes registrados en el sistema.\n";
        return;
    }

    std::cout << "--- LISTADO DE CLIENTES ---\n";
    for (int i = 0; i < this->cantidad; i++) {
        if (this->clientes[i] != nullptr) {
            std::cout << "Cliente [" << (i + 1) << "]: "
                << this->clientes[i]->getNombre()
                << " | ID: " << this->clientes[i]->getId()
                << " | Telefono: " << this->clientes[i]->getTelefono() << "\n";
        }
    }
}

int ColeccionClientes::getCantidad() const {
    return this->cantidad;
}

int ColeccionClientes::getCapacidad() const {
    return this->capacidad;
}