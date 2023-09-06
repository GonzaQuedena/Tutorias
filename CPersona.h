#pragma once

#include"Util.h"

class CPersona {

public:
	/*constructor clase*/
	CPersona(stg nombre = "", us edad = 0, size_t ncomp=0, double monto=0.0f) {
		/*inicializando atributos*/
		this->nombre = nombre;
		//this->direc = direc;
		this->edad = edad;
		//this->telf = telf;
		this->nrocomp = ncomp;

		this->monto = monto;
	}
	/*método de clase*/
	string toString() {
		return nombre + " " + " " + to_string(edad) + " " 
			+ to_string(monto) + " " + to_string(nrocomp) + "\n";
	}

	/*atributos clase*/
	stg nombre;
	us edad;
	size_t nrocomp;

	double monto;
};