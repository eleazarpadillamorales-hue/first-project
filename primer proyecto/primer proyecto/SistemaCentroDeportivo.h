#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "ColeccionClientes.h"
#include "ColeccionCanchas.h"
#include "ColeccionReservas.h"
#include "ColeccionEspera.h"

using namespace std;

class SistemaCentroDeportivo {
private:
    ColeccionClientes clientes;
    ColeccionCanchas canchas;
    ColeccionReservas reservas;
    ColeccionEspera listaEspera;

    // Métodos auxiliares de validación e interfaz
    void limpiarConsola() const;
    void pausarConsola() const;
    int leerOpcionInt();
    double leerDoublePositivo(string mensaje);
    string leerTexto(string mensaje);

    // Submenús del sistema
    void menuGestionCanchas();
    void menuGestionClientes();
    void menuGestionReservas();
    void menuGestionEspera();
    void menuReportesEstadisticas();

    // Métodos de operaciones por módulo
    // Módulo Canchas
    void registrarCancha();
    void modificarPrecioCancha();
    void gestionarMantenimientoCancha();

    // Módulo Clientes
    void registrarCliente();

    // Módulo Reservas
    void registrarReserva();
    void cancelarReserva();

    // Módulo Lista de Espera
    void registrarEnEspera();
    void cambiarEstadoEspera();

    // Módulo Reportes
    void reporteCanchaMasReservada();
    void reporteClienteMasReservas();
    void reporteIngresoTotal();
    void reportePorcentajeOcupacionCanchas();
    void reporteHorasExtremasReservas();

public:
    SistemaCentroDeportivo();
    ~SistemaCentroDeportivo();

    // Método principal de ejecución
    void ejecutar();
};
