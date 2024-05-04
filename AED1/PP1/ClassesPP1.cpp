#include <iostream>

using namespace std;


class Soldado {

private:

    string Nome;              //Não coloquei typedef só porque pra mim fica mais fácil de escrever a função depois;
    string Raca;
    int Forca,i,j;

public:

    Soldado (){}
    Soldado (string Nome,string Raca,int i,int j, int Forca){   //Padrao da forma que será dado na entrada;
         this->Nome = Nome;
         this->Raca = Raca;
         this->i = i;
         this->j = j;
         this->Forca = Forca;
    }

    void setNome(string Nome);
    string getNome();
    void setRaca (string Raca);
    string getRaca();
    void setI(int i);
    int getI();
    void setJ(int j);
    int getJ();
    void setForca(int Forca);
    int getForca();
    void ImprimeSoldado();
};


void Soldado::setNome(string Nome){
      this->Nome = Nome;
}

string Soldado::getNome(){
     return this->Nome;
}

void Soldado::setRaca(string Raca){
     this->Raca = Raca;
}

string Soldado::getRaca(){
    return this->Raca;
}

void Soldado::setI(int i){
     this->i = i;

}

int Soldado::getI(){

   return this->i;

}

void Soldado::setJ(int j){
     this->i = i;

}

int Soldado::getJ(){

   return this->j;

}

void Soldado::setForca(int Forca){

   this->Forca = Forca;
}

int Soldado::getForca(){
return this->Forca;
}


void Soldado::ImprimeSoldado(){

  cout <<"Nome: "<<Nome <<" " << "Raca: "<<Raca << " "<<"Forca: "<<Forca << " "<<"Posicao: "<<i<<" "<<j<<"\n";

}

// IMPLEMENTANDO A CLASSE NO ENCAPSULADA

class No {

private:

    Soldado soldado;
    No* prox;

public:

    No (){            //CONSTRUTOR PADRAO

    prox = NULL;

    }

    No (Soldado soldado){

       this->soldado = soldado;
       prox = NULL;
    }

    No* getProx (){         //RETORNA PONTEIRO PARA O PROXIMO NO
      return this->prox;
    }

    void setNULL (){        //ANULA O PONTEIRO PARA O NO SEGUINTE AO ULTIMO JA QUE ELE NAO EXISTE

      this->prox = NULL;
    }

    void setSoldado (Soldado soldado){   // INSERE O SOLDADO NA VARIAVEL SOLDADO DESSA CLASSE

      this->soldado = soldado;
    }

    Soldado getSoldado (){      //RETORNA O SOLDADO QUE ESTA NESSA CLASSE

      return this->soldado;

    }

   void setNo (){            //CRIA UM NOVO NO VISTO QUE ESTÁ ENCAPSULADO E É PRECISO FAZER "MANUALMENTE"

     this->prox = new No ();

    }

};

//IMPLEMENTANDO A CLASSE LISTA

class Lista_Soldados {

private:

    No *prim, *ult;
    int TAM = 0;             // UTIL PARA INFORMAR O TAMANHO ATUAL DA LISTA

public:

    Lista_Soldados (){

      prim = new No ();
      prim->setNULL();
      ult = prim;
    }


     void Insere (Soldado soldado);
     void Imprime_Lista();
};

void Lista_Soldados::Insere(Soldado soldado){

    ult->setNo();             //CRIANDO NOVO NO
    ult = ult->getProx();
    ult->setNULL();
    ult->setSoldado(soldado);
    TAM++;

}

void Lista_Soldados::Imprime_Lista(){

  No* p = prim->getProx();   //PEGA O PRIMEIRO NO DEPOIS DO CABEÇA

  while (p != NULL){

    p->getSoldado().ImprimeSoldado();
    p = p->getProx();

  }
}


int main(){


Lista_Soldados s;

Soldado a ("A1","AZURI",1,2,40);
Soldado b ("B1","IAMTECO",3,6,20);
Soldado c ("C3","AZURI",4,1,10);
Soldado d ("D5","UMASHI",6,3,4);

s.Insere(a);
s.Insere(b);
s.Insere(c);
s.Insere(d);

//IMPRIMINDO PARA TESTAR SE FOI INSERIDO

s.Imprime_Lista();




}



