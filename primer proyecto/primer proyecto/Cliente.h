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
    Cliente();
    // Constructor con parámetros
    Cliente(string id, string nombre, string telefono);
    //Destructor
    ~Cliente();
    // Métodos Getters (Consultores)
    string getId();
    string getNombre();
    string getTelefono();
    // Métodos Setters (Modificadores)
    void setNombre(string nombre);
    void setTelefono(string telefono);
    void mostrar();
};