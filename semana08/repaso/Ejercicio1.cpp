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
void ordenarPolinomio(Polinomio& p){
    for(int i=0;i<p.numTerminos-1;i++){
        for(int j=i+1;j<p.numTerminos;j++){
            if(p.terminos[i].exponente<p.terminos[j].exponente){
                Termino aux=p.terminos[i];
                p.terminos[i]=p.terminos[j];
                p.terminos[j]=aux;
            }
        }
    }
}
void mostrarPolinomio(const Polinomio& p){
    if(p.numTerminos==0){
        cout<<"0";
        return;
    }
    for(int i=0;i<p.numTerminos;i++){
        if(i>0&&p.terminos[i].coeficiente>=0){
            cout<<"+";
        }
        if(p.terminos[i].exponente==0){
            cout<<p.terminos[i].coeficiente;
        }else if(p.terminos[i].exponente==1){
            cout<<p.terminos[i].coeficiente<<"x";
        }else{
            cout<<p.terminos[i].coeficiente<<"x^"<<p.terminos[i].exponente;
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
    ordenarPolinomio(p1);
    ordenarPolinomio(p2);
    crearPolinomio(resultado,p1.numTerminos+p2.numTerminos);
    int i=0,j=0,k=0;
    while(i<p1.numTerminos&&j<p2.numTerminos){
        if(p1.terminos[i].exponente==p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p1.terminos[i].coeficiente+p2.terminos[j].coeficiente;
            resultado.terminos[k].exponente=p1.terminos[i].exponente;
            i=i+1;
            j=j+1;
        }else if(p1.terminos[i].exponente>p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p1.terminos[i].coeficiente;
            resultado.terminos[k].exponente=p1.terminos[i].exponente;
            i=i+1;
        }else if(p1.terminos[i].exponente<p2.terminos[j].exponente){
            resultado.terminos[k].coeficiente=p2.terminos[j].coeficiente;
            resultado.terminos[k].exponente=p2.terminos[j].exponente;
            j=j+1;
        }
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
    resultado.numTerminos=k;
}
void liberarPolinomio(Polinomio& p){
    delete[] p.terminos;
    p.terminos=nullptr;
    p.numTerminos=0;
}
void derivadaEnesima(const Polinomio& p,Polinomio& resultado,int n){
    crearPolinomio(resultado, p.numTerminos);
    for(int i=0;i<p.numTerminos;i++){
        resultado.terminos[i]=p.terminos[i];
    }
    for(int k=0;k<n;k++){
        Polinomio temp;
        derivarPolinomio(resultado,temp);
        liberarPolinomio(resultado);
        resultado=temp;
    }
}
int main(){
    Polinomio p1,p2,d1,d2,suma;
    int n1,n2;
    cout<<"Ingrese la cantidad de terminos del primer polinomio: ";
    cin>>n1;
    crearPolinomio(p1,n1);
    leerPolinomio(p1);
    ordenarPolinomio(p1);
    cout<<"\nP1(x)= ";
    mostrarPolinomio(p1);
    double v1;
    cout<<"\nValor a evaluar: ";
    cin>>v1;
    cout<<"Resultado: "<<evaluarPolinomio(p1,v1)<<endl;
    cout<<"\nIngrese la cantidad de terminos del segundo polinomio: ";
    cin>>n2;
    crearPolinomio(p2,n2);
    leerPolinomio(p2);
    ordenarPolinomio(p2);
    cout<<"\nP2(x)= ";
    mostrarPolinomio(p2);
    cout<<"\n\nDerivadas:\n";
    derivarPolinomio(p1,d1);
    derivarPolinomio(p2,d2);
    cout<<"P1'(x)= ";
    mostrarPolinomio(d1);
    cout<<"\nP2'(x)= ";
    mostrarPolinomio(d2);
    cout<<"\n\nSuma: ";
    sumaPolinomios(p1,p2,suma);
    mostrarPolinomio(suma);
    Polinomio dn;
    int n;
    cout<<"\nOrden de derivada: ";
    cin>>n;
    derivadaEnesima(p1,dn,n);
    cout<<"Derivada "<<n<<"-esima: ";
    mostrarPolinomio(dn);
    liberarPolinomio(p1);
    liberarPolinomio(p2);
    liberarPolinomio(d1);
    liberarPolinomio(d2);
    liberarPolinomio(suma);
    return 0;
}
//qué es una estructura, defina la clase.(preguntas teoricas)