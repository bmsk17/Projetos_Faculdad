#include<iostream>
using namespace std;

typedef string Chave;
typedef string Hora;

class Item {
private:
	Chave desc;
	Hora hora;
	bool feito;
public:
	Item() {}
	Item(Chave desc, Hora hora, bool feito);
	void print();
	Chave getDesc();
	void setDesc(Chave);
};


class No {
public:
	Item item;
	No *prox;

	No() {
		prox = NULL;
	}

	No(Item item) {
		this->item = item;
		prox = NULL;
	}

};

class ListaLigada {
private:
	No *prim, *ult;
	int tam;
	No* predecessor(No*);

public:
	ListaLigada() { 
		cria(); 
	}

	void cria();
	void insere(Item);
	void print();
	void remove(No *p, Item &item);
	No* busca(Chave);

};


