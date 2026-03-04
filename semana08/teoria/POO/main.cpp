#include "vehiculos.h"
Vehiculo** lista = nullptr;
int cantidad = 0;
void agregar(Vehiculo* nuevo){
    Vehiculo** temp=new Vehiculo*[cantidad+1];
    for(int i=0;i<cantidad;i++){
        temp[i]=lista[i];
    }
    temp[cantidad]=nuevo;
    delete[] lista;
    lista=temp;
    cantidad++;
}
void registrar(){
    int tipo;
    cout<<"1. Automovil\n";
    cout<<"2. Camion\n";
    cout<<"3. Motocicleta\n";
    cout<<"Seleccione tipo: ";
    cin>>tipo;
    string placa,marca;
    int anio;
    double precio;
    cout<<"Placa: ";
    cin>>placa;
    cout<<"Marca: ";
    cin>>marca;
    cout<<"Anio: ";
    cin>>anio;
    cout<<"Precio Base: ";
    cin>>precio;
    if(tipo==1){
        int puertas;
        cout<<"Puertas: ";
        cin>>puertas;
        agregar(new Automovil(placa,marca,anio,precio,puertas));
    }else if(tipo==2){
        double cap;
        cout<<"Capacidad: ";
        cin>>cap;
        agregar(new Camion(placa,marca,anio,precio,cap));
    }else{
        double pot;
        cout<<"Potencia: ";
        cin>>pot;
        agregar(new Motocicleta(placa,marca,anio,precio,pot));
    }
}
void mostrar(){
    if(cantidad==0){
        cout<<"No hay vehiculos registrados.\n";
        return;
    }
    cout<<"\n=========== VEHICULOS ===========\n";
    for(int i=0;i<cantidad;i++){
        cout<<"Vehiculo "<<i+1<<"\n";
        cout<<"---------------------------------\n";
        lista[i]->mostrar();
        cout<<"---------------------------------\n";
    }
}
void guardar(){
    ofstream out("vehiculos.dat",ios::binary);
    out.write((char*)&cantidad,sizeof(cantidad));
    for(int i=0;i<cantidad;i++){
        int tipo=lista[i]->getTipo();
        out.write((char*)&tipo,sizeof(tipo));
        lista[i]->guardar(out);
    }
    out.close();
}
void leer(){
    ifstream in("vehiculos.dat",ios::binary);
    if(!in){
        cout<<"No existe archivo.\n";
        return;
    }
    int n;
    in.read((char*)&n,sizeof(n));
    for(int i=0;i<n;i++){
        int tipo;
        in.read((char*)&tipo,sizeof(tipo));
        Vehiculo* v=nullptr;
        if(tipo==1){
            v=new Automovil();
        }else if(tipo==2){
            v=new Camion();
        }else{
            v=new Motocicleta();
        }
        v->cargar(in);
        agregar(v);
    }
    in.close();
}
void liberar(){
    for(int i=0;i<cantidad;i++){
        delete lista[i];
    }
    delete[] lista;
}
int main(){
    int opcion;
    do{
        cout<<"=====================================\n";
        cout<<"         SISTEMA DE VEHICULOS        \n";
        cout<<"=====================================\n";
        cout<<"1. Registrar vehiculo\n";
        cout<<"2. Mostrar vehiculos\n";
        cout<<"3. Guardar en archivo\n";
        cout<<"4. Leer desde archivo\n";
        cout<<"0. Salir\n";
        cout<<"-----------------------------------------\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:{
                cout<<"--- REGISTRO DE VEHICULO ---\n";
                registrar();
                break;
            }
            case 2:{
                cout<<"--- LISTA DE VEHICULOS ---\n";
                mostrar();
                break;
            }
            case 3:{
                guardar();
                cout<<"Vehiculos guardados correctamente.\n";
                break;
            }
            case 4:{
                leer();
                cout<<"Vehiculos cargados correctamente.\n";
                break;
            }
            case 0:{
                cout<<"Saliendo del sistema...\n";
            }
        }

    }while(opcion!=0);
    liberar();
    return 0;
}