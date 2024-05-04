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
    T BFS(T iniVert, T fimVert,Lista<T> listaExecao);//busca em largura
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
T Grafo<T>::BFS (T iniVert, T fimVert,Lista<T> listaExecao){      //Busca em largura, que irá pegar o menor caminho entre dois vertices

    T vertice = iniVert;
    bool encontrou = false;
    int cor[ordem + 1];
    int distancia[ordem + 1];
    T predecessor[ordem + 1];
    int pulou;

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
        cout<<endl<<"MUDOU PARA : "<< vertice<<endl;
        fila.desenfileira(vertice);
        No<T>* posicao = adj[vertice].getPrim()->getProx();    //Pega o primeiro valor da lista

        while(posicao != NULL){     //percorre a lista
            No<T>* lista_execao = listaExecao.getPrim()->getProx();    //Pega o primeiro valor da lista de execeções.
            pulou=0;
            while(lista_execao != NULL){
                cout<<endl<<"----- lista de exclusao : "<<lista_execao->getItem()<<endl;
                cout<<endl<<"----- APONTANDO PARA : "<<posicao->getItem()<<endl;
                if(posicao->getItem() == lista_execao->getItem()){
                    cout<<endl<<"----- Pulou :"<<posicao->getItem()<<" do vetor : "<<vertice<<endl;
                    pulou=1;
                }
                lista_execao = lista_execao->getProx();
            }
            if(pulou==1){
                posicao = posicao->getProx();
                cout<<endl<<"PULOU"<<endl;
            }else{
                if(cor[posicao->getItem()] == BRANCO){     //Se o elemento da lista n foi visto
                    cor[posicao->getItem()] = CINZA;       //Troca o valor pra visto
                    distancia[posicao->getItem()] = distancia[vertice] + 1;    //Pega a distancia e incrementa 1
                    predecessor[posicao->getItem()] = vertice;
                    fila.enfileira(posicao->getItem());
                    cout<<endl<<"ENTROU NA FILA : "<< posicao->getItem()<<endl;
                }

                if(posicao->getItem() == fimVert){  //Se o elemento for o ultimo, ele ira alterar o valor booleano
                    encontrou = true;
                }
                posicao = posicao->getProx();   //Irá pegar o proximo elemento da lista
            }
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

Lista<int> LS;
Grafo<int> g(8);
int i;

g.insereAresta(1, 2);
g.insereAresta(2, 3);
g.insereAresta(3, 4);
g.insereAresta(4, 5);
g.insereAresta(5, 1);
g.insereAresta(5, 2);
g.insereAresta(2, 4);
g.insereAresta(6, 1);
g.insereAresta(6, 5);
g.insereAresta(6, 8);
g.insereAresta(7, 4);
g.insereAresta(7, 8);

g.print();

LS.insere(2);
LS.insere(5);
i = g.BFS(3,6,LS);

cout <<"distancia: "<<i<<"\n";




  return 0;
}






