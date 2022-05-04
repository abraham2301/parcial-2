#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class Id_estudiante{
protected: int id_estudiante;
protected:
	Id_estudiante(){}

	Id_estudiante(int idest) {
		id_estudiante = idest;
	}
};

