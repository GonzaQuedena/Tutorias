#include<iostream>
#include"CLoteria.h"

int main() {

	CLoteria* loteria = new CLoteria;
	/*registrando personas*/
	loteria->registrarPersona(new CPersona("Gustavo", 20, 234515));
	loteria->registrarPersona(new CPersona("Carlos", 23, 123456));
	loteria->registrarPersona(new CPersona("Luciana", 18, 123456));
	loteria->registrarPersona(new CPersona("Valentino", 25, 240534));

	/*generando numero ganador*/
	loteria->generarNumeroGanador(123456);

	/*---*/
	loteria->ganadorLoteria();
	
	/*listado personas*/
	loteria->listarRegPersonas();

	delete loteria;
	return 0;
}