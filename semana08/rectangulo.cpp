#include "rectangulo.h"
#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;
bool Rectangulo::coordenadasValidas(double x,double y) const{
    if(x<0||y<0){
        return false;
    }
    if(x>20.0||y>20.0){
        return false;
    }
    return true;
}
bool Rectangulo::formaRectangulo() const{
    if(y1==y2&&x2==x3&&y3==y4&&x1==x4){
        return true;
    }else{
        return false;
    }
}
Rectangulo::Rectangulo(double a,double b,double c,double d,double e,double f,double g,double h){
    if(coordenadasValidas(a,b)&&coordenadasValidas(c,d)&&coordenadasValidas(e,f)&&coordenadasValidas(g,h)){
        this->x1=a;this->y1=b;
        this->x2=c;this->y2=d;
        this->x3=e;this->y3=f;
        this->x4=g;this->y4=h;
        if(formaRectangulo()){
            valido=true;
        }else{
            cout<<"Las coordenadas ingresadas no forman un rectangulo valido.\n";
            valido=false;
        }
    }else{
        cout<<"Coordenadas fuera del rango permitido.\n";
        valido=false;
    }
}
Rectangulo::Rectangulo(double largo,double ancho){
    if(largo<=0||ancho<=0||largo>20.0||ancho>20.0){
        cout<<"Dimensiones invalidas para el rectangulo.\n";
        this->x1=0;this->y1=0;
        this->x2=1;this->y2=0;
        this->x3=1;this->y3=1;
        this->x4=0;this->y4=1;
        valido=false;
    }else{
        this->x1=0;this->y1=0;
        this->x2=largo;this->y2=0;
        this->x3=largo;this->y3=ancho;
        this->x4=0;this->y4=ancho;
        valido=true;
    }
}
double Rectangulo::largo() const{
    if(!valido){
        return 0;
    }
    double base=fabs(x2-x1);
    double altura=fabs(y4-y1);
    if(base>altura){
        return base;
    }else{
        return altura;
    }
}
double Rectangulo::ancho() const{
    if(!valido){
        return 0;
    }
    double base=fabs(x2-x1);
    double altura=fabs(y4-y1);
    if(base>altura){
        return altura;
    }else{
        return base;
    }
}
double Rectangulo::area() const{
    if(!valido){
        return 0;
    }
    return largo()*ancho();
}
double Rectangulo::perimetro() const{
    if(!valido){
        return 0;
    }
    return 2*(largo()+ancho());
}
bool Rectangulo::esCuadrado() const{
    if(!valido){
        return false;
    }
    if(largo()==ancho()){
        return true;
    }else{
        return false;
    }
}
void Rectangulo::mostrarDatos() const{
    cout<<fixed<<setprecision(2);
    if(!valido){
        cout<<"Rectangulo invalido.\n";
        return;
    }
    cout<<"Largo: "<<largo()<<endl;
    cout<<"Ancho: "<<ancho()<<endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimetro: "<<perimetro()<<endl;
    if(esCuadrado()){
        cout<<"Es un cuadrado.\n";
    }else{
        cout<<"No es un cuadrado.\n";
    }
}
Rectangulo::~Rectangulo(){
    cout<<"Destrutor llamado: liberando memoria del objeto Rectangulo: ["<<largo()<<","<<ancho()<<"]"<<endl;
}