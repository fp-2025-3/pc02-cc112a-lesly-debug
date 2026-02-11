#include<iostream>
#include<cmath>
using namespace std;
struct Punto3D{
    float x;
    float y;
    float z;
};
float distanciaEuclidiana(Punto3D p1,Punto3D p2){
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
}
int main(){
    Punto3D p1;
    Punto3D p2;
    cout<<"Ingrese las coordenadas del primer punto:"<<endl;
    cout<<"X: ";
    cin>>p1.x;
    cout<<"Y: ";
    cin>>p1.y;
    cout<<"Z: ";
    cin>>p1.z;
    cout<<"Ingrese las coordenadas del segundo punto:"<<endl;
    cout<<"X: ";
    cin>>p2.x;
    cout<<"Y: ";
    cin>>p2.y;
    cout<<"Z: ";
    cin>>p2.z;
    float d=distanciaEuclidiana(p1,p2);
    cout<<"La distancia entre los dos puntos es: "<<d;
    return 0;
}