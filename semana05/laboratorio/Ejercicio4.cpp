#include<iostream>
using namespace std;
struct Termino{
    int exponente;
    double coeficiente;
};
void leerDatos(Termino*& A,int n){
    A=new Termino[n+1];
    int j=n;
    for(int i=0;i<=n;i++){
        cout<<"Ingrese el coeficiente de x"<<j<<":";
        cin>>A[i].coeficiente;
        A[i].exponente=j;
        j=j-1;
    }
}
int gradoSumaPolinomios(Termino A[],Termino B[],int n,int m,Termino suma[]){
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(A[i].exponente==B[j].exponente){
            suma[k].coeficiente=A[i].coeficiente+B[j].coeficiente;
            suma[k].exponente=A[i].exponente;
            k=k+1;
            i=i+1;
            j=j+1;
        }
        if(A[i].exponente>B[j].exponente){
            suma[k].coeficiente=A[i].coeficiente;
            suma[k].exponente=A[i].exponente;
            k=k+1;
            i=i+1;
        }else{
            suma[k].coeficiente=B[j].coeficiente;
            suma[k].exponente=B[j].exponente;
            k=k+1;
            j=j+1;
        }
    }
    while(i<n){
        suma[k].coeficiente=A[i].coeficiente;
        suma[k].exponente=A[i].exponente;
        k=k+1;
        i=i+1;
    }
    while(j<m){
        suma[k].coeficiente=B[j].coeficiente;
        suma[k].exponente=A[i].exponente;
        k=k+1;
        j=j+1;
    }
    return k;
}
void mostrarPolinomio(Termino A[],int n){
    for(int i=0;i<=n;i++){
        cout<<A[i].coeficiente;
        if(A[i].exponente!=0){
            cout<<"x"<<A[i].exponente;
        }
        if(i<n){
            cout<<"+";
        }
    }
    cout<<endl;
}
int main(){
    Termino* A;
    Termino* B;
    int n,m;
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>n;
    A=new Termino[n+1];
    leerDatos(A,n);
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>m;
    B=new Termino[m+1];
    leerDatos(B,m);
    cout<<"Primer polinomio: ";
    mostrarPolinomio(A,n);
    cout<<"Segundo polinomio: ";
    mostrarPolinomio(B,m);
    Termino suma[20];
    int gradoSuma=gradoSumaPolinomios(A,B,n,m,suma);
    mostrarPolinomio(suma,gradoSuma);
    delete[] A;
    delete[] B;
    return 0;
}