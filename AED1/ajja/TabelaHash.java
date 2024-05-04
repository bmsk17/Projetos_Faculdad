//----------------------------------------------------------------------------------------

//C++ TO JAVA CONVERTER TODO TASK: The original C++ template specifier was replaced with a Java generic specifier, which may not produce the same behavior:
//ORIGINAL LINE: template<typename TIPO>
public class TabelaHash<TIPO>
{
	private int TAM;
	private AVL<TIPO> thash;
public TabelaHash(int tam)
{
	   this.TAM = MaiorPrimo(tam / 4);
	   thash = new AVL<TIPO>[TAM];
	   System.out.print("TAMANHO ATUAL DA TAB = ");
	   System.out.print(TAM);
	   System.out.print("\n");
}
  public final void InsereHash(TIPO item)
  {
	  int aux;
	  String Chave;

	  Chave = item.getKey();
	  aux = FuncaoHash(Chave);
	  thash[aux].Insere(item);
  }
  public final int FuncaoHash(String Chave)
  {
  //C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
  //ORIGINAL LINE: unsigned long long int Soma = 0;
	 long Soma = 0;
	 int p;
	 p = Chave.length();
	 p--;
  //C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
  //ORIGINAL LINE: for (unsigned int i=0; i<Chave.length(); ++i)
  for (int i = 0; i < Chave.length(); ++i)
  {
  //C++ TO JAVA CONVERTER WARNING: Unsigned integer types have no direct equivalent in Java:
  //ORIGINAL LINE: Soma = Soma+ (((unsigned char)Chave[i]) * Fatorar(1000000000+7,p));
	  Soma = Soma + (((byte)Chave.charAt(i)) * Fatorar(1000000000 + 7, p));
	  Soma = Soma % TAM;
	  p--;
  }
  return Soma % TAM;
  }
  public final void ImprimeHash(int Pos)
  {

	thash[Pos].ImprimePreOrdem(thash[Pos].getRaiz());
  }
  public final int Fatorar(long Base, int Expoente)
  {
	long Total = 1;
	long i = 1;
	 while (i <= Expoente)
	 {
	  Total = Total * Base;
	  Total = Total % TAM;
	  i++;
	 }
	return Total;
  }
  public final AVL<TIPO> getNo()
  {
	 return thash;
  }
  public final int MaiorPrimo(int x)
  {

	 int i;
	 int cont = 0;
	 int aux = x;
	 for (i = 1;i <= aux;i++)
	 {
		   if (aux % i == 0)
		   {
			  cont++;
		   }
	 }
	   if (cont == 2)
	   {
		  return aux;
	   }
		else if (aux == 1 || aux == 0)
		{
		  return -1;
		}
		else
		{
		   return MaiorPrimo(aux - 1);
		}
  }
  public final int getTAM()
  {
	 return this.TAM;
  }
  public final void mostrar()
  {
	  for (int i = 0;i < getTAM();i++)
	  {
			thash[i].ImprimePreOrdem(thash[i].getRaiz());
			System.out.print("\n");
	  }

  }
}