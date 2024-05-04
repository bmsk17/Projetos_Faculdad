#include <iostream>

using namespace std;

class Capturado {

private:

    string Nome;              //N�o coloquei typedef s� porque pra mim fica mais f�cil de escrever a fun��o depois;
    string Raca;
    int Forca,i,j;

public:

    Capturado (){}
    Capturado (string Nome,string Raca,int i,int j, int Forca){   //Padrao da forma que ser� dado na entrada;
         this->Nome = Nome;
         this->Raca = Raca;
         this->i = i;
         this->j = j;
         this->Forca = Forca;
    }

    void setNome(string Nome);
    string getNome();
    void setRaca (string Raca);
    string getRaca();
    void setI(int i);
    int getI();
    void setJ(int j);
    int getJ();
    void setForca(int Forca);
    int getForca();
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

void Capturado::setI(int i){
     this->i = i;

}

int Capturado::getI(){

   return this->i;

}

void Capturado::setJ(int j){
     this->i = i;

}

int Capturado::getJ(){

   return this->j;

}

void Capturado::setForca(int Forca){

   this->Forca = Forca;
}

int Capturado::getForca(){
return this->Forca;
}


void Capturado::ImprimeCapturado(){

  cout <<"Nome: "<<Nome <<" " << "Raca: "<<Raca << " "<<"Forca: "<<Forca << " "<<"Posicao: "<<i<<" "<<j<<"\n";

}

class Node {

public:

    Capturado capturado;
    Node* prox;

    Node(){

    prox = NULL;
    }

    Node (Capturado capturado){

     this->capturado = capturado;
     prox = NULL;
    }

};

class Fila {

private:

    Node *tras, *frente;
    int TAM;

public:

    Fila (){

      frente = new Node ();
      frente->prox = NULL;
      tras = frente;
      TAM=0;

    }

    void InsereCapturado (Capturado capturado);
    void Imprime_Fila();
    void Remove_Capturado();
};

void Fila::InsereCapturado (Capturado capturado){

   tras->prox = new Node();
   tras = tras->prox;
   tras->capturado = capturado;
   tras->prox = NULL;
   TAM++;
}

void Fila::Imprime_Fila(){

   Node* p = frente->prox;

   while (p != NULL){

    p->capturado.ImprimeCapturado();
    p = p->prox;

   }
}

void Fila::Remove_Capturado(){

    Node* aux = frente;

    frente = frente->prox;

    delete aux;

}

class Soldado {

private:

    string Nome;              //N�o coloquei typedef s� porque pra mim fica mais f�cil de escrever a fun��o depois;
    string Raca;
    int Forca,i,j;
    Fila capturado;

public:

    Soldado (){}
    Soldado (string Nome,string Raca,int i,int j, int Forca,Fila capturado){   //Padrao da forma que ser� dado na entrada;
         this->Nome = Nome;
         this->Raca = Raca;
         this->i = i;
         this->j = j;
         this->Forca = Forca;
         this->capturado = capturado;
    }

    void setNome(string Nome);
    string getNome();
    void setRaca (string Raca);
    string getRaca();
    void setI(int i);
    int getI();
    void setJ(int j);
    int getJ();
    void setForca(int Forca);
    int getForca();
    void setCapturado(Fila capturado);
    Fila getCapturado();
    void ImprimeSoldado();
};


void Soldado::setNome(string Nome){
      this->Nome = Nome;
}

string Soldado::getNome(){
     return this->Nome;
}

void Soldado::setRaca(string Raca){
     this->Raca = Raca;
}

string Soldado::getRaca(){
    return this->Raca;
}

void Soldado::setI(int i){
     this->i = i;

}

int Soldado::getI(){

   return this->i;

}

void Soldado::setJ(int j){
     this->i = i;

}

int Soldado::getJ(){

   return this->j;

}

void Soldado::setForca(int Forca){

   this->Forca = Forca;
}

int Soldado::getForca(){
return this->Forca;
}
void Soldado::setCapturado(Fila capturado){

   this->capturado = capturado;
}

Fila Soldado::getCapturado(){
return this->capturado;
}


void Soldado::ImprimeSoldado(){

  cout <<"Nome: "<<Nome <<" " << "Raca: "<<Raca << " "<<"Forca: "<<Forca << " "<<"Posicao: "<<i<<" "<<j<<"\n";

}

class No_PilhaTropa {
private:
    Soldado soldado;
    No_PilhaTropa* prox;

public:
    No_PilhaTropa() {} // construtor

    Soldado getSoldado() {
        return soldado;
    }

    void setSoldado(Soldado soldado) {
        this->soldado = soldado;
    }

    No_PilhaTropa* getProx() {
        return prox;
    }

    void setProx(No_PilhaTropa* prox) {
        this->prox = prox;
    }
};


class Pilha_Tropa {
private:
    No_PilhaTropa *fundo, *topo;

public:
    Pilha_Tropa(); // construtor
    void empilha(Soldado soldado);
    bool vazia();
    void desempilha(Soldado& soldado);
    void mostra();
};

Pilha_Tropa::Pilha_Tropa() {
    fundo = new No_PilhaTropa(); // nó cabeça
    topo = fundo;
}

void Pilha_Tropa::empilha(Soldado soldado) {
    No_PilhaTropa *aux = new No_PilhaTropa();
    topo->setSoldado(soldado);
    aux->setProx(topo);
    topo = aux;
}

bool Pilha_Tropa::vazia() {
    return topo == fundo;
}

void Pilha_Tropa::desempilha(Soldado& soldado) {
    if (vazia()) {
        cout << "pilha vazia: impossível remover item\n";
    }
    else {
        No_PilhaTropa *aux = topo;
        topo = topo->getProx();
        soldado = topo->getSoldado();
        delete aux;
    }
}

void Pilha_Tropa::mostra() {
    cout << "Pilha: topo-> ";
    for (No_PilhaTropa *nav = topo->getProx(); nav != nullptr;
                                   nav = nav->getProx()) {
        nav->getSoldado().ImprimeSoldado();
        cout<<" Capturados de "<<nav->getSoldado().getNome()<<" : "<<endl;
        nav->getSoldado().getCapturado().Imprime_Fila();
    }
    cout << "<- fundo\n";
}
// IMPLEMENTANDO A CLASSE NO ENCAPSULADA

class No {

private:

    Pilha_Tropa Tropa;
    No* prox;

public:

    No (){            //CONSTRUTOR PADRAO

    prox = NULL;

    }

    No (Pilha_Tropa Tropa){

       this->Tropa = Tropa;
       prox = NULL;
    }

    No* getProx (){         //RETORNA PONTEIRO PARA O PROXIMO NO
      return this->prox;
    }

    void setNULL (){        //ANULA O PONTEIRO PARA O NO SEGUINTE AO ULTIMO JA QUE ELE NAO EXISTE

      this->prox = NULL;
    }

    void setTropa (Pilha_Tropa Tropa){   // INSERE O SOLDADO NA VARIAVEL SOLDADO DESSA CLASSE

      this->Tropa = Tropa;
    }

    Pilha_Tropa getTropa (){      //RETORNA O SOLDADO QUE ESTA NESSA CLASSE

      return this->Tropa;

    }

   void setNo (){            //CRIA UM NOVO NO VISTO QUE EST� ENCAPSULADO E � PRECISO FAZER "MANUALMENTE"

     this->prox = new No ();

    }

};

//IMPLEMENTANDO A CLASSE LISTA

class Lista_Tropa {

private:

    No *prim, *ult;
    int TAM;             // UTIL PARA INFORMAR O TAMANHO ATUAL DA LISTA

public:

    Lista_Tropa (){
      TAM=0;
      prim = new No ();
      prim->setNULL();
      ult = prim;
    }


     void Insere (Pilha_Tropa Tropa);
     void Imprime_Lista();
};

void Lista_Tropa::Insere(Pilha_Tropa Tropa){

    ult->setNo();             //CRIANDO NOVO NO
    ult = ult->getProx();
    ult->setNULL();
    ult->setTropa(Tropa);
    TAM++;

}

void Lista_Tropa::Imprime_Lista(){

  No* p = prim->getProx();   //PEGA O PRIMEIRO NO DEPOIS DO CABE�A

  while (p != NULL){

    p->getTropa().mostra();
    p = p->getProx();

  }
}

int main(){

  Fila f;

  Capturado x1 ("A1","bernardo",1,2,40);
  Capturado x2 ("B1","kanekiyo",3,6,20);
  Capturado x3 ("C3","amanda",4,1,10);
  Capturado x4 ("D5","deubson",6,3,4);

  f.InsereCapturado(x1);
  f.InsereCapturado(x2);
  f.InsereCapturado(x3);
  f.InsereCapturado(x4);

    Pilha_Tropa p;

  Soldado a ("A1","AZURI",1,2,40,f);
  Soldado b ("B1","IAMTECO",3,6,20,f);
  Soldado c ("C3","AZURI",4,1,10,f);
  Soldado d ("D5","UMASHI",6,3,4,f);

  p.empilha(a);
  p.empilha(b);
  p.empilha(c);
  p.empilha(d);

  p.mostra();

//IMPRIMINDO PARA TESTAR SE FOI INSERIDO



}
