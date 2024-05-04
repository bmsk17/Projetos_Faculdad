//----------------------------------------------------------------------------------------

public class Alfabeto
{
	private AVL<VarKinojo> avl = new AVL<VarKinojo>();
	public Alfabeto()
	{
	}
	public final AVL<VarKinojo> getArvore()
	{
	   return this.avl;
	}
	public final void setArvore(AVL<VarKinojo> arvore)
	{
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created if it does not yet exist:
//ORIGINAL LINE: this->avl = arvore;
			this.avl.copyFrom(arvore);
	}
	public final void uniao(String nomeA, String nomeB, String nomeTab)
	{
		VarKinojo tabA = new VarKinojo();
		VarKinojo tabB = new VarKinojo();
		VarKinojo novaTab = new VarKinojo();
		tabA.setKey(nomeA);
		tabB.setKey(nomeB);
		novaTab.setKey(nomeTab);

		No<VarKinojo> pTabA;

//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: pTabA=avl.Busca(avl.getRaiz(),tabA);
		pTabA = avl.Busca(avl.getRaiz(), new VarKinojo(tabA));
		pTabA.getChave().getTabela().mostrar();

		avl.ImprimeNo(pTabA);
	}
}