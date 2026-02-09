#include<iostream>
#include<string>
using namespace std;
struct Motor{
    int cilindrada;
    int caballos;
    string tipo;
};
struct Vehiculo{
    string marca;
    string modelo;
    int anio;
    float precio;
    Motor motor;
};
int main(){
    Vehiculo vehiculos[3]={{"Toyota","Corolla",2020,18000,{1800,140,"gasolina"}},{"Tesla","Model 3",2022,35000,{0,283,"electrico"}},{"Hyundai","Santa Fe",2019,28000,{220,200,"gasolina"}}};
    bool encontrado=false;
    for(int i=0;i<3;i++){
        if(vehiculos[i].motor.tipo=="gasolina"){
            cout<<"Vehiculo "<<i+1<<endl;
            cout<<"Marca: "<<vehiculos[i].marca<<"| Modelo: "<<vehiculos[i].modelo<<"| Anio: "<<vehiculos[i].anio<<"| Precio: "<<vehiculos[i].precio<<endl;
            cout<<"Motor "<<i+1<<endl;
            cout<<"Cilindrada: "<<vehiculos[i].motor.cilindrada<<" Caballos: "<<vehiculos[i].motor.caballos<<" Tipo: "<<vehiculos[i].motor.tipo<<endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<"No hay motor de gasolina."<<endl;
    }
    int indMax=0;
    for(int i=1;i<3;i++){
        if(vehiculos[i].motor.caballos>vehiculos[indMax].motor.caballos){
            indMax=i;
        }
    }
    cout<<"Vehiculo con MAYOR fuerza:\n";
    cout<<"Marca: "<<vehiculos[indMax].marca<<" Modelo: "<<vehiculos[indMax].modelo<<" Anio: "<<vehiculos[indMax].anio<<" Precio: "<<vehiculos[indMax].precio<<endl;
    return 0;
}