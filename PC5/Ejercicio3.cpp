#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
    ofstream archivo;
    archivo.open("grafico.txt");
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return -1;
    }
    const int FILAS=21;
    const int COLUMNAS=80;
    double x;
    double y;
    double paso=(2*M_PI)/(COLUMNAS-1);
    char grafico[FILAS][COLUMNAS];
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            grafico[i][j]=' ';
        }
    }
    int filaEjeX=FILAS/2;
    for(int j=0;j<COLUMNAS;j++){
        grafico[filaEjeX][j]='-';
    }
    for(int i=0;i<FILAS;i++){
        grafico[i][0]='|';
    }
    for(int j=0;j<COLUMNAS;j++){
        x=j*paso;
        y=sin(5*x);
        int fila=(int)((1 - y)*(FILAS-1)/2);
        if(fila>=0&&fila<FILAS){
            grafico[fila][j]='*';
        }
    }
    for(int i=0;i<FILAS;i++){
        for(int j=0; j<COLUMNAS;j++){
            archivo<<grafico[i][j];
        }
        archivo<< endl;
    }
    archivo.close();
    cout<<"Archivo grafico.txt generado correctamente.\n";
    return 0;
}