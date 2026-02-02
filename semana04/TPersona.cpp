#include<iostream>
#include<cstring>
using namespace std;

struct TPersona{
    char codigo[15];
    char* nombre;
    int dni;
    char direccion[50];
    double sueldo;
};

int main(){
    TPersona empleado;
    TPersona trabajador;

    //Asignar memoria dinámica para nombre de empleado
    empleado.nombre=new char[20];
    strcpy(empleado.nombre,"Juan Lopez");
    //Otros campos
    strcpy(empleado.codigo,"EMP001");
    empleado.dni=12345678;
    strcpy(empleado.direccion,"Av. ABC 123");
    empleado.sueldo=2500.50;

    trabajador=empleado;//Copia superficial

    strcpy(trabajador.nombre,"Pedro Perez");

    cout<<"Empleado: "<<empleado.nombre<<endl;
    cout<<"Trabajador: "<<trabajador.nombre<<endl;

    //Liberar memoria(solo una vez, porque empleado con trabajador la comparten)
    delete[] empleado.nombre;

    return 0;
}
