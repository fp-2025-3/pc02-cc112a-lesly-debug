#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const double M_PI=3.1415926535;
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
            colorRGB[i]=otro.colorRGB[i];
        }
    }
    Figura& operator=(Figura& otro){
        if(this!=&otro){
            nombre=otro.nombre;
            delete[] colorRGB;
            colorRGB=new double[3];
            for(int i=0;i<3;i++){
                colorRGB[i]=otro.colorRGB[i];
            }
        }
        return *this;
    }
    virtual ~Figura(){
        delete[] colorRGB;
    }
    virtual double area() const=0;
    virtual double perimetro() const=0;
    virtual void imprimir() const=0;
    string getNombre() const{
        return nombre;
    }
    double getR() const{
        return colorRGB[0];
    }
    double getG() const{
        return colorRGB[1];
    }
    double getB() const{
        return colorRGB[2];
    }
};
class Circulo:public Figura{
    private:
    double radio;
    public:
    Circulo(string nom,double r,double g,double b,double rd):Figura(nom,r,g,b),radio(rd){}
    double area() const{
        return M_PI*radio*radio;
    }
    double perimetro() const{
        return 2*M_PI*radio;
    }
    void imprimir() const{
        cout<<"Figura: "<<getNombre()<<endl;
        cout<<"Radio: "<<radio<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimetro: "<<perimetro()<<endl;
        cout<<endl;
    }
};
class Rectangulo:public Figura{
    private:
    double base;
    double altura;
    public:
    Rectangulo(string nom,double r,double g,double b,double bas,double alt):Figura(nom,r,g,b),base(bas),altura(alt){}
    double area() const{
        return base*altura;
    }
    double perimetro() const{
        return 2*(base+altura);
    }
    void imprimir() const{
        cout<<"Figura: "<<getNombre()<<endl;
        cout<<"Base: "<<base<<endl;
        cout<<"Altura: "<<altura<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimetro: "<<perimetro()<<endl;
        cout<<endl;
    }
};
class GestorFigura{
    private:
    Figura** figuras;
    int cantidad;
    int capacidad;
    public:
    GestorFigura(int cap){
        capacidad=cap;
        cantidad=0;
        figuras=new Figura*[capacidad];
    }
    ~GestorFigura(){
        for(int i=0;i<cantidad;i++){
            delete figuras[i];
        }
        delete[] figuras;
    }
    void agregarFigura(Figura* f){
        if(cantidad==capacidad){
            int nuevaCapacidad=capacidad*2;
            Figura** nuevo=new Figura*[nuevaCapacidad];
            for(int i=0;i<cantidad;i++){
                nuevo[i]=figuras[i];
            }
            delete[] figuras;
            figuras=nuevo;
            capacidad=nuevaCapacidad;
        }
        figuras[cantidad]=f;
        cantidad=cantidad+1;
    }
    void mostrarFiguras() const{
        for(int i=0;i<cantidad;i++){
            figuras[i]->imprimir();
        }
    }
    double areaTotal() const{
        double total=0;
        for(int i=0;i<cantidad;i++){
            total=total+figuras[i]->area();
        }
        return total;
    }
    void guardarArchivo(string nombreArchivo){
        ofstream archivo(nombreArchivo);
        if(!archivo){
            cerr<<"Error al abrir el archivo.\n";
            return;
        }
        for(int i=0;i<cantidad;i++){
            archivo<<"Figura: "<<figuras[i]->getNombre()<<endl;
            archivo<<"Area: "<<figuras[i]->area()<<endl;
            archivo<<"Perimetro: "<<figuras[i]->perimetro()<<endl;
            archivo<<endl;
        }
        archivo.close();
    }
};
int main(){
    GestorFigura gestor(2);
    gestor.agregarFigura(new Circulo("Circulo",255,0,0,5));
    gestor.agregarFigura(new Rectangulo("Rectangulo",0,255,0,4,6));
    gestor.mostrarFiguras();
    cout<<"Area total: "<<gestor.areaTotal()<<endl;
    gestor.guardarArchivo("figuras.txt");
    return 0;
}