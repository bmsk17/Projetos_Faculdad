#include <iostream>
#include <cstring>

using namespace std;

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
