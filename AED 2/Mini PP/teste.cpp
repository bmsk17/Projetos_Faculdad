#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class UnionFind{
private:
    int tamanho,*vetorVertice;
public:
    UnionFind(){}
    UnionFind(int tamanho){
        this->tamanho=tamanho;
        vetorVertice = new int[tamanho];
        for(int i=1;i<=tamanho;i++){
            vetorVertice[i]=i;
        }
    }
    int busca(int x);
    void uniao(int x,int y);
};


template<class T>
void UnionFind<T>::uniao(int x,int y){
    int v1 = busca(x);
    int v2 = busca(y);

    vetorVertice[v1]=v2;
}

template<class T>
int UnionFind<T>::busca(int x){
    if(vetorVertice[x]==x){
        return x;
    }
    return busca(vetorVertice[x]);

}





template<class T>
class Aresta{
private:
    T vertice1,vertice2;
    double peso;
public:
    Aresta(){}
    Aresta( T vertice1,T vertice2,double peso){
        this->vertice1=vertice1;
        this->vertice2=vertice2;
        this->peso=peso;
    }

    T getVertice1();
    T getVertice2();
    double getPeso();
    void setVertice1(T vertice);
    void setVertice2(T vertice);
    void setPeso(double peso);

};


template<class T>
T Aresta<T>::getVertice1(){
    return vertice1;
}

template<class T>
T Aresta<T>::getVertice2(){
    return vertice2;
}

template<class T>
double Aresta<T>::getPeso(){
    return peso;
}

template<class T>
void Aresta<T>::setVertice1(T vertice){
    this->vertice1=vertice;
}

template<class T>
void Aresta<T>::setVertice2(T vertice){
    this->vertice2=vertice;
}

template<class T>
void Aresta<T>::setPeso(double peso){
    this->peso=peso;
}

template<class T>
class Grafo{
private:
    double **matriz;
    Aresta<T> *vet;
    int ordem,tamanho,aux=0;
    void inicializador();

public:
    Grafo(){}
    Grafo(int ordem,int tamanho){
        this->tamanho=tamanho;
        this->ordem=ordem;

        vet =new Aresta<T>[tamanho+1];
        matriz = new double*[ordem+1];

        for(int i=1; i<=ordem; i++ ){
            matriz[i]= new double[ordem+1];
        }
        inicializador();
    }

public:
    double** getMatriz();
    int getOrdem();
    int getTamanho();
    Aresta<T>* getVet();
    void setVet(Aresta<T>* aresta);
    void insereAresta(T vet1,T vet2,double peso);
    void print();

};

template<class T>
void Grafo<T>::print(){

    for(int i = 1; i <= ordem; i++){
        cout <<endl;
        for(int j = 1; j <= ordem; j++){
            cout << matriz[i][j]<< "  ";
        }
    }

}


template<class T>
void Grafo<T>::insereAresta(T vet1,T vet2,double peso){
    matriz[vet1][vet2]= peso;
    matriz[vet2][vet1]= peso;

    vet[aux].setVertice1(vet1);
    vet[aux].setVertice2(vet2);
    vet[aux].setPeso(peso);
    aux++;


}



template<class T>
void Grafo<T>::inicializador(){
    for(int i=1; i<=ordem; i++ ){
        for(int j=1; j<=ordem; j++ ){
            matriz[i][j] = 0;
        }
    }
}

template<class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template<class T>
int Grafo<T>::getTamanho(){
    return tamanho;
}

template<class T>
Aresta<T>* Grafo<T>::getVet(){
    return vet;
}

template<class T>
double** Grafo<T>::getMatriz(){
    return matriz;
}

template<class T>
void Grafo<T>::setVet(Aresta<T>* aresta){
    this->vet=aresta;
}


template <class T>
class Kruskal{
private:
    Aresta<T>* vetKrustal;
    double** matriz,pesoMst;
    int tam,ordem;
public:
    Kruskal(){}
    Kruskal(Aresta<T>* vet,int tam, int ordem){
        this->vetKrustal=vet;
        this->tam=tam;
        this->ordem=ordem;
        this->pesoMst=0;
    }

    double** getMatriz();
    double getPesoMst();
    int getOrdem();
    int getTamanho();
    Aresta<T>* getVetKrustal();
    void setVetKrustal(Aresta<T>* aresta);
    void setPesoMst(double peso);
    void setMatriz(double** matriz);
    void executaKrustal();
    void chamaKrustal();
    void ordenarVetor(Aresta<T>* vet,int tam);

};

template <class T>
int Kruskal<T>::getOrdem(){
    return this->ordem;
}

template<class T>
int Kruskal<T>::getTamanho(){
    return this->tam;
}

template<class T>
double Kruskal<T>::getPesoMst(){
    return this->pesoMst;
}

template<class T>
double** Kruskal<T>::getMatriz(){
    return this->matriz;
}

template<class T>
Aresta<T>* Kruskal<T>::getVetKrustal(){
    return this->vetKrustal;
}

template<class T>
void Kruskal<T>::setVetKrustal(Aresta<T>* aresta){
    this->vetKruskal=aresta;
}

template<class T>
void Kruskal<T>::setPesoMst(double peso){
    this->pesoMst=peso;
}

template<class T>
void Kruskal<T>::setMatriz(double** matriz){
    this->matriz=matriz;
}

template<class T>
void Kruskal<T>::chamaKrustal(){
    executaKrustal();
}

template<class T>
void Kruskal<T>::ordenarVetor(Aresta<T>* vet,int tam){

    int vet1,vet2;
    double peso;

    for(int i=0; i<tam-1; i++ ){
        for(int j=0; j<tam-1-i; j++ ){
            if(vet[j].getPeso()>vet[j+1].getPeso()){
                vet1= vet[j].getVertice1();
                vet2= vet[j].getVertice2();
                peso= vet[j].getPeso();

                vet[j].setVertice1(vet[j+1].getVertice1());
                vet[j].setVertice2(vet[j+1].getVertice2());
                vet[j].setPeso(vet[j+1].getPeso());

                vet[j+1].setVertice1(vet1);
                vet[j+1].setVertice2(vet2);
                vet[j+1].setPeso(peso);

            }
        }
    }




}



template<class T>
void Kruskal<T>::executaKrustal(){
    Aresta<T>* vet = getVetKrustal();
    int ordem= getOrdem();
    int tamanho = getTamanho();
    Aresta<T> arvore[ordem];
    UnionFind<T> une(ordem);
    int h =0;
    double soma=0;

    ordenarVetor(vet,tamanho);

    for(int i = 0; i<tamanho;i++){
        int v1 = une.busca(vet[i].getVertice1());
        int v2 = une.busca(vet[i].getVertice2());

        if(v1!=v2){
            arvore[i].setVertice1(vet[i].getVertice1());
            arvore[i].setVertice2(vet[i].getVertice2());
            arvore[i].setPeso(vet[i].getPeso());
            h++;
            une.uniao(v1,v2);
            soma= soma + vet[i].getPeso();
        }
    }
    cout<<endl<<"Aqui : "<<soma;

}





int main(){

Grafo<int> g(6,13);

g.insereAresta (1, 2, 48.0);
g.insereAresta (1 ,3, 86.0);
g.insereAresta (1 ,4, 34.0);
g.insereAresta (1, 5, 66.0);
g.insereAresta (2, 3, 82.0);
g.insereAresta (2, 4 ,53.0);
g.insereAresta (2, 5, 67.0);
g.insereAresta (2, 6, 9.0);
g.insereAresta (3, 4, 79.0);
g.insereAresta (3,6, 38.0);
g.insereAresta (4 ,5, 14.0);
g.insereAresta (4 ,6, 47.0);
g.insereAresta (5, 6 ,83.0);



g.print();



Kruskal <int> k (g.getVet(),g.getTamanho(),g.getOrdem());

k.chamaKrustal();

    return 0;

}




