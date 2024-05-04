#include "Lista.hpp"

int main() {
	ListaLigada lista;

	Item t1("Dar uma surra no Batman", "8:00", false);
	Item t2("Ir à academia", "8:07", false);
	Item t3("Rodizio de Churras", "9:00", false);
	Item t4("Pegar um ventinho (rolê no mundo)", "10:00", false);

	lista.insere(t1);
	lista.insere(t2);
	lista.insere(t3);
	lista.insere(t4);
	lista.print();

	cout << "Buscando item por chave...\n";
	Chave k = "Rodizio de Churras";
	No* p = lista.busca(k);
	if (p != NULL)
		p->item.print();
	else {
		cout << "Item não encontrado\n";
	}

	// cout << "\n";
	// cout << "Buscando item por posição...\n";
	// int pos = -4;
	// Tarefa* tt = lista.busca(pos);
	// if (tt != NULL)
	// 	tt->print();
	// else {
	// 	cout << "Item não encontrado\n";
	// }

	cout << "\n";
	cout << "Removendo item...\n";
	Item it;
	lista.remove(p, it);
	p->item.print();
	lista.print();
	cout << endl;
	return 0;
}