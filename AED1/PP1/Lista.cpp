#include "Lista.hpp"

Item::Item(Chave desc, Hora hora, bool feito) {
	this->desc = desc;
	this-> hora = hora;
	this->feito = feito;
}

void Item::print() {
	cout << desc << ":" << hora << " - ";
	cout << (feito? "OK":"X") << endl;
}

Chave Item::getDesc() {
	return desc;
}

void Item::setDesc(Chave desc) {
	this->desc = desc;
}



void ListaLigada::cria() { 
	prim = new No(); // Cabeça
	prim->prox = NULL;
	ult = prim;
	tam = 0;
}


void ListaLigada::insere(Item it) {
	ult->prox = new No();
	ult = ult->prox;
	ult->prox = NULL;
	ult->item = it;
	tam++;
}


void ListaLigada::print() {
	cout << "Lista:\n";
	No *p = prim->prox;
	while (p != NULL) {
		p->item.print();
		p = p->prox;
	}
}


No* ListaLigada::busca(Chave desc) {
	No *p = prim->prox;
	while (p != NULL && p->item.getDesc() != desc) {
		p = p->prox;
	}
	return p;
}


No* ListaLigada::predecessor(No *r) {
	No *p = prim;
	while (p->prox != r) {
		p = p->prox;
	}
	return p;
}


void ListaLigada::remove(No *r, Item &item) {
	if (tam == 0 || r == NULL || r == prim) {
		cout << "Impossível remover!\n";
	}
	else{
		item = r->item;
		No* p = predecessor(r);
		p->prox = r->prox;
		if (p->prox == NULL) {
			ult = p;
		}
		delete r;
	}
}





