#include "RegistroEspera.h"

// Inicialización de la variable estática del autoincremental
int RegistroEspera::contadorConsecutivo = 1;

RegistroEspera::RegistroEspera() {
    numeroConsecutivo = 0;
    cliente = nullptr;
    cancha = nullptr;
    franja = 0;
    estado = EstadoEspera::ESPERANDO;
}

RegistroEspera::RegistroEspera(Cliente* clientePtr, Cancha* canchaPtr, int franja) {
    this->numeroConsecutivo = contadorConsecutivo++;
    this->cliente = clientePtr;
    this->cancha = canchaPtr;
    this->franja = franja;
    this->estado = EstadoEspera::ESPERANDO;
}

// Getters
int RegistroEspera::getNumeroConsecutivo() const { return numeroConsecutivo; }
Cliente* RegistroEspera::getCliente() const { return cliente; }
Cancha* RegistroEspera::getCancha() const { return cancha; }
int RegistroEspera::getFranja() const { return franja; }
EstadoEspera RegistroEspera::getEstado() const { return estado; }

string RegistroEspera::getEstadoString() const {
    switch (estado) {
    case EstadoEspera::ESPERANDO: return "Esperando";
    case EstadoEspera::ASIGNADO:  return "Asignado";
    case EstadoEspera::CANCELADO: return "Cancelado";
    default:                      return "Desconocido";
    }
}

void RegistroEspera::setEstado(EstadoEspera nuevoEstado) {
    this->estado = nuevoEstado;
}

void RegistroEspera::mostrarInformacion() const {
    cout << "---------------------------------------" << endl;
    cout << "Consecutivo Espera: #" << numeroConsecutivo << endl;
    cout << "Estado: " << getEstadoString() << endl;

    if (cliente != nullptr) {
        cout << "Cliente: " << cliente->getNombre() << " (ID: " << cliente->getIdentificacion() << ")" << endl;
    }
    else {
        cout << "Cliente: No asignado" << endl;
    }

    if (cancha != nullptr) {
        cout << "Cancha: " << cancha->getCodigo() << endl;
    }
    else {
        cout << "Cancha: No asignada" << endl;
    }

    int horaInicio = 8 + franja;
    cout << "Franja Horaria: " << (horaInicio < 10 ? "0" : "") << horaInicio << ":00 a "
        << (horaInicio + 1 < 10 ? "0" : "") << horaInicio + 1 << ":00 (Posición [" << franja << "])" << endl;
    cout << "---------------------------------------" << endl;
}
