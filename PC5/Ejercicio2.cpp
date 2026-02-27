#include<iostream>
#include<fstream>
using namespace std;
struct Empleado{
    int id;
    char nombre[30];
    double salario;
};
int main(){
    fstream archivo;
    archivo.open("empleados.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo\n";
        return -1;
    }
    Empleado empleados;
    int posicionId;
    cout<<"Ingrese el ID del empleado: ";
    cin>>posicionId;
    posicionId=posicionId-1;
    archivo.seekg(posicionId*sizeof(Empleado),ios::beg);
    archivo.read((char*)&empleados,sizeof(Empleado));
    double nuevoSalario;
    cout<<"--- DATOS DEL EMPLEADO ---\n";
    cout<<"ID: "<<empleados.id<<endl;
    cout<<"Nombre: "<<empleados.nombre<<endl;
    cout<<"Salario: "<<empleados.salario<<endl;
    cout<<endl;
    cout<<"Ingrese nuevo salario: ";
    cin>>nuevoSalario;
    empleados.salario=nuevoSalario;
    archivo.seekp(posicionId*sizeof(Empleado),ios::beg);
    archivo.write((char*)&empleados,sizeof(Empleado));
    archivo.close();
    cout<<"Salario actualizado correctamente.\n";
    return 0;
}