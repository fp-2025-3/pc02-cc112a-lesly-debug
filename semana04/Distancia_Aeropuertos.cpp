#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
double** crearMatriz(int n){
    double** M=new double*[n];
    for(int i=0;i<n;i++){
        M[i]=new double[n];
    }
    return M;
}
void llenarMatriz(double** M,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                M[i][j]=0.0;
            }else{
                double r=(double)rand()/RAND_MAX;
                double d=100.0+r*(1500.0-100.0);
                M[i][j]=d;
                M[j][i]=d;
            }
        }
    }
}
void mostrarMatriz(double** M,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}
double promedioTotal(double** M,int n){
    double suma=0;
    int contador=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                suma=suma+M[i][j];
                contador=contador+1;
            }
        }
    }
    return suma/contador;
}
int menorPromedio(double** M,int n){
    int indice=0;
    double menor=1e9;//valor grande para iniciar la comparación
    for(int i=0;i<n;i++){
        double suma=0.0;
        for(int j=0;j<n;j++){
            if(i!=j){
                suma=suma+M[i][j];
            }
        }
        double promedio=suma/(n-1);
        if(promedio<menor){
            menor=promedio;
            indice=i;
        }
    }
    return indice;
}
void liberarMatriz(double** M,int n){
    for(int i=0;i<n;i++){
        delete[] M[i];
    }
    delete[] M;
}
int main(){
    srand(time(NULL));
    int n;
    double** matriz;
    cout<<"Ingrese el numero de aeropuertos: ";
    cin>>n;
    matriz=crearMatriz(n);
    llenarMatriz(matriz,n);
    double prom=promedioTotal(matriz,n);
    cout<<"Promedio total: "<<prom<<" km"<<endl;
    int ind=menorPromedio(matriz,n);
    cout<<"Aeropuerto con menor distancia promedio: "<<ind+1<<endl;
    cout<<"Mostrando matriz: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(matriz+i)+j)<<" ";
        }
        cout<<endl;
    }
    liberarMatriz(matriz,n);
    return 0;
}