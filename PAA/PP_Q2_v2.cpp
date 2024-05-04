#include <iostream>


using namespace std;


int maximo(int x, int y) {
  if(x > y) return x;
  return y;
}

void coin(int *vetor, int k, int distancia){
    int fila[k+1],i;
    fila[0] = 0;
    fila[1] = vetor[0];

    for(i=2;i<=k;i++){
        if((i-distancia)>0){
            fila[i] = maximo(vetor[i-1] + fila[i-distancia], fila[i-1]);
        }else{
            fila[i] = maximo(vetor[i-1] + fila[0], fila[i-1]);
             }
    }
    cout << fila[k];
}

int main(){

int *x;
int tamVetor,distancia;

cin>>tamVetor;
x= new int[tamVetor];
for(int i=0;i<tamVetor;i++){
    cin>>x[i];
}
cin>>distancia;

coin(x,tamVetor,distancia);

}





