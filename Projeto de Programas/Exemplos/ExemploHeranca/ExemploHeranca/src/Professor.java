
public class Professor extends Pessoa {

	private double salario;
	
	public Professor(String nomePessoa, int idadePessoa,double salario){
		super(nomePessoa, idadePessoa);
		this.salario = salario;
	}
	
	public double getSalario() {
		return salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}
}
