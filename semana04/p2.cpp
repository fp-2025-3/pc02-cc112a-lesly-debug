#include<iostream>
#include <iomanip>
using namespace std;
double** crearMatriz(int n){
    double** A;
    A=new double*[n];
    for(int i=0;i<n;i++){
        *(A+i)=new double[n];
    }
    return A;
}
void leerMatriz(double** a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>*(*(a+i)+j);
        }
    }
}
void imprimir(double** a,int n){
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(7)<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
}
double** transpuesta(double** a,int n){
    double** aT=crearMatriz(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(aT+i)+j)=*(*(a+j)+i);;
        }
    }
    return aT;
}
double** inercia(double** a,double** b,int n){
    double** I=crearMatriz(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(I+i)+j)=0;
            for(int k=0;k<n;k++){
                *(*(I+i)+j)=*(*(I+i)+j)+(*(*(a+i)+k))*(*(*(b+k)+j));
            }
        }
    }
    return I;
}
double traza(double** a,int n){
    double trz=0;
    for(int i=0;i<n;i++){
        trz=trz+*(*(a+i)+i);
    }
    return trz;
}
double energia(double** I,int n){
    double suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            suma=suma+(*(*(I+i)+j))*(*(*(I+i)+j));
        }
    }
    return suma/n*n;
}
int main(){
    double** a;
    int n;
    cout<<"N= ";
    cin>>n;
    a=crearMatriz(n);
    leerMatriz(a,n);
    cout<<"Matriz A: "<<endl;
    imprimir(a,n);
    cout<<endl;
    double** aT=transpuesta(a,n);
    cout<<"Transpuesta de A: "<<endl;
    imprimir(aT,n);
    cout<<endl;
    double** I=inercia(a,aT,n);
    cout<<"Matriz de inercia: "<<endl;
    imprimir(I,n);
    cout<<endl;
    double t=traza(I,n);
    cout<<"Traza: "<<t<<endl;
    double e=energia(I,n);
    cout<<"Energia normalizada= "<<e;
    return 0;
}