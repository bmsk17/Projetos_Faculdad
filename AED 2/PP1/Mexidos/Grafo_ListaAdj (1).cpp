#include <iostream>

using namespace std;

template<class T>
class No{                      //Nozão da massa!

private:

    T item;
    No<T>* prox;

public:

    No(){
        prox = NULL;
    }
    No(T item);
    void setItem(T item);
    void setProx(No<T>* prox);
    T getItem();
    No<T>* getProx();
};

template<class T>
No<T>::No(T item) {
    this->item = item;
    this->prox = NULL;
}

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

    Lista ();
    ~Lista(){}
    No<T>* getPrim();
    No<T>* busca(T item);
    void insere(T item);
    void remove(T item);
    void print();

};

template <class T>
Lista<T>::Lista(){
    prim = new No<T>;
    prim->setProx(NULL);
    ult = prim;
}

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

template<class T>
class Aresta{
private:

    T vertice1;
    T vertice2;
    float peso ;

public:

    Aresta(T vertice1,T vertice2,float peso){
        this->vertice1= vertice1;
        this->vertice2= vertice2;
        this->peso= peso;
    }
    int getVertice1();
    int getVertice2();
    float getPeso();
};
template<class T>
int Aresta<T>::getVertice1() {
     return vertice1;
}

template<class T>
int Aresta<T>::getVertice2() {
     return vertice2;
}

template<class T>
float Aresta<T>::getPeso() {
     return peso;
}

//-----------------------------------------FIM LISTA-----------------------------------

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
    int verificaVertice (T vert1, T vert2); //BUSCA ARESTA NO GRAFO (listas de adj)
};

template <class T>
int Grafo<T>::verificaVertice(T vert1,T vert2){

    Lista<T> *aux = adj;
    No<T> *p;
    int i = ordem;
    int cont=0;

    for (int j = 1;j<=i;j++){
        if(j==vert1){
            for (int u = 1;u<=i;u++){
                p = aux[j].busca(vert2);
                if (p != NULL){
                    cont++;
                }
            }
        }
    }


  if (cont > 0){
    return 0;
  }
  else{
    return 1;
  }

}

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
void Grafo<T>::print(){
    for(int i = 1;i < ordem+1;i++){
        cout << "v[" << i << "] = ";
        adj[i].print();
    }
}

//-------------------------------------FIM GRAFO --------------------

int main (){

Grafo<int> g(5);

g.insereAresta(1, 2);
g.insereAresta(2, 3);
g.insereAresta(3, 4);
g.insereAresta(4, 5);
g.insereAresta(5, 1);
g.insereAresta(5, 2);
g.insereAresta(2, 4);
g.print();

int pos;

pos = g.verificaVertice(3,5);

cout <<pos;


  return 0;
}






