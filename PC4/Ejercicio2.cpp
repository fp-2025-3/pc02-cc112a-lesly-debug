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
        s[i].nombre="Pais_"+to_string(i+1);
        s[i].PG=0;
        s[i].PE=0;
        s[i].PP=0;
        s[i].GF=0;
        s[i].GC=0;
        for(int j=0;j<NUM_PARTIDOS;j++){
            int gf=rand()%6;
            int gc=rand()%6;
            s[i].GF=s[i].GF+gf;
            s[i].GC=s[i].GC+gc;
            if(gf>gc){
                s[i].PG=s[i].PG+1;
            }else if(gf==gc){
                s[i].PE=s[i].PE+1;
            }else{
                s[i].PP=s[i].PP+1;
            }
        }
        s[i].puntosTotales=s[i].PG*3+s[i].PE;
        s[i].DG=s[i].GF-s[i].GC;
        s[i].rendimiento=(double)s[i].puntosTotales*100/(NUM_PARTIDOS*3);
    }
}
void ordenar(Seleccion* s,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[j].puntosTotales>s[i].puntosTotales||(s[j].puntosTotales==s[i].puntosTotales&&s[j].DG>s[i].DG)||(s[j].puntosTotales==s[i].puntosTotales&&s[j].DG==s[i].DG&&s[j].GF>s[i].GF)){
                Seleccion aux;
                aux=s[i];
                s[i]=s[j];
                s[j]=aux;
            }
        }
    }
}
void mostrandoDatos(Seleccion s[],int n){
    cout<<"Seleccion\tPG\tPP\tPE\tGF\tGC\tDG\tPts\tRend(%)\n";
    cout<<"----------------------------------------------------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<s[i].nombre<<"\t\t"<<s[i].PG<<"\t"<<s[i].PP<<"\t"<<s[i].PE<<"\t"<<s[i].GF<<"\t"<<s[i].GC<<"\t"<<s[i].DG<<"\t"<<s[i].puntosTotales<<"\t"<<s[i].rendimiento<<endl;
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
    ordenar(selecciones,NUM_SELECCIONES);
    mostrandoDatos(selecciones,NUM_SELECCIONES);
    int pos=indMayorRendimiento(selecciones,NUM_SELECCIONES);
    cout<<"\nCAMPEON: Pais_"<<pos+1<<" | Puntaje: "<<selecciones[pos].puntosTotales<<" | DG: "<<selecciones[pos].DG<<" | Rendimiento: "<<selecciones[pos].rendimiento;
    return 0;
}