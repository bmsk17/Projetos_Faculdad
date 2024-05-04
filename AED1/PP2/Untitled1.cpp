template <class T>
class TabelaHash {

private:

    int TAM;
    string Nome;
    AVL<T> *thash;

public:

  TabelaHash(string Nome,int tam){
       this->TAM = MaiorPrimo(tam/4);
       this->Nome = Nome;
       thash = new AVL<T>[TAM];
       cout <<"TAMANHO ATUAL DA TAB = "<<TAM;
    }
  string getNome();
  void InsereHash(T item);
  int FuncaoHash(string Chave);
  void ImprimeHash(int Pos);
  int Fatorar(long long int Base, int Expoente);
  AVL<T>* getNo();
  int MaiorPrimo (int x);
  int getTAM();

};

template <class T>
int TabelaHash<T>::getTAM(){
   return this->TAM;
}

template <class T>
int TabelaHash<T>::MaiorPrimo (int x){

   int i,cont=0;
   int aux = x;


   for (i=1;i<=aux;i++){

         if (aux%i==0){

            cont++;
         }
 }
     if (cont==2){
        return aux;
      }
      else if(aux==1 || aux==0){
        return -1;
      }
      else {
         return MaiorPrimo(aux-1);
      }
}

template <class T>
AVL<T>* TabelaHash<T>::getNo(){
   return thash;
}

template <class T>
string TabelaHash<T>::getNome(){
   return this->Nome;
}

template <class T>
int TabelaHash<T>::FuncaoHash(string Chave){

   unsigned long long int Soma = 0;
   int p;


   p = Chave.length();
   p--;
for (unsigned int i=0; i<Chave.length(); ++i){

    Soma = Soma+ (((unsigned char)Chave[i]) * Fatorar(1000000000+7,p));
    Soma = Soma%TAM;
    p--;

}

return Soma%TAM;

}

template <class T>
int TabelaHash<T>::Fatorar(long long int Base, int Expoente){

  long long int Total = 1,i = 1;

   while (i<=Expoente){
    Total = Total * Base;
    Total = Total %TAM;
    i++;
   }

  return Total;

}

template <class T>
void TabelaHash<T>::InsereHash(T item){

    int aux;
    string Chave;


    Chave = item.getNome();

    aux = FuncaoHash(Chave);

    thash[aux].Insere(item);

}

template <class T>
void TabelaHash<T>::ImprimeHash(int Pos){

  thash[Pos].ImprimePreOrdem(thash[Pos].getRaiz());

}
