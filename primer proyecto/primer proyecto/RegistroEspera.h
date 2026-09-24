#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Cancha.h"

using namespace std;

// Posibles estados del registro de espera
enum class EstadoEspera { ESPERANDO, ASIGNADO, CANCELADO };
//No estoy seguro si es mejor ponerlo como string o como enum,
//pero creo que enum es mejor para manejarlo internamente y luego convertirlo 
//a string para mostrarlo.
class RegistroEspera {
private:
    static int contadorConsecutivo; // Para consecutivo autoincremental
    int numeroConsecutivo;
    Cliente* cliente;
    Cancha* cancha;
    int franja;             // Posición de la franja horaria (0 a 11)
    EstadoEspera estado;    // ESPERANDO, ASIGNADO o CANCELADO

public:
    RegistroEspera();
    RegistroEspera(Cliente* clientePtr, Cancha* canchaPtr, int franja);

    // Getters
    int getNumeroConsecutivo() const;
    Cliente* getCliente() const;
    Cancha* getCancha() const;
    int getFranja() const;
    EstadoEspera getEstado() const;
    string getEstadoString() const;

    // Setters y Cambios de estado
    void setEstado(EstadoEspera nuevoEstado);

    // Método para desplegar información
    void mostrarInformacion() const;
};
