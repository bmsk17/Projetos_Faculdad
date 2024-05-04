#include <iostream>
#include <limits>
#include <vector>

using namespace std;



template <class T>
class No {

private:

    T item;
    No<T>* prox;

public:


    No<T>(){

      this->prox = NULL;
    }

    No<T> (T item){

       this->item = item;
       prox = NULL;

    }

    T getItem();
    No<T>* getProx();
    void setItem(T item);
    void setProx (No<T>* prox);
    void setNULL();
    void setNovoNo();



};

template <class T>
T No<T>::getItem(){

  return this->item;
}

template <class T>
No<T>* No<T>::getProx(){
   return prox;
}

template <class T>
void No<T>::setItem(T item){
   this->item = item;
}

template <class T>
void No<T>::setProx(No<T>* prox){
   this->prox = prox;
}

template <class T>
void No<T>::setNULL (){
  this->prox = NULL;
}

template <class T>
void No<T>::setNovoNo (){
 this->prox = new No<T>();
}



template<class T>
class Lista{
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
    double busca(int i);
    void insere(T item);
    void remove(No<T>* r);
    void print();
    void TrocarValor(int i,double valor);
    int getTAM();
    bool vazia();
    No<T>* pred(No<T>*);
};

template<typename T>
bool Lista<T>::vazia() {
    return prim == ult;
}


template<typename T>
No<T>* Lista<T>::pred(No<T>* r) {
    No<T>* p = prim->getProx();
    while (p->getProx() != r) {
        p = p->getProx();
    }
    return p;
}

template<typename T>
void Lista<T>::remove(No<T>* r){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        No<T>* p = pred(r);
        p->setProx(r->getProx());
        if (p->getProx() == NULL) ult = p;
        delete r;
    }
}

template <class T>
int Lista<T>::getTAM(){
    return TAM;
}

template<class T>
No<T>* Lista<T>::getPrim(){
    return prim;
}

template<class T>
double Lista<T>::busca(int i){

    No<T> *p = getPrim()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         achou = p->getItem();
         break;
      }
      cont++;
      p = p->getProx();
    }

    return achou;
}

template<class T>
void Lista<T>::TrocarValor(int i,double valor){

    No<T> *p = getPrim()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         p->setItem(valor);
         break;
      }
      cont++;
      p = p->getProx();
    }
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

//-------------------------------------------------------------------------------template <class T>

//-------------------------------------------------------------------------------

template <class T>
class Fila{

 private:

    No<T> *tras, *frente;
    int TAM;

public:

    Fila (){
      TAM = 0;
      frente = new No<T>();
      frente->setNULL();
      tras = frente;

    }

    void Enfileira (T item);
    T Desinfileira();
    void ImprimeFila();
    bool vazia();
    int pai(int i);
    int esquerda(int i);
    int direita(int i);
    void heapify_up(int v);
    void heapify_down(int v);
    void insere(int valor);
    void deleta(int posicao);


};

template <class T>
bool Fila<T>::vazia(){
  return tras == frente;
}

template <class T>
void Fila<T>::Enfileira(T item){

   tras->setNovoNo();
   tras = tras->getProx();
   tras->setItem(item);
   tras->setNULL();
   TAM++;

}

template <class T>
T Fila<T>::Desinfileira(){


    No<T>* aux = frente;
    T p;

    if (frente == tras){

        cout <<"Fila Vazia \n";
    }else{
    p = frente->getProx()->getItem();
    frente = frente->getProx();
    delete aux;
    return p;
    }


}

template <class T>
void Fila<T>::ImprimeFila(){

   No<T>* p = frente->getProx();

   while (p != NULL){


    p->getItem().imprime(); //mudar
    p = p->getProx();

   }
}

template <class T>
int Fila<T>::pai(int i){
    return i/2;
}

template <class T>
int Fila<T>::esquerda(int i){
    return 2*i;
}

template <class T>
int Fila<T>::direita(int i){
    return 2*i+1;
}

template <class T>
bool Fila<T>::vazia(){
  return heap.vazia();
}

template <class T>
void Fila<T>::heapify_up(int v){
    Lista<T> aux;
    aux=heap;
    if(v == 1) return;

    int p = pai(v);

    double lv = aux.busca(v);
    double lp = aux.busca(p);
    cout<<"POsicao v : "<<v<<"  -- Valor de v : "<<lv<<endl;
    cout<<"POsicao p : "<<p<<"  -- Valor de p : "<<lp<<endl;

    if(lv > lp){
        cout<<endl<<"TROCU--------------"<<endl;
        aux.TrocarValor(v,lp);
        aux.TrocarValor(p,lv);

    cout<<"POsicao v : "<<v<<"  -- Valor de v : "<<lv<<endl;
    cout<<"POsicao p : "<<p<<"  -- Valor de p : "<<lp<<endl;
        heapify_up(p);
    }
         cout<<endl<<"Lista  aux Atualizando : ";
        aux.print();
        cout<<endl;
        heap=aux;
        cout<<endl<<"Lista Atualizando : ";
        heap.print();
        cout<<endl;
}

template <class T>
void Fila<T>::heapify_down(int v){

    int d = direita(v);
    int e = esquerda(v);

    int maior = v;

    double dd = heap.busca(d);
    double ee = heap.busca(e);

    double mm = heap.busca(maior);

    if(d <= tamanho_heap && dd > mm) maior = d;
    if(e <= tamanho_heap && ee > mm) maior = e;

    if(maior != v){
        double hv = heap.busca(v);
        double ma = heap.busca(maior);
        swap(hv, ma);

        heapify_down(maior);
    }
}

template <class T>
void Fila<T>::insere(int valor){
    tamanho_heap=tamanho_heap+1;
    heap.insere(valor);
    heapify_up(tamanho_heap);
}

template <class T>
void Fila<T>::deleta(int posicao){

    double lp = heap.busca(posicao);
    double lth = heap.busca(tamanho_heap);

    swap(lp, lth);
    tamanho_heap--;

    heapify_down(posicao);
}


//-------------------------------------------------------------------------------

int main(){
    FilaPrioridades<int> fila;
    int n,vert1;

    cin>>n;

    for(int i = 1;i <= n;i++){

        cin>>vert1;
        fila.insere(vert1);
    }


    fila.ImprimeFila();

    return 0;
}




