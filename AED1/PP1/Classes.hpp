#include<iostream>
using namespace std;

typedef String Nome;
typedef String Raca;
typedef int Forca;


class Soldado{
private:
    Nome nome;
    Raca raca;
    Forca forca;
public:
    Soldado() { }
    Soldado(Nome nome, Raca raca, Forca forca,Tabuleiro tabuleiro);
    Nome getNome();
  	void setNome(Nome);
    Raca getRaca();
  	void setRaca(Raca);
    Forca getForca();
  	void setForca(Forca);
};

///// talvez tenhamos de fazer uma lista duplamente encadeada.
class No {
private:
	Soldado capturado;
	No *prox;
public:
	No() { prox = NULL;}
	No(Soldado soldado);
  Soldado getSoldado();
  void setSoldado(Soldado soldado);
  No* getProx();
  void setProx(No* prox);
};

class Lista_Capturado {
private:
	No *prim, *ult;
	int tam;
	No *predecessor(No*);

public:
	Lista_Capturado() {
		cria();
	}
	void cria();
	void insere(Soldado);
	void print();
	void remove(No *p, Soldado &capturado);
	No* busca(Nome);

};

class Pilha_Tropa {
private:
    No *fundo, *topo;

public:
    Pilha_Tropa();
    void empilha(Soldado);
    bool vazia();
    void desempilha(Soldado&);
    void mostra();
};
