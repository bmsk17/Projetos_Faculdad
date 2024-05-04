#include <iostream>
#include <limits>

using namespace std;

#define BRANCO 0    //N visitado
#define CINZA 1     //Na fila
#define PRETO 2     //Visitado e removido da fila

template<class T>
class No{                      //Nozão da massa!

private:

    T item;
    No<T>* prox;

public:

    No(){
        prox = NULL;
    }
    No(T item){
    this->item = item;
    this->prox = NULL;
    }

    void setItem(T item);
    void setProx(No<T>* prox);
    T getItem();
    No<T>* getProx();
};

template<class T>
void No<T>::setItem(T item) {
    this->item = item;
}

template<class T>
void No<T>::setProx(No* prox) {
    this->prox = prox;
}

template<class T>
T No<T>::getItem() {
    return item;
}

template<class T>
No<T>* No<T>::getProx() {
     return prox;
}

//----------------------------FIM NÓ ------------------------------------------------

template<class T>
class Lista{                        //Lista dinâmica basicona
private:

    No<T>* prim;
    No<T>* ult;

public:

    Lista (){
    prim = new No<T>;
    prim->setProx(NULL);
    ult = prim;
    }

    ~Lista(){}
    No<T>* getPrim();
    No<T>* busca(T item);
    void insere(T item);
    void remove(T item);
    void print();
};

template<class T>
No<T>* Lista<T>::getPrim(){
    return prim;
}

template<class T>
No<T>* Lista<T>::busca(T item){
    No<T>* p = prim->getProx();
    while(p != NULL && p->getItem() != item){
        p = p->getProx();
    }
    return p;
}

template<class T>
void Lista<T>::insere(T item){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
}

template<class T>
void Lista<T>::print(){
    No<T>* p = prim->getProx();
    while(p != NULL){
        cout << p->getItem() << " ";
        p = p->getProx();
    }
    cout << endl;
}

//-----------------------------------------FIM LISTA-----------------------------------

template<class T>
class Fila{                     //Fila usada na função de busca em largura!
private:

    No<T>* frente;
    No<T>* tras;


public:

    Fila(){
    frente = new No<T>;
    frente->setProx(NULL);
    tras = frente;
    }

    T getFrente();
    bool vazia();
    void enfileira(T item);
    void desenfileira(T item);
    void print();
};

template<class T>
bool Fila<T>::vazia(){
    return tras == frente;
}

template<class T>
T Fila<T>::getFrente(){
    return frente->getProx()->getItem();
}

template<class T>
void Fila<T>::enfileira(T item){
    tras->setProx(new No<T>);
    tras = tras->getProx();
    tras->setItem(item);
    tras->setProx(NULL);
}

template<class T>
void Fila<T>::desenfileira(T item){
    No<T>* aux = frente;
    frente = frente->getProx();
    item = frente->getItem();
    delete aux;
}

template<class T>
void Fila<T>::print(){
    frente = frente->getProx();
    while(frente != NULL){
        cout << frente->getItem() << "\n";
        frente = frente->getProx();
    }
}

//----------------------------------------FIM FILA---------------------------------

template<class T>
class Grafo{
private:

    Lista<T> *adj;     //Lista de adjacência pra guardar os adjacentes de cada vertice
    int ordem = 0;          //Ordem = quantidade de vertices do grafo.
    int tamanho;

public:

    Grafo(T ordem);
    void inicializar(T ordem);
    void insereAresta(T vert1, T vert2);
    void print();
    T BFS(T iniVert, T fimVert);//busca em largura
};

template<class T>
Grafo<T>::Grafo(T ordem){
     inicializar(ordem);    //Construtor que recebe a ordem do grafo!
}

template<class T>
void Grafo<T>::inicializar(T ordem){
    this->ordem = ordem;
    adj = new Lista<T>[ordem + 1];
}

template<class T>                             //Insere arestas
void Grafo<T>::insereAresta(T vert1, T vert2){
    adj[vert1].insere(vert2);
    adj[vert2].insere(vert1);
    tamanho++;
}

template<class T>
T Grafo<T>::BFS (T iniVert, T fimVert){      //Busca em largura, que irá pegar o menor caminho entre dois vertices

    T vertice = iniVert;
    bool encontrou = false;
    int cor[ordem + 1];
    int distancia[ordem + 1];
    T predecessor[ordem + 1];

    for(int i = 0; i < ordem + 1; i++){     //Deixar todos com cor branca, distancia infinita e antecessor -1
        cor[i] = BRANCO;
        distancia[i] = numeric_limits<int>::max();  //INFINITO!
        predecessor[i] = -1;
    }

    cor[vertice] = CINZA;
    distancia[vertice] = -1;
    predecessor[vertice] = -1;

    Fila<T> fila;
    fila.enfileira(vertice);

    while(!fila.vazia() && !encontrou){
        vertice = fila.getFrente();
        fila.desenfileira(vertice);
        No<T>* posicao = adj[vertice].getPrim()->getProx();    //Pega o primeiro valor da lista

        while(posicao != NULL){     //percorre a lista
            if(cor[posicao->getItem()] == BRANCO){     //Se o elemento da lista n foi visto
                cor[posicao->getItem()] = CINZA;       //Troca o valor pra visto
                distancia[posicao->getItem()] = distancia[vertice] + 1;    //Pega a distancia e incrementa 1
                predecessor[posicao->getItem()] = vertice;
                fila.enfileira(posicao->getItem());
            }

            if(posicao->getItem() == fimVert){  //Se o elemento for o ultimo, ele ira alterar o valor booleano
                encontrou = true;
                cout<<"Predecessor : "<<predecessor[posicao->getItem()]<<endl;
                cout<<"Posicao : "<<posicao->getItem()<<endl;
                int mudarv,mudau;
                mudarv=predecessor[posicao->getItem()];
                mudau=posicao->getItem();
                for(int i=1;i<=distancia[fimVert]+1;i++){
                    mudau=mudarv;
                    mudarv=predecessor[mudarv];
                    cout<<"--------------------------------------------------"<<endl;
                    cout<<"Predecessor : "<<mudarv<<endl;
                    cout<<"Posicao : "<<mudau<<endl;

                }
            }

            posicao = posicao->getProx();   //Irá pegar o proximo elemento da lista
        }
        cor[vertice] = PRETO; //saindo do loop vértice vira preto pois ja foi visitado
    }

    return distancia[fimVert]+1;
}

template<class T>
void Grafo<T>::print(){
    for(int i = 1;i < ordem+1;i++){
        cout << "v[" << i << "] = ";
        adj[i].print();
    }
}

//-------------------------------------FIM GRAFO --------------------

int main (){

Grafo<int> g(18);
int i;

g.insereAresta(1, 3);
g.insereAresta(1, 9);
g.insereAresta(1, 15);
g.insereAresta(1, 16);
g.insereAresta(1, 17);
g.insereAresta(2, 4);
g.insereAresta(2, 5);
g.insereAresta(2, 11);
g.insereAresta(2, 12);
g.insereAresta(2, 18);
g.insereAresta(3, 8);
g.insereAresta(3, 9);
g.insereAresta(3, 14);
g.insereAresta(4, 5);
g.insereAresta(4, 6);
g.insereAresta(4, 7);
g.insereAresta(4, 9);
g.insereAresta(4, 15);
g.insereAresta(5, 7);
g.insereAresta(5, 12);
g.insereAresta(5, 14);
g.insereAresta(5, 15);
g.insereAresta(6, 7);
g.insereAresta(6, 9);
g.insereAresta(7, 12);
g.insereAresta(7, 13);
g.insereAresta(7, 15);
g.insereAresta(7, 17);
g.insereAresta(8, 11);
g.insereAresta(8, 12);
g.insereAresta(8, 14);
g.insereAresta(9, 10);
g.insereAresta(9, 11);
g.insereAresta(9, 12);
g.insereAresta(9, 14);
g.insereAresta(9, 13);
g.insereAresta(10, 14);
g.insereAresta(10, 15);
g.insereAresta(11, 12);
g.insereAresta(11, 13);
g.insereAresta(11, 16);
g.insereAresta(11, 18);
g.print();

i = g.BFS(1,2);

cout <<"distancia: "<<i<<"\n";




  return 0;
}






