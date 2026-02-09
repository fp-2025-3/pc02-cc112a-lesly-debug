#include<iostream>
using namespace std;
struct Rectangulo{
    float base;
    float altura;
};
float calcularArea(Rectangulo r){
    return r.base*r.altura;
}
void duplicarDimensiones(Rectangulo& r){
    r.base=r.base*2;
    r.altura=r.altura*2;
}
int main(){
    Rectangulo rect;
    cout<<"Ingrese la base: ";
    cin>>rect.base;
    cout<<"Ingrese la altura: ";
    cin>>rect.altura;
    cout<<"Area: "<<calcularArea(rect)<<endl;
    duplicarDimensiones(rect);
    cout<<"Base: "<<rect.base<<endl;
    cout<<"Altura: "<<rect.altura<<endl;
    cout<<"Area: "<<calcularArea(rect);
    return 0;
}