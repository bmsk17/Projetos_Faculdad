#include <iostream>


using namespace std;



int maximo(int a, int b) {
  if(a > b) return a;
  return b;
}

int coin(int *vetor, int k, int distancia){
    int fila[k+1],i;
    fila[0] = 0;
    fila[1] = vetor[0];

    for(i=2;i<=k;i++){
        if((i-distancia)>0){
            fila[i] = maximo(vetor[i-1] + fila[i-distancia], fila[i-1]);
            cout << i << " = " <<fila[i] << " //// "<<
            vetor[i-1]<<" + "<<fila[i-distancia]<<" ou "<< fila[i-1]<<endl;
        }else{
            fila[i] = maximo(vetor[i-1] + fila[0], fila[i-1]);
            cout << i << " = " <<fila[i] << " *////* "<<
            vetor[i-1]<<" + "<<fila[i-distancia]<<" ou "<< fila[i-1]<<endl;        }
    }

    cout << fila[k];
    for(int y=0;y<k;y++){
        cout <<endl<<y<<" = "<< fila[y];
    }
}

int main(){

int *x;
int u,n=2,tamVetor=7,distancia=3;
int vetor[] = {4,3,2,1,8,5,5};

coin(vetor,tamVetor,distancia);

}


/*
cin>>u;
x= new int[u];
for(int i=0;i<u;i++){
    cin>>x[i];
}
cout<<endl;
for(int j=0;j<u;j++){
    cout<<x[j]<<" ";
}
*/

