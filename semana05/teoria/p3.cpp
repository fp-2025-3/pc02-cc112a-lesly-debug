#include<iostream>
#include<string>
using namespace std;
struct Empleado{
    string nombre;
    float sueldo;
    string area;
};
int main(){
    Empleado empleados[5]={{"Juan Perez",3500,"Analista"},{"Maria Lopez",3200,"Programador"},{"Carlos Ruiz",2800,"Diseñador"},{"Ana Torres",5000,"Gerente"},{"Luis Garcia",3300,"Programador"}};
    string areaBuscada;
    cout<<"Ingrese puesto a buscar: ";
    getline(cin,areaBuscada);
    float suma=0;
    int contador=0;
    for(int i=0;i<5;i++){
        if(empleados[i].area==areaBuscada){
            suma=suma+empleados[i].sueldo;
            contador=contador+1;
        }
    }
    if(contador>0){
        float promedio=suma/contador;
        cout<<"Promedio de sueldos del area '"<<areaBuscada<<"': "<<promedio;
    }else{
        cout<<"No se encontraron empleados en ese puesto."<<endl;
    }
    return 0;
}