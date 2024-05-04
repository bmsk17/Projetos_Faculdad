public class Pessoa {

	String nome;
	String telefone;
	
	public Pessoa(){}
	
	void inserirNome(String nomeDaPessoa){
		nome = nomeDaPessoa;
	}
	
	String obterNome(){
		return nome;
	}
	
	void inserirTelefone(String telefoneDaPessoa){
		telefone = telefoneDaPessoa;
	}
	
	String obterTelefone(){
		return telefone;
	}
	
}