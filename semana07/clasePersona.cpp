#include<iostream>
using namespace std;
class Persona{
    private:
    int* edad;
    public:
    Persona(int e){
        edad=new int;
        *edad=e;
        cout<<"Constructor: Persona creada con edad "<<*edad<<endl;
    }
    ~Persona(){
        cout<<"Destructor: Liberando memoria de edad "<<*edad<<endl;
        delete edad;
    }
    void mostrar(){
        cout<<"Edad: "<<*edad<<endl;
    }
};
int main(){
    Persona p1(20);
    p1.mostrar();
    return 0;
}