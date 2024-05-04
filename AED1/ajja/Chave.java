public class Chave
{


	private String key;


	public Chave()
	{
	}
	public Chave(String key)
	{
	  this.key = key;
	}

	public final void Imprime()
	{
	  if (!key.equals(" "))
	  {
	  System.out.print(key);
	  System.out.print(" ");
	  }
	}
	public final String getKey()
	{
	   return this.key;
	}
	public final void setKey(String chave)
	{
			this.key = chave;
	}
}