//-------------------------------------------------------------------------------------------------

public class VarKinojo
{
	private String key;
	private TabelaHash<Chave> tab;
	public VarKinojo()
	{
	}
	public VarKinojo(String key,int tamanho)
	{
		this.key = key;
		this.tab = new TabelaHash<Chave>(tamanho);
	}
	public final String getKey()
	{
	   return this.key;
	}
	public final void setKey(String chave)
	{
			this.key = chave;
	}
	public final void Imprime()
	{
	  System.out.print(key);
	  System.out.print(" ");
	}
	public final TabelaHash<Chave> getTabela()
	{
	   return this.tab;
	}
	public final void setTabela(TabelaHash<Chave> tabs)
	{
			this.tab = tabs;
	}

}