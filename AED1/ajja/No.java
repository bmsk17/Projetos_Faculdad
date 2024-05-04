//-------------------------------------------------------------------------------------------------
//C++ TO JAVA CONVERTER TODO TASK: The original C++ template specifier was replaced with a Java generic specifier, which may not produce the same behavior:
//ORIGINAL LINE: template <class T>
public class No<T>
{


	private No<T> esq;
	private No<T> dir;
	private T item = new T();
	private int alt;


		public No(T item)
		{
			this.item = item;
			this.esq = null;
			this.dir = null;
			this.alt = 0;
		}

		 public final void setAlt(int alt)
		 {
			this.alt = alt;
		 }
		 public final int getAlt()
		 {
			return this.alt;
		 }
		 public final No<T> getEsq()
		 {
			return this.esq;
		 }
		 public final No<T> getDir()
		 {
			return this.dir;
		 }
		 public final T getChave()
		 {
		   return this.item;
		 }
		 public final void setChave(T item)
		 {
		   this.item = item;
		 }
		 public final void setEsq(No<T> no)
		 {
			this.esq = no;
		 }
		 public final void setDir(No<T> no)
		 {
			this.dir = no;
		 }
		 public final void imprime()
		 {
			item.Imprime();
		 }


}