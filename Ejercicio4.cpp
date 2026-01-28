#include <iostream>
using namespace std;
int sumaSubmatriz(int *mat,int cols,int i1,int j1,int i2,int j2){
    int suma=0;
    int *p;
    for(int i=i1;i<=i2;i++){
        for(int j=j1;j<=j2;j++){
            p=mat+i*cols+j;
            suma=suma+*p;
        }
    }
    return suma;
}
void submatrizMaxima(int *mat,int filas,int cols){
    int maxSuma=sumaSubmatriz(mat,cols,0,0,0,0);
    int fi=0,ci=0;
    int ff=0,cf=0;
    int suma;
    for(int i1=0;i1<filas;i1++){
        for(int j1=0;j1<cols;j1++){
            for(int i2=i1;i2<filas;i2++){
                for(int j2=j1;j2<cols;j2++){
                    suma=sumaSubmatriz(mat,cols,i1,j1,i2,j2);
                    if(suma>maxSuma){
                        maxSuma=suma;
                        fi=i1;
                        ci=j1;
                        ff=i2;
                        cf=j2;
                    }
                }
            }
        }
    }
    cout<<"\nSubmatriz de suma maxima:\n";
    cout<<"Esquina superior izquierda: ("<<fi<<","<<ci<<")\n";

    cout<<"Esquina inferior derecha: ("<<ff<<","<<cf<< ")\n";
    cout<<"Suma maxima: "<<maxSuma<<endl;
}
void mostrarMatriz(int *mat, int f, int c){
    int *p;
    cout<<"Matriz:\n";

    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            p=mat+i*c+j;
            cout<<*p<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int filas=4;
    int cols=5;
    int matriz[4][5] = {{-2,  1, -3,  4, -1},{ 1, -2,  4, -1,  2},{-3,  4, -1,  2, -5},{ 4, -1,  2, -5,  1}};
    mostrarMatriz(&matriz[0][0],filas,cols);
    submatrizMaxima(&matriz[0][0],filas,cols);
    return 0;
}