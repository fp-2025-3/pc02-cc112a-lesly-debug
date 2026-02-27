#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    ifstream f;
    f.open("notas.txt");
    if(!f){
        cerr<<"Error al abir el archivo.\n";
        return -1;
    }
    string linea;
    double suma=0;
    int total=0;
    int numero;
    string nombre;
    float promedio;
    float nota1,nota2,nota3;
    float promedioMax=-1;
    float promedioMin=30;
    string nombreMax;
    string nombreMin;
    ofstream archivo("reporteAlumnos.txt");
    while(getline(f,linea,' ')){
        numero=stoi(linea);
        getline(f,nombre,' ');
        getline(f,linea,' ');
        nota1=stof(linea);
        getline(f,linea,' ');
        nota2=stof(linea);
        getline(f,linea);
        nota3=stof(linea);
        promedio=(nota1+nota2+nota3)/3;
        total=total+1;
        suma=suma+promedio;
        if(promedioMax<promedio){
            promedioMax=promedio;
            nombreMax=nombre;
        }
        if(promedioMin>promedio){
            promedioMin=promedio;
            nombreMin=nombre;
        }
        archivo<<fixed<<setprecision(2);
        archivo<<numero<<"\t"<<nombre<<"\t\t"<<promedio;
        if(promedio>=10){
            archivo<<"\t\tAPROBADO\n";
        }else if(nota1<5||nota2<5||nota3<5){
            archivo<<"\t\tDESAPROBADO\n";
        }else{
            archivo<<"\t\tDESAPROBADO\n";
        }
    }
    f.close();
    archivo<<"Total de estudiantes: "<<total<<endl;
    archivo<<"Promedio general: "<<suma/total<<endl;
    archivo<<"Estudiante con mayor promedio: "<<nombreMax<<endl;
    archivo<<"Estudiante con menor promedio: "<<nombreMin<<endl;
    archivo.close();
    return 0;
}