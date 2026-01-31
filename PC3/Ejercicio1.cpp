#include<iostream>
using namespace std;
int separar(char* texto,char* valores[]){
    int i=0;
    char* p=texto;
    while(*p!='\0'){
        while(*p==' '){
            p=p+1;
        }
        if(*p>='0'&&*p<='9'){
            valores[i]=p;
            i=i+1;
            while(*p!=','&&*p!='\0'){//Permite avanzar hasta coma o fin
                p=p+1;
            }
            if(*p==','){
                *p='\0';
                p=p+1;
            }
        }else{
            p=p+1;
        }
    }
    return i;
}
int convertir_entero(char* cadena){
    int n=0;
    while(*cadena>='0'&&*cadena<='9'){//Validando espacios (" 12")
        n=n*10+(*cadena-'0');
        cadena=cadena+1;
    }
    return n;
}
int main(){
    char texto[]={"1, 2, 4, 7, 11"};
    char* valores[30];
    int k=10;
    cout<<texto<<endl;
    int n=separar(texto,valores);
    bool existen=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int p=convertir_entero(*(valores+i));
            int q=convertir_entero(*(valores+j));
            if(p+q==k){
                existen=true;
            }
        }
    }
    if(existen){
        cout<<"SI existen 2 numeros con suma "<<k;
    }else{
        cout<<"NO existen 2 numeros con suma "<<k;
    }
    return 0;
}