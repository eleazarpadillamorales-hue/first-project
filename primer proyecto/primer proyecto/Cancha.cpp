#include "Cancha.h"

// Constructor por defecto
Cancha::Cancha() {
    this->codigo = "";
    this->tipoDeporte = "";
    this->precioPorHora = 0.0;
    // Inicializa todas las franjas como Libres ('L')
    for (int i = 0; i < 12; i++) {
        this->franjasHorarias[i] = 'L';
    }
}

// Constructor con parámetros
Cancha::Cancha(string codigo, string tipoDeporte, double precioPorHora) {
    this->codigo = codigo;
    this->tipoDeporte = tipoDeporte;
    this->precioPorHora = precioPorHora;
    // Inicializa todas las franjas como Libres ('L')
    for (int i = 0; i < 12; i++) {
        this->franjasHorarias[i] = 'L';
    }
}

Cancha::~Cancha() {}

// Métodos Getters
string Cancha::getCodigo() const {
    return codigo;
}

string Cancha::getTipoDeporte() const {
    return tipoDeporte;
}

double Cancha::getPrecioPorHora() const {
    return precioPorHora;
}

// Métodos Setters
void Cancha::setPrecioPorHora(double precioPorHora) {
    if (precioPorHora >= 0) {
        this->precioPorHora = precioPorHora;
    }
}

// Obtener el estado de una franja específica (índice 0 a 11)
char Cancha::getEstadoFranja(int indice) const {
    if (indice >= 0 && indice < 12) {
        return franjasHorarias[indice];
    }
    return 'X'; // Retorna 'X' si el índice es inválido
}

// Cambiar el estado de una franja respetando las reglas de negocio
bool Cancha::cambiarEstadoFranja(int indice, char nuevoEstado) {
    if (indice < 0 || indice >= 12) {
        cout << "Error: Indice fuera de rango (debe ser entre 0 y 11)." << endl;
        return false; 
    }

    char estadoActual = franjasHorarias[indice];

    // Regla: No colocar en Mantenimiento ('M') si la franja esta Ocupada ('O')
    if (nuevoEstado == 'M' && estadoActual == 'O') {
        cout << "Error: No se puede colocar en mantenimiento (M) una franja ocupada (O)." << endl;
        return false;
    }

    // Cambios validos
    if (nuevoEstado == 'L' || nuevoEstado == 'O' || nuevoEstado == 'M') {
        this->franjasHorarias[indice] = nuevoEstado;
        return true;
    }

    return false;
}

// Calcula el porcentaje de ocupación (únicamente franjas con reserva activa 'O')
double Cancha::calcularPorcentajeOcupacion() const {
    int ocupadas = 0;
    for (int i = 0; i < 12; i++) {
        if (franjasHorarias[i] == 'O') {
            ocupadas++;
        }
    }
    return (static_cast<double>(ocupadas) / 12.0) * 100.0;
}

// Visualización clara del arreglo de 12 franjas horarias requerida por el proyecto
void Cancha::mostrarDisponibilidad() const {
    cout << "\nDisponibilidad de la Cancha " << codigo << ":" << endl;
    
    // Fila de horas (08:00 a 19:00)
    cout << "Hora:   ";
    for (int i = 0; i < 12; i++) {
        int h = 8 + i;
        cout << (h < 10 ? "0" : "") << h << ":00 ";
    }
    cout << endl;

    // Fila de estados (L, O, M)
    cout << "Estado: ";
    for (int i = 0; i < 12; i++) {
        cout << "  " << franjasHorarias[i] << "   ";
    }
    cout << endl;

    // Fila de índices/posiciones
    cout << "Pos:    ";
    for (int i = 0; i < 12; i++) {
        cout << " [" << (i < 10 ? "0" : "") << i << "] ";
    }
    cout << endl;
    cout << "(L = Libre | O = Ocupada | M = Mantenimiento)\n" << endl;
}

void Cancha::mostrar() const {
    cout << "--- Informacion de la Cancha ---" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Tipo de Deporte: " << tipoDeporte << endl;
    cout << "Precio por hora: $" << precioPorHora << endl;
    mostrarDisponibilidad();
}
