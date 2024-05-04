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



//-------------------------------------------------------------------------------

template <class T>
class Fila{

 private:

    No<T> *tras, *frente;
    int tamanho_heap;

public:

    Fila (){
      tamanho_heap = 0;
      frente = new No<T>();
      frente->setNULL();
      tras = frente;

    }

    void Enfileira (T item);
    T Desinfileira();
    No<T>* getFrente();
    void ImprimeFila();
    bool vazia();
    int esquerda(int i);
    int direita(int i);
    void heapify_up(int v);
    void heapify_down(int v);
    int pai(int i);
    double busca(int i);
    void TrocarValor(int i,double valor);


};

template<class T>
No<T>* Fila<T>::getFrente(){
    return frente;
}

template<class T>
double Fila<T>::busca(int i){

    No<T> *p = getFrente()->getProx();

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
void Fila<T>::TrocarValor(int i,double valor){

    No<T> *p = getFrente()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         p->setItem(valor);
         cout<<endl<<"++++++++++++trocou++++++++++"<<endl;
         break;
      }
      cont++;
      p = p->getProx();
    }
}


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
   tamanho_heap++;
   heapify_up(tamanho_heap);


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
    tamanho_heap--;
    return p;
    }


}

template <class T>
void Fila<T>::ImprimeFila(){

   No<T>* p = frente->getProx();

   while (p != NULL){


    cout<< endl<<" "<<p->getItem(); //mudar
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
void Fila<T>::heapify_up(int v){


    if(v == 1) return;

    int p = pai(v);

    double lv = busca(v);
    double lp = busca(p);
    cout<<"POsicao v : "<<v<<"  -- Valor de v : "<<lv<<endl;
    cout<<"POsicao p : "<<p<<"  -- Valor de p : "<<lp<<endl;

    if(lv > lp){
        cout<<endl<<"TROCU--------------"<<endl;
        TrocarValor(v,lp);
        TrocarValor(p,lv);
    cout<<"POsicao v : "<<v<<"  -- Valor de v : "<<lv<<endl;
    cout<<"POsicao p : "<<p<<"  -- Valor de p : "<<lp<<endl;
        heapify_up(p);
    }
   // ImprimeFila();
    cout<<endl;
}

template <class T>
void Fila<T>::heapify_down(int v){

    int d = direita(v);
    int e = esquerda(v);

    int maior = v;

    double dd = busca(d);
    double ee = busca(e);

    double mm = busca(maior);

    if(d <= tamanho_heap && dd > mm) maior = d;
    if(e <= tamanho_heap && ee > mm) maior = e;

    if(maior != v){
        double hv = busca(v);
        double ma = busca(maior);
        swap(hv, ma);

        heapify_down(maior);
    }
}



//-------------------------------------------------------------------------------

int main(){
    Fila<int> fila;
    int n,vert1;

    cin>>n;

    for(int i = 1;i <= n;i++){

        cin>>vert1;
        fila.Enfileira(vert1);
    }


    fila.ImprimeFila();

    return 0;
}




