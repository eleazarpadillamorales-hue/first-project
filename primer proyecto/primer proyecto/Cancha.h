#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cancha {
private:
    // Atributos privados
    int codigo;
    string tipoDeporte;
    double precioPorHora;
    char franjasHorarias[12]; // Representa 12 horas del día chambeando

public:
    // Constructor por defecto
    Cancha() {
        this->codigo = 0;
        this->tipoDeporte = "";
        this->precioPorHora = 0.0;
        // Inicializa todas las franjas como Libres ('L')
        for (int i = 0; i < 12; i++) {
            this->franjasHorarias[i] = 'L';
        }
    }

    // Constructor con parámetros
    Cancha(int codigo, string tipoDeporte, double precioPorHora) {
        this->codigo = codigo;
        this->tipoDeporte = tipoDeporte;
        this->precioPorHora = precioPorHora;
        // Inicializa todas las franjas como Libres ('L')
        for (int i = 0; i < 12; i++) {
            this->franjasHorarias[i] = 'L';
        }
    }

    // Métodos Getters
    int getCodigo() const {
        return codigo;
    }

    string getTipoDeporte() const {
        return tipoDeporte;
    }

    double getPrecioPorHora() const {
        return precioPorHora;
    }

    // Métodos Setters
    void setPrecioPorHora(double precioPorHora) {
        this->precioPorHora = precioPorHora;
    }

    // Obtener el estado de una franja específica (índice 0 a 11)
    char getEstadoFranja(int indice) const {
        if (indice >= 0 && indice < 12) {
            return franjasHorarias[indice];
        }
        return 'X'; // Retorna 'X' si el índice es inválido
    }

    // Cambiar el estado de una franja (ej: 'L' por Libre, 'O' por Ocupada)
    bool cambiarEstadoFranja(int indice, char nuevoEstado) {
        if (indice >= 0 && indice < 12) {
            this->franjasHorarias[indice] = nuevoEstado;
            return true;
        }
        return false; // Retorna false si el índice está fuera de rango
    }

    // Calcula el porcentaje de franjas que NO están libres ('L')
    double calcularPorcentajeOcupacion() const {
        int ocupadas = 0;
        for (int i = 0; i < 12; i++) {
            if (franjasHorarias[i] != 'L') {
                ocupadas++;
            }
        }
        return (static_cast<double>(ocupadas) / 12.0) * 100.0;
    }
};