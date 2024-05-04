#include <iostream>
using namespace std;


class  Vetor {
private:

    int chave;

public:

    Vetor (){}
    Vetor(int chave): chave(chave) { }
    void setChave(int chave);
    int getChave();
    void Imprime();

};

void Vetor::setChave(int chave){
   this->chave = chave;
}

int Vetor::getChave(){
   return chave ;
}

void Vetor::Imprime(){
  cout <<chave <<" ";
  }

//*****************************************************************************

template <class T>
class heapSort {

private:

    T *vet; //ainda sem utilizar
    int TAM;
    int pai;
    int esq;
    int dir;

public:

    heapMax (){}
    void heapMax (T *vet, int i, int n);
    void constroiHeap(T *vet, int n);
    void heapsort(T *vet, int n);
    bool ordenado (T *vet, int TAM);
    void setTAM(int TAM);
    void setVET (T *vet);
    T* getVET  ();
    int getTAM();
    int getPai(int i);
    int getEsq(int i);
    int getDir(int i);

};


template <class T>
 void heapSort<T>::setVET (T *vet){
    this->vet = vet;
}

template <class T>
T* heapSort<T>::getVET (){
    return *vet;
}

template <class T>
void heapSort<T>::setTAM(int TAM){
   this->TAM = TAM;
}

template <class T>
int heapSort<T>::getTAM(){
   return this->TAM ;
}

template <class T>
int heapSort<T>::getPai(int i) {
   return (i/2);
}

template <class T>
int heapSort<T>::getEsq(int i) {
   return 2*i;
}

template <class T>
int heapSort<T>::getDir(int i) {
   return 2*i+1;
}

template <class T>
void heapSort<T>::heapMax (T *vet, int i, int n){
  int esq,dir,maior,aux;

  esq=2*i;
  dir=(2*i+1);

  if((esq<=n)&&vet[esq]>vet[i]){
    maior=esq;
  }
  else{
    maior=i;
  }
  if((dir<=n)&&(vet[dir]>vet[maior])){
    maior=dir;
  }
  if(maior!=i)
    {
      aux=vet[i];
      vet[i]=vet[maior];
      vet[maior]=aux;
      heapMax(vet, maior,n);
    }
}

template <class T>
void heapSort<T>::constroiHeap(T *vet, int n){
  for(int k = n/2; k >= 1; k--)
    {
      heapMax(vet, k, n);
    }
}

template <class T>
void heapSort<T>::heapsort(T *vet, int n){

  constroiHeap(vet,n);
  int i, temp;
  for (i = n; i >= 2; i--)
    {
      temp = vet[i];
      vet[i] = vet[1];
      vet[1] = temp;
      heapMax(vet, 1, i - 1);
    }
}

template <class T>
bool heapSort<T>::ordenado (T *vet,int TAM){

     for(int i = 1; i < TAM; i++){
        if (vet[i] > vet[i + 1]) {
            return false;
        }
    }
    return true;

}


//-------------------------------------------------------------------------------------------------


template <class T>
class No {
private:
    T item;
    No *prox;
public:
    No() {}
    T getItem();
    void setItem(T item);
    No* getProx();
    void setProx(No* prox);
};

template <class T>
T No<T>::getItem() {
        return item;
    }

template <class T>
void No<T>::setItem(T item) {
        this->item = item;
    }

template <class T>
No<T>* No<T>::getProx() {
        return prox;
    }

template <class T>
void No<T>::setProx(No* prox) {
        this->prox = prox;
    }


template <class T>
class Fila {

private:

    No<T> *tras, *frente;
    int TAM = 0;

public:
    Fila (){
      frente = new No<T> ();
      frente->setProx(NULL);
      tras = frente;
    }
    No<T> getFrente();
    void InsereItem (T item);
    void Imprime_Fila();
    void Remove_Item();
};
template <class T>
No<T> Fila<T>::getFrente(){
    return *frente;
}
template <class T>
void Fila<T>::InsereItem (T item){
   tras->setProx(new No<T>());
   tras = tras->getProx();
   tras->setItem(item);
   tras->setProx(NULL);
   TAM++;
}

template <class T>
void Fila<T>::Imprime_Fila(){
   No<T>* p = frente->getProx();
   while (p != NULL){
    p->getItem().Imprime();
    p = p->getProx();
   }
}

template <class T>
void Fila<T>::Remove_Item(){
    No<T>* aux = frente;
    frente = frente->getProx();
    delete aux;
}


//-------------------------------------------------------------------------------------------------


template <class T>
class  Fila_de_Prioridade {
private:

    Fila<T> fila;
    int total=0;
public:

    FilaDP (){}
    void InsereItem (T item);
    void Remove_Item();
    void Ordenar_FilaDP();
    void Imprime_FilaDP();

};

template <class T>
void Fila_de_Prioridade<T>::InsereItem (T item){
    total++;
   fila.InsereItem(item);
}

template <class T>
void Fila_de_Prioridade<T>::Imprime_FilaDP(){
    fila.Imprime_Fila();
}

template <class T>
void Fila_de_Prioridade<T>::Remove_Item(){
    total--;
    fila.Remove_Item();
}

template <class T>
void Fila_de_Prioridade<T>::Ordenar_FilaDP(){
    No<T>* p = fila.getFrente().getProx();
    int v[total],i=0;
    while (p != NULL){
        v[i++]=p->getItem().getChave();
        p = p->getProx();
    }
    for(int j=0;j<total;j++){
        fila.Remove_Item();
    }

    heapSort<int> test;
    test.heapsort(v, total);

    for(int j=0;j<total;j++){
        Vetor x(v[j]);
        fila.InsereItem(x);
    }
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
void Grafo<T>::print(){
    for(int i = 1;i < ordem+1;i++){
        cout << "v[" << i << "] = ";
        adj[i].print();
    }
}
//-------------------------------------------------------------------------------------------------


int main (){
 Fila_de_Prioridade< Vetor > fila;


    Vetor a(1);
    Vetor b(23);
    Vetor c(3);
    Vetor d(4);
    Vetor e(5);


    fila.InsereItem(a);
    fila.InsereItem(b);
    fila.InsereItem(c);
    fila.InsereItem(d);
    fila.InsereItem(e);
    fila.Imprime_FilaDP();
    fila.Ordenar_FilaDP();
    cout<<endl;
    fila.Imprime_FilaDP();


    Grafo<int> g(8);

    cout<<endl<<endl;

    g.insereAresta(1, 2);
    g.insereAresta(2, 3);
    g.insereAresta(3, 4);
    g.insereAresta(4, 5);
    g.insereAresta(5, 1);
    g.insereAresta(5, 2);
    g.insereAresta(2, 6);
    g.insereAresta(2, 7);
    g.insereAresta(2, 8);
    g.print();

    return 0;

}
