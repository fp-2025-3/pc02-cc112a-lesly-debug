#include<iostream>
using namespace std;
struct Polinomio{
    int grado;
    double* coeficiente;
};
void mostrarPolinomio(const Polinomio& p){
    for(int i=p.grado;i>=0;i--){
        if(p.coeficiente[i]!=0){
            cout<<p.coeficiente[i];
            if(i>0){
                cout<<"x^"<<i<<"+";
            }
        }
    }
    cout<<endl;
}
Polinomio suma(const Polinomio& a,const Polinomio& b){
    Polinomio s;
    if(a.grado>b.grado){
        s.grado=a.grado;
    }else{
        s.grado=b.grado;
    }
    s.coeficiente=new double[s.grado+1];
    for(int i=0;i<=s.grado;i++){
        s.coeficiente[i]=0;
    }
    for(int i=0;i<=a.grado;i++){
        s.coeficiente[i]=s.coeficiente[i]+a.coeficiente[i];
    }
    for(int i=0;i<=b.grado;i++){
        s.coeficiente[i]=s.coeficiente[i]+b.coeficiente[i];
    }
    return s;
}
Polinomio multiplicar(const Polinomio& a,const Polinomio& b){
    Polinomio p;
    p.grado=a.grado+b.grado;
    p.coeficiente=new double[p.grado+1];
    for(int i=0;i<=p.grado;i++){
        p.coeficiente[i]=0;
    }
    for(int i=0;i<=a.grado;i++){
        for(int j=0;j<=b.grado;j++){
            p.coeficiente[i+j]=p.coeficiente[i+j]+a.coeficiente[i]*b.coeficiente[j];
        }
    }
    return p;
}
double evaluar(const Polinomio& p,double x) {
    double resultado=0;
    double potencia=1;
    for(int i=0;i<=p.grado;i++) {
        resultado=resultado+(p.coeficiente[i]*potencia);
        potencia=potencia*x;
    }
    return resultado;
}

void liberar(Polinomio& p) {
    delete[] p.coeficiente;
}

int main() {
    Polinomio A,B;
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>A.grado;
    A.coeficiente=new double[A.grado+1];
    for(int i=A.grado;i>=0;i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>A.coeficiente[i];
    }
    cout<<endl;
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>B.grado;
    B.coeficiente=new double[B.grado+1];
    for(int i=B.grado;i>=0;i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>B.coeficiente[i];
    }
    cout<<endl;
    cout<<"Primer polinomio: ";
    mostrarPolinomio(A);
    cout<<"Segundo polinomio: ";
    mostrarPolinomio(B);
    Polinomio sumaP=suma(A, B);
    cout<<"La suma de los polinomios es: ";
    mostrarPolinomio(sumaP);
    Polinomio producto=multiplicar(A, B);
    cout<<"El producto de los polinomios es: ";
    mostrarPolinomio(producto);
    double x;
    cout<<endl;
    cout<<"Ingrese el valor de x para evaluar el primer polinomio: ";
    cin>>x;
    cout<<"El primer polinomio evaluado en x = "<<x<<" es: "<<evaluar(A,x)<<endl;
    liberar(A);
    liberar(B);
    liberar(sumaP);
    liberar(producto);
    return 0;
}