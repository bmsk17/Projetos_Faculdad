#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

template<class T>
class No{

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
    int busca(int i);
    void insere(T item);
    void remove(No<T>* r);
    void print();
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
int Lista<T>::busca(int i){

    No<T> *p = getPrim()->getProx();

    int cont = 1;
    int achou;

    while(p != NULL){
      if(cont == i){
         achou = p->getItem();
      }
      cont++;
      p = p->getProx();
    }

    return achou;
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

template<class T>
class Fila{
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

template <class T>
class UnionFind{
private:

   int *vetorVertice, tamanho;

public:
  UnionFind(){};
  UnionFind(int tamanho){
    this->tamanho = tamanho;
    vetorVertice = new int[tamanho];
    for(int i = 1; i <= tamanho;i++){
        vetorVertice[i] = i;
    }
  }

   int getTamanho();
   int busca(int);
   void une(int,int);

};

template <class T>
int UnionFind<T>::getTamanho() {
    return tamanho;
}

template <class T>
int UnionFind<T>::busca(int vertice) {
    if(vetorVertice[vertice] == vertice){
        return vertice;
    }
    return busca(vetorVertice[vertice]);
}

template <class T>
void UnionFind<T>::une(int vertice1, int vertice2) {
    int valorVertice1 = busca(vertice1);
    int valorVertice2 = busca(vertice2);

    vetorVertice[valorVertice1] = valorVertice2;
}


//------------------------------------------------------------------------fim union find-----------------------------------------------------------------------

template<class T>
class Aresta{
private:

    T vertice1;
    T vertice2;
    double peso ;

public:
    Aresta(){}
    Aresta(T vertice1,T vertice2,double peso){
        this->vertice1= vertice1;
        this->vertice2= vertice2;
        this->peso= peso;
    }
    void setVertice1(T vertice);
    void setVertice2(T vertice);
    void setPeso(double peso);
    T getVertice1();
    T getVertice2();
    double getPeso();
};

template <class T>
void Aresta<T>::setVertice1(T vertice){
     this->vertice1 = vertice;
}

template <class T>
void Aresta<T>::setVertice2(T vertice){
     this->vertice2 = vertice;
}

template <class T>
void Aresta<T>::setPeso(double peso){
     this->peso = peso;
}

template<class T>
T Aresta<T>::getVertice1() {
     return vertice1;
}

template<class T>
T Aresta<T>::getVertice2() {
     return vertice2;
}

template<class T>
double Aresta<T>::getPeso() {
     return peso;
}

//----------------------------------------------------------------------------------------------

template <class T>
class Kruskal {

private:
      Aresta<T>*  vetKruskal;
      int tam,ordem;
      double pesoMST;
public:
       Kruskal (){}
       Kruskal (Aresta<T>* vetKruskal,int tam, int ordem){

           this->vetKruskal = vetKruskal;
           this->ordem = ordem;
           this->tam = tam;
           this->pesoMST = 0;

       }

       void ordenaVetor(Aresta<T>*, int);
       void executaKruskal();
       int getTam();
       int getOrdem();
       double getpesoMST();
       Aresta<T>* getvetKruskal();
       void setPesoMST(double peso);

};

template <class T>
int Kruskal<T>::getOrdem(){
    return this->ordem;
}


template <class T>
void Kruskal<T>::ordenaVetor(Aresta<T>* vetor, int tam){

  int vert1,vert2;
  double peso;

  for(int i=0;i<tam-1;i++){
    for(int j=0;j<tam-i-1;j++){
      if (vetor[j].getPeso() > vetor[j+1].getPeso()) {

        vert1 = vetor[j].getVertice1();
        vert2 = vetor[j].getVertice2();
        peso = vetor[j].getPeso();

        vetor[j].setVertice1(vetor[j+1].getVertice1());
        vetor[j].setVertice2(vetor[j+1].getVertice2());
        vetor[j].setPeso(vetor[j+1].getPeso());

        vetor[j+1].setVertice1(vert1);
        vetor[j+1].setVertice2(vert2);
        vetor[j+1].setPeso(peso);


      }
    }
  }
}

template <class T>
int Kruskal<T>::getTam(){
    return this->tam;
}

template <class T>
void Kruskal<T>::setPesoMST(double peso){
   this->pesoMST = peso;
}

template <class T>
double Kruskal<T>::getpesoMST(){
    return this->pesoMST;
}


template <class T>
Aresta<T>* Kruskal<T>::getvetKruskal(){
    return vetKruskal;
}

template <class T>
void Kruskal<T>::executaKruskal(){

        Aresta<T>* vet = getvetKruskal();
        int tam = getTam();
        int ordem = getOrdem();
        Aresta<T> arvore[tam];
        UnionFind<T> une(ordem);
        int h = 0;
		double soma =0;


	  ordenaVetor(vet,tam);

	  for(int i = 0; i < tam; i++)
		{
			int v1 = une.busca(vet[i].getVertice1());
			int v2 = une.busca(vet[i].getVertice2());

			if(v1 != v2)
			{
				// se diferentes NÃO forma ciclo, insere no vetor
				arvore[i].setVertice1(vet[i].getVertice1());
				arvore[i].setVertice2(vet[i].getVertice2());
				arvore[i].setPeso(vet[i].getPeso());
				h++;
				une.une(v1, v2); // une os subconjuntos
			    soma = soma + vet[i].getPeso();

			}
		}

		cout <<"soma da arvore minima = "<< soma;
		setPesoMST(soma);
}


//-------------------------------------------------------------fim kruskal----------------------------------------------

template <class T>
class Grafo{
private:
    double **matriz;
    Aresta<T> *vet;
    int ordem, tamanho=0;
    void inicializador();

public:
    Grafo(){}
    Grafo(int ordem){
       this->ordem = ordem;
       matriz = new double*[ordem+1];
       for(int i = 1; i <= ordem; i++){
                matriz[i] = new double[ordem+1];
        }
       inicializador();
    }
    int getOrdem();
    double** getMatriz();
    void insereAresta(T,T,double);
    void print();
    void chamaKruskal();
    int getTamanho();
    Aresta<T>* getVet();
    void setVet(Aresta<T>*);
};

template <class T>
void Grafo<T>::setVet(Aresta<T>* vetAux){
   this->vet = vetAux;
}

template <class T>
Aresta<T>* Grafo<T>::getVet(){
   return vet;
}

template <class T>
void Grafo<T>::chamaKruskal (){


   Aresta<T>* vetor;
   int aux = 0;

   vetor = new Aresta<T>[getTamanho()];

  for (int i = 1; i<=getOrdem();i++){
       for (int j = 1; j<=getOrdem();j++){

           if (getMatriz()[i][j] > 0 ){

                vetor[aux].setVertice1(i);
                vetor[aux].setVertice2(j);
                vetor[aux].setPeso(getMatriz()[i][j]);
                aux++;
            }

        }
   }

  setVet(vetor);

  Kruskal<T> krs(vetor,getTamanho(),getOrdem());
  krs.executaKruskal();

}


template <class T>
void Grafo<T>::inicializador(){
    for(int i = 1;i <= ordem; i++){
        for(int j = 1; j <= ordem; j++){
            matriz[i][j] = 0;
        }
    }
}

template <class T>
void Grafo<T>::insereAresta(T u, T v, double peso){
    matriz[u][v] = peso;
   // matriz[v][u] = peso;
    tamanho++;
}

template <class T>
int Grafo<T>::getOrdem(){
    return ordem;
}

template <class T>
int Grafo<T>::getTamanho(){
    return tamanho;
}

template <class T>
double** Grafo<T>::getMatriz(){
    return matriz;
}

template <class T>
void Grafo<T>::print(){

    cout << " ";

    for(int i = 1; i <= ordem; i++){
        cout <<  i << "   ";

    }
     cout << endl;

    for(int i = 1; i <= ordem; i++){
        cout <<  i << " ";
        for(int j = 1; j <= ordem; j++){
            cout << matriz[i][j]<< "  ";
        }
        cout << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------

template <class T>
class Djakstra {

private:
      Grafo<T> grafoDjakstra;
      int ordem,tam;
public:
       Djakstra (){}
       Djakstra (Grafo<T> grafoDjakstra,int tam, int ordem){
           this->grafoDjakstra = grafoDjakstra;
           this->ordem = ordem;
           this->tam = tam;

       }
       void inicializa(int *d,int *p,int s);
       void relaxa(int *d,int *p,int u,int v);
       int existeAberto(bool *aberto);
       int menorAberto(bool *aberto,int *d);
       Lista<T> djakstra(int s);
       Grafo<T> getGrafodjakstra();

};

template <class T>
void Djakstra<T>::inicializa(int *d,int *p,int s){
    int v;
    for(v=0;v<=grafoDjakstra.getOrdem();v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
    }

    d[s] = 0;
}

template <class T>
Grafo<T> Djakstra<T>::getGrafodjakstra(){
    return grafoDjakstra;
}


template <class T>
void Djakstra<T>::relaxa(int *d,int *p,int u,int v){
    cout<<endl<<"---------ENTROU NA fUNCAO Relaxa---------"<<endl;
        double peso = grafoDjakstra.getMatriz()[u][v];
        if(peso>0 ){
            cout<<endl<<"---------Relaxa---------"<<endl;
            cout<<" "<<v<<endl;
            if(d[v] > d[u] + peso){
                cout<<endl<<"tROCOU---------"<<endl;
                d[v] = d[u]+ peso;
                p[v]= u;
            }
        }

}

template <class T>
int Djakstra<T>::existeAberto(bool *aberto){
    int verificador=0;
    for(int v=1;v<=grafoDjakstra.getOrdem();v++){
        if(aberto[v]== true){
            verificador=1;
        }
    }
    return verificador;
}


template <class T>
int Djakstra<T>::menorAberto(bool *aberto,int *d){
    int i;
    for(i = 1; i<=grafoDjakstra.getOrdem();i++){
            cout<<"!!!!!!!!!!!!!!!!  i = "<<i<<endl;
        if(aberto[i]) break;
        if(i==grafoDjakstra.getOrdem()){
            return -1;
        }

    }
    int menor = i;


    for(i = menor+1;i<=grafoDjakstra.getOrdem();i++){
        if(aberto[i] && (d[menor]>d[i])){
            menor=i;
        }

    }
    return menor;
}

template <class T>
Lista<T> Djakstra<T>::djakstra(int s){
    Lista<int> lis;
    int d[grafoDjakstra.getOrdem()+1];
    int p[grafoDjakstra.getOrdem()+1];
    bool aberto[grafoDjakstra.getOrdem()+1];

    inicializa(d,p,s);

    for(int i = 1;i<=grafoDjakstra.getOrdem();i++){
        aberto[i]=true;
    }

    while(existeAberto(aberto)==1){
        int u = menorAberto(aberto,d);
        cout<<endl<<"U é IGUAL A :"<<u<<endl;
        aberto[u]=false;
        for(int i = 1; i<=grafoDjakstra.getOrdem();i++){
            cout<<"Abberto "<<i<<"  : "<<aberto[i]<<endl;
        }
        cout<<endl<<"++++++++++TESTANDO E FECHANDO : "<<u<<endl;

        for(int j = 1; j <= grafoDjakstra.getOrdem(); j++){
            double peso = grafoDjakstra.getMatriz()[u][j];
            cout<<endl<<"------------------------------------adjacente de "<<u<<" : "<<j<<endl;
            if(peso>0){
            relaxa(d,p,u,j);
            }
        }
    }

    int x= 5;
    while(x != -1){
        lis.insere(x);
        x=p[x];
    }
    cout<<"LISTA :"<<endl;
    lis.print();

    return lis;
}



//-------------------------------------------------------------------------------------------------------------


int main(){

Grafo<int> g(5);

g.insereAresta(1, 2, 2);
g.insereAresta(2, 4, 4);
g.insereAresta(1, 4, 3);
g.insereAresta(1, 3, 3);
g.insereAresta(2, 5, 2);
g.insereAresta(3, 5, 3);


g.print();

g.chamaKruskal();

Djakstra<int> d(g,5,6);
cout<<endl;

Lista<int> lista = d.djakstra(1);

  return 0;
}











