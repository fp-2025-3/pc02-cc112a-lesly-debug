#include<iostream>
#include<fstream>
using namespace std;
struct Empleado{
    int id;
    char nombre[30];
    float salario;
};
void crearArchivo(const char* nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al crear el archivo.\n";
        return;
    }
    Empleado empleados[8]={{1,"Empleado A",3000},{2,"Empleado B",4000},{3,"Empleado C",3500},{4,"Empleado D",4500},{5,"Empleado E",3200},{6,"Empleado F",3800},{7,"Empleado G",4200},{8,"Empleado H",3900}};
    archivo.write((char*)empleados,8*sizeof(Empleado));
    archivo.close();
    cout<<"El archivo se creo correctamente.\n";
}
void leerArchivo(const char* nombreArchivo){
    ifstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Empleado empleados[8];
    archivo.read((char*)empleados,8*sizeof(Empleado));
    for(int i=0;i<8;i++){
        cout<<"ID: "<<empleados[i].id<<", Nombre: "<<empleados[i].nombre<<", Salario: "<<empleados[i].salario<<endl;
    }
    archivo.close();
    cout<<"Archivo leido correctamente.\n";
}
void mostrarRango(const char* nombreArchivo,double min,double max){
    ifstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Empleado empleados[8];
    archivo.read((char*)empleados,8*sizeof(Empleado));
    for(int i=0;i<8;i++){
        if(empleados[i].salario>=min&&empleados[i].salario<=max){
            cout<<"ID: "<<empleados[i].id<<", Nombre: "<<empleados[i].nombre<<", Salario: "<<empleados[i].salario<<endl;
        }
    }
}
int main(){
    double salarioMin,salarioMax;
    crearArchivo("empleados.bin");
    leerArchivo("empleados.bin");
    cout<<"Ingrese el salario minimo: ";
    cin>>salarioMin;
    cout<<"Ingrese el salario maximo: ";
    cin>>salarioMax;
    mostrarRango("empleados.bin",salarioMin,salarioMax);
    return 0;
}