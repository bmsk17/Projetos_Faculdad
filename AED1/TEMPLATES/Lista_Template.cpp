#include <iostream>
using namespace std;

class Capturado {

private:

    string Nome;
    string Raca;
    unsigned long long int Forca;

public:

    Capturado (){}
    Capturado (string Nome,string Raca, unsigned long long int Forca){
         this->Nome = Nome;
         this->Raca = Raca;
         this->Forca = Forca;
    }

    void setNome(string Nome);
    string getNome();
    void setRaca (string Raca);
    string getRaca();
    void setForca(unsigned long long int Forca);
    unsigned long long int getForca();
    void ImprimeCapturado();
};



void Capturado::setNome(string Nome){
      this->Nome = Nome;
}

string Capturado::getNome(){
     return this->Nome;
}

void Capturado::setRaca(string Raca){
     this->Raca = Raca;
}

string Capturado::getRaca(){
    return this->Raca;
}

void Capturado::setForca(unsigned long long int Forca){
   this->Forca = Forca;
}

unsigned long long int Capturado::getForca(){
return this->Forca;
}

void Capturado::ImprimeCapturado(){
  cout <<"Nome: "<<Nome <<" " << "Raca: "<<Raca << " "<<"Forca: "<<Forca<<"\n";
}


//-------------------------------------------------------------------------------------------------

template<typename TIPO>
class NoGenerico {
private:
    TIPO item;
    NoGenerico *prox;
public:
    NoGenerico() {} // construtor
    TIPO getItem();
    void setItem(TIPO item);
    NoGenerico* getProx();
    void setProx(NoGenerico* prox);
};

template<typename TIPO>
TIPO NoGenerico<TIPO>::getItem() {
        return item;
    }

template<typename TIPO>
void NoGenerico<TIPO>::setItem(TIPO item) {
        this->item = item;
    }

template<typename TIPO>
NoGenerico<TIPO>* NoGenerico<TIPO>::getProx() {
        return prox;
    }

template<typename TIPO>
void NoGenerico<TIPO>::setProx(NoGenerico* prox) {
        this->prox = prox;
    }

//*****************************************************************************
template<typename TIPO>
class LSE {
private:
    NoGenerico<TIPO> *prim, *ult;
public:
    LSE () {
        prim = new NoGenerico<TIPO>();
        prim->setProx(NULL);
        ult = prim;
    }

    void insere(TIPO item);
    NoGenerico<TIPO>* pred(NoGenerico<TIPO>*);
    bool vazia();
    NoGenerico<TIPO>* busca(TIPO);
    void remove(NoGenerico<TIPO>*, TIPO item);
    NoGenerico<TIPO>* getPrim();
    void print();
};

template<typename TIPO>
NoGenerico<TIPO>* LSE<TIPO>::getPrim(){
   return prim;
}

template<typename TIPO>
void LSE<TIPO>::insere(TIPO item) {
    ult->setProx(new NoGenerico<TIPO>());
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
}


template<typename TIPO>
bool LSE<TIPO>::vazia() {
    return prim == ult;
}


template<typename TIPO>
NoGenerico<TIPO>* LSE<TIPO>::pred(NoGenerico<TIPO>* r) {
    NoGenerico<TIPO>* p = prim->getProx();
    while (p->getProx() != r) {
        p = p->getProx();
    }
    return p;
}

template<typename TIPO>
void LSE<TIPO>::remove(NoGenerico<TIPO>* r, TIPO item){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        item = r->getItem();
        NoGenerico<TIPO>* p = pred(r);
        p->setProx(r->getProx());
        if (p->getProx() == NULL) ult = p;
        delete r;
    }
}



template<typename TIPO>
NoGenerico<TIPO>* LSE<TIPO>::busca(TIPO item) {
    NoGenerico<TIPO>* p = prim->getProx();
    while (p != NULL && p->item.getNome() != item.getNome()) {
        p = p->getProx();
    }
    return p;
}

template<typename TIPO>
void LSE<TIPO>::print() {
    NoGenerico<TIPO>* p = prim->getProx();
    while (p != NULL) {
        p->getItem().ImprimeCapturado();
        p = p->getProx();
        cout << endl;
    }
}


//*****************************************************************************

int main(){
    LSE<Capturado> lista;
    Capturado a("Bernardo","humano",2);
    Capturado b("amanda","humano",2);
    Capturado c("deubson","humano",2);
    Capturado d("arley","humano",2);
    Capturado e("vitor","humano",2);
    lista.insere(a);
    lista.insere(b);
    lista.insere(c);
    lista.insere(d);
    lista.insere(e);
    NoGenerico<Capturado>* s =lista.getPrim()->getProx();
    Capturado cs=s->getItem();
    lista.remove(s,cs);
    lista.print();

}
