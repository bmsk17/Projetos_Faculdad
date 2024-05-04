#include <iostream>

using namespace std;

template <class T>
class Grafo{
private:
    double **matriz;
    int ordem, tamanho;
    void inicializador();
public:
    Grafo(){}
    Grafo(int ordem){
       this->ordem = ordem;
       matriz = new double*[ordem+1];
        for(int i = 1; i <= ordem; i++){
                matriz[i] = new double[ordem+1];
        }
       inicializador();
    }
    void setOrdem(int);
    int getOrdem();
    double** getMatriz();
    void insereAresta(T,T,double);
    void print();
};


template <class T>
void Grafo<T>::inicializador(){
    for(int i = 1;i <= ordem; i++){
        for(int j = 1; j <= ordem; j++){
            matriz[i][j] = 0;
        }
    }
}

template <class T>
void Grafo<T>::insereAresta(T u, T v, double peso){
    matriz[u][v] = peso;
    matriz[v][u] = peso;
    tamanho++;
}

template <class T>
void Grafo<T>::setOrdem(int ordem){
    this->ordem = ordem;
    matriz = new double*[ordem+1];
    for(int i = 1; i <= ordem; i++){
            matriz[i] = new double[ordem+1];
    }
    inicializador();
}

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template <class T>
double** Grafo<T>::getMatriz(){
    return matriz;
}

template <class T>
void Grafo<T>::print(){

    cout << " ";

    for(int i = 1; i <= ordem; i++){
        cout <<  i << "   ";

    }
     cout << endl;

    for(int i = 1; i <= ordem; i++){
        cout <<  i << " ";
        for(int j = 1; j <= ordem; j++){
            cout << matriz[i][j]<< "  ";
        }
        cout << endl;
    }
}




int main(){

Grafo<int> g(5);

g.insereAresta(1, 2,3.5);
g.insereAresta(2, 3,2.1);
g.insereAresta(3, 4,2.8);
g.insereAresta(4, 5,1.0);
g.insereAresta(5, 1,1.3);
g.insereAresta(5, 2,1.25);
g.insereAresta(2, 4,7.5);
g.print();




  return 0;
}
