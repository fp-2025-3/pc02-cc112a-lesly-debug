#ifndef RECTANGULO_H
#define RECTANGULO_H
using namespace std;
class Rectangulo{
    private:
    double x1,y1;
    double x2,y2;
    double x3,y3;
    double x4,y4;
    bool valido;
    bool coordenadasValidas(double x,double y) const;
    bool formaRectangulo() const;
    public:
    Rectangulo(double,double,double,double,double,double,double,double);
    Rectangulo(double largo,double ancho);
    double largo() const;
    double ancho() const;
    double area() const;
    double perimetro() const;
    bool esCuadrado() const;
    void mostrarDatos() const;
    ~Rectangulo();
};
#endif