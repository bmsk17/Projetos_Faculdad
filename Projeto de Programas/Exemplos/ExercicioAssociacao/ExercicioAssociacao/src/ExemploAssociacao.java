import javax.swing.JOptionPane;
public class ExemploAssociacao {
	public static void main(String[] args) {
		
		Departamento departamento = new Departamento("Departamento de Informatica");
		String operacao;
		do{
			operacao = JOptionPane.showInputDialog(null, "\t << Departamento >>\n Informe a operacao: \n [i] inserir \n [l] listar funcionarios \n [f] fim\n");
			if (operacao.charAt(0) == 'i'){
				Funcionario funcionario = new Funcionario();
				funcionario.setNome(JOptionPane.showInputDialog(null, "Informe o nome:"));
				funcionario.setIdade(Integer.parseInt(JOptionPane.showInputDialog(null, "Informe a idade:")));
				funcionario.setDepartamento(departamento);
				departamento.addFuncionario(funcionario);
				
			}else if (operacao.charAt(0) == 'l'){
				String informacoes = departamento.getDescricao()+"\n"+
									 departamento.getFuncionarios();
								  
				JOptionPane.showMessageDialog(null, informacoes);
			}
		}while(operacao.charAt(0)!= 'f');
		System.exit(0);
		}
}
