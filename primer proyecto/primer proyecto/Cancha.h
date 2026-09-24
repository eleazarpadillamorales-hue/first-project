#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cancha {
private:
    string codigo;
    string tipoDeporte;
    double precioPorHora;
    char franjasHorarias[12]; // 12 franjas de 1 hora: [0] es 08:00-09:00 ... [11] es 19:00-20:00

public:
    Cancha();
    Cancha(string codigo, string tipoDeporte, double precioPorHora);
    ~Cancha();

    // Getters y Setters
    string getCodigo() const;
    string getTipoDeporte() const;
    double getPrecioPorHora() const;
    void setPrecioPorHora(double precioPorHora);

    // Métodos para franjas horarias
    char getEstadoFranja(int indice) const;
    bool cambiarEstadoFranja(int indice, char nuevoEstado);
    
    // Métodos de estadísticas y visualización
    double calcularPorcentajeOcupacion() const;
    void mostrarDisponibilidad() const;
    void mostrar() const;
};
