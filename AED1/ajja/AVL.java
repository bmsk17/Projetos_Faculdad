//-------------------------------------------------------------------------------------------------

//C++ TO JAVA CONVERTER TODO TASK: The original C++ template specifier was replaced with a Java generic specifier, which may not produce the same behavior:
//ORIGINAL LINE: template <class T>
public class AVL<T>
{


	private No<T> raiz;


	public AVL()
	{
	  raiz = null;
	}

	public final No<T> getRaiz()
	{
	   return this.raiz;
	}
	public final No<T> BuscaMenor(No<T> no)
	{

			if (no == null)
			{
				return null;
			}
			else if (no.getEsq() == null)
			{
				return no;
			}
			else
			{
				return BuscaMenor(no.getEsq());
			}
	}
	public final No<T> BuscaMaior(No<T> no)
	{

			if (no == null)
			{
				return null;
			}
			else if (no.getDir() == null)
			{
				return no;
			}
			else
			{
				return BuscaMaior(no.getDir());
			}
	}
	public final int Maior(int x, int y)
	{

	   if (x > y)
	   {
		return x;
	   }
	   else
	   {
		return y;
	   }
	}
	public final int Altura(No<T> no)
	{

	   if (no == null)
	   {
		 return -1;
	   }
	   else
	   {
		 return no.getAlt();
	   }
	}
	public final void Insere(T item)
	{

		raiz = Insere(item, raiz);
	}
	public final No<T> Insere(T item, No<T> no)
	{

		  if (no == null)
		  {
				no = new No<T>(item);

		  }
			else if (item.getKey() < no.getChave().getKey())
			{

				no.setEsq(Insere(item, no.getEsq()));

			   if (Altura(no.getEsq()) - Altura(no.getDir()) == 2)
			   {
					if (item.getKey() < no.getEsq().getChave().getKey())
					{
						no = RSD(no);
					}
					else
					{
						no = RDD(no);
					}
			   }
			}

			else if (item.getKey() > no.getChave().getKey())
			{

				no.setDir(Insere(item, no.getDir()));

				if (Altura(no.getDir()) - Altura(no.getEsq()) == 2)
				{
					if (item.getKey() > no.getDir().getChave().getKey())
					{
						no = RSE(no);
					}
					else
					{
						no = RDE(no);
					}
				}
			}

			no.setAlt(Maior(Altura(no.getEsq()), Altura(no.getDir())) + 1);
			return no;
	}
	public final No<T> Remove(T item, No<T> no)
	{

			No<T> aux;


			if (no == null)
			{
				return null;
			}


			else if (item.getKey() < no.getChave().getKey())
			{
				no.setEsq(Remove(item, no.getEsq()));
			}
			else if (item.getKey() > no.getChave().getKey())
			{
				no.setDir(Remove(item, no.getDir()));
			}


			else if (no.getEsq() != null && no.getDir() != null)
			{

				aux = BuscaMenor(no.getDir());
				no.setChave(aux.getChave());
				no.setDir(Remove(no.getChave(), no.getDir()));
			}

			else
			{
				aux = no;
				if (no.getEsq() == null)
				{
				   no = no.getDir();
				}
				else if (no.getDir() == null)
				{
					no = no.getEsq();
				}
				if (aux != null)
					aux.dispose();
			}

			if (no == null)
			{
				return no;
			}

			no.setAlt(Maior(Altura(no.getEsq()), Altura(no.getDir())) + 1);


			if (Altura(no.getEsq()) - Altura(no.getDir()) == 2)
			{

				if (Altura(no.getEsq().getEsq()) - Altura(no.getEsq().getDir()) == 1)
				{
					  return RSE(no);
				}

				else
				{
					return RDE(no);
				}
			}


			else if (Altura(no.getDir()) - Altura(no.getEsq()) == 2)
			{

				if (Altura(no.getDir().getDir()) - Altura(no.getDir().getEsq()) == 1)
				{
					return RSD(no);

				}
				else
				{
					return RDD(no);
				}
			}

			return no;
	}
	public final void Remove(T item)
	{

	   raiz = Remove(item, raiz);
	}
	public final No<T> RSD(No<T> no)
	{

			No<T> aux = no.getEsq();
			no.setEsq(aux.getDir());
			aux.setDir(no);
			no.setAlt(Maior(Altura(no.getEsq()), Altura(no.getDir())) + 1);
			aux.setAlt(Maior(Altura(aux.getEsq()), no.getAlt()) + 1);
			return aux;
	}
	public final No<T> RSE(No<T> no)
	{

			No<T> aux = no.getDir();
			no.setDir(aux.getEsq());
			aux.setEsq(no);
			no.setAlt(Maior(Altura(no.getEsq()), Altura(no.getDir())) + 1);
			aux.setAlt(Maior(Altura(aux.getDir()), no.getAlt()) + 1);
			return aux;
	}
	public final No<T> RDE(No<T> no)
	{

			no.setDir(RSD(no.getDir()));
			return RSE(no);

	}
	public final No<T> RDD(No<T> no)
	{

			no.setEsq(RSE(no.getEsq()));
			return RSD(no);

	}
	public final void ImprimePreOrdem(No<T> Raiz)
	{

		if (Raiz != null)
		{
			Raiz.getChave().Imprime();
			ImprimePreOrdem(Raiz.getEsq());
			ImprimePreOrdem(Raiz.getDir());

		}
	}
	public final void ImprimeOrdem(No<T> Raiz)
	{

		if (Raiz != null)
		{

			ImprimeOrdem(Raiz.getEsq());
			Raiz.getChave().Imprime();
			ImprimeOrdem(Raiz.getDir());

		}
	}
	public final void ImprimePosOrdem(No<T> Raiz)
	{

		if (Raiz != null)
		{

			ImprimePosOrdem(Raiz.getEsq());
			ImprimePosOrdem(Raiz.getDir());
			Raiz.getChave().Imprime();

		}
	}
	public final No<T> Busca(No<T> Raiz, T item)
	{
		if (Raiz == null || Raiz.getChave().getKey() == item.getKey())
		{
				 System.out.print("\n");
				 System.out.print("Vai tomar no cu+++++++++++++++++++++++++ ACHPU");
				 System.out.print("\n");

		   return Raiz;
		}

		if (Raiz.getChave().getKey() > item.getKey())
		{
					 System.out.print("\n");
					 System.out.print("Vai tomar no cu+++++++++++++++++++++++++ ESQUERDA");
					 System.out.print("\n");

		   return Busca(Raiz.getEsq(), item);
		}
		else if (Raiz.getChave().getKey() < item.getKey())
		{
					 System.out.print("\n");
					 System.out.print("Vai tomar no cu+++++++++++++++++++++++++ DIREITA");
					 System.out.print("\n");

		   return Busca(Raiz.getDir(), item);
		}
		else
		{
			return null;
		}

	}
	public final void ImprimeNo(No<T> no)
	{

	  if (no == null)
	  {
		System.out.print("ITEM N ENCONTRADO");
	  }
	  else
	  {
	   no.getChave().Imprime();
	  }
	}


}