#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
const int PARTIDOS=100;
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
        s[i].nombre="Pais_Seleccion"+to_string(i);
        int pg=rand()%PARTIDOS;
        s[i].PG=pg;
        int pe=rand()%(PARTIDOS-pg);
        s[i].PE=pe;
        s[i].PP=PARTIDOS-pg-pe;
        s[i].puntosTotales=s[i].PG*3+s[i].PE;
        s[i].rendimiento=(float)s[i].puntosTotales/PARTIDOS;
    }
}
void mostrandoDatos(Seleccion s[],int n){
    cout<<"Seleccion\t\tPG\tPP\tPE\tPuntaje\t\tRendimiento\n";
    for(int i=0;i<n;i++){
        cout<<s[i].nombre<<"\t\t"<<s[i].PG<<"\t"<<s[i].PP<<"\t"<<s[i].PE<<"\t"<<s[i].puntosTotales<<"\t\t"<<s[i].rendimiento<<endl;
    }
}
int indMejorRendimiento(Seleccion s[],int n){
    int indMax=0;
    for(int i=0;i<n;i++){
        if(s[i].rendimiento>s[indMax].rendimiento){
            indMax=i;
            return i;
        }
    }
    return -1;
}
int main(){
    Seleccion selecciones[5];
    generandoValores(selecciones,5);
    mostrandoDatos(selecciones,5);
    int pos=indMejorRendimiento(selecciones,5);
    cout<<"La seleccion con mejor rendimiento es: Seleccion"<<pos<<" Rendimiento: "<<selecciones[pos].rendimiento;
    return 0;
}