#include<iostream>
#include<stdlib.h>
using namespace std;

class Grafo{
    public:
    int vertices;
    int p[100];
    int posicionPeso = 1;
    int previo[100];
    int distancia[100];
    int grafo[100][100];
    void inicializarGrafo();
    void mostrarGrafo(); 
    int cargaGrafo(int v, int r);
    bool calcularRutaMasCorta();
    void impresionRutaCorta(int destino);
};

void Grafo::impresionRutaCorta(int destino){
    cout<<destino<<"\n";
    if(previo[destino] != -1){
        impresionRutaCorta(previo[destino]);
    }
    cin.get();
}
bool Grafo::calcularRutaMasCorta(){
    int verticeI = 1;
    int vertice = 1;
    int po = 1;
    cout<<"Ingrese el vertice Inicial ";cin>>verticeI;
    distancia[verticeI] = 0;
    while(vertice <= vertices){
        for(int j = 1; j <= vertices; j++){
            if(grafo[vertice][j] == 1){
                cout<<"el vertice "<<vertice<<" posee una distancia  de "<<distancia[vertice]<<" cuyo peso adyacente es "<<p[po]<<"\n";
                if(distancia[vertice] + p[po] < distancia[j]){
                    distancia[j] = distancia[vertice] + p[po];
                    previo[j] = vertice;
                }
                cout<<"la distancia del vertice "<<j<<" ha sido actualizada a:  "<<distancia[j]<<"\n";
                cin.get();
                po++;
            }
        }
        vertice++;
    }

}

int Grafo::cargaGrafo(int v, int r){
    int a;
    int peso;
    do{
        cout<<"Tiene el vertice "<<v<<" relacion con otro vertice 1 - si / 2 - no ? ";cin>>r;
        system("clear");
        if(r == 1){
            cout<<"Ingrese  el vertice con el cual tiene relacion ";cin>>a;
            system("clear");
            cout<<"Ingrese el peso de esta arista ";cin>>peso;
            p[posicionPeso] = peso;
            posicionPeso++;
            system("clear");
            grafo[v][a] = 1;
        }
        distancia[v] = 999;
        previo[v] = -1;
    }while(r == 1);

    return r;
}

void Grafo::inicializarGrafo(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            grafo[i][j] = 0;
        }
    }
    int r;
    int v = 1;
    cout<<"Ingrese la cantidad de vertices ";cin>>vertices;
    system("clear");
    for(int i = 1; i <= vertices; i++){
       int resp = cargaGrafo(v,r);
       if(resp != 1){
           v++;
       }
    }
    cin.get();
    system("clear");
}

void Grafo::mostrarGrafo(){
    int pesoP = 1;
    for(int y = 0; y <=vertices; y++){
        cout<<" "<<y;
    }
    for(int i = 1; i <= vertices; i++){
        cout<<"\n "<<i;
        for(int j = 1; j <= vertices; j++){
            cout<<" "<<grafo[i][j];
        }
    }
    cout<<"\n";
    cout<<"\n";
    for(int x = 1; x <= vertices; x++ ){
        for(int f = 1; f <= vertices; f++ ){
            if(grafo[x][f] == 1){

                cout<<"La arista entre el vertice "<<x<<" y el vertice "<<f<<" posee un peso de: "<<p[pesoP]<<"\n";
                pesoP++;
            }
        } 
    }
    for(int d = 1; d <= vertices; d++){
        cout<<"La distacia del vertice "<<d<<" es: "<<distancia[d]<<"\n";
    }
    for(int previ = 1; previ <= vertices; previ++){
        cout<<"El vertice previo a "<<previ<<" es: "<<previo[previ]<<"\n";
    }
    cin.get();
    system("clear");
}

int main()
{
    int op = 0;
    int destino;
    Grafo objGrafo;
    while(op < 5 ){
        cout<<"Selecione una de las siguientes operaciones\n";
        cout<<"1 - Ingrese el grafo\n";
        cout<<"2 - Visualizar el grafo\n";
        cout<<"3 - Paso de relajacion\n";
        cout<<"4 - Impresion de la ruta mas corta\n";
        cout<<"5 - Salir del programa\n";cin>>op;
        cin.get();
        system("clear");
        switch(op){
            case 1:
                objGrafo.inicializarGrafo();
            break;
            case 2:
                objGrafo.mostrarGrafo();
            break;
            case 3:
                objGrafo.calcularRutaMasCorta();
            break;
            case 4:
                cout<<"Ingrese el nodo destino ";cin>>destino;
                objGrafo.impresionRutaCorta(destino);
            break;
        }
    }
}