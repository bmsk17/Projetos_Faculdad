
public class Aluno extends Pessoa {

	private String matricula;
	
	public Aluno(String nomePessoa, int idadePessoa, String matriculaAluno) {
		super(nomePessoa, idadePessoa);
		matricula = matriculaAluno;
	}

	public void setMatricula(String matriculaAluno){
		matricula = matriculaAluno;
	}
	public String getMatricula(){
		return matricula;
	}
}
