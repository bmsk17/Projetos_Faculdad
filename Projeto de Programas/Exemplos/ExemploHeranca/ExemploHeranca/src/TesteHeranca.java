
public class TesteHeranca {

	public static void main(String[] args) {
		
		Aluno estudante = new Aluno("Maria",18,"123456");
		
		System.out.println("Nome = "+estudante.getNome());
		System.out.println("Idade = "+estudante.getIdade());
		System.out.println("Matricula = "+estudante.getMatricula());
		
		Aluno estudante2 = new Aluno("Jose",20,"4534343"); 
		
		System.out.println("Nome = "+estudante2.getNome());
		System.out.println("Idade = "+estudante2.getIdade());
		System.out.println("Matricula = "+estudante2.getMatricula());
		
		Professor prof = new Professor("Fabio", 27,20000);
		
		System.out.println("Nome Professor = "+prof.getNome());
		System.out.println("Idade = "+prof.getIdade());
		System.out.println("Salario = "+prof.getSalario());
		
		Aluno universitario = new Universitario("Paulo",23,"283382","3 periodo");
		
		System.out.println("Nome Universitario = "+universitario.getNome());
		System.out.println("Matricula = "+universitario.getMatricula());
		System.out.println("Idade = "+universitario.getIdade());
		//System.out.println("Periodo = "+universitario.getPeriodo());
		
		
		
		
		
	}
}
