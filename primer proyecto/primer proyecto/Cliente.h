#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string id;
    string nombre;
    string telefono;

public:
    Cliente();
    Cliente(string id, string nombre, string telefono);
    ~Cliente();

    // Getters (Consultores)
    string getId() const;
    string getNombre() const;
    string getTelefono() const;

    // Setters (Modificadores)
    void setNombre(string nombre);
    void setTelefono(string telefono);

    // Muestra de datos
    void mostrar() const;
};
