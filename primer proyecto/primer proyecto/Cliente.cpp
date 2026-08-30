#include"Cliente.h"

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
// Métodos Getters (Consultores)
string Cliente::getId(){
    return id;
}

string Cliente::getNombre(){
    return nombre;
}

string Cliente::getTelefono(){
    return telefono;
}

// Métodos Setters (Modificadores)
void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setTelefono(string telefono) {
    this->telefono = telefono;
}