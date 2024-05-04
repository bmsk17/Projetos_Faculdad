
public class Aluno {

	String nome;
	int idade;
	int matricula;
		
	Aluno(){}
	Aluno(String nomeAluno, int idadeAluno, int matriculaAluno){
		nome = nomeAluno;
		idade = idadeAluno;
		matricula = matriculaAluno;
	}
	
		
	void inserirMatricula(int matriculaAluno){
		matricula = matriculaAluno;
	}
	
	int obterMatricula(){
		return matricula;
	}
	
	
	void inserirIdade(int idadeAluno){
		idade = idadeAluno;
	}
	
	int obterIdade(){
		return idade;
	}
	
	void inserirNome(String nomeAluno){
		nome = nomeAluno;
	}
	
	String obterNome(){
		return nome;	
	}
	
	
	String obterNomeIdade(){
		return nome+" "+idade;
	}
	
}
