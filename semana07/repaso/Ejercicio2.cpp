#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int main(){
    ifstream f("input/baseUNI.txt");
    if(!f){
        cerr<<"Error al abrir el archivo.\n";
        return 1;
    }
    string linea;
    int numero;
    string nombre,apellidos;
    float promedio;
    float nota1,nota2;
    float promedioMax=-1;
    string nombreMax,apellidoMax;
    cout<<"Num\tApellidos\tNombre\tNota1\tNota2\tPromedio\n";
    while(getline(f,linea,'.')){
        numero=stoi(linea);
        getline(f,apellidos,',');
        getline(f,nombre,'-');
        getline(f,linea,'-');
        nota1=stof(linea);
        getline(f,linea);
        nota2=stof(linea);
        promedio=(nota1+nota2)/2;
        if(promedioMax<promedio){
            promedioMax=promedio;
            nombreMax=nombre;
            apellidoMax=apellidos;
        }
        cout<<numero<<"\t"<<apellidos<<"\t"<<nombre<<"\t"<<nota1<<"\t"<<nota2<<"\t"<<promedio<<endl;
    }
    cout<<"El promedio maximo: "<<promedioMax<<endl;
    cout<<"Alumno: "<<apellidoMax<<" "<<nombreMax<<endl;
    return 0;
}