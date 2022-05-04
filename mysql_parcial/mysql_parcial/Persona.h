#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class Persona{
	//atributos
protected: string carnet, nombres, apellidos, direccion, email, genero, fecha_nacimiento;
		 int telefono, estudiante;
		 //constructor
protected:
	Persona(){}
	Persona(string car, string nom, string ape, string dire, string ema, string gene, string fn, int celular, int idestuss) {
		carnet = car;
		nombres = nom;
		apellidos = ape;
		direccion = dire;
		email = ema;
		genero = gene;
		fecha_nacimiento = fn;
		estudiante = idestuss;
	}
};

