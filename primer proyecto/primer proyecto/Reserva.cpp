#include"Reserva.h"

Reserva::Reserva(){
	numeroReserva = 0;
	cliente = nullptr;
	cancha = nullptr;
	monto = 0;
	activa = false;
}
Reserva::Reserva(Cliente* clientePtr, Cancha* canchaPtr, float monto){
	this->numeroReserva = numeroReserva++;
	this->cliente = clientePtr;
	this->cancha = canchaPtr;
	this->monto = monto;
}
// Getters
int Reserva::getIdReserva() const { return numeroReserva; }
Cliente* Reserva::getCliente() const { return this->cliente; }
Cancha* Reserva::getCancha() const { return this->cancha; }
float Reserva::getMonto() const { return monto; }
bool Reserva::isActiva() const { return activa; }
void Reserva::cancelar(){
	activa = false;
}
void Reserva::mostrarInformacion() const{
	cout << "Numero de la Reserva: " << numeroReserva << endl;
	cout << " Estado de la Reserva: " << (activa ? "Activa" : "Cancelada") << endl;
	cout << " | Monto Total de la reserva: $" << monto << endl;
}