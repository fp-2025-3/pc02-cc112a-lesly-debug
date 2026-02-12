#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
const int PARTIDOS=100;
const int NUM_SELECCIONES=5;
struct Seleccion{
    string nombre;
    int puntosTotales;
    int partidosJugados;
    int PG;
    int PE;
    int PP;
    float rendimiento;
};
void generandoValores(Seleccion s[],int n){
    for(int i=0;i<n;i++){
        s[i].nombre="Pais_Seleccion "+to_string(i);
        s[i].partidosJugados=PARTIDOS;
        s[i].PG=rand()%(PARTIDOS+1);
        s[i].PE=rand()%(PARTIDOS-s[i].PG+1);
        s[i].PP=PARTIDOS-s[i].PG-s[i].PE;
        s[i].puntosTotales=s[i].PG*3+s[i].PE;
        s[i].rendimiento=(float)s[i].puntosTotales*100/(PARTIDOS*3);
    }
}
void mostrandoDatos(Seleccion s[],int n){
    cout<<"Seleccion\t\tPG\tPP\tPE\tPuntaje\t\tRendimiento\n";
    for(int i=0;i<n;i++){
        cout<<s[i].nombre<<"\t"<<s[i].PG<<"\t"<<s[i].PP<<"\t"<<s[i].PE<<"\t"<<s[i].puntosTotales<<"\t\t"<<s[i].rendimiento<<endl;
    }
}
int indMejorRendimiento(Seleccion s[],int n){
    int indMax=0;
    for(int i=0;i<n;i++){
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
    int pos=indMejorRendimiento(selecciones,NUM_SELECCIONES);
    cout<<"La seleccion con mejor rendimiento es: Seleccion"<<pos<<" Rendimiento: "<<selecciones[pos].rendimiento;
    return 0;
}