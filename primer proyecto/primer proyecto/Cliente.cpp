#include "Cliente.h"

// Constructor por defecto
Cliente::Cliente() {
    id = "";
    nombre = "";
    telefono = "";
}

// Constructor con parámetros
Cliente::Cliente(string id, string nombre, string telefono) {
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
}

Cliente::~Cliente() {}

// Métodos Getters
string Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getTelefono() const {
    return telefono;
}

// Métodos Setters
void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}

// Método para mostrar información en consola
void Cliente::mostrar() const {
    cout << "--- Informacion del Cliente ---" << endl;
    cout << "Identificación: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Teléfono: " << telefono << endl;
}
