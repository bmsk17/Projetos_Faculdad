#include <iostream>

enum Cores {BRANCO,CINZA,PRETO};
int TEMPO;

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
    int TAM;

public:

    Lista (){
    prim = new No<T>;
    prim->setProx(NULL);
    ult = prim;
    }

    ~Lista(){}
    No<T>* getPrim();
    int busca(int i);
    void insere(T item);
    void remove(T item);
    void print();
    int getTAM();
};

template <class T>
int Lista<T>::getTAM(){
    return TAM;
}

template<class T>
No<T>* Lista<T>::getPrim(){
    return prim;
}

template<class T>
int Lista<T>::busca(int i){

    No<T> *p = getPrim()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         achou = p->getItem();
      }
      cont++;
      p = p->getProx();
    }

    return achou;
}

template<class T>
void Lista<T>::insere(T item){
    ult->setProx(new No<T>);
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
    TAM++;
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

//--------------------------------FIM LISTA-------------------------------

//--------------------------------INICIO GRAFO----------------------------

template<class T>
class Grafo{
private:

    Lista<T> *adj;     //Lista de adjacência pra guardar os adjacentes de cada vertice
    int ordem = 0;          //Ordem = quantidade de vertices do grafo.
    int tamanho;


public:

    Grafo(T ordem){
     inicializar(ordem);    //Construtor que recebe a ordem do grafo!
    }
    void inicializar(T ordem);
    void insereAresta(T vert1, T vert2);
    void print();
    int getOrdem();
    Lista<T>* getAdj();
};

template <class T>
Lista<T>* Grafo<T>::getAdj(){
   return adj;
}

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
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

//--------------------------------INICIO DFS----------------------------


class DFS {
private:
  int *pred;
  Cores *cor;
  int *d;
  int *f;
  int *vertx1;
  int *vertx2;
  void dfs(Grafo<int> &);
  void dfsVisita(Grafo<int> &,int);
public:
  DFS();
  void inicia(Grafo<int> &);
  int *getPred();
  Cores *getCor();
  int *getF();
  int *getD();
  int *getVertex1();
  int *getVertex2();
};

DFS::DFS(){ }
void DFS::inicia(Grafo<int> &g){
  dfs(g);
}

int * DFS::getPred(){
  return pred;
}

Cores * DFS::getCor(){
  return cor;
}

int *DFS::getF(){
  return f;
}

int *DFS::getD(){
  return d;
}
int *DFS::getVertex1(){
  return vertx1;
}
int *DFS::getVertex2(){
  return vertx2;
}

void DFS::dfsVisita(Grafo<int> &g, int u){
  TEMPO = TEMPO +1;
  vertx1[u] = u;
  d[u] = TEMPO;
  cor[u] = CINZA;
  Lista<int> adj = g.getAdj()[u];
  int i = 1;
  while(i <= adj.getTAM()){
        int v = adj.busca(i);
        if(cor[v] == BRANCO){
            vertx2[u] = v;
            pred[v] = u;
            dfsVisita(g,v);
        }
        i++;
    }
  cor[u] = PRETO;
  TEMPO = TEMPO + 1;
  f[u] = TEMPO;
}

void DFS::dfs(Grafo<int> &g){
    const int N = g.getOrdem();
    pred = new int[N];
    cor = new Cores[N];
    d = new int[N];
    f = new int[N];
    vertx1 = new int[N];
    vertx2 = new int[N];

    for(int u=1;u<=N;u++){
      cor[u] = BRANCO;
      pred[u] = -1;
    }
    TEMPO = 0;
    for(int u=1;u<=N;u++){
      if(cor[u] == BRANCO){
         dfsVisita(g,u);
      }
    }
}

//--------------------------------FIM DFS----------------------------


int main()
{
 Grafo<int> g(18);
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

    DFS dfs;
    dfs.inicia(g);

    g.print();

  for(int i=1;i<=g.getOrdem();i++){
    cout <<"Tempo inicial: "<< dfs.getD()[i] <<"Tempo final: " << dfs.getF()[i]<<'\n';
  }
    for(int i=1;i<=g.getOrdem();i++){
    cout <<"Vertice inicial: "<< dfs.getVertex1()[i] <<"Vertice final: " << dfs.getVertex2()[i]<<'\n';
  }

    return 0;
}




























