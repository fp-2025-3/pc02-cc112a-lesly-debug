#include<iostream>
#include<string>
using namespace std;
class Vehiculo{
    protected:
    int ruedas;
    string color;
    public:
    Vehiculo(int r,string c):ruedas(r),color(c){}
    void mostrarInfo(){
        cout<<"Numero de ruedas del vehiculo: "<<ruedas<<endl;
        cout<<"Color del vehiculo: "<<color<<endl;
    }
    ~Vehiculo(){
        cout<<"Destructor vehiculo.\n"<<endl;
    }
};
class Coche:public Vehiculo{
    private:
    int numeroPuertas;
    public:
    Coche(int r,string c,int np):Vehiculo(r,c),numeroPuertas(np){

    }
    void mostrarCoche(){
        cout<<"Numero de puertas del coche: "<<numeroPuertas<<endl;
        cout<<"Color del coche: "<<color<<endl;
        cout<<"Numero de ruedas del coche: "<<ruedas<<endl;
    }
    ~Coche(){
        cout<<"Destructor coche.\n"<<endl;
    }
};
class Motocicleta:public Vehiculo{
    private:
    double potencia;
    public:
    Motocicleta(int r,string c,int np,double p):Vehiculo(r,c),potencia(p){

    }
    ~Motocicleta(){
        cout<<"Destructor motocicleta.\n";
    }
};
class Moto:public Vehiculo{
    private:
    bool conCasco;
    public:
    Moto(int r,string c,bool casco):Vehiculo(r,c),conCasco(casco){

    }
    void mostrarMoto(){
        cout<<"Color de la moto: "<<color<<endl;
        cout<<"Numero de ruedas de la moto: "<<ruedas<<endl;
        if(conCasco){
            cout<<"Casco puesto.\n";
        }else{
            cout<<"Sin casco.\n";
        }
    }
    ~Moto(){
        cout<<"Destructor moto.\n";
    }
};
int main(){
    Vehiculo v1(4,"Azul");
    v1.mostrarInfo();
    Coche c1(4,"Rojo",4);
    c1.mostrarCoche();
    Moto m1(2,"Negro",true);
    m1.mostrarMoto();
    return 0;
}