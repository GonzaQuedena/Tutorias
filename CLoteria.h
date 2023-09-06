#pragma once

#include"CPersona.h"

class CLoteria {

public:
	/*constructor de clase*/
	CLoteria() : nroGan(0), pozo(50000){
		regSorteo = new DoubleLinkedList<CPersona*>;
	}
	/*destructor de clase*/
	~CLoteria() {
		delete regSorteo;
	}
	/*metodos de clase*/
	void registrarPersona(CPersona* persona) {
		/*agregando entidad a lista doble*/
		regSorteo->push_back(persona);
	}
	void generarNumeroGanador(size_t nroGan) {
		/*estableciendo nro ganador*/
		this->nroGan = nroGan;
	}
	void listarRegPersonas() {
		/*mostrando elementos de lista*/
		regSorteo->iterator(
			[](CPersona* aux) { std::cout << aux->toString(); },
			'n'
		);
	}
	bool isSorted(size_t nro) {

		bool flag = true;
		stg stgNro = to_string(nro);

		for (us i = 1; i <= stgNro.size() - 1; ++i) {

			int current = stoi(stg(1, stgNro[i]));
			int prev = stoi(stg(1, stgNro[i - 1]));

			//cout << prev << " - " << current << "\n";

			if (current < prev) {
				flag = false;
			}
		}

		return flag;
	}
	bool verificarCoincidenciaNroGan(size_t nroP) {

		us cantC = 0;

		stg stgNroG = to_string(this->nroGan);
		stg stgNroP = to_string(nroP);

		for (us i = 0; i < 6; ++i) {

			if (stgNroG[i] == stgNroP[i]) {
				cantC += 1;
			}
		}

		return (cantC == 4);
	}
	void ganadorLoteria() {
		/**/
		vector<CPersona*> ganNE;
		vector<CPersona*> gan4N;

		/*buscando ganadores*/
		regSorteo->iterator(

			[&](CPersona* aux) { 

				us nroComp = aux->nrocomp;

				/*verificamos Nro exacto*/
				if (nroComp == this->nroGan) {
					ganNE.push_back(aux);
				}
				else {
					/*verificamos 4Nro iguales*/
					if (isSorted(nroComp)
						&& verificarCoincidenciaNroGan(nroComp)) {

						gan4N.push_back(aux);
					}
				}

			},
			'n'
		);

		for (us i = 0; i < ganNE.size(); ++i) {
			double montoPartido = pozo / ganNE.size();
			ganNE.at(i)->monto = montoPartido;
		}
	}


	/*atributos clase*/
	size_t pozo;
	size_t nroGan;
	DoubleLinkedList<CPersona*>* regSorteo;
};