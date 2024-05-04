import java.util.ArrayList;
public class Departamento {
	private String descricao;
	private ArrayList<Funcionario> funcionarios;
	
	public Departamento(String desc){
		descricao = desc;
		this.funcionarios = new ArrayList<Funcionario>();
	}
	public void setDescricao(String desc){
		descricao = desc;
	}
	public String getDescricao(){
		return descricao;
	}
	public void addFuncionario(Funcionario funcionario){
		this.funcionarios.add(funcionario);
	}
	public String getFuncionarios(){
		String retorno = "";
		for(int i=0;i<this.funcionarios.size();i++){
			retorno+= this.funcionarios.get(i).getNome()+"\n"+
			this.funcionarios.get(i).getIdade()+"\n";
			
		}
		return retorno;
	}
}
