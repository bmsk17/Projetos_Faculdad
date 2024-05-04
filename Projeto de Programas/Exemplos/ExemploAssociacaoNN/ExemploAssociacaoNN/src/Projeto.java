import java.util.ArrayList;

public class Projeto {

	private String nome;
	private int duracao;
    private ArrayList<Pesquisador> pesquisador;
    
    public Projeto(String nome, int duracao) {
		this.nome = nome;
		this.duracao = duracao;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getDuracao() {
		return duracao;
	}

	public void setDuracao(int duracao) {
		this.duracao = duracao;
	}

	public ArrayList<Pesquisador> getPesquisador() {
		return pesquisador;
	}

	public void setPesquisador(ArrayList<Pesquisador> pesquisador) {
		this.pesquisador = pesquisador;
	}

    
    
}
