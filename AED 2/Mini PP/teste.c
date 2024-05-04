#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class UnionFind{
private:
    int tamanho,*vetorvertice;

public:
    UnionFind(){}
    UnionFind(T tamanho){
        this->tamanho=tamanho;
        vetorVertice = new int[tamanho+1];
        for(int i=1;i<=tamanho;i++){
            vetorVertice[i]=i;
        }
    }
    void uniao(T x,T y);
    T busca(T x);

}

template<class T>
void UnionFind::uniao(T x,T y){
    T valorx = busca(x);
    T svalory = busca(y);

    vetorvertice[valorx] = vvalory;

};



