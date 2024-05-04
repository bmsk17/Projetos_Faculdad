#include <iostream>
#include <limits>

using namespace std;

enum Cores {BRANCO,CINZA,PRETO};
int TEMPO;

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
    int getTAM();
    void print();
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
    int getOrdem();
    Lista<T>* getAdj();
    Lista<T> BFS(T iniVert, T fimVert,Lista<T> listaExecao);//busca em largura
};

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template <class T>
Lista<T>* Grafo<T>::getAdj(){
   return adj;
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
Lista<T> Grafo<T>::BFS (T iniVert, T fimVert,Lista<T> listaExecao){      //Busca em largura, que irá pegar o menor caminho entre dois vertices

    T vertice = iniVert;
    bool encontrou = false;
    int cor[ordem + 1];
    int distancia[ordem + 1];
    //T predecessor[ordem + 1];
    int pulou;
    Lista<T> Vcaminho;

    for(int i = 0; i < ordem + 1; i++){     //Deixar todos com cor branca, distancia infinita e antecessor -1
        cor[i] = BRANCO;
        distancia[i] = numeric_limits<int>::max();  //INFINITO!
        //predecessor[i] = -1;
    }

    cor[vertice] = CINZA;
    distancia[vertice] = -1;
    //predecessor[vertice] = -1;

    Fila<T> fila;
    fila.enfileira(vertice);

    while(!fila.vazia() && !encontrou){
        vertice = fila.getFrente();
        fila.desenfileira(vertice);
        No<T>* posicao = adj[vertice].getPrim()->getProx();    //Pega o primeiro valor da lista

        while(posicao != NULL){     //percorre a lista
            No<T>* lista_execao = listaExecao.getPrim()->getProx();    //Pega o primeiro valor da lista de execeções.
            pulou=0;
            while(lista_execao != NULL){
                if(posicao->getItem() == lista_execao->getItem()){
                    pulou=1;
                }
                lista_execao = lista_execao->getProx();
            }
            if(pulou==1){
                posicao = posicao->getProx();
            }else{
                if(cor[posicao->getItem()] == BRANCO){     //Se o elemento da lista n foi visto
                    cor[posicao->getItem()] = CINZA;       //Troca o valor pra visto
                    distancia[posicao->getItem()] = distancia[vertice] + 1;    //Pega a distancia e incrementa 1
                    //predecessor[posicao->getItem()] = vertice;
                    fila.enfileira(posicao->getItem());
                    Vcaminho.insere(posicao->getItem());
                }

                if(posicao->getItem() == fimVert){  //Se o elemento for o ultimo, ele ira alterar o valor booleano
                    encontrou = true;
                }
                posicao = posicao->getProx();   //Irá pegar o proximo elemento da lista
            }
        }
        cor[vertice] = PRETO; //saindo do loop vértice vira preto pois ja foi visitado
    }

    return Vcaminho;
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

template<class T>
class SistemaPlanetario{
private:

    Grafo<T> *grafo;
    float tamanho;

public:
    SistemaPlanetario(){}
    SistemaPlanetario(T ordem){
        this->grafo= new Grafo<int>(ordem) ;
        this->tamanho=0;
    }
    void inserirAresta(int vert1, int vert2,float tam);
    void print();
    T BFS(T iniVert, T fimVert,Lista<T> listaExecao);
    float getTamanho();


};

template <class T>
float SistemaPlanetario<T>::getTamanho(){
    return tamanho;
}
template<class T>                             //Insere arestas
void SistemaPlanetario<T>::inserirAresta(int vert1, int vert2,float tam){
    grafo->insereAresta(vert1,vert2);
    this->tamanho= tamanho+tam;
}
template<class T>                             //Insere arestas
void SistemaPlanetario<T>::print(){
    grafo->print();
}
template<class T>                             //Insere arestas
T SistemaPlanetario<T>::BFS(T iniVert, T fimVert,Lista<T> listaExecao){
    grafo->BFS(iniVert,fimVert,listaExecao);
}

int main (){

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
    DFS<int> dfs;
    dfs.inicia(g);

    g.print();
    int i = g.BFS(1,5);

    cout <<"BFS VALOR: = "<<i<<"\n";

  for(int i=1;i<=g.getOrdem();i++){
    cout <<"Vertice : "<<i<<" Tempo inicial: "<< dfs.getD()[i] <<" Tempo final: " << dfs.getF()[i]<<'\n';
  }
    for(int i=1;i<=g.getOrdem();i++){
    cout <<"Vertice inicial: "<< dfs.getVertex1()[i] <<" Vertice final: " << dfs.getVertex2()[i]<<'\n';
  }

  for(int i=1;i<=g.getOrdem();i++){
    cout <<"Tempo inicial: "<< dfs.getD()[i] <<"Tempo final: " << dfs.getF()[i]<<'\n';
  }


/*
    int ordem,tamanho,vert1,vert2,inimigo,vInicial,vFinal,contador;
    Lista<int> LInimigos,caminho;
    float soma=0,peso;

    cin>>ordem;
    cin>>tamanho;

    Grafo<int> g(ordem);
    SistemaPlanetario<int> sistema[ordem+1];
    for(int j=0;j<tamanho;j++){
        cin>>vert1;
        cin>>vert2;
        g.insereAresta(vert1,vert2);
    }
    cin>>tamanho;
    for(int j=0;j<tamanho;j++){
        cin>>inimigo;
        LInimigos.insere(inimigo);
    }
    cin>>vInicial;
    cin>>vFinal;

    contador = ordem;

    for(int j=1;j<=contador;j++){
        cin>>ordem;
        cin>>tamanho;
        SistemaPlanetario<int> s(ordem);
        sistema[j]=s;
        for(int i=1;i<=tamanho;i++){
            cin>>vert1;
            cin>>vert2;
            cin>>peso;
            sistema[j].inserirAresta(vert1,vert1,peso);
        }
    }

    caminho= g.BFS(vInicial,vFinal,LInimigos);
    No<int>* p = caminho.getPrim()->getProx();
    while(p != NULL){
        soma=soma + sistema[p->getItem()].getTamanho();
        cout<<"Item : "<<p->getItem()<<" SOMA NELE : "<<sistema[p->getItem()].getTamanho()<<endl;
        p = p->getProx();
    }
    cout<<soma<<endl;

    g.print();
    //cout<<endl<<"O : "<<ordem<<" T : "<<tamanho<<endl;
*/
  return 0;
}






