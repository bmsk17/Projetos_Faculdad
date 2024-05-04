#include <iostream>
using namespace std;

class Item {
private:
    int valor;

public:
    Item() { }
    Item(int valor): valor(valor) { }
    int getValor();
    void setValor(int valor);
    void mostra();
};

int Item::getValor() {
        return valor;
    }

void Item::setValor(int valor) {
        this->valor = valor;
    }

void Item::mostra() {
        cout << valor << " ";
    }

//*****************************************************************************

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
    void InsereItem (T item);
    void Imprime_Fila();
    void Remove_Item();
};

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
    p->getItem().mostra();
    p = p->getProx();
   }
}

template <class T>
void Fila<T>::Remove_Item(){
    No<T>* aux = frente;
    frente = frente->getProx();
    delete aux;
}

int main (){
 Fila< Item > fila;
    Item a(1);
    Item b(23);
    Item c(3);
    Item d(4);
    Item e(5);
    fila.InsereItem(a);
    fila.InsereItem(b);
    fila.InsereItem(c);
    fila.InsereItem(d);
    fila.InsereItem(e);
    fila.Imprime_Fila();
    cout <<endl<<"///////// "<<endl;
    fila.Remove_Item();
    fila.Imprime_Fila();

return 0;

}
