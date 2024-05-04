import java.util.ArrayList;

public class Pesquisador {

	private String nome;
	private int cpf;
	private ArrayList<Projeto> projetos;
	
	public Pesquisador(String nome, int cpf) {
		
		this.nome = nome;
		this.cpf = cpf;
		
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getCpf() {
		return cpf;
	}
	public void setCpf(int cpf) {
		this.cpf = cpf;
	}
	public ArrayList<Projeto> getProjetos() {
		return projetos;
	}
	public void setProjetos(ArrayList<Projeto> projetos) {
		this.projetos = projetos;
	}
	
	

}
