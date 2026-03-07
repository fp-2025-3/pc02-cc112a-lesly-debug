#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Sensor{
    protected:
    string id;
    double *posicion;
    public:
    Sensor(string id,double x,double y){
        this->id=id;
        posicion=new double[2];
        posicion[0]=x;
        posicion[1]=y;
    }
    Sensor(const Sensor &s){
        id=s.id;
        posicion=new double[2];
        posicion[0]=s.posicion[0];
        posicion[1]=s.posicion[1];
    }
    Sensor& operator=(const Sensor& s){
        if(this!=&s){
            id=s.id;
            delete[] posicion;
            posicion=new double[2];
            posicion[0]=s.posicion[0];
            posicion[1]=s.posicion[1];
        }
        return *this;
    }
    virtual ~Sensor(){
        delete[] posicion;
    }
    virtual double areaCobertura() const=0;
    virtual bool detecta(double x,double y) const=0;
    virtual void imprimir() const=0;
};
class SensorCircular:public Sensor{
    private:
    double radio;
    public:
    SensorCircular(string id,double x,double y,double r):Sensor(id,x,y){
        radio=r;
    }
    double areaCobertura() const{
        return M_PI*radio*radio;
    }
    bool detecta(double x,double y) const{
        double dx=x-posicion[0];
        double dy=y-posicion[1];
        double distancia=sqrt(dx*dx+dy*dy);
        return (distancia<=radio);
    }
    void imprimir() const{
        cout<<"Sensor Circular\n";
        cout<<"ID: "<<id<<endl;
        cout<<"Centro: ("<<posicion[0]<<","<<posicion[1]<<")\n";
        cout<<"Radio: "<<radio<<endl;
        cout<<"Area: "<<areaCobertura()<<endl;
        cout<<"-------------------\n";
    }
};
class SensorRectangular:public Sensor{
    private:
    double ancho;
    double alto;
    public:
    SensorRectangular(string id,double x,double y,double a,double h):Sensor(id,x,y){
        ancho=a;
        alto=h;
    }
    double areaCobertura() const{
        return ancho*alto;
    }
    bool detecta(double x,double y) const{
        double xMin=posicion[0]-ancho/2;
        double xMax=posicion[0]+ancho/2;
        double yMin=posicion[1]-alto/2;
        double yMax=posicion[1]+alto/2;
        return (x>=xMin&&x<=xMax&&y>=yMin&&y<=yMax);
    }
    void imprimir() const{
        cout<<"Sensor Rectangular\n";
        cout<<"ID: "<<id<<endl;
        cout<<"Centro: ("<<posicion[0]<<","<<posicion[1]<<")\n";
        cout<<"Ancho: "<<ancho<<endl;
        cout<<"Alto: "<<alto<<endl;
        cout<<"Area: "<<areaCobertura()<<endl;
        cout<<"-------------------\n";
    }
};
class SistemaSensores{
    private:
    Sensor **sensores;
    int cantidad;
    int capacidad;
    public:
    SistemaSensores(){
        capacidad=5;
        cantidad=0;
        sensores=new Sensor*[capacidad];
    }
    ~SistemaSensores(){
        for(int i=0;i<cantidad;i++){
            delete sensores[i];
        }
        delete[] sensores;
    }
    void agregarSensor(Sensor *s){
        if(cantidad==capacidad){
            capacidad*=2;
            Sensor **nuevo=new Sensor*[capacidad];
            for(int i=0;i<cantidad;i++){
                nuevo[i]=sensores[i];
            }
            delete[] sensores;
            sensores=nuevo;
        }
        sensores[cantidad]=s;
        cantidad=cantidad+1;
    }
    void mostrarSensores() const{
        for(int i=0;i<cantidad;i++){
            sensores[i]->imprimir();
        }
    }
    double areaTotalCobertura() const{
        double suma=0;
        for(int i=0;i<cantidad;i++){
            suma=suma+sensores[i]->areaCobertura();
        }
        return suma;
    }
    int sensoresQueDetectan(double x,double y) const{
        int contador=0;
        for(int i=0;i<cantidad;i++){
            if(sensores[i]->detecta(x,y)){
                contador=contador+1;
            }
        }
        return contador;
    }
    Sensor* sensorMayorCobertura() const{
        if(cantidad==0){
            return nullptr;
        }
        int posicion=0;
        for(int i=1;i<cantidad;i++){
            if(sensores[i]->areaCobertura()>sensores[posicion]->areaCobertura()){
                posicion=i;
            }
        }
        return sensores[posicion];
    }
};
int main(){
    SistemaSensores sistema;
    int opcion;
    do{
        cout<<"==== MENU DE SENSORES ====\n";
        cout<<"1 Agregar sensor circular\n";
        cout<<"2 Agregar sensor rectangular\n";
        cout<<"3 Mostrar sensores\n";
        cout<<"4 Area total cobertura\n";
        cout<<"5 Sensores que detectan punto\n";
        cout<<"6 Sensor mayor cobertura\n";
        cout<<"0 Salir\n";
        cin>>opcion;
        switch(opcion){
            case 1:{
                string id;
                double x,y,r;
                cout<<"ID: ";
                cin>>id;
                cout<<"x y: ";
                cin>>x>>y;
                cout<<"radio: ";
                cin>>r;
                sistema.agregarSensor(new SensorCircular(id,x,y,r));
                break;
            }
            case 2:{
                string id;
                double x,y,a,h;
                cout<<"ID: ";
                cin>>id;
                cout<<"x y: ";
                cin>>x>>y;
                cout<<"ancho alto: ";
                cin>>a>>h;
                sistema.agregarSensor(new SensorRectangular(id,x,y,a,h));
                break;
            }
            case 3:{
                sistema.mostrarSensores();
                break;
            }
            case 4:{
                cout<<"Area total: "<<sistema.areaTotalCobertura()<<endl;
                break;
            }
            case 5:{
                double x,y;
                cout<<"Ingrese punto: ";
                cin>>x>>y;
                cout<<"Detectan: "<<sistema.sensoresQueDetectan(x,y)<<endl;
                break;
            }
            case 6:{
                Sensor* s=sistema.sensorMayorCobertura();
                if(s){
                    s->imprimir();
                }
                break;
            }
        }
    }while(opcion!=0);
    return 0;
}