#include<iostream>
#include<string>
using namespace std;
class Figura{
    private:
    string nombre;
    double* colorRGB;
    public:
    Figura(string nom,double r,double g,double b):nombre(nom){
        colorRGB=new double[3];
        colorRGB[0]=r;
        colorRGB[1]=g;
        colorRGB[2]=b;
    }
    Figura(Figura& otro):nombre(otro.nombre){
        colorRGB=new double[3];
        for(int i=0;i<3;i++){
            colorRGB=otro.colorRGB[i];
        }
    }
    Figura& operator=(Figura& otro){
        if(this!=)
    }
    virtual ~Figura(){
        delete[] colorRGB;
    }
    virtual double area() const=0;
    virtual double perimetro() const=0;
    virtual double imprimir() const=0;
};
int main(){
    return 0;
}