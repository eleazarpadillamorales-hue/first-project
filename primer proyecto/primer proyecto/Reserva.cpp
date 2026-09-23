#include "Reserva.h"

// Inicialización de la variable estática del contador consecutivo
int Reserva::contadorConsecutivo = 1;

Reserva::Reserva() {
    numeroReserva = 0;
    cliente = nullptr;
    cancha = nullptr;
    franjaInicial = 0;
    cantidadFranjas = 0;
    monto = 0.0f;
    activa = false;
}

Reserva::Reserva(Cliente* clientePtr, Cancha* canchaPtr, int franjaInicial, int cantidadFranjas, float monto) {
    this->numeroReserva = contadorConsecutivo++; // Asigna consecutivo único y luego incrementa
    this->cliente = clientePtr;
    this->cancha = canchaPtr;
    this->franjaInicial = franjaInicial;
    this->cantidadFranjas = cantidadFranjas;
    this->monto = monto;
    this->activa = true; // La reserva se crea activa por defecto
}

// Getters
int Reserva::getIdReserva() const { return numeroReserva; }
Cliente* Reserva::getCliente() const { return cliente; }
Cancha* Reserva::getCancha() const { return cancha; }
int Reserva::getFranjaInicial() const { return franjaInicial; }
int Reserva::getCantiladFranjas() const { return cantidadFranjas; }
float Reserva::getMonto() const { return monto; }
bool Reserva::isActiva() const { return activa; }

void Reserva::cancelar() {
    activa = false;
}

void Reserva::mostrarInformacion() const {
    cout << "---------------------------------------" << endl;
    cout << "Número de Reserva: " << numeroReserva << endl;
    cout << "Estado: " << (activa ? "Activa" : "Cancelada") << endl;

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

    // Traducir índices a hora militar para mostrar en pantalla claramente
    int horaInicio = 8 + franjaInicial;
    int horaFin = horaInicio + cantidadFranjas;

    cout << "Horario: " << (horaInicio < 10 ? "0" : "") << horaInicio << ":00 a "
        << (horaFin < 10 ? "0" : "") << horaFin << ":00 (" << cantidadFranjas << " hora/s)" << endl;
    cout << "Monto Total: $" << monto << endl;
    cout << "---------------------------------------" << endl;
}
