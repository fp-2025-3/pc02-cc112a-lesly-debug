#include<iostream>
using namespace std;
struct Polinomio{
    int grado;
    double* coeficiente;
};
void mostrarPolinomio(Polinomio& p){
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
Polinomio suma(const Polinomio& a,const Polinomio& b,const Polinomio& c){
    Polinomio s;
    if(a.grado>=b.grado&&a.grado>=c.grado){
        s.grado=a.grado;
    }else if(b.grado>=a.grado&&b.grado>=c.grado){
        s.grado=b.grado;
    }else{
        s.grado=c.grado;
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
    for(int i=0;i<=c.grado;i++){
        s.coeficiente[i]=s.coeficiente[i]+c.coeficiente[i];
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
void liberarMemoria(Polinomio& p){
    delete[] p.coeficiente;
}
int main(){
    Polinomio a;
    a.grado=2;
    a.coeficiente=new double[3];
    a.coeficiente[0]=3.0;
    a.coeficiente[1]=0.0;
    a.coeficiente[2]=1.0;
    Polinomio b;
    b.grado=1;
    b.coeficiente=new double[2];
    b.coeficiente[0]=5.0;
    b.coeficiente[1]=-4.0;
    Polinomio c;
    c.grado=2;
    c.coeficiente=new double[3];
    c.coeficiente[0]=1.0;
    c.coeficiente[1]=0.0;
    c.coeficiente[2]=3.0;
    cout<<"Polinomio 1: ";
    mostrarPolinomio(a);
    cout<<"Polinomio 2: ";
    mostrarPolinomio(b);
    cout<<"Polinomio 3: ";
    mostrarPolinomio(c);
    cout<<endl;
    Polinomio s=suma(a,b,c);
    cout<<"Suma de los tres polinomios: ";
    mostrarPolinomio(s);
    cout<<endl;
    Polinomio p1=multiplicar(a,b);
    Polinomio p2=multiplicar(p1,c);
    cout<<"Producto de los tres polinomios: ";
    mostrarPolinomio(p2);
    liberarMemoria(a);
    liberarMemoria(b);
    liberarMemoria(c);
    liberarMemoria(s);
    liberarMemoria(p1);
    liberarMemoria(p2);
    return 0;
}