#include <iostream>
#include <string>

using namespace std;
using std::string;

char** crearMatriz(int,string);
void liberarMatriz(char**,int);
void llenarMatriz(char**,int,string);
void Mazmorra();
void imprimirMatriz(char**,int,string);
bool valPfila(string);

int main(){//menu principal
	int opcm=0;
	while(opcm!=2){
		cout<<"Menu"<<endl
			<<"1. Mazmorra"<<endl
			<<"2. Salir"<<endl
			<<"Ingrese una opcion: "<<endl;
		cin>>opcm;
		if(opcm==1){
			Mazmorra();
		}
	}	
}

char** crearMatriz(int size, string pfila){//crear matriz
	char** matriz=new char*[size];
	for(int i=0;i<size;i++){
		matriz[i]=new char[pfila.length()];
	}
	return matriz;
}

void Mazmorra(){
	int size=99;
	cout<<"Ingrese el numero de filas: "<<endl;
	cin>>size;
	while(size<=1){
		cout<<"Ingrese el numero de filas: "<<endl;
	        cin>>size;
	}
	string pfila;
	cout<<"Ingrese el patron de la primera fila utilizando ^ y ."<<endl
		<<"siendo ^ las trampas y . los lugares seguros: "<<endl;
	cin>>pfila;
	while(valPfila(pfila)){
		cout<<"Ingrese el patron de la primera fila utilizando ^ y ."<<endl
                <<"siendo ^ las trampas y . los lugares seguros "<<endl
		<<"ingrese solo caracteres validos: "<<endl;
	        cin>>pfila;
	}
	char** mazmorra= crearMatriz(size,pfila);//se crea la matriz a traves del metodo crearMatriz
	llenarMatriz(mazmorra,size,pfila);
	cout<<"La matriz queda: "<<endl;
	imprimirMatriz(mazmorra,size,pfila);//se muestra la matriz final
	cout<<endl;
	int cont=0;
	for(int x=0;x<size;x++){//se inicia el conteo de azulejos seguros en la matriz
		for(int y=0;y<pfila.length();y++){
			if(mazmorra[x][y]=='.')
				cont++;	
		}
	}
	cout<<"La cantidad de azulejos seguros es: "<<cont<<endl;
	liberarMatriz(mazmorra,size);
}

void imprimirMatriz(char** matriz,int size,string pfila){
	//impresion de los datos que contiene la matriz
	for(int x=0;x<size;x++){
		for(int y=0;y<pfila.length();y++){
			cout<<matriz[x][y];
		}
		cout<<endl;
	}
}

void llenarMatriz(char** matriz, int size, string pfila){
	for(int i=0;i<pfila.length();i++){
		matriz[0][i]=pfila[i];
	}
	for(int x=1;x<size;x++){
		bool izq=false,cen=false,der=false;
		for(int y=0;y<pfila.length();y++){
			if((y-1)<0){//validacion de espacio vacio
				izq=true;
			}else if(matriz[x-1][y-1]=='.'){//validacion de azulejo
				izq=true;
			}else{
				izq=false;
			}
			if((y+1)==pfila.length()){//validacion de espacio vacio
				der=true;
			}else if(matriz[x-1][y+1]=='.'){//validacion de azulejo
				der=true;
			}else{
				der=false;
			}
			if(matriz[x-1][y]=='.'){//validacion de azulejo
				cen=true;
			}else{
				cen=false;
			}
			if((izq==true&&cen==true&&der==false)||(izq==false&&cen==true&&der==true)||
					(izq==false&&cen==false&&der==true)||(izq==true&&cen==false&&der==false)){
				//asignacion del azulejo debido a las validaciones creadas
				matriz[x][y]='^';
			}else{
				matriz[x][y]='.';
			}
		}
	}
}

void liberarMatriz(char** matriz,int size){//libera el espacio de memoria dinamica de la matriz
	if(matriz!=NULL){
		for(int i=0;i<size;i++){
			delete[] matriz[i];
			matriz[i]=NULL;
		}
		delete[] matriz;
		matriz=NULL;
	}
}
bool valPfila(string pfila){
	int cont=0;
	for(int i=0;i<pfila.length();i++){
		if(pfila[i]=='.'||pfila[i]=='^'){
			cont++;
		}
	}
	if(cont==pfila.length()){
		return false;
	}else{
		return true;
	}
}
