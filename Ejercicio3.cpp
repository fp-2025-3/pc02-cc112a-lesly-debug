#include<iostream>
using namespace std;
void imprimir(int (*inicio)[5],int (*fin)[5]);
int* obtenerFila(int (*inicio)[5],int (*fin)[5],int fila);
int* obtenerCol(int (*inicio)[5],int (*fin)[5],int fila,int col);
bool esPico(int (*inicio)[5],int filas,int columnas,int i,int j);
void busquedaPico(int (*inicio)[5],int filas,int columnas);
int main(){
    int A[4][5]={{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    int (*inicio)[5]=&A[0];
    int (*fin)[5]=&A[4];
    cout<<"Matriz: "<<endl;
    imprimir(inicio,fin);
    busquedaPico(inicio,4,5);
    return 0;
}
void imprimir(int (*inicio)[5],int (*fin)[5]){
    for(int (*fila)[5]=inicio;fila<fin;fila++){
        int* colInicio=*fila;
        int* colFin=colInicio+5;
        for(int* col=colInicio;col<colFin;col++){
            cout<<*col<<" ";
        }
        cout<<endl;
    }
}
bool esPico(int (*inicio)[5],int filas,int columnas,int i,int j){
    int val=*(*(inicio+i)+j);
    bool mayorEstricto=false;
    if(i-1>=0){
        int v=*(*(inicio+i-1)+j);
        if(val<v){
            return false;
        }
        if(val>v){
            mayorEstricto=true;
        }
    }
    if(i+1<filas){
        int v=*(*(inicio+i+1)+j);
        if(val<v){
            return false;
        }
        if(val<v){
            mayorEstricto=true;
        }
    }
    if(j-1>=0){
        int v=*(*(inicio+i)+j-1);
        if(val<v){
            return false;
        }
        if(val>v){
            mayorEstricto=true;
        }
    }
    if(j+1<columnas){
        int v=*(*(inicio+i)+j+1);
        if(val<v){
            return false;
        }
        if(val>v){
            mayorEstricto=true;
        }
    }
    return mayorEstricto;
}
void busquedaPico(int (*inicio)[5],int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(esPico(inicio,filas,columnas,i,j)){
                cout<<"Pico en ("<<i<<","<<j<<"):"<<*(*(inicio+i)+j)<<endl;
            }
        }
    }
}