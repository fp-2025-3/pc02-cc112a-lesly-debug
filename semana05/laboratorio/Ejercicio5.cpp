#include<iostream>
using namespace std;
struct Proceso{//Proceso: Nodo de la lista
    int ID;
    char* nombre;
    double memoria;
    Proceso* sig;
};
struct ListaProcesos{//Representa la lista completa
    Proceso* cabeza;
};
void my_strcpy(char* destino,const char* origen){
    while(*origen!='\0'){
        *destino=*origen;
        destino=destino+1;
        origen=origen+1;
    }
    *destino='\0';
}
int my_strlen(const char* texto){
    int contador=0;
    while(*texto!='\0'){
        contador=contador+1;
        texto=texto+1;
    }
    return contador;
}
void inicializarLista(ListaProcesos& lista){
    lista.cabeza=nullptr;
}
void insertarInicio(ListaProcesos& lista,int id,const char* nombre,double memoria){
    Proceso* nuevo=new Proceso;
    nuevo->ID=id;
    nuevo->nombre=new char[my_strlen(nombre)+1];
    my_strcpy(nuevo->nombre,nombre);
    nuevo->memoria=memoria;
    nuevo->sig=lista.cabeza;
    lista.cabeza=nuevo;
}
void insertarFinal(ListaProcesos& lista,int id,const char* nombre,double memoria){
    Proceso* nuevo=new Proceso;
    nuevo->ID=id;
    nuevo->nombre=new char[my_strlen(nombre)+1];
    my_strcpy(nuevo->nombre,nombre);
    nuevo->memoria=memoria;
    nuevo->sig=nullptr;
    if(lista.cabeza==nullptr){
        lista.cabeza=nuevo;
        return;
    }
    Proceso* aux=lista.cabeza;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    aux->sig=nuevo;
}
void mostrarProcesos(const ListaProcesos& lista){
    Proceso* aux=lista.cabeza;
    if(aux==nullptr){
        cout<<"Lista vacia\n";
        return;
    }
    while(aux!=nullptr){
        cout<<"ID: "<<aux->ID<<" | Nombre: "<<aux->nombre<<" | Memoria. "<<aux->memoria<<" MB\n";
        aux=aux->sig;
    }
}
bool buscarProceso(const ListaProcesos& lista,int id){
    Proceso* aux=lista.cabeza;
    while(aux!=nullptr){
        if(aux->ID==id){
            return true;
        }
        aux=aux->sig;
    }
    return false;
}
bool eliminarProceso(ListaProcesos& lista,int id){
    if(lista.cabeza==nullptr){
        return false;
    }
    if(lista.cabeza->ID==id){
        Proceso* temp=lista.cabeza;
        lista.cabeza=lista.cabeza->sig;
        delete[] temp->nombre;
        delete temp;
        return true;
    }
    Proceso* aux=lista.cabeza;
    while(aux->sig!=nullptr&&aux->sig->ID!=id){
        aux=aux->sig;
    }
    if(aux->sig==nullptr){
        return false;
    }
    Proceso* temp=aux->sig;
    aux->sig=temp->sig;
    delete[] temp->nombre;
    delete temp;
    return true;
}
int contarProcesos(const ListaProcesos& lista){
    int contador=0;
    Proceso* aux=lista.cabeza;
    while(aux!=nullptr){
        contador=contador+1;
        aux=aux->sig;
    }
    return contador;
}
void ordenarPorMemoria(ListaProcesos& lista){
    if(lista.cabeza==nullptr){
        return;
    }
    bool cambiado;
    do{
        cambiado=false;
        Proceso* aux=lista.cabeza;
        while(aux->sig!=nullptr){
            if(aux->memoria>aux->sig->memoria){
                int idTemp=aux->ID;
                aux->ID=aux->sig->ID;
                aux->sig->ID=idTemp;
                char* nombreTemp=aux->nombre;
                aux->nombre=aux->sig->nombre;
                aux->sig->nombre=nombreTemp;
                double memTemp=aux->memoria;
                aux->memoria=aux->sig->memoria;
                aux->sig->memoria=memTemp;
                cambiado=true;
            }
            aux=aux->sig;
        }
    }while(cambiado);
}
void insertarOrdenado(ListaProcesos& lista,int id,const char* nombre,double memoria){
    Proceso* nuevo=new Proceso;
    nuevo->ID=id;
    nuevo->nombre=new char[my_strlen(nombre)+1];
    my_strcpy(nuevo->nombre,nombre);
    nuevo->memoria=memoria;
    nuevo->sig=nullptr;
    if(lista.cabeza==nullptr||memoria<(lista.cabeza->memoria)){
        nuevo->sig=lista.cabeza;
        lista.cabeza=nuevo;
        return;
    }
    Proceso* aux=lista.cabeza;
    while(aux->sig!=nullptr&&aux->sig->memoria<memoria){
        aux=aux->sig;
    }
    nuevo->sig=aux->sig;
    aux->sig=nuevo;
}
void liberarLista(ListaProcesos& lista){
    while(lista.cabeza!=nullptr){
        Proceso* temp=lista.cabeza;
        lista.cabeza=lista.cabeza->sig;
        delete[] temp->nombre;
        delete temp;
    }
}
int main(){
    ListaProcesos lista;
    inicializarLista(lista);
    insertarInicio(lista,1,"Proceso A",120);
    insertarInicio(lista,2,"Proceso B",120);
    insertarInicio(lista,3,"Proceso C",120);
    insertarFinal(lista,4,"Proceso D",150);
    insertarFinal(lista,5,"Proceso E",60);
    cout<<"Procesos actuales:\n";
    mostrarProcesos(lista);
    int idEliminado;
    cout<<"Ingrese ID a eliminar: ";
    cin>>idEliminado;
    if(buscarProceso(lista,idEliminado)){
        cout<<"Encontrado\n";
        eliminarProceso(lista,idEliminado);
        cout<<"Eliminado\n";
    }else{
        cout<<"Proceso no encontrado\n";
    }
    cout<<"Lista luego de eliminar:\n";
    mostrarProcesos(lista);
    cout<<"Cantidad de procesos: "<<contarProcesos(lista)<<endl;
    cout<<"\nOrdenando lista por memoria...\n";
    ordenarPorMemoria(lista);
    mostrarProcesos(lista);
    cout<<"\nInsertar ordenado por memoria:\n";
    int idInsertado=6;
    const char* nombreInsertado={"Proceso F"};
    double memoriaInsertada=90;
    insertarOrdenado(lista,idInsertado,nombreInsertado,memoriaInsertada);
    cout<<"ID: "<<idInsertado<<" | Nombre: "<<nombreInsertado<<" | "<<" | Memoria: "<<memoriaInsertada<<" MB\n\n";
    mostrarProcesos(lista);
    liberarLista(lista);
    return 0;
}