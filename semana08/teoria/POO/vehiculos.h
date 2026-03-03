#ifndef VEHICULOS_H
#define VEHICULOS_H
#include<iostream>
#include<string>
using namespace std;
class Vehiculo{
    protected:
    string placa;
    string marca;
    int anio;
    double precioVenta;
    public:
    Vehiculo();
    Vehiculo(string p,string m,int a,double pv);
    virtual ~Vehiculo();//OBLIGATORIO
    virtual void aumentarPrecio()=0;
    virtual void guardar(ofstream& out) const=0;
    virtual void cargar(ifstream& in) const=0;
    virtual void mostrarInfo() const=0;
};
class Automovil:public Vehiculo{
    private:
    int numeroPuertas;
    public:
    Automovil();
    Automovil(string p,string m,int a,double pv,int np);
    ~Automovil();
    void aumentarPrecio();
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) const override;
    void mostrarInfo() const override;
};
class Camion:public Vehiculo{
    private:
    double capacidad;
    public:
    Camion();
    Camion(string p,string m,int a,double pv,double c);
    ~Camion();
    void aumentarPrecio();
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) const override;
    void mostrarInfo() const override;
};
class Motocicleta:public Vehiculo{
    private:
    double potencia;
    public:
    Motocicleta();
    Motocicleta(string p,string m,int a,double pv,double pt);
    ~Motocicleta();
    void aumentarPrecio();
    void guardar(ofstream& out) const override;
    void cargar(ifstream& in) const override;
    void mostrarInfo() const override;
};
#endif