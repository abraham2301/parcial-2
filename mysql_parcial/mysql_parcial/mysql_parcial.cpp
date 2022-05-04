
#include <iostream>
#include <mysql.h>
#include "Estudiante.h"
using namespace std;

int main(){
    string carne, nombre, apellidos, direccion, genero, email, fecha_nac;
    int tele, eleccion,id_estudianta;
    cout << "-----Bienevenido al menu-----" << endl;
    cout << "Que quieres hacer: " << endl;
    cout << "Ingresar nuevo estudiante = 1" << endl;
    cout << "Ver estudiantes  = 2" << endl;
    cout << "Eliminar estudiantes = 3" << endl;
    cout << "Modificar estudiantes = 4" << endl;
    cout << "Respuesta: ";
    cin >> eleccion;
    if ((eleccion > 4) || (eleccion <= 0)) {
        cout << "Eleccion invalidad intenta de nuevo" << endl;
    }
    else {
        if (eleccion == 1) {
            cout << "Ingresa el numero telefonico del estudiante: ";
            cin >> tele;
            cin.ignore();
            cout << "Ingresa el carne del estudiante: ";
            getline(cin, carne);
            cout << "Ingresa los nombres de los estudiante: ";
            getline(cin, nombre);
            cout << "Ingresa los apellidos del estudiante: ";
            getline(cin, apellidos);
            cout << "Ingresa la direccion del estudiante: ";
            getline(cin, direccion);
            cout << "Ingresa el genero del estudiante: ";
            getline(cin, genero);
            cout << "Ingresa el email del estudiante: ";
            getline(cin, email);
            cout << "Ingresa la fecha de nacimiento del estudiante: ";
            getline(cin, fecha_nac);
            cout << "Ingresa el cualquier numero para verificar que no seas un robot: ";
            cin >> id_estudianta;
 
            Estudiante c = Estudiante(carne, nombre, apellidos, direccion, email, genero, fecha_nac,tele,id_estudianta);
            c.crear_estudiante();
        }
        else {
            if (eleccion == 2) {
                Estudiante l = Estudiante();
                l.leer_estudiante();
            }
            else {
                if (eleccion == 3) {
                    cout << "Ingresa el id del estudiante que quieres eliminar: ";
                    cin >> id_estudianta;
                    Estudiante e = Estudiante(id_estudianta);
                    e.eliminar_estudiante();
                }
                else {
                    if (eleccion == 4) {
                        cout << "Ingresa el nuevo numero telefonico del estudiante: ";
                        cin >> tele;
                        cin.ignore();
                        cout << "Ingresa el nuevo carne del estudiante: ";
                        getline(cin, carne);
                        cout << "Ingresa los nuevos nombres de los estudiante: ";
                        getline(cin, nombre);
                        cout << "Ingresa los nuevos apellidos del estudiante: ";
                        getline(cin, apellidos);
                        cout << "Ingresa la nueva direccion del estudiante: ";
                        getline(cin, direccion);
                        cout << "Ingresa el nuevo genero del estudiante: ";
                        getline(cin, genero);
                        cout << "Ingresa el nuevo email del estudiante: ";
                        getline(cin, email);
                        cout << "Ingresa la nueva fecha de nacimiento del estudiante: ";
                        getline(cin, fecha_nac);
                        cout << "Ingresa Id del estudiante al que quieres modificar: ";
                        cin >> id_estudianta;

                        Estudiante m = Estudiante(carne, nombre, apellidos, direccion, email, genero, fecha_nac, tele, id_estudianta);
                        m.Modificar_estudiante();
                    }
                }
            }
        }
    }


    /*Estudiante c = Estudiante();
    c.leer_estudiante();*/
    return 0;
}
