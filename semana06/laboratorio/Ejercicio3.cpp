#include<iostream>
#include<fstream>
using namespace std;
struct Producto{
    int id;
    char nombre[30];
    double precio;
    int stock;
    bool activo;
};
int buscarproductoPorID(const char* nombreArchivo,int Idbuscar){
    ifstream archivo(nombreArchivo,ios::binary);
    if(!archivo){
        return -1;
    }
    Producto p;
    int posicion=0;
    while(archivo.read((char*)&p,sizeof(Producto))){
        if(p.id==Idbuscar){
            archivo.close();
            return posicion;
        }
        posicion=posicion+1;
    }
    archivo.close();
    return -1;
}
void registrarProducto(const char* nombreArchivo){
    Producto p;
    cout<<"Ingrese ID: ";
    cin>>p.id;
    if(buscarproductoPorID(nombreArchivo,p.id)!=-1){
        cout<<"Error, el ID ya existe.\n";
    }
    cin.ignore();
    cout<<"Ingrese el nombre: ";
    cin.getline(p.nombre,30);
    cout<<"Ingrese el precio: ";
    cin>>p.precio;
    if(p.precio<=0){
        cout<<"Precio invalido.\n";
        return;
    }
    cout<<"Ingrese el stock: ";
    cin>>p.stock;
    if(p.stock<=0){
        cout<<"Stock invalido.\n";
        return;
    }
    p.activo=true;
    ofstream archivo(nombreArchivo,ios::binary|ios::app);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    archivo.write((char*)&p,sizeof(Producto));
    archivo.close();
    cout<<"Producto registrado correctamente.\n";
}
void mostrarProductos(const char* nombreArchivo){
    ifstream archivo(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Producto p;
    while(archivo.read((char*)&p,sizeof(Producto))){
        if(p.activo){
            cout<<"ID: "<<p.id<<" | Nombre:"<<p.nombre<<" | Precio: "<<p.precio<<" | Stock: "<<p.stock<<endl;
        }
    }
    archivo.close();
}
void modificarPrecio(const char* nombreArchivo,int id,double nuevoPrecio){
    if(nuevoPrecio<=0){
        cout<<"Precio invalido.\n";
        return;
    }
    int posicion=buscarproductoPorID(nombreArchivo,id);
    if(posicion==-1){
        cout<<"Producto no encontrado.\n";
        return;
    }
    fstream archivo(nombreArchivo,ios::binary|ios::in|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Producto p;
    archivo.seekg(posicion*sizeof(Producto),ios::beg);
    archivo.read((char*)&p,sizeof(Producto));
    p.precio=nuevoPrecio;
    archivo.seekp(posicion*sizeof(Producto),ios::beg);
    archivo.write((char*)&p,sizeof(Producto));
    archivo.close();
    cout<<"Precio modificado correctamente.\n";
}
void eliminarProducto(const char* nombreArchivo,int id){
    int posicion=buscarproductoPorID(nombreArchivo,id);
    if(posicion==-1){
        cout<<"Producto no encontrado.\n";
        return;
    }
    fstream archivo(nombreArchivo,ios::binary|ios::in|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Producto p;
    archivo.seekg(posicion*sizeof(Producto),ios::beg);
    archivo.read((char*)&p,sizeof(Producto));
    p.activo=false;
    archivo.seekp(posicion*sizeof(Producto),ios::beg);
    archivo.write((char*)&p,sizeof(Producto));
    archivo.close();
    cout<<"Producto eliminado correctamente.\n";
}
double calcularValorInventario(const char* nombreArchivo){
    ifstream archivo(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return 0;
    }
    Producto p;
    double total=0;
    while(archivo.read((char*)&p,sizeof(Producto))){
        if(p.activo){
            total=total+p.precio*p.stock;
        }
    }
    return total;
}
int main(){
    const char* archivo="inventario.dat";
    int opcion;
    do{
        cout<<"=======MENU=======\n";
        cout<<"1. Registrar producto\n";
        cout<<"2. Mostrar productos\n";
        cout<<"3. Buscar producto\n";
        cout<<"4. Modificar precio\n";
        cout<<"5. Eliminar producto\n";
        cout<<"6. Calcular valor total\n";
        cout<<"7. Salir\n";
        cin>>opcion;
        int id;
        double precio;
        switch(opcion){
            case 1:{
                registrarProducto(archivo);
                break;
            }
            case 2:{
                mostrarProductos(archivo);
                break;
            }
            case 3:{
                cout<<"Ingrese ID a buscar: ";
                cin>>id;
                cout<<"Posicion: "<<buscarproductoPorID(archivo,id)<<endl;
                break;
            }
            case 4:{
                cout<<"Ingrese ID: ";
                cin>>id;
                cout<<"Ingrese el nuevo precio: ";
                cin>>precio;
                modificarPrecio(archivo,id,precio);
                break;
            }
            case 5:{
                cout<<"Ingrese ID a eliminar: ";
                cin>>id;
                eliminarProducto(archivo,id);
                break;
            }
            case 6:{
                cout<<"Valor total del inventario: "<<calcularValorInventario(archivo)<<endl;
                break;
            }
            case 7:{
                cout<<"Saliendo...\n";
            }
        }
    }while(opcion!=7);
    return 0;
}