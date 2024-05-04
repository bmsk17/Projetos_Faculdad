
public class EscolaPrincipal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	Aluno aluno01 = new Aluno();
	
	aluno01.inserirNome("Fabio Santos");
	System.out.println("Nome do aluno:"+aluno01.obterNome());
	aluno01.inserirIdade(28);
	System.out.println("Idade do aluno:"+aluno01.obterIdade());
	aluno01.inserirMatricula(123456);
	System.out.println("Matricula do aluno:"+aluno01.obterMatricula());
	
	
	Aluno aluno02 = new Aluno();
	
	aluno02.inserirNome("Maria Silva");
	System.out.println("Nome do aluno:"+aluno02.obterNome());
	aluno02.inserirIdade(17);
	System.out.println("Idade do aluno:"+aluno02.obterIdade());
	
	Aluno aluno03 = new Aluno("Jose Souza",30,654321);
	System.out.println("Nome do aluno:"+aluno03.obterNome());
	System.out.println("Idade do aluno:"+aluno03.obterIdade());
	System.out.println("Matricula do aluno:"+aluno03.obterMatricula());
	
	
	
	}

}
