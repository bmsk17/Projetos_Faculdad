//
//  malabarismo_de_malter.cpp
//
//  Created by Lucca Siaudzionis on 17/05/15.
//
//  Malabarismo de Malter - Noic

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

//---------------------
#define MAXN 1000100

int heap[MAXN];
int tamanho_heap;
//---------------------

int pai(int i){
    return i/2;
}

int esquerda(int i){
    return 2*i;
}

int direita(int i){
    return 2*i+1;
}

void heapify_up(int v){

    if(v == 1) return;

    int p = pai(v);

     cout<<"POsicao v : "<<v<<endl;
    cout<<"POsicao p : "<<p<<endl;
    if(heap[v] > heap[p]){
        swap(heap[v], heap[p]);

        heapify_up(p);
    }

}

void heapify_down(int v){

    int d = direita(v);
    int e = esquerda(v);

    int maior = v;

    if(d <= tamanho_heap && heap[d] > heap[maior]) maior = d;
    if(e <= tamanho_heap && heap[e] > heap[maior]) maior = e;

    if(maior != v){
        swap(heap[v], heap[maior]);

        heapify_down(maior);
    }
}

void insere(int valor){
    heap[++tamanho_heap] = valor;

    heapify_up(tamanho_heap);
    cout<<endl<<"Lista Atualizando : ";
    for (int y=1;y<tamanho_heap;y++ ){
        printf("%d ", heap[y]);
    }
}

void deleta(int posicao){

    swap(heap[posicao], heap[tamanho_heap]);
    tamanho_heap--;

    heapify_down(posicao);
}

int main(){

    int n,valor;
    scanf("%d", &n);

    cin>>n;

    for(int i = 1;i < n;i++){
    cin>>valor;

        insere(valor);
    }
    cout<<endl<<"Lista Final : ";

    for (int y=1;y<n;y++ ){
        printf("%d ", heap[y]);
    }

    return 0;
}
