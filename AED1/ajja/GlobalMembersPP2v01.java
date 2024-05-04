public class GlobalMembersPP2v01
{

	public static int Main()
	{


		/*int tam;
	
	
		Chave a("Rude");
		Chave b("Areia");
		Chave c("NOOB");
		Chave d("ODEIO");
		Chave e("TAU");
		Chave f("ALOU");
		Chave z("AMEM");
		Chave g("BICICLETA");
		Chave h("abcdefg");
		Chave j("xyz");
		Chave k("far");
	
		cin >>tam;
		VarKinojo a1("Bernardo",tam);
		a1.getTabela()->InsereHash(a);
		a1.getTabela()->InsereHash(b);
		a1.getTabela()->InsereHash(c);
		a1.getTabela()->InsereHash(d);
		a1.getTabela()->InsereHash(e);
		a1.getTabela()->InsereHash(f);
		a1.getTabela()->InsereHash(g);
		a1.getTabela()->InsereHash(h);
		a1.getTabela()->InsereHash(z);
		a1.getTabela()->InsereHash(k);
	
		a1.getTabela()->mostrar();
		VarKinojo b1("amanda",8);
		VarKinojo c1("joao",45);
		VarKinojo d1("leticia",34);
		VarKinojo e1("raimundo",76);
		VarKinojo f1("fernando",56);
	
	
	
		av.Insere(a1);
		av.Insere(b1);
		av.Insere(c1);
		av.Insere(d1);
		av.Insere(e1);
		av.Insere(f1);
		cout <<"PRE-ORDEM\n";
		av.ImprimePreOrdem(av.getRaiz());
		cout <<"\n";
		cout <<"ORDEM\n";
		av.ImprimeOrdem(av.getRaiz());
		cout <<"\n";
		cout <<"POS-ORDEM\n";
		av.ImprimePosOrdem(av.getRaiz());
		cout <<"\n";*/
		AVL <VarKinojo> av = new AVL();
	   /* TabelaHash<Chave> *t,*w; */
		VarKinojo varKinojo = new VarKinojo();
		Alfabeto alfabeto = new Alfabeto();
		String nome;
		String lixo;
		String comando;
		String nomeNovo;
		String tabA;
		String tabB;
		int tamanho;

		cin >> comando;
		while (comando.equals("TH"))
		{
			cin >> nome;
			cin >> lixo;
			cin >> tamanho;
			cin >> comando;
			VarKinojo varAux = new VarKinojo(nome, tamanho);
			while (!comando.equals("."))
			{
				Chave chaveAux = new Chave(comando);
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: varAux.getTabela()->InsereHash(chaveAux);
				varAux.getTabela().InsereHash(new Chave(chaveAux));
				cin >> comando;
			}
			av.Insere(varAux);
			cin >> comando;
		}
		/*while(comando == "UNION"){
		    cin >> nomeNovo;
		    cin >> lixo;
		    cin >> tabA;
		    cin >> tabB;
		    cin >> comando;
		    VarKinojo varAux(nome,tamanho);
		    while(comando!="."){
		        Chave chaveAux(comando);
		        varAux.getTabela()->InsereHash(chaveAux);
		        cin >> comando;
		    }
		    av.Insere(varAux);
		    cin >> comando;
		}*/
		System.out.print("ORDEM\n");
//C++ TO JAVA CONVERTER WARNING: The following line was determined to be a copy constructor call - this should be verified and a copy constructor should be created if it does not yet exist:
//ORIGINAL LINE: alfabeto.setArvore(av);
		alfabeto.setArvore(new AVL(av));
		alfabeto.getArvore().ImprimeOrdem(av.getRaiz());
		alfabeto.uniao("bijuu", "", "oioi");



	}
}