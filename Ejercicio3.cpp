#include<iostream>
using namespace std;
void imprimir(int (*inicio)[5],int (*fin)[5]);
int* obtenerFila(int (*inicio)[5],int (*fin)[5],int fila);
int* obtenerCol(int (*inicio)[5],int (*fin)[5],int fila,int col);
void busquedaPico(int (*inicio)[5],int (*fin)[5]);
int main(){
    int A[4][5]={{3,3,3,3,3},{3,4,4,2,3},{3,4,5,4,3},{3,3,3,3,3}};
    int (*inicio)[5]=&A[0];
    int (*fin)[5]=&A[4];
    cout<<"Matriz: "<<endl;
    imprimir(inicio,fin);
    busquedaPico(inicio,fin);
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
int* obtenerFila(int (*inicio)[5],int (*fin)[5],int fila){
    int totalFilas=fin-inicio;
    if(fila<0||fila>totalFilas){
        return *(inicio+fila);
    }
    return nullptr;
}
int* obtenerCol(int (*inicio)[5],int (*fin)[5],int fila,int col){
    int totalFilas=fin-inicio;
    if(fila<0||fila>totalFilas||col<0||col>5){
        return *(inicio+fila)+col;
    }
    return nullptr;
}
void busquedaPico(int (*inicio)[5],int (*fin)[5]){
    for(int (*fila)[5]=inicio;fila<fin;fila++){
        int* colInicio=*fila;
        int* colFin=colInicio+5;
        for(int* col=colInicio;col<colFin;col++){
            if(((*col>=*(*(inicio+**fila)-1))&&(*col>=*(*(inicio+**fila)+1)))&&((*col>*(*(inicio+**fila)-1))&&(*col>*(*(inicio+**fila)+1)))){
                cout<<"Pico en ("<<obtenerFila(inicio,fin,**fila)<<","<<obtenerCol(inicio,fin,**fila,*col)<<"): "<<*col<<endl;
            }
        }
    }
}