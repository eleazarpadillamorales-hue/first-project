#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    // Atributos privados
    string id;
    string nombre;
    string telefono;

public:
    // Constructor por defecto
    Cliente() {
        this->id = "";
        this->nombre = "";
        this->telefono = "";
    }

    // Constructor con parámetros
    Cliente(string id, string nombre, string telefono) {
        this->id = id;
        this->nombre = nombre;
        this->telefono = telefono;
    }

    // Métodos Getters (Consultores)
    string getId() const {
        return id;
    }

    string getNombre() const {
        return nombre;
    }

    string getTelefono() const {
        return telefono;
    }

    // Métodos Setters (Modificadores)
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setTelefono(string telefono) {
        this->telefono = telefono;
    }
};