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
        cout<<"Ingrese el coeficiente de x^"<<j<<":";
        cin>>A[i].coeficiente;
        A[i].exponente=j;
        j=j-1;
    }
}
int sumaPolinomios(Termino A[],Termino B[],int n,int m,Termino suma[]){
    int i=0,j=0,k=0;
    while(i<=n&&j<=m){
        if(A[i].exponente==B[j].exponente){
            suma[k].coeficiente=A[i].coeficiente+B[j].coeficiente;
            suma[k].exponente=A[i].exponente;
            k=k+1;
            i=i+1;
            j=j+1;
        }else if(A[i].exponente>B[j].exponente){
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
    while(i<=n){
        suma[k].coeficiente=A[i].coeficiente;
        suma[k].exponente=A[i].exponente;
        k=k+1;
        i=i+1;
    }
    while(j<=m){
        suma[k].coeficiente=B[j].coeficiente;
        suma[k].exponente=B[j].exponente;
        k=k+1;
        j=j+1;
    }
    return k;
}
int productoPolinomio(Termino A[],Termino B[],int n,int m,Termino producto[]){
    int k=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            producto[k].coeficiente=A[i].coeficiente*B[j].coeficiente;
            producto[k].exponente=A[i].exponente+B[j].exponente;
            k=k+1;
        }
    }
    int r=0;
    for(int i=0;i<k;i++){
        if(producto[i].coeficiente!=0){
            for(int j=i+1;j<k;j++){
                if(producto[i].exponente==producto[j].exponente){
                    producto[i].coeficiente=producto[i].coeficiente+producto[j].coeficiente;
                    producto[j].coeficiente=0;
                }
            }
            producto[r]=producto[i];
            r=r+1;
        }
    }
    return r;
}
void mostrarPolinomio(Termino A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i].coeficiente;
        if(A[i].exponente!=0){
            cout<<"x^"<<A[i].exponente;
        }
        if(i<(n-1)&&A[i+1].coeficiente>=0){
            cout<<"+";
        }
    }
    cout<<endl;
}
double evaluarPolinomio(Termino A[],int n,double x){
    double resultado=0;
    for(int i=0;i<n;i++){
        double potencia=1;
        for(int j=0;j<A[i].exponente;j++){
            potencia=potencia*x;
        }
        resultado=resultado+A[i].coeficiente*potencia;
    }
    return resultado;
}
int main(){
    Termino* A;
    Termino* B;
    int n,m;
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>n;
    leerDatos(A,n);
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>m;
    leerDatos(B,m);
    cout<<"Primer polinomio: ";
    mostrarPolinomio(A,n+1);
    cout<<"Segundo polinomio: ";
    mostrarPolinomio(B,m+1);
    Termino suma[50];
    int terminosSuma=sumaPolinomios(A,B,n,m,suma);
    cout<<"Suma:";
    mostrarPolinomio(suma,terminosSuma);
    Termino producto[60];
    int terminosProducto=productoPolinomio(A,B,n,m,producto);
    cout<<"Producto:";
    mostrarPolinomio(producto,terminosProducto);
    double x;
    cout<<"Ingrese el valor de x para evaluar el primer polinomio: ";
    cin>>x;
    double valor=evaluarPolinomio(A,n+1,x);
    cout<<"El primer polinomio evaluado en x= "<<x<<" es: "<<valor<<endl;
    delete[] A;
    delete[] B;
    return 0;
}