#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;



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
       int djakstra(int s);

};

template <class T>
void Djakstra<T>::inicializa(int *d,int *p,int s){
    int v;
    for(v=0;v<grafoDjakstra.getOrdem();v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
        cout<<"VETOR PREDECESSOR: Passou por > "<<v<<" de "<<p[v]<<endl;
    }
    d[s] = 0;
}


template <class T>
void Djakstra<T>::relaxa(int *d,int *p,int u,int v){
    for(int j = 1; j <= grafoDjakstra.getOrdem(); j++){
        double peso = grafoDjakstra.getMatriz()[u][j];
        cout <<endl<< "**********peSO : "<<peso<< "  ";
        if(peso>0 && j!=v ){
            if(d[v] > d[u] + peso){
                cout<<endl<<"-----------------------------------relaxa------- J :"<<j<<endl;
                cout<<endl<<"D["<<u<<"]: " <<d[u]<<endl;
                cout<<"VETOr SOMA: Passou por > "<<"D["<<v<<"]: "<<d[v]
                <<" TEM QUE SER MAIOR QUE "<<"D["<<u<<"] : "<<d[u]
                <<" + peso: "<<peso<<" : "<<d[u]+peso<<endl;
                cout<<endl<<"SIM"<<endl;
                d[v] = d[u]+ peso;
                cout<<endl<<"D["<<v<<"] VIROU: "<<d[v]<<endl;
                p[v]= u;
            }
        }
    }
    cout<<endl;
    for(int x = 1; x <= grafoDjakstra.getOrdem(); x++){
        cout<< "d["<<x<<"] = "<<d[x]<<endl;
    }
    cout<<endl<<"------------------finalizou--------relaxa-------"<<endl;
    cout<<endl;
}

template <class T>
int Djakstra<T>::existeAberto(bool *aberto){
    int verificador=0;
    for(int v=0;v<grafoDjakstra.getOrdem();v++){
        cout<<"VETOR EXISTE ABERTO: Passou por > "<<v<<" de "<<aberto[v]<<endl;
        if(aberto[v]== true){
            verificador=1;
        }
    }
    return verificador;
}


template <class T>
int Djakstra<T>::menorAberto(bool *aberto,int *d){
    int i;
    for(i = 0; i<grafoDjakstra.getOrdem();i++){
        if(aberto[i]) break;
    }

    if(i==grafoDjakstra.getOrdem()){
        return -1;
    }
    int menor = i;


    for(i = menor+1;i<grafoDjakstra.getOrdem();i++){
        cout<<"VETOR MENOR ABERTO: Passou por > "<<i<<" de "<<d[i]<<endl;
        if(aberto[i] && (d[menor]>d[i])){
            menor=i;
        }

    }
    cout<<"VETOR MENOR ABERTO +++++: "<<menor<<endl;
    return menor;
}

template <class T>
int Djakstra<T>::djakstra(int s){
    int d[grafoDjakstra.getOrdem()+1];
    int p[grafoDjakstra.getOrdem()+1];
    bool aberto[grafoDjakstra.getOrdem()+1];

    inicializa(d,p,s);

    for(int i = 0;i<grafoDjakstra.getOrdem();i++){
        aberto[i]=true;
        cout<<"VETOR ABERTO: Passou por > "<<i<<" que esta "<<aberto[i]<<endl;
    }

    while(existeAberto(aberto)==1){
        int u = menorAberto(aberto,d);
        cout<<endl<<"U é IGUAL A :"<<u<<endl;
        aberto[u]=false;

        for(int j = 1; j <= grafoDjakstra.getOrdem(); j++){
            double peso = grafoDjakstra.getMatriz()[u][j];
            relaxa(d,p,u,j);
        }
    }

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
d.djakstra(1);

  return 0;
}











