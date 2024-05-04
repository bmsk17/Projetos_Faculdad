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


template<typename TIPO>
class No {
private:
    TIPO item;
    No *prox;
public:
    No() {} // construtor
    TIPO getItem();
    void setItem(TIPO item);
    No* getProx();
    void setProx(No* prox);
};

template<typename TIPO>
TIPO No<TIPO>::getItem() {
        return item;
    }

template<typename TIPO>
void No<TIPO>::setItem(TIPO item) {
        this->item = item;
    }

template<typename TIPO>
No<TIPO>* No<TIPO>::getProx() {
        return prox;
    }

template<typename TIPO>
void No<TIPO>::setProx(No* prox) {
        this->prox = prox;
    }

//*****************************************************************************

template<typename NO,typename COISA>
class Pilha {
private:
    NO *fundo, *topo;

public:
    Pilha(); // construtor
    void empilha(COISA item);
    bool vazia();
    void desempilha(COISA item);
    void mostra();
};


template<typename NO,typename COISA>
Pilha<NO,COISA>::Pilha() {
    fundo = new NO(); // nó cabeça
    topo = fundo;
}

template<typename NO,typename COISA>
void Pilha<NO,COISA>::empilha(COISA item) {
    NO *aux = new NO();
    topo->setItem(item);
    aux->setProx(topo);
    topo = aux;
}

template<typename NO,typename COISA>
bool Pilha<NO,COISA>::vazia() {
    return topo == fundo;
}

template<typename NO,typename COISA>
void Pilha<NO,COISA>::desempilha(COISA item) {
    if (vazia()) {
        cout << "pilha vazia: impossível remover item\n";
    }
    else {
        NO *aux = topo;
        topo = topo->getProx();
        item = topo->getItem();
        delete aux;
    }
}

template<typename NO,typename COISA>
void Pilha<NO,COISA>::mostra() {
    cout << "Pilha: topo-> ";
    for (NO *nav = topo->getProx(); nav != NULL;
                                   nav = nav->getProx()) {
        nav->getItem().mostra();
    }
    cout << "<- fundo\n";
}

//*****************************************************************************

int main(){
    Pilha< No < Item >, Item > pil;
    Item a(1);
    Item b(2);
    Item c(3);
    Item d(4);
    Item e(5);
    pil.empilha(a);
    pil.empilha(b);
    pil.empilha(c);
    pil.empilha(d);
    pil.empilha(e);
    pil.mostra();







}



