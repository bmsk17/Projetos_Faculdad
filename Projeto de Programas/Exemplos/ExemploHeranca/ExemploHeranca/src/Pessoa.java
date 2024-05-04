
public class Pessoa {
	private String nome;
	private int idade;
	
	public Pessoa(String nomePessoa, int idadePessoa){
		nome = nomePessoa;
		idade = idadePessoa;
	}
	public void setNome(String nomePessoa){
		nome = nomePessoa;
	}
	public String getNome(){
		return nome;
	}
	public void setIdade(int idadePessoa){
		idade = idadePessoa;
	}
	public int getIdade(){
		return idade;
	}
}
