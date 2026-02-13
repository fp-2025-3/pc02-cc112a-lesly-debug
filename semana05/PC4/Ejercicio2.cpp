#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
const int NUM_PARTIDOS=100;
const int NUM_SELECCIONES=5;
struct Seleccion{
    string nombre;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int puntosTotales;
    int DG;
    double rendimiento;
};
void generandoValores(Seleccion* s,int n){
    for(int i=0;i<n;i++){
        s[i].nombre="Pais_"+to_string(i);
        s[i].PG=rand()%(NUM_PARTIDOS+1);
        s[i].PE=rand()%(NUM_PARTIDOS-s[i].PG+1);
        s[i].PP=NUM_PARTIDOS-s[i].PG-s[i].PE;
        s[i].GF=rand()%(500-0+1)+1;
        s[i].GC=
        s[i].puntosTotales=s[i].PG*3+s[i].PE;
        s[i].rendimiento=(double)s[i].puntosTotales*100/(NUM_PARTIDOS*3);
    }
}
void mostrandoDatos(Seleccion s[],int n){
    cout<<"Seleccion\tPG\tPP\tPE\tPuntaje\t\tRendimiento\n";
    for(int i=0;i<n;i++){
        cout<<s[i].nombre<<"\t\t"<<s[i].PG<<"\t"<<s[i].PP<<"\t"<<s[i].PE<<"\t"<<s[i].puntosTotales<<"\t\t"<<s[i].rendimiento<<endl;
    }
}
int indMayorRendimiento(Seleccion* s,int n){
    int indMax=0;
    for(int i=1;i<n;i++){
        if(s[i].rendimiento>s[indMax].rendimiento){
            indMax=i;
        }
    }
    return indMax;
}
int main(){
    srand(time(nullptr));
    Seleccion selecciones[NUM_SELECCIONES];
    generandoValores(selecciones,NUM_SELECCIONES);
    mostrandoDatos(selecciones,NUM_SELECCIONES);
    int pos=indMayorRendimiento(selecciones,NUM_SELECCIONES);
    cout<<"La seleccion con mejor rendimiento es: Pais_"<<pos<<" Rendimiento: "<<selecciones[pos].rendimiento;
    return 0;
}