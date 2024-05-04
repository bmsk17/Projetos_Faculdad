#include <iostream>

using namespace std;

class Chave{

private:

    string key;

public:

    Chave (){}
    Chave (string key){
      this->key = key;
    }

    void Imprime();
    string getKey();
    void setKey(string chave);
};

string Chave::getKey(){
   return this->key;
}

void Chave::setKey(string chave) {
        this->key = chave;
    }

void Chave::Imprime(){
  if(key!=" "){
  cout <<key <<" ";
  }
}

//-------------------------------------------------------------------------------------------------

template<typename T>
class NoGenerico {
private:
    T item;
    NoGenerico *prox;
public:
    NoGenerico() {} // construtor
    T getItem();
    void setItem(T item);
    NoGenerico* getProx();
    void setProx(NoGenerico* prox);
};

template<typename T>
T NoGenerico<T>::getItem() {
        return item;
    }

template<typename T>
void NoGenerico<T>::setItem(T item) {
        this->item = item;
    }

template<typename T>
NoGenerico<T>* NoGenerico<T>::getProx() {
        return prox;
    }

template<typename T>
void NoGenerico<T>::setProx(NoGenerico* prox) {
        this->prox = prox;
    }

//-------------------------------------------------------------------------------------------------
template<typename T>
class LSE {
private:
    NoGenerico<T>* prim, *ult;
public:
    LSE () {
        prim = new NoGenerico<T>();
        prim->setProx(NULL);
        ult = prim;
    }

    void insere(T item);
    NoGenerico<T>* pred(NoGenerico<T>*);
    bool vazia();
    NoGenerico<T>* busca(T);
    void remove(NoGenerico<T>*, T item);
    NoGenerico<T>* getPrim();
    void print();
};

template<typename T>
NoGenerico<T>* LSE<T>::getPrim(){
   return prim;
}

template<typename T>
void LSE<T>::insere(T item) {
    ult->setProx(new NoGenerico<T>());
    ult = ult->getProx();
    ult->setProx(NULL);
    ult->setItem(item);
}


template<typename T>
bool LSE<T>::vazia() {
    return prim == ult;
}


template<typename T>
NoGenerico<T>* LSE<T>::pred(NoGenerico<T>* r) {
    NoGenerico<T>* p = prim->getProx();
    while (p->getProx() != r) {
        p = p->getProx();
    }
    return p;
}

template<typename T>
void LSE<T>::remove(NoGenerico<T>* r, T item){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        item = r->getItem();
        NoGenerico<T>* p = pred(r);
        p->setProx(r->getProx());
        if (p->getProx() == NULL) ult = p;
        delete r;
    }
}



template<typename T>
NoGenerico<T>* LSE<T>::busca(T item) {
    NoGenerico<T>* p = prim->getProx();
    while (p != NULL && p->item.getNome() != item.getNome()) {
        p = p->getProx();
    }
    return p;
}

template<typename T>
void LSE<T>::print() {
    NoGenerico<T>* p = prim->getProx();
    while (p != NULL) {
        p->getItem().Imprime();
        p = p->getProx();
        cout << endl;
    }
}

//-------------------------------------------------------------------------------------------------
template <class T>
class No {

private:

    No<T>* esq,*dir;
    T item;
    int alt;

public:

        No<T>(T item){
            this->item = item;
            this->esq = NULL;
            this->dir = NULL;
            this->alt = 0;
        }

         void setAlt(int alt);
         int getAlt ();
         No<T>* getEsq();
         No<T>* getDir();
         T getChave();
         void setChave(T item);
         void setEsq(No<T>* item);
         void setDir(No<T>* item);
         void imprime();


};

template <class T>
void No<T>::imprime(){
   item.Imprime();
}

template <class T>
void No<T>::setAlt(int alt){
   this->alt = alt;
}

template <class T>
int No<T>::getAlt(){
   return this->alt;
}

template <class T>
 No<T>* No<T>::getEsq(){
    return this->esq;
}

template <class T>
T No<T>::getChave(){
  return this->item;
}

template <class T>
void No<T>::setChave(T item){
  this->item = item;
}

template <class T>
 No<T>* No<T>::getDir(){
    return this->dir;
}

template <class T>
 void No<T>::setEsq(No<T>* no){
    this->esq = no;
}

template <class T>
 void No<T>::setDir(No<T>* no){
    this->dir = no;
}


//-------------------------------------------------------------------------------------------------

template <class T>
class AVL{

private:

    No<T>* raiz;

public:

    AVL (){
      raiz = NULL;
    }

    No<T>* getRaiz();
    No<T>* BuscaMenor(No<T>* no);
    No<T>* BuscaMaior(No<T>* no);
    int Maior(int x,int y);
    int Altura(No<T>* no);
    void Insere(T item);
    No<T>* Insere(T item, No<T>* no);
    No<T>* Remove(T item, No<T>* no);
    void Remove(T item);
    No<T>* RSD (No<T>* no);
    No<T>* RSE (No<T>* no);
    No<T>* RDE(No<T>* no);
    No<T>* RDD(No<T>* no);
    void ImprimePreOrdem (No<T>* Raiz);
    LSE<T> colocarLista(No<T>* Raiz, LSE<T> lista);
    void ImprimeOrdem (No<T>* Raiz);
    void ImprimePosOrdem (No<T>* Raiz);
    No<T>* Busca (No<T>* Raiz, T item);
    void ImprimeNo(No<T>* no);


};

template <class T>
No<T>* AVL<T>::getRaiz(){
   return this->raiz;
}

template <class T>
No<T>* AVL<T>::BuscaMenor(No<T>* no){

        if(no == NULL){
            return NULL;
        }
        else if(no->getEsq() == NULL){
            return no;
         }
        else{
            return BuscaMenor(no->getEsq());
        }
}

template <class T>
No<T>* AVL<T>::BuscaMaior(No<T>* no){

        if(no == NULL){
            return NULL;
        }
        else if(no->getDir() == NULL){
            return no;
        }
        else{
            return BuscaMaior(no->getDir());
        }
}

template <class T>
int AVL<T>::Maior(int x,int y){

   if (x > y){
    return x;
   }
   else {
    return y;
   }
}

template <class T>
int AVL<T>::Altura(No<T>* no){

   if (no == NULL){
     return -1;
   }
   else{
     return no->getAlt();
   }
}

template <class T>
void AVL<T>::Insere(T item){

    raiz = Insere(item, raiz);
}

template <class T>
No<T>* AVL<T>::Insere(T item, No<T>* no){

      if(no == NULL){
            no = new No<T>(item);

        }
        else if(item.getKey() < no->getChave().getKey()){

            no->setEsq(Insere(item, no->getEsq()));

           if(Altura(no->getEsq()) - Altura(no->getDir()) == 2){
                if(item.getKey() < no->getEsq()->getChave().getKey()){
                    no = RSD(no);
                }
                else{
                    no = RDD(no);
                }
            }
        }

        else if(item.getKey() > no->getChave().getKey()){

            no->setDir(Insere(item, no->getDir()));

            if(Altura(no->getDir()) - Altura(no->getEsq()) == 2){
                if(item.getKey() > no->getDir()->getChave().getKey()){
                    no = RSE(no);
                }
                else{
                    no = RDE(no);
                }
            }
        }

        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        return no;
}

template <class T>
void AVL<T>::Remove(T item){

   raiz = Remove(item, raiz);
}

template <class T>
No<T>* AVL<T>::Remove(T item, No<T>* no){

        No<T>* aux;


        if(no == NULL){
            return NULL;
        }


        else if(item.getKey() < no->getChave().getKey()){
            no->setEsq(Remove(item, no->getEsq()));
        }
        else if(item.getKey() > no->getChave().getKey()){
            no->setDir(Remove(item, no->getDir()));
        }


        else if(no->getEsq() != NULL && no->getDir() != NULL){

            aux = BuscaMenor(no->getDir());
            no->setChave(aux->getChave());
            no->setDir(Remove(no->getChave(), no->getDir()));
        }

        else{
            aux = no;
            if(no->getEsq() == NULL)
               no = no->getDir();
            else if(no->getDir() == NULL)
                no = no->getEsq();
            delete aux;
        }

        if(no == NULL){
            return no;
        }

        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);


        if(Altura(no->getEsq()) - Altura(no->getDir()) == 2){

            if(Altura(no->getEsq()->getEsq()) - Altura(no->getEsq()->getDir()) == 1){
                  return RSE(no);
            }

            else{
                return RDE(no);
            }
        }


        else if(Altura(no->getDir()) - Altura(no->getEsq()) == 2){

            if(Altura(no->getDir()->getDir()) - Altura(no->getDir()->getEsq()) == 1){
                return RSD(no);

            }
            else{
                return RDD(no);
            }
        }

        return no;
}

template <class T>
No<T>* AVL<T>::RSD(No<T>* no){

        No<T>* aux = no->getEsq();
        no->setEsq(aux->getDir());
        aux->setDir(no);
        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        aux->setAlt(Maior(Altura(aux->getEsq()), no->getAlt())+1);
        return aux;
}

template <class T>
No<T>* AVL<T>::RSE(No<T>* no){

        No<T>* aux = no->getDir();
        no->setDir(aux->getEsq());
        aux->setEsq(no);
        no->setAlt(Maior(Altura(no->getEsq()), Altura(no->getDir()))+1);
        aux->setAlt(Maior(Altura(aux->getDir()), no->getAlt())+1);
        return aux;
}

template <class T>
No<T>* AVL<T>::RDE(No<T>* no){

        no->setDir(RSD(no->getDir()));
        return RSE(no);

}

template <class T>
No<T>* AVL<T>::RDD(No<T>* no){

        no->setEsq(RSE(no->getEsq()));
        return RSD(no);

}

template <class T>
void AVL<T>::ImprimePreOrdem(No<T>* Raiz){
    if (Raiz != NULL){
        Raiz->getChave().Imprime();
        ImprimePreOrdem(Raiz->getEsq());
        ImprimePreOrdem(Raiz->getDir());
    }
}

template <class T>
LSE<T> AVL<T>::colocarLista(No<T>* Raiz,LSE<T> lista){
    LSE<T> aux,aux2;
    if (Raiz != NULL){
        aux = colocarLista(Raiz->getEsq(),aux);
        aux2 =colocarLista(Raiz->getDir(),aux2);

        aux.insere(Raiz->getChave());

        NoGenerico<T>* p = aux.getPrim()->getProx();
            while (p != NULL) {
                aux2.insere(p->getItem());
                p = p->getProx();
            }


    }
    return aux2;
}

template <class T>
void AVL<T>::ImprimeOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimeOrdem(Raiz->getEsq());
        Raiz->getChave().Imprime();
        ImprimeOrdem(Raiz->getDir());

    }
}

template <class T>
void AVL<T>::ImprimePosOrdem(No<T>* Raiz){

    if (Raiz != NULL){

        ImprimePosOrdem(Raiz->getEsq());
        ImprimePosOrdem(Raiz->getDir());
        Raiz->getChave().Imprime();

    }
}

template <class T>
No<T>* AVL<T>::Busca(No<T>* Raiz, T item){
    if (Raiz == NULL || Raiz->getChave().getKey() == item.getKey()){
       return Raiz;
    }

    if (Raiz->getChave().getKey() > item.getKey()){
       return Busca (Raiz->getEsq(), item);
    }
    else if (Raiz->getChave().getKey() < item.getKey()){
       return Busca (Raiz->getDir(), item);
    }
    else{
        return NULL;
    }

}
template <class T>
void AVL<T>::ImprimeNo(No<T>* no){

  if (no == NULL){
    cout <<"ITEM N ENCONTRADO";
  }
  else{
   no->getChave().Imprime();
  }
}

//----------------------------------------------------------------------------------------

template<typename T>
class TabelaHash {
private:
    int TAM;
    AVL<T> *thash;
public:
TabelaHash(int tam){
       this->TAM = MaiorPrimo(tam/4);
       thash = new AVL<T>[TAM];
    }
  void InsereHash(T item);
  int FuncaoHash(string Chave);
  void ImprimeHash(int Pos);
  int Fatorar(long long int Base, int Expoente);
  AVL<T>* getNo();
  int MaiorPrimo (int x);
  int getTAM();
  void mostrar();
  LSE<T> pegarLista();
  void acharPrint(Chave chave,string nomeVar);

};
template <typename T>
void TabelaHash<T>::mostrar(){
    for (int i=0;i<getTAM();i++){
          thash[i].ImprimePreOrdem(thash[i].getRaiz());
          cout<<endl;
          }

    }
template <typename T>
LSE<T> TabelaHash<T>::pegarLista(){
    LSE<T> lista,aux;
    for (int i=0;i<getTAM();i++){
            aux = thash[i].colocarLista(thash[i].getRaiz(),aux);
            NoGenerico<T>* p = aux.getPrim()->getProx();
            while (p != NULL) {
            lista.insere(p->getItem());
            p = p->getProx();
        }
    }
    return lista;
}

template <typename T>
int TabelaHash<T>::getTAM(){
   return this->TAM;
}

template <typename T>
int TabelaHash<T>::MaiorPrimo (int x){

   int i,cont=0;
   int aux = x;
   for (i=1;i<=aux;i++){
         if (aux%i==0){
            cont++;
         }
 }
     if (cont==2){
        return aux;
      }
      else if(aux==1 || aux==0){
        return -1;
      }
      else {
         return MaiorPrimo(aux-1);
      }
}

template <typename T>
AVL<T>* TabelaHash<T>::getNo(){
   return thash;
}

template <typename T>
int TabelaHash<T>::FuncaoHash(string Chave){
   unsigned long long int Soma = 0;
   int p;
   p = Chave.length();
   p--;
for (unsigned int i=0; i<Chave.length(); ++i){
    Soma = Soma+ (((unsigned char)Chave[i]) * Fatorar(1000000000+7,p));
    Soma = Soma%TAM;
    p--;
}
return Soma%TAM;
}

template <typename T>
int TabelaHash<T>::Fatorar(long long int Base, int Expoente){
  long long int Total = 1,i = 1;
   while (i<=Expoente){
    Total = Total * Base;
    Total = Total %TAM;
    i++;
   }
  return Total;
}

template <typename T>
void TabelaHash<T>::InsereHash(T item){
    int aux;
    string Chave;

    Chave = item.getKey();
    aux = FuncaoHash(Chave);
    thash[aux].Insere(item);
}

template <typename T>
void TabelaHash<T>::ImprimeHash(int Pos){

  thash[Pos].ImprimePreOrdem(thash[Pos].getRaiz());
}

template <typename T>
void TabelaHash<T>::acharPrint(Chave chave,string nomeVar){
    int verificar = 0;
    for (int i=0;i<getTAM();i++){
        No<T>* noRaiz = thash[i].Busca(thash[i].getRaiz(),chave);
        if(noRaiz != NULL){
            verificar=1;
            thash[i].ImprimeOrdem(thash[i].getRaiz());
            cout<<endl;
        }
    }
    if(verificar == 0){
        cout<<"Chave "<<chave.getKey()<<" nao encontrada em Tabela "<<nomeVar<<endl;
    }
}

//-------------------------------------------------------------------------------------------------

class VarKinojo {
private:
    string key;
    TabelaHash<Chave> *tab;
public:
    VarKinojo(){}
    VarKinojo(string key,int tamanho){
        this->key=key;
        this->tab= new TabelaHash<Chave>(tamanho) ;
    }
    string getKey();
    void setKey(string chave);
    void Imprime();
    TabelaHash<Chave>* getTabela();
    void setTabela(TabelaHash<Chave>* tabs);

};
TabelaHash<Chave>* VarKinojo::getTabela(){
   return this->tab;
}
void VarKinojo::setTabela(TabelaHash<Chave>* tabs) {
        this->tab = tabs;
    }

string VarKinojo::getKey(){
   return this->key;
}
void VarKinojo::setKey(string chave) {
        this->key = chave;
    }
void VarKinojo::Imprime(){
  cout <<key <<" ";
}

//----------------------------------------------------------------------------------------

class Alfabeto {
private:
    AVL<VarKinojo> avl;
public:
    Alfabeto(){}
    AVL<VarKinojo> getArvore();
    void setArvore(AVL<VarKinojo> arvore);
    void uniao(string nomeA,string nomeB,string nomeTab);
    void inter(string nomeA,string nomeB,string nomeTab);
    void menos(string nomeA,string nomeB,string nomeTab);
    void print(string nomeVarK,string nomeChave);
    int MaiorPrimo (int x);
};

AVL<VarKinojo> Alfabeto::getArvore(){
   return this->avl;
}
void Alfabeto::setArvore(AVL<VarKinojo> arvore) {
        this->avl = arvore;
}
int Alfabeto::MaiorPrimo (int x){
   int i,cont=0;
   int aux = x;
   for (i=1;i<=aux;i++){
         if (aux%i==0){
            cont++;
         }
 }
     if (cont==2){
        return aux;
      }
      else if(aux==1 || aux==0){
        return -1;
      }
      else {
         return MaiorPrimo(aux-1);
      }
}

void Alfabeto::uniao(string nomeA,string nomeB,string nomeTab){
    int tamanho;
    VarKinojo tabA,tabB;
    LSE<Chave> listaA,listaB;
    No<VarKinojo>* pTabA;
    No<VarKinojo>* pTabB;


    tabA.setKey(nomeA);
    tabB.setKey(nomeB);


    pTabA=avl.Busca(avl.getRaiz(),tabA);
    pTabB=avl.Busca(avl.getRaiz(),tabB);

    if(pTabA != NULL ||	 pTabB != NULL){



        AVL<VarKinojo> avl;

        avl= getArvore();

        listaA = pTabA->getChave().getTabela()->pegarLista();
        listaB = pTabB->getChave().getTabela()->pegarLista();

        tamanho = pTabA->getChave().getTabela()->getTAM()+pTabB->getChave().getTabela()->getTAM();

        VarKinojo novaTab(nomeTab,tamanho*4);

        NoGenerico<Chave>* p = listaA.getPrim()->getProx();
        NoGenerico<Chave>* q = listaB.getPrim()->getProx();

        while (p != NULL) {
            while (q != NULL) {
                if(p->getItem().getKey() != q->getItem().getKey() ){
                    listaA.insere(q->getItem().getKey());
                }
                q = q->getProx();
            }
            p = p->getProx();
        }
        NoGenerico<Chave>* novoP = listaA.getPrim()->getProx();
        while (novoP != NULL) {
            novaTab.getTabela()->InsereHash(novoP->getItem());
            novoP= novoP->getProx();
        }
        avl.Insere(novaTab);
        setArvore(avl);

    }
}
void Alfabeto::inter(string nomeA,string nomeB,string nomeTab){
    int tamanho;
    VarKinojo tabA,tabB;
    LSE<Chave> listaA,listaB,listaAux;;
    No<VarKinojo>* pTabA;
    No<VarKinojo>* pTabB;
    AVL<VarKinojo> avl;

    avl= getArvore();

    tabA.setKey(nomeA);
    tabB.setKey(nomeB);


    pTabA=avl.Busca(avl.getRaiz(),tabA);
    pTabB=avl.Busca(avl.getRaiz(),tabB);

    if(pTabA != NULL && pTabB != NULL){

        listaA = pTabA->getChave().getTabela()->pegarLista();
        listaB = pTabB->getChave().getTabela()->pegarLista();

        if(pTabA->getChave().getTabela()->getTAM() <= pTabA->getChave().getTabela()->getTAM()){
            tamanho = pTabA->getChave().getTabela()->getTAM();
        }else{
            tamanho = pTabB->getChave().getTabela()->getTAM();
        }
        VarKinojo novaTab(nomeTab,tamanho*4);

        NoGenerico<Chave>* p = listaA.getPrim()->getProx();

        while (p != NULL) {
            NoGenerico<Chave>* q = listaB.getPrim()->getProx();
            while (q != NULL) {
                if(p->getItem().getKey() == q->getItem().getKey() ){
                    listaAux.insere(q->getItem().getKey());
                }
                q = q->getProx();
            }
            p = p->getProx();
        }
        NoGenerico<Chave>* novoP = listaAux.getPrim()->getProx();
        while (novoP != NULL) {
            novaTab.getTabela()->InsereHash(novoP->getItem());
            novoP= novoP->getProx();
        }

        avl.Insere(novaTab);
        setArvore(avl);

    }else if(pTabA != NULL || pTabB != NULL){


    }
}

void Alfabeto::print(string nomeVarK,string nomeChave){
    VarKinojo tabA;
    LSE<Chave> listaA;
    tabA.setKey(nomeVarK);
    int tamanho=0;

    No<VarKinojo>* pTabA;
    pTabA=avl.Busca(avl.getRaiz(),tabA);

    if (pTabA!= NULL){
        Chave chaveAux(nomeChave);
        listaA = pTabA->getChave().getTabela()->pegarLista();

        NoGenerico<Chave>* p = listaA.getPrim()->getProx();
        while (p != NULL) {
            tamanho++;
            p = p->getProx();
        }

        if(tamanho != 0){
            pTabA->getChave().getTabela()->acharPrint(chaveAux,nomeVarK);
        }else{
            cout<<"Tabela "<<nomeVarK<<" vazia"<<endl;
        }
    }else{
        cout<<"Tabela "<<nomeVarK<<" vazia"<<endl;
    }

}

void Alfabeto::menos(string nomeA,string nomeB,string nomeTab){
    int tamanho;
    VarKinojo tabA,tabB;
    LSE<Chave> listaA,listaB;
    No<VarKinojo>* pTabA;
    No<VarKinojo>* pTabB;

    tabA.setKey(nomeA);
    tabB.setKey(nomeB);


    pTabA=avl.Busca(avl.getRaiz(),tabA);
    pTabB=avl.Busca(avl.getRaiz(),tabB);

    if(pTabA != NULL){

        if(pTabB == NULL){
        }else{
            AVL<VarKinojo> avl;

        avl= getArvore();

        listaA = pTabA->getChave().getTabela()->pegarLista();
        listaB = pTabB->getChave().getTabela()->pegarLista();

        tamanho = pTabA->getChave().getTabela()->getTAM()- pTabB->getChave().getTabela()->getTAM();


        if(tamanho<2){
            cout<<"Operacao invalida"<<endl;
        }else{
            VarKinojo novaTab(nomeTab,tamanho*4);

            NoGenerico<Chave>* p = listaA.getPrim()->getProx();
            NoGenerico<Chave>* q = listaB.getPrim()->getProx();

            LSE<Chave> listaAux;

            while (p != NULL) {
                while (q != NULL) {
                    if(p->getItem().getKey() != q->getItem().getKey()){
                        listaAux.insere(p->getItem());
                    }
                    q = q->getProx();
                }
            p = p->getProx();
            }

            NoGenerico<Chave>* novoP = listaAux.getPrim()->getProx();
            while (novoP != NULL) {
                novaTab.getTabela()->InsereHash(novoP->getItem());
                novoP= novoP->getProx();
            }
            avl.Insere(novaTab);
            setArvore(avl);
            }
        }
    }else{
                cout<<"Operacao invalida"<<endl;

    }

}


int main(){


    AVL <VarKinojo> av;
    VarKinojo varKinojo;
    Alfabeto alfabeto;
    string nome,lixo,comando,nomeNovo,tabA,tabB,chave;
    int tamanho;

    cin >> comando;

    while(comando != "FIM"){

      if (comando == "TH"){
        while(comando == "TH"){
        cin >> nome;
        cin >> lixo;
        cin >> tamanho;
        cin >> comando;
        VarKinojo varAux(nome,tamanho);
        while(comando!="."){
            Chave chaveAux(comando);
            varAux.getTabela()->InsereHash(chaveAux);
            cin >> comando;
        }
        av.Insere(varAux);
        cin >> comando;
        }
       alfabeto.setArvore(av);

      }

        if(comando == "UNION"){
        cin >> nomeNovo;
        cin >> lixo;
        cin >> tabA;
        cin >> tabB;
        alfabeto.uniao(tabA,tabB,nomeNovo);

        cin >> comando;
        }
        if(comando == "PRINT"){
        cin >> tabA;
        cin >> lixo;
        cin >> chave;
        alfabeto.print(tabA,chave);

        cin >> comando;
        }
        if(comando == "INTER"){
        cin >> nomeNovo;
        cin >> lixo;
        cin >> tabA;
        cin >> tabB;
        alfabeto.inter(tabA,tabB,nomeNovo);

        cin >> comando;
        }
        if(comando == "MINUS"){
        cin >> nomeNovo;
        cin >> lixo;
        cin >> tabA;
        cin >> tabB;
        alfabeto.menos(tabA,tabB,nomeNovo);

        cin >> comando;
        }
        cin >> comando;
    }

}
