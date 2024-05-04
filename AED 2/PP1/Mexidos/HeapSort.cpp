#include <iostream>

using namespace std;


template <class T>
class heapSort {

private:

    T *vet; //ainda sem utilizar
    int TAM;
    int pai;
    int esq;
    int dir;

public:

    heapMax (){}
    void heapMax (T *vet, int i, int n);
    void constroiHeap(T *vet, int n);
    void heapsort(T *vet, int n);
    bool ordenado (T *vet, int TAM);
    void setTAM(int TAM);
    void setVET (T *vet);
    T* getVET  ();
    int getTAM();
    int getPai(int i);
    int getEsq(int i);
    int getDir(int i);

};


template <class T>
 void heapSort<T>::setVET (T *vet){
    this->vet = vet;
}

template <class T>
T* heapSort<T>::getVET (){
    return *vet;
}

template <class T>
void heapSort<T>::setTAM(int TAM){
   this->TAM = TAM;
}

template <class T>
int heapSort<T>::getTAM(){
   return this->TAM ;
}

template <class T>
int heapSort<T>::getPai(int i) {
   return (i/2);
}

template <class T>
int heapSort<T>::getEsq(int i) {
   return 2*i;
}

template <class T>
int heapSort<T>::getDir(int i) {
   return 2*i+1;
}

template <class T>
void heapSort<T>::heapMax (T *vet, int i, int n){
  int esq,dir,maior,aux;

  esq=2*i;
  dir=(2*i+1);

  if((esq<=n)&&vet[esq]>vet[i]){
    maior=esq;
  }
  else{
    maior=i;
  }
  if((dir<=n)&&(vet[dir]>vet[maior])){
    maior=dir;
  }
  if(maior!=i)
    {
      aux=vet[i];
      vet[i]=vet[maior];
      vet[maior]=aux;
      heapMax(vet, maior,n);
    }
}

template <class T>
void heapSort<T>::constroiHeap(T *vet, int n){
  for(int k = n/2; k >= 1; k--)
    {
      heapMax(vet, k, n);
    }
}

template <class T>
void heapSort<T>::heapsort(T *vet, int n){

  constroiHeap(vet,n);
  int i, temp;
  for (i = n; i >= 2; i--)
    {
      temp = vet[i];
      vet[i] = vet[1];
      vet[1] = temp;
      heapMax(vet, 1, i - 1);
    }
}

template <class T>
bool heapSort<T>::ordenado (T *vet,int TAM){

     for(int i = 1; i < TAM; i++){
        if (vet[i] > vet[i + 1]) {
            return false;
        }
    }
    return true;

}

int main()
{
  int n;
  heapSort<int> test;
  heapSort<char> test1;
  string x;


  cout<<"INSIRA O TAMANHO DO VETOR"<<endl;
  cin>>n;

  int vet[n];

  cout<<"INSIRA OS ELEMENTOS"<<endl;
  for (int i = 1; i <= n; i++)
    {
      cin >>vet[i];
    }

  test.heapsort(vet, n);

  cout<<"ORDENADO"<<endl;
  for (int i = 1; i <=n; i++)
    {
      cout<<vet[i]<<endl;
    }

    return 0;
}
