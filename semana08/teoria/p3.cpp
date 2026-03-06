#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Figura{
    private:
    int tipo;
    double* medidas;
    public:
    Figura(){
        tipo=0;
        medidas=nullptr;
    }
    void leerFigura(){
        cout<<"Ingrese el numero de lados (3 o 4) de la figura: ";
        cin>>tipo;
        if(tipo==3){
            medidas=new double[3];
            cout<<"Ingrese los lados a, b, c del triangulo: ";
            cin>>medidas[0]>>medidas[1]>>medidas[2];
        }else{
            medidas=new double[2];
            cout<<"Ingrese lados a, b del rectangulo: ";
            cin>>medidas[0]>>medidas[1];
        }
    }
    bool existeTriangulo(){
        if(tipo!=3){
            return true;
        }
        return (medidas[0]+medidas[1]>medidas[2]&&medidas[1]+medidas[2]>medidas[0]&&medidas[0]+medidas[2]>medidas[1]);
    }
    double area(){
        if(tipo==3&&existeTriangulo()){
            double a=medidas[0];
            double b=medidas[1];
            double c=medidas[2];
            double s=(a+b+c)/2;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
        if(tipo==4){
            return medidas[0]*medidas[1];
        }
        return 0;
    }
    ~Figura(){
        delete[] medidas;
    }
};
int main(){
    int n;
    cout<<"Ingrese el numero de rectangulos o triangulos: ";
    cin>>n;
    Figura* figuras=nullptr;
    figuras=new Figura[n];
    for(int i=0;i<n;i++){
        figuras[i].leerFigura();
    }
    for(int i=0;i<n;i++){
        if(figuras[i].existeTriangulo()){
            cout<<fixed<<setprecision(2);
            cout<<"Area de la figura "<<i+1<<": "<<figuras[i].area()<<endl;
        }else{
            cout<<"No existe un triangulo con los lados ingresados.\n";
        }
    }
    delete[] figuras;
    return 0;
}