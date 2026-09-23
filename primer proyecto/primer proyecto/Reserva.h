#pragma once
#include <iostream>
#include <string>
#include "Cancha.h"
#include "Cliente.h"

using namespace std;

class Reserva {
private:
    static int contadorConsecutivo; // Para generar el id autoincremental de forma global
    int numeroReserva;
    Cliente* cliente;
    Cancha* cancha;
    int franjaInicial;     
    int cantidadFranjas;     
    float monto;
    bool activa;

public:
    Reserva();
    Reserva(Cliente* clientePtr, Cancha* canchaPtr, int franjaInicial, int cantidadFranjas, float monto);

    // Getters
    int getIdReserva() const;
    Cliente* getCliente() const;
    Cancha* getCancha() const;
    int getFranjaInicial() const;
    int getCantidadFranjas() const;
    float getMonto() const;
    bool isActiva() const;

    // Métodos de comportamiento
    void cancelar();
    void mostrarInformacion() const;
};
