
public class Universitario extends Aluno {

	String periodo;
	
	
	public Universitario(String nome,int idade, String matricula, String periodo){
		super(nome, idade, matricula);
		this.periodo = periodo;
		
	}
	public String getPeriodo() {
		return periodo;
	}

	public void setPeriodo(String periodo) {
		this.periodo = periodo;
	}

		
}
