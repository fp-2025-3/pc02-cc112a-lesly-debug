#include<iostream>
#include<fstream>
using namespace std;
const int MAX_LIBROS=7;
struct Libro{
    int codigo;
    char titulo[50];
    bool prestado;
};
struct Usuario{
    int codigo;
    string nombres;
    int prestamos;
};
int my_strcmp(const char* a,const char* b){
    while(*a!='\0'&&*b!='\0'&&*a==*b){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
void registrarLibro(Libro libros[],int& n){
    if(n>=MAX_LIBROS){
        cout<<"Capacidad maxima alcanzada.";
        return;
    }
    cout<<"-----REGISTRO DE LIBRO-----\n";
    cout<<"Codigo: ";
    cin>>libros[n].codigo;
    cout<<"Titulo: ";
    cin.ignore();
    cin.getline(libros[n].titulo,50);
    libros[n].prestado=false;
    n=n+1;
}
int buscarLibro(Libro libros[],int n,int codigo){
    for(int i=0;i<n;i++){
        if(libros[i].codigo==codigo){
            if(!libros[i].prestado){
                return i;
            }
        }
    }
    return -1;
}
int encontrarLibro(Libro libros[],int n,int codigo){
    for(int i=0;i<n;i++){
        if(libros[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}
void prestarLibro(Libro libros[],int n,int codigo){
    int pos=encontrarLibro(libros,n,codigo);
    if(pos==-1){
        cout<<"Libro no existe.\n";
    }else{
        if(libros[pos].prestado){
            cout<<"Libro no disponible.\n";
        }else{
            libros[pos].prestado=true;
            cout<<"Libro: "<<libros[pos].titulo<<endl;
            cout<<"Libro prestado correctamente.\n";
        }
    }
}
void devolverLibro(Libro libros[],int n){
    int codigo;
    char nombre[50];
    cout<<"Ingrese el codigo: ";
    cin>>codigo;
    cout<<"Ingrese el titulo: ";
    cin.ignore();
    cin.getline(nombre,50);
    int pos=encontrarLibro(libros,n,codigo);
    if(pos==-1){
        cout<<"Libro no registrado.\n";
        return;
    }
    if(!libros[pos].prestado){
        cout<<"El libro no fue prestado.\n";
        return;
    }
    if(my_strcmp(libros[pos].titulo,nombre)==0){
        libros[pos].prestado=false;
        cout<<"Libro devuelto correctamente.\n";
    }else{
        cout<<"Datos incorrectos.\n";
    }
}
void mostrarLibros(Libro libros[], int n){
    if(n==0){
        cout << "No hay libros registrados.\n";
        return;
    }
    cout<<"---- LISTA DE LIBROS ----\n";
    for(int i=0;i<n;i++){
        cout<<libros[i].codigo<<" - "<<libros[i].titulo<<" - ";
        if(libros[i].prestado){
            cout<<"Prestado\n";
        }else{
            cout<<"Disponible\n";
        }
    }
}
void guardarEnArchivo(Libro libros[],int n){
    ofstream archivo("libros.dat",ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo para guardar.\n";
        return;
    }
    archivo.write((char*)&n,sizeof(int));
    archivo.write((char*)libros,sizeof(Libro)*n);
    archivo.close();
    cout<<"Datos guardados correctamente.\n";
}
void cargarDesdeArchivo(Libro libros[], int& n){
    ifstream archivo("libros.dat",ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        n=0;
        return;
    }
    archivo.read((char*)&n,sizeof(int));
    archivo.read((char*)libros,sizeof(Libro)*n);
    archivo.close();
    cout<<"Datos cargados correctamente.\n";
}
int main(){
    Libro libros[MAX_LIBROS];
    int cantidad=0;
    int codigo;
    int opcion;
    cargarDesdeArchivo(libros, cantidad);
    do{
        cout<<"====== MENU DE OPCIONES ======\n";
        cout<<"1. Registrar libro."<<endl;
        cout<<"2. Prestar libro."<<endl;
        cout<<"3. Devolver libro."<<endl;
        cout<<"4. Buscar libro."<<endl;
        cout<<"5. Mostrar libros."<<endl;
        cout<<"6. Salir."<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                registrarLibro(libros,cantidad);
                break;
            }
            case 2:{
                cout<<"Ingrese el codigo: ";
                cin>>codigo;
                if(encontrarLibro(libros,cantidad,codigo)!=-1){
                    prestarLibro(libros,cantidad,codigo);
                }else{
                    cout<<"Libro no registrado.\n";
                }
                break;
            }
            case 3:{
                devolverLibro(libros,cantidad);
                break;
            }
            case 4:{
                cout<<"Ingrese el codigo: ";
                cin>>codigo;
                int pos = encontrarLibro(libros, cantidad, codigo);
                if(pos == -1){
                    cout << "Libro no registrado.\n";
                }else{
                    cout << libros[pos].codigo << " - "<< libros[pos].titulo << " - ";
                    if(libros[pos].prestado){
                        cout<<"Prestado\n";
                    }else{
                        cout<<"Disponible.\n";
                    }
                }
                break;
            }
            case 5:{
                mostrarLibros(libros,cantidad);
                break;
            }
            case 6:{
                guardarEnArchivo(libros, cantidad);
                cout<<"Saliendo...";
                break;
            }
        }
    }while(opcion!=6);
    return 0;
}