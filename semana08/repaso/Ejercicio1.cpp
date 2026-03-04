#include<iostream>
using namespace std;
struct Termino{
    double coeficiente;
    int exponente;
};
struct Polinomio{
    Termino* terminos;
    int numTerminos;
};
void crearPolinomio(Polinomio& p,int n){
    p.numTerminos=n;
    p.terminos=new Termino[p.numTerminos];
}
void leerPolinomio(Polinomio& p){
    for(int i=0;i<p.numTerminos;i++){
        cout<<"Coeficiente "<<i+1<<": ";
        cin>>p.terminos[i].coeficiente;
        cout<<"Exponente "<<i+1<<": ";
        cin>>p.terminos[i].exponente;
    }
}
void mostrarPolinomio(const Polinomio& p){
    for(int i=0;i<p.numTerminos;i++){
        cout<<p.terminos[i].coeficiente;
        if(p.terminos[i].exponente!=0){
            cout<<"x^"<<p.terminos[i].exponente;
        }
        if(i<(p.numTerminos-1)&&p.terminos[i+1].coeficiente>=0){
            cout<<"+";
        }
    }
}
double evaluarPolinomio(const Polinomio& p,double x){
    double resultado=0;
    for(int i=0;i<p.numTerminos;i++){
        double potencia=1;
        for(int j=0;j<p.terminos[i].exponente;j++){
            potencia=potencia*x;
        }
        resultado=resultado+p.terminos[i].coeficiente*potencia;
    }
    return resultado;
}
void derivarPolinomio(const Polinomio& p,Polinomio& derivada){
    int numExpNoNulos=0;
    for(int i=0;i<p.numTerminos;i++){
        if(p.terminos[i].exponente!=0){
            numExpNoNulos=numExpNoNulos+1;
        }
    }
    crearPolinomio(derivada,numExpNoNulos);
    int j=0;
    for(int i=0;i<p.numTerminos;i++){
        if(p.terminos[i].exponente!=0){
            derivada.terminos[j].coeficiente=p.terminos[i].coeficiente*p.terminos[i].exponente;
            derivada.terminos[j].exponente=p.terminos[i].exponente-1;
            j=j+1;
        }
    }
}
void sumaPolinomios(Polinomio& p1,Polinomio& p2,Polinomio& resultado){
    int i=0,j=0,k=0;
    crearPolinomio(resultado,p1.numTerminos+p2.numTerminos);
    while(i<p1.numTerminos&&j<p2.numTerminos){
        if(p1.terminos[i].exponente==p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p1.terminos[i].coeficiente+p2.terminos[j].coeficiente;
            resultado.terminos[k].exponente=p1.terminos[i].exponente;
        }else if(p1.terminos[i].exponente>p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p1.terminos[i].coeficiente;
            resultado.terminos[k].exponente=p1.terminos[i].exponente;
        }else if(p1.terminos[i].exponente<p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p2.terminos[j].coeficiente;
            resultado.terminos[k].exponente=p2.terminos[j].exponente;
        }
        i=i+1;
        j=j+1;
        k=k+1;
    }
    while(i<p1.numTerminos){
        resultado.terminos[k].coeficiente=p1.terminos[i].coeficiente;
        resultado.terminos[k].exponente=p1.terminos[i].exponente;
        i=i+1;
        k=k+1;
    }
    while(j<p2.numTerminos){
        resultado.terminos[k].coeficiente=p2.terminos[j].coeficiente;
        resultado.terminos[k].exponente=p2.terminos[j].exponente;
        j=j+1;
        k=k+1;
    }
}
void liberarPolinomio(Polinomio& p){
    delete[] p.terminos;
    p.terminos=nullptr;
}
int main(){
    Polinomio p1;
    Polinomio p2;
    Polinomio d1;
    Polinomio d2;
    Polinomio suma;
    int n1;
    int n2;
    cout<<"Ingrese la cantidad de terminos del primer polinomio: ";
    cin>>n1;
    crearPolinomio(p1,n1);
    leerPolinomio(p1);
    cout<<"\nPolinomio 1: ";
    mostrarPolinomio(p1);
    double v1;
    cout<<"\nIngrese valor a evaluar: ";
    cin>>v1;
    cout<<"Evaluando polinomio en x="<<v1<<": "<<evaluarPolinomio(p1,v1)<<endl;
    cout<<"\nIngrese la cantidad de terminos del segundo polinomio: ";
    cin>>n2;
    crearPolinomio(p2,n2);
    leerPolinomio(p2);
    cout<<"\nPolinomio 2: ";
    mostrarPolinomio(p2);
    double v2;
    cout<<"\nIngrese valor a evaluar: ";
    cin>>v2;
    cout<<"Evaluando polinomio en x="<<v2<<": "<<evaluarPolinomio(p2,v2)<<endl;
    cout<<"\nDerivando polinomios:\n";
    cout<<"Polinomio 1: ";
    derivarPolinomio(p1,d1);
    mostrarPolinomio(d1);
    cout<<"\nPolinomio 2: ";
    derivarPolinomio(p2,d2);
    mostrarPolinomio(d2);
    cout<<endl;
    cout<<"\nSuma: ";
    sumaPolinomios(p1,p2,suma);
    mostrarPolinomio(suma);
    liberarPolinomio(p1);
    liberarPolinomio(p2);
    liberarPolinomio(d1);
    liberarPolinomio(d2);
    liberarPolinomio(suma);
    return 0;
}
//qué es una estructura, defina la clase.(preguntas teoricas)