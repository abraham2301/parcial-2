#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Persona.h"
#include "Id_estudiante.h"
using namespace std;
class Estudiante: Persona, Id_estudiante{
private: string CARNE;
protected:
public:
	Estudiante(){}

	Estudiante(string car, string nom, string ape, string dire, string ema, string gene, string fn, int celular, int idestuss) :Persona(car,nom,ape,dire,ema,gene,fn,celular, idestuss) {

	}
	Estudiante(int idest):Id_estudiante(idest) {

	}

	//metodo
	void leer_estudiante() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Estatus del estudiante ----------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << endl;

				}
			}
			else
			{
				cout << "----- Error al mostrar la informacion reinicia el sistema" << endl;
			}
		}
		else {
			cout << "----- Error en la conexion intentalo de nuevo -----" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear_estudiante() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string celu = to_string(telefono);
			string insert = "INSERT INTO estudiantes (carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) VALUES('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + celu + "','" + genero + "','" + email + "','" + fecha_nacimiento + "' );";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
			}
			else {
				cout << "----- Error al ingresar el estudiante, intentalo de nuevo" << endl;
			}
		}
		else {
			cout << "----- Error en la conexion intetalo de nuevo -----" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar_estudiante() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(id_estudiante);
			string consulta = "DELETE FROM estudiantes WHERE id_estudiante='" + borrar + "';";
			const char*	e = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "Eliminacion exitosa" << endl;
			}
			else {
				cout << "Error en la eliminacion comprueba tu conexion" << endl;
			}
		}
		else {
			cout << "----- Error en la conexion ----- " << endl;
		}
		cn.cerrar_conexion();
	}
	void Modificar_estudiante() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(estudiante);
			string phone = to_string(telefono);
			string consulta = "UPDATE estudiantes SET carnet ='"+carnet+"',nombres ='"+nombres+"',apellidos ='"+apellidos+"',direccion ='"+direccion+"',telefono ='"+phone+"',genero ='"+genero+"',email ='"+email+"',fecha_nacimiento = '"+fecha_nacimiento+"' WHERE id_estudiante = '"+modificar+"';";
			const char* m = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), m);
			if (!q_estado) {
				cout << "Modificacion exitosa" << endl;
			}
			else {
				cout << "----- Error al modificar intenta cambiando la fecha de nacimiento" << endl;
			}
		}
		else {
			cout << "---- Error en la conexion ------" << endl;
		}
		cn.cerrar_conexion();
	}
};

