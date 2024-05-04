#include <iostream>
#include <locale>
#include <math.h>

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



class Node {

private:

    Capturado capturado;
    Node* prox;

public:

    Node(){
    prox = NULL;
    }

    Node (Capturado capturado){
     this->capturado = capturado;
     prox = NULL;
    }

    void setNode();
    Node* getProx ();
    void setNo();
    void setCapturado(Capturado capturado);
    Capturado getCapturado();

};


void Node::setNode(){
  this->prox = NULL;
}

Node* Node::getProx (){
  return this->prox;
}

void Node::setNo(){
  this->prox = new Node();
}

void Node::setCapturado(Capturado capturado){
  this->capturado = capturado;
}

Capturado Node::getCapturado(){
   return this->capturado;
}




class Fila {

private:

    Node *tras, *frente;
    int TAM;
    unsigned long long int forca_total;

public:

    Fila (){

      frente = new Node ();
      frente->setNode();
      tras = frente;
      TAM=0;
      forca_total=0;

    }
    Node* getFrente();
    void InsereCapturado (Capturado capturado);
    void Imprime_Fila();
    void Remove_Capturado();
    int getTamanho();
    unsigned long long int  Forca_dos_Capturados();
};



int Fila::getTamanho(){
    return this->TAM;
}

Node* Fila::getFrente(){
    return this->frente;
}

void Fila::InsereCapturado (Capturado capturado){

   tras->setNo();
   tras = tras->getProx();
   tras->setCapturado(capturado);
   tras->setNode();
   TAM++;
   forca_total=forca_total + capturado.getForca();
}

void Fila::Imprime_Fila(){
   Node* p = frente->getProx();
   while (p != NULL){
    p->getCapturado().ImprimeCapturado();
    p = p->getProx();
   }
}

void Fila::Remove_Capturado(){
    Node* aux = frente;
    frente = frente->getProx();
    TAM--;
    delete aux;
}

unsigned long long int Fila::Forca_dos_Capturados(){
    return forca_total;
}



class Soldado {

private:

    string Nome;
    string Raca;
    unsigned long long int Forca;
    int i,j;
    Fila capturado;

public:

    Soldado (){}
    Soldado (string Nome,string Raca,int i,int j,unsigned long long int Forca,Fila capturado){
         this->Nome = Nome;
         this->Raca = Raca;
         this->i = i;
         this->j = j;
         this->Forca = Forca;
         this->capturado = capturado;
    }

      Soldado (string Nome,string Raca,unsigned long long int Forca){

         this->Nome = Nome;
         this->Raca = Raca;
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
    void setForca(unsigned long long int Forca);
    unsigned long long int getForca();
    void setCapturado(Fila capturado);
    Fila getCapturado();
    void ImprimeSoldado();
    unsigned long long int Forca_Conjunta_Capturados();
    Fila Soldado_Remove_Capturado();
    Fila Soldado_Insere_Capturado(Capturado cap);
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
     this->j = j;
}

int Soldado::getJ(){
   return this->j;
}

void Soldado::setForca(unsigned long long int Forca){
   this->Forca = Forca;
}

unsigned long long int Soldado::getForca(){
return this->Forca;
}

void Soldado::setCapturado(Fila capturado){
   this->capturado = capturado;
}

Fila Soldado::getCapturado(){
return this->capturado;
}

unsigned long long int Soldado::Forca_Conjunta_Capturados(){
  unsigned long long int TOTAL = 0;
  TOTAL = getForca()+getCapturado().Forca_dos_Capturados();
  return TOTAL;
}
void Soldado::ImprimeSoldado(){
  cout <<"Nome: "<<getNome() <<" " << "Raca: "<<getRaca() << " "<<"Forca: "<<Forca_Conjunta_Capturados() << " "<<"Posicao: "<<getI()<<" "<<getJ()<<endl;
}
Fila Soldado::Soldado_Remove_Capturado(){
  Fila f =getCapturado();
  f.Remove_Capturado();
  return f;
}
Fila Soldado::Soldado_Insere_Capturado(Capturado cap){
  Fila f =getCapturado();
  f.InsereCapturado(cap);
  return f;
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

    void setSoldado(Soldado soldado);
    No_PilhaTropa* getProx();
    void setProx(No_PilhaTropa* prox);
};


void No_PilhaTropa::setSoldado(Soldado soldado) {
  this->soldado = soldado;
}

No_PilhaTropa* No_PilhaTropa::getProx() {
  return prox;
}

void No_PilhaTropa::setProx(No_PilhaTropa* prox) {
  this->prox = prox;
}



class Pilha_Tropa {
private:
    No_PilhaTropa *fundo, *topo;
    int tamanho;

public:
    Pilha_Tropa();
    void empilha(Soldado soldado);
    bool vazia();
    void desempilha(Soldado soldado);
    No_PilhaTropa* getTopo();
    unsigned long long int Forca_Conjunta_Soldados();
    void setTamanho(int Tamanho);
    int getTamanho();
    void Trocar_Posicao(int pfx,int pfy);
    void mostra();
 };


void Pilha_Tropa::setTamanho(int Tamanho){
      this->tamanho = Tamanho;
}

int Pilha_Tropa::getTamanho(){
     return this->tamanho;
}

No_PilhaTropa* Pilha_Tropa::getTopo(){
    return this->topo;
}

Pilha_Tropa::Pilha_Tropa() {
    fundo = new No_PilhaTropa();
    topo = fundo;
    tamanho=0;
}

void Pilha_Tropa::empilha(Soldado soldado) {
    No_PilhaTropa *aux = new No_PilhaTropa();
    topo->setSoldado(soldado);
    aux->setProx(topo);
    topo = aux;
    tamanho++;
}

bool Pilha_Tropa::vazia() {
    return topo == fundo;
}

void Pilha_Tropa::desempilha(Soldado soldado) {
    if (vazia()) {
        cout << "pilha vazia: impossível remover item\n";
    }
    else {
        No_PilhaTropa *aux = topo;
        topo = topo->getProx();
        soldado = topo->getSoldado();
        tamanho--;
        delete aux;
    }
}

void Pilha_Tropa::mostra() {
    for (No_PilhaTropa *nav = topo->getProx(); nav != NULL;nav = nav->getProx()) {
        std::cout << '\n';
        nav->getSoldado().ImprimeSoldado();
        cout<<" Capturados de "<<nav->getSoldado().getNome()<<" : "<<endl;
        nav->getSoldado().getCapturado().Imprime_Fila();
    }
}
unsigned long long int Pilha_Tropa::Forca_Conjunta_Soldados(){
    unsigned long long TOTAL=0;
    for (No_PilhaTropa *nav = topo->getProx(); nav != NULL;nav = nav->getProx()) {
        TOTAL = TOTAL + nav->getSoldado().Forca_Conjunta_Capturados();
    }
    return TOTAL;
}
void Pilha_Tropa::Trocar_Posicao(int pfx,int pfy){
  for (No_PilhaTropa *nav = topo->getProx(); nav != NULL;nav = nav->getProx()) {
      Soldado s = nav->getSoldado();
      s.setI(pfx);
      s.setJ(pfy);
      nav->setSoldado(s);
  }
}





class No {

private:

    Pilha_Tropa Tropa;
    No* prox;

public:

    No (){
    prox = NULL;
    }

    No (Pilha_Tropa Tropa){
       this->Tropa = Tropa;
       prox = NULL;
    }

    No* getProx ();
    void setNULL ();
    void setTropa (Pilha_Tropa Tropa);
    Pilha_Tropa getTropa ();
    void setNo ();
    void setProx(No* prox);
};



No* No::getProx (){
  return this->prox;
}

void No::setProx (No* prox){
  this->prox = prox;
}

void No::setNULL (){
  this->prox = NULL;
}

void No::setTropa (Pilha_Tropa Tropa){
  this->Tropa = Tropa;
}

Pilha_Tropa No::getTropa (){
  return this->Tropa;
}

void No::setNo (){
 this->prox = new No ();
}



class Lista_Tropa {

private:

    No *prim, *ult;
    int TAM,Tam_A,Tam_U,Tam_I;
    No* predecessor(No*);

public:

    Lista_Tropa (){
      TAM=0;
      prim = new No ();
      prim->setNULL();
      ult = prim;
      Tam_A=0;
      Tam_U=0;
      Tam_I=0;

    }

     No* getPrim();
     No* getUlt();
     int getTam();
     int getTam_A();
     void setTam_A(int tam);
     int getTam_U();
     void setTam_U(int tam);
     int getTam_I();
     void setTam_I(int tam);
     void Insere (Pilha_Tropa Tropa);
     void Imprime_Lista();
     void remove(No *p,Pilha_Tropa Tropa);
     Pilha_Tropa verificar_posicao(Soldado soldado);
     void Eliminacao(string raca);
     int Tamanho_Azuri();
     int Tamanho_Ianteco();
     int Tamanho_Umashi();

};

int Lista_Tropa::getTam_A(){
  return this->Tam_A;
}

void Lista_Tropa::setTam_U(int tam){
  this->Tam_A = tam;
}
int Lista_Tropa::getTam_U(){
  return this->Tam_U;
}

void Lista_Tropa::setTam_I(int tam){
  this->Tam_U = tam;
}
int Lista_Tropa::getTam_I(){
  return this->Tam_I;
}

void Lista_Tropa::setTam_A(int tam){
  this->Tam_A = tam;
}

int Lista_Tropa::getTam(){
     return this->TAM;
}
No* Lista_Tropa::getPrim(){
     return this->prim;
}
No* Lista_Tropa::getUlt(){
     return this->ult;
}
void Lista_Tropa::Insere(Pilha_Tropa Tropa){

    ult->setNo();
    ult = ult->getProx();
    ult->setNULL();
    ult->setTropa(Tropa);
    TAM++;

}

No* Lista_Tropa::predecessor(No *r) {
	No *p = prim;
	while (p->getProx() != r) {
		p = p->getProx();
	}
	return p;
}


void Lista_Tropa::remove(No *r, Pilha_Tropa Tropa) {
	if (TAM == 0 || r == NULL || r == prim) {
		cout << "Impossível remover!\n";
	}
	else{
		Tropa = r->getTropa();
		No* p = predecessor(r);
		p->setProx(r->getProx());
		if (p->getProx() == NULL) {
			ult = p;
		}
		delete r;
	}
}

void Lista_Tropa::Imprime_Lista(){

  No* p = prim->getProx();
  while (p != NULL){
    std::cout << "Pilha inicia,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,," << '\n';
    p->getTropa().mostra();
    p = p->getProx();
  }
}

Pilha_Tropa Lista_Tropa::verificar_posicao(Soldado soldado){
  No* p = prim->getProx();
  Pilha_Tropa nova;
  while(p!=NULL){
    Soldado s = p->getTropa().getTopo()->getProx()->getSoldado();
    Pilha_Tropa as =p->getTropa();
    if(s.getI() == soldado.getI() && s.getJ() == soldado.getJ()){
        Pilha_Tropa paux =p->getTropa();
        remove(p,paux);
        return as;
    }
    p = p->getProx();
  }
  return nova;
}

int Lista_Tropa::Tamanho_Azuri(){
No* p = prim->getProx();
  Pilha_Tropa nova = p->getTropa();
  int azuri=0;
  while (p != NULL){
    if(nova.getTopo()->getProx()->getSoldado().getRaca() == "AZURI"){
        azuri++;
    }
    p = p->getProx();
  }
  return azuri;
 }

int Lista_Tropa::Tamanho_Ianteco(){
No* p = prim->getProx();
  Pilha_Tropa nova = p->getTropa();
  int ianteco=0;
  while (p != NULL){
    if(nova.getTopo()->getProx()->getSoldado().getRaca() == "IANTECO"){
        ianteco++;
    }
    p = p->getProx();
  }
  return ianteco;
}

int Lista_Tropa::Tamanho_Umashi(){
No* p = prim->getProx();
  Pilha_Tropa nova = p->getTropa();
  int umashi=0;
  while (p != NULL){
    if(nova.getTopo()->getProx()->getSoldado().getRaca() == "UMASHI"){
        umashi++;
    }
    p = p->getProx();
  }
  return umashi;
}

void Lista_Tropa::Eliminacao(string raca){

  No* p = prim->getProx();
  Pilha_Tropa nova = p->getTropa();
  int umashi=0,azuri=0,ianteco=0;
  while (p != NULL){
    if(nova.getTopo()->getProx()->getSoldado().getRaca() == "UMASHI"){
        umashi++;
    }else if(nova.getTopo()->getProx()->getSoldado().getRaca() == "AZURI"){
        azuri++;
    }else if(nova.getTopo()->getProx()->getSoldado().getRaca() == "IANTECO"){
        ianteco++;
    }
    p = p->getProx();
  }
    if(umashi == 0 && raca=="UMASHI" ){
        cout<<"UMASHI foi eliminada"<<endl;
    }else if(azuri == 0 && raca=="AZURI"){
        cout<<"AZURI foi eliminada"<<endl;
    }else if(ianteco == 0 && raca=="IANTECO"){
        cout<<"IANTECO foi eliminada"<<endl;
     }

    if(umashi == 0 && azuri==0 && getTam_U()==0 && getTam_A()==0){
        cout<<"IANTECO tem supremacia sobre Tau!"<<endl;
    }else if(umashi == 0 && ianteco == 0 && getTam_U()==0 && getTam_I()==0){
        cout<<"AZURI tem supremacia sobre Tau!"<<endl;
    }else if(azuri == 0 && ianteco == 0 && getTam_I()==0 && getTam_A()==0){
        cout<<"UMASHI tem supremacia sobre Tau!"<<endl;
    }
}

class NoListaHash {
private:
    Soldado soldado;
    NoListaHash* prox;

public:

    NoListaHash (){
    prox = NULL;
    }

    NoListaHash (Soldado soldado){
       this->soldado = soldado;
       prox = NULL;
    }

    NoListaHash* getProx (){
      return this->prox;
    }

    void setNULL (){
      this->prox = NULL;
    }

    void setSoldado (Soldado soldado){
      this->soldado = soldado;
    }

    Soldado getSoldado (){
      return this->soldado;
    }

   void setNo (){
     this->prox = new NoListaHash ();
    }
};



class Lista_Soldados {

private:
    NoListaHash *prim, *ult;
    int TAM;

public:

    Lista_Soldados (){
      prim = new NoListaHash ();
      prim->setNULL();
      ult = prim;
      TAM = 0;
    }

     void Insere (Soldado soldado);
     void Imprime_Lista();
     NoListaHash* getPrim();
};

NoListaHash* Lista_Soldados::getPrim(){
   return prim;
}

void Lista_Soldados::Insere(Soldado soldado){
    ult->setNo();
    ult = ult->getProx();
    ult->setNULL();
    ult->setSoldado(soldado);
    TAM++;
}

void Lista_Soldados::Imprime_Lista(){
 NoListaHash* p = prim->getProx();
  while (p != NULL){
    p->getSoldado().ImprimeSoldado();
    p = p->getProx();
  }
}



class TabelaHash {

private:
    Lista_Soldados thash[43];

public:
  void InsereHash(Soldado soldado);
  int FuncaoHash(string Chave);
  unsigned long long int RecuperaForca(string Chave);
  void ImprimeHash(int Pos);
  int Fatorar(int Base, int Expoente);
};

void TabelaHash::InsereHash(Soldado soldado){
    int aux;
    string Chave;
    Chave = soldado.getNome()+soldado.getRaca();
    aux = FuncaoHash(Chave);
    thash[aux].Insere(soldado);
}

int TabelaHash::Fatorar(int Base, int Expoente){

   int Total = 1,i = 1;

   while (i<=Expoente){
    Total = Total * Base;
    Total = Total %43;
    i++;
   }

  return Total;

}

int TabelaHash::FuncaoHash(string Chave){
   int Soma = 0;
   int p;
   locale loc;
   p = Chave.length();
   p--;
   for (unsigned int i=0; i<Chave.length(); ++i){
     Chave[i] = tolower(Chave[i],loc);
     Soma = Soma+ ((unsigned char)Chave[i]%43) * Fatorar(31,p);
     p--;
    }

  return Soma%43;
}
 unsigned long long int TabelaHash::RecuperaForca(string Chave){
     int aux;
     unsigned long long int soma=0;
    NoListaHash* p;

    aux = FuncaoHash(Chave);
    p = thash[aux].getPrim()->getProx();

    while (p != NULL){
        soma = soma + p->getSoldado().getForca();
        p = p->getProx();
    }
    return soma;
}

void TabelaHash::ImprimeHash(int Pos){
  thash[Pos].Imprime_Lista();
}



class Tabuleiro {

private:
    Lista_Tropa U_tatica;
    TabelaHash Tabela_Hash;

public:

    Tabuleiro (){}
    Tabuleiro (Lista_Tropa U_tatica,TabelaHash Tabela_Hash){
         this->U_tatica= U_tatica;
         this->Tabela_Hash=Tabela_Hash;
    }
    void setTabela_Hash(TabelaHash Tabela_Hash);
    TabelaHash getTabela_Hash();
    void setU_tatica(Lista_Tropa U_tatica);
    Lista_Tropa getU_tatica();
    No* busca(int pix,int piy);
    void Mova(int pix,int piy,int pfx,int pfy);
    void Forca_raca(string raca);
    void Forca(int pix,int piy);
    void terr(int pix,int piy);
    int Movimento_Valido(int pix,int piy,int pfx,int pfy);
    void Organizar_Pilhas();
    void Mostra_lista();
    void Ataque_Principal(No* a,No* d,int pfx,int pfy);
    long double Teste_Max_Ataque(int pix,int piy,int pfx,int pfy);
    void Max_Ataque(int pix,int piy);
    long double Simular_Ataque(No* a,No* d,int pfx,int pfy);

};



void Tabuleiro::setTabela_Hash(TabelaHash Tabela_Hash){
    this->Tabela_Hash = Tabela_Hash;
}

TabelaHash Tabuleiro::getTabela_Hash(){
    return this->Tabela_Hash;
}

Lista_Tropa Tabuleiro::getU_tatica(){
    return this->U_tatica;
}

void Tabuleiro::setU_tatica(Lista_Tropa U_tatica){
    this->U_tatica = U_tatica;
}

void Tabuleiro::Mostra_lista(){
  U_tatica.Imprime_Lista();
}

void Tabuleiro::Organizar_Pilhas(){
  int trocou;
  No* p = U_tatica.getPrim()->getProx();
  while (p!=NULL) {
    trocou=1;
    while(trocou==1){
      Pilha_Tropa paux = p->getTropa();
      trocou=0;
      for (No_PilhaTropa *nav = paux.getTopo()->getProx(); nav != NULL;nav = nav->getProx()) {
        No_PilhaTropa *nav2 = nav->getProx();
        if(nav2 != NULL){
          unsigned long long int fora1 = nav->getSoldado().Forca_Conjunta_Capturados();
           unsigned long long int fora2 = nav2->getSoldado().Forca_Conjunta_Capturados();
          if(fora2 > fora1){
            Soldado aux = nav->getSoldado();
            Soldado aux2 = nav2->getSoldado();
            nav->setSoldado(aux2);
            nav2->setSoldado(aux);
            trocou=1;
            p->setTropa(paux);
          }
        }
      }

    }
    p=p->getProx();
  }

}


int Tabuleiro::Movimento_Valido(int pix,int piy,int pfx,int pfy){
  if((pfy>=0) && (pfy<10) && (pfx>=0) && (pfx<10)){
    for(int i=0;i<=3;i++){
        int j=3;
        if(pfx == pix-i || pfy == piy+j){
            return 1;
        }else if(pfx == pix-i || pfy == piy-j){
            return 1;
        }else if(pfx == pix+i || pfy == piy-j){
            return 1;
        }else if(pfx == pix+i || pfy == piy+j){
            return 1;
        }
        j--;
    }
  }else{
    return 0;
  }
    return 0;
}

No* Tabuleiro::busca(int pix,int piy){
    No *p = U_tatica.getPrim()->getProx();
    while (p != NULL){
      Soldado c = p->getTropa().getTopo()->getProx()->getSoldado();
      if(c.getI() == pix && c.getJ() == piy){
        return p;
      }
      p = p->getProx();
    }
    return NULL;
}

void Tabuleiro::Ataque_Principal(No* a,No* d,int pfx,int pfy){
    int tamanho_D = d->getTropa().getTopo()->getProx()->getSoldado().getCapturado().getTamanho();


    if(tamanho_D > 0){
        Capturado cap = d->getTropa().getTopo()->getProx()->getSoldado().getCapturado().getFrente()->getProx()->getCapturado();
        Fila faux = d->getTropa().getTopo()->getProx()->getSoldado().Soldado_Remove_Capturado();
        Soldado saux =d->getTropa().getTopo()->getProx()->getSoldado();
        saux.setCapturado(faux);
        d->getTropa().getTopo()->getProx()->setSoldado(saux);
        Soldado r(cap.getNome(),cap.getRaca(),cap.getForca());
        Tabela_Hash.InsereHash(r);

    }else {
        Soldado insere = d->getTropa().getTopo()->getProx()->getSoldado();
        Capturado cap_Aux(insere.getNome(),insere.getRaca(),insere.Forca_Conjunta_Capturados());
        Fila fauxx = a->getTropa().getTopo()->getProx()->getSoldado().Soldado_Insere_Capturado(cap_Aux);
        Soldado sauxx =a->getTropa().getTopo()->getProx()->getSoldado();
        sauxx.setCapturado(fauxx);
        a->getTropa().getTopo()->getProx()->setSoldado(sauxx);

        int x = d->getTropa().getTamanho();
        Pilha_Tropa paux = d->getTropa();
        paux.desempilha(insere);
        d->setTropa(paux);

        if(x==1){
            Pilha_Tropa aux_vazio = a->getTropa();
            aux_vazio.Trocar_Posicao(pfx,pfy);
            a->setTropa(aux_vazio);

            U_tatica.remove(d,aux_vazio);


            Soldado lider  = a->getTropa().getTopo()->getProx()->getSoldado();
            std::cout << "unidade "<<lider.getNome()<<"+"<<lider.getRaca() << " avanca para ("<<lider.getI()<<"," " "<<lider.getJ()<<")"<<'\n';
            U_tatica.Eliminacao(insere.getRaca());
        }
    }



}


void Tabuleiro::Mova(int pix,int piy,int pfx,int pfy){
  No* a = busca(pix,piy);
  No* d = busca(pfx,pfy);
  Organizar_Pilhas();
  int x = Movimento_Valido(pix,piy,pfx,pfy);
  if( a != NULL && x==1){
     string racaAtacante(a->getTropa().getTopo()->getProx()->getSoldado().getRaca() );
     if(d==NULL){
       Pilha_Tropa aux_vazio =a->getTropa();
       aux_vazio.Trocar_Posicao(pfx,pfy);
       a->setTropa(aux_vazio);
     }else{
        string racaDefensora(d->getTropa().getTopo()->getProx()->getSoldado().getRaca() );
       unsigned long long int forcaA = a->getTropa().Forca_Conjunta_Soldados();
       unsigned long long int forcaD = d->getTropa().Forca_Conjunta_Soldados();
        if(racaAtacante == racaDefensora){

              Pilha_Tropa paux =a->getTropa();
              Pilha_Tropa paux2 =d->getTropa();
           for (No_PilhaTropa *nav = paux.getTopo()->getProx(); nav != NULL;nav = nav->getProx()) {
                  Soldado s = nav->getSoldado();
                  paux2.empilha(s);
              }
              paux2.Trocar_Posicao(pfx,pfy);
              d->setTropa(paux2);
              U_tatica.remove(a,paux);
              Organizar_Pilhas();
        }else if (racaAtacante != racaDefensora){
              long double dois_terco =((2*forcaD)/3);
              if(forcaA>forcaD){
                  cout << "Ataque bem sucedido" << '\n';
                  Ataque_Principal(a,d,pfx,pfy);
              }else if(forcaA <= dois_terco){
                  Soldado s_Aux = a->getTropa().getTopo()->getProx()->getSoldado();
                  unsigned long long int k = Tabela_Hash.RecuperaForca(s_Aux.getNome()+s_Aux.getRaca());
                  long double forca_Auxiliar = forcaA + (k*0.7);
                  if(forca_Auxiliar>forcaD){
                      cout << "Ataque bem sucedido" << '\n';
                      Ataque_Principal(a,d,pfx,pfy);
                  }else{
                    std::cout << "Contra-ataque!" << '\n';
                    Ataque_Principal(d,a,pix,piy);
                  }
              }

        }else{
              Soldado c = a->getTropa().getTopo()->getProx()->getSoldado();
              c.ImprimeSoldado();
       }
     }
  }
}

long double Tabuleiro::Simular_Ataque(No* a,No* d,int pfx,int pfy){
    int tamanho_D = d->getTropa().getTopo()->getProx()->getSoldado().getCapturado().getTamanho();
    Soldado insere = d->getTropa().getTopo()->getProx()->getSoldado();
    Capturado cap = d->getTropa().getTopo()->getProx()->getSoldado().getCapturado().getFrente()->getCapturado();
    if(tamanho_D > 0){
        return 0;
    }else {
        return insere.Forca_Conjunta_Capturados();
    }


}

long double Tabuleiro::Teste_Max_Ataque(int pix,int piy,int pfx,int pfy){ //verificar se função busca esta funcionando
  No* a = busca(pix,piy);
  No* d = busca(pfx,pfy);
  long double soma=0;
  int x = Movimento_Valido(pix,piy,pfx,pfy);
  if( a != NULL && x==1){
     string racaAtacante(a->getTropa().getTopo()->getProx()->getSoldado().getRaca() );
     if(d==NULL){
       return soma=0;
     }else{
        string racaDefensora(d->getTropa().getTopo()->getProx()->getSoldado().getRaca() );
        unsigned long long int forcaA = a->getTropa().Forca_Conjunta_Soldados();
        unsigned long long int forcaD = d->getTropa().Forca_Conjunta_Soldados();
        if(racaAtacante == racaDefensora){
              return soma=0;
        }if (racaAtacante != racaDefensora){
              long double dois_terco =((2*forcaD)/3);
              if(forcaA>forcaD){
                 unsigned long long int forca_ganha = Simular_Ataque(a,d,pfx,pfy);
                  soma=forcaA+forca_ganha;
                  return soma;
              }else if(forcaA <= dois_terco){
                  Soldado s_Aux = a->getTropa().getTopo()->getProx()->getSoldado();
                unsigned long long int k = Tabela_Hash.RecuperaForca(s_Aux.getNome()+s_Aux.getRaca());
                  long double forca_Auxiliar = a->getTropa().Forca_Conjunta_Soldados() + (k*0.7);
                  if(forca_Auxiliar>forcaD){
                      unsigned long long int forca_ganha = Simular_Ataque(a,d,pfx,pfy);
                      soma=forca_Auxiliar + forca_ganha;
                      return soma = forcaA;
                  }else{
                    return soma=-1;
                  }
             }
        }
     }
  }else{
      return soma=0;
  }
  return soma;
}

void Tabuleiro::Max_Ataque(int pix,int piy){
     long double resultado[16];
     unsigned long long int soma=0;
     int h=0;
     int verificar_ContraAtaque=0;
     int j=3;
     for(int i=0;i<=3;i++){
        resultado[h] = Teste_Max_Ataque(pix,piy,pix-i,piy+j);
        resultado[h++] = Teste_Max_Ataque(pix,piy,pix-i,piy-j);
        resultado[h++]= Teste_Max_Ataque(pix,piy,pix+i,piy+j);
        resultado[h++] = Teste_Max_Ataque(pix,piy,pix+i,piy-j);
        j--;
    }
     for(int x=0;x<=16;x++){
        if(resultado[x]==-1){
            verificar_ContraAtaque++;
        }else if(resultado[x]>soma){
            soma=resultado[x];
        }
     }
     if(verificar_ContraAtaque==16){
       std::cout << "nao mova" << '\n';
     }else if(soma>0){
       std::cout << soma << '\n';
     }else if(verificar_ContraAtaque<16){
       No* a = busca(pix,piy);
       unsigned long long int forcaA = a->getTropa().Forca_Conjunta_Soldados();
       soma=forcaA;
       std::cout << soma << '\n';
     }else{
       std::cout << -1 << '\n';
     }
}

void Tabuleiro::Forca_raca(string raca){

    int total=0;
    No *p = U_tatica.getPrim()->getProx();
    while (p != NULL){
          No_PilhaTropa *nav = p->getTropa().getTopo()->getProx();
          Soldado c = nav->getSoldado();
          if(c.getRaca() == raca){
            total = total + p->getTropa().Forca_Conjunta_Soldados();
          }
      p = p->getProx();
    }
    cout <<total<<endl;

}
void Tabuleiro::Forca(int pix,int piy){
  No* d = busca(pix,piy);
  if(d == NULL){
    cout << -1 << endl;
  }else{
    cout << d->getTropa().Forca_Conjunta_Soldados() << endl;
}
}
void Tabuleiro::terr(int pix,int piy){
  No* p = busca(pix,piy);
  if(p == NULL){
    cout<<"[ ]"<<endl;
  }else{
    int x = p->getTropa().getTamanho();
    No_PilhaTropa *nav = p->getTropa().getTopo()->getProx();
    Pilha_Tropa pilha = p->getTropa();
    Soldado c = nav->getSoldado();
    if(x == 1){
      cout<<"[" <<c.getNome()<<" "<<c.getRaca()<<" "<<c.Forca_Conjunta_Capturados()<<"]" <<endl;
    }else{
      cout<<"[[" <<c.getNome()<<" "<<c.getRaca()<<" "<<pilha.Forca_Conjunta_Soldados()<<"]]" <<endl;

    }
  }
}

//------------------------------------------------------------------------------------------------
int main(){
    string nome,s_Nome,raca,s_Raca,comando="UTA",teste,racap;
    int s_I,s_J,pix,piy,pfx,pfy;
    unsigned long long int forca,s_Forca;
    TabelaHash l;
    Lista_Tropa lt;


    while(comando == "UTA"){

        while(comando !="STO"){
            Fila f;
            cin >> s_Nome;
            cin >> s_Raca;
            cin >> s_I;
            cin >> s_J;
            cin >> s_Forca;

            cin>> comando;

            while(comando != "UTA" && comando != "STO"){
                nome = comando;
                cin >> raca;
                cin >> forca;
                Capturado x1 (nome,raca,forca);
                f.InsereCapturado(x1);

                cin >> comando;

            }
            Soldado a (s_Nome,s_Raca,s_I,s_J,s_Forca,f);
            Pilha_Tropa p = lt.verificar_posicao(a);
            p.empilha(a);
            lt.Insere(p);
        }

    }

 if (comando == "STO"){

        cin >> s_Nome;

    while(s_Nome !="CMD"){

      cin >> s_Raca;
      cin >> s_Forca;
      Soldado a (s_Nome,s_Raca,s_Forca);
      l.InsereHash(a);
      cin >> s_Nome;
    }


 }
int x = lt.Tamanho_Azuri();
int y = lt.Tamanho_Ianteco();
int z = lt.Tamanho_Umashi();
lt.setTam_A(x);
lt.setTam_I(y);
lt.setTam_U(z);
Tabuleiro tab(lt,l);
tab.Organizar_Pilhas();


cin >> comando;

    while(comando != "FIM"){
        if(comando == "MOVA"){
            cin >> pix;
            cin >> piy;
            cin >> pfx;
            cin >> pfy;

            tab.Mova(pix,piy,pfx,pfy);

            cin >> comando;
        }else if(comando == "FORCA"){
            cin >> pix;
            cin >> piy;
            tab.Forca(pix,piy);

            cin >> comando;
        }else if(comando == "TERR"){
            cin >> pix;
            cin >> piy;
            tab.terr(pix,piy);

            cin >> comando;
        }else if(comando == "FORCA_RACA"){
            cin >> racap;
            tab.Forca_raca(racap);

            cin >> comando;
        }else if(comando == "MAX_ATAQUE"){
            cin >> pix;
            cin >> piy;
            tab.Max_Ataque(pix,piy);

            cin >> comando;
        }

    }

    return 0;

}
