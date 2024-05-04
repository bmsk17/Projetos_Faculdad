import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		
		//cadastrar N professores 
		Professor professor1 = new Professor("Fabio Santos", 3455);
		Professor professor2 = new Professor("Salvador", 1223);
		Professor professor3 = new Professor("Jucimar", 9944);
		//cadastrar N alunos		
		Aluno aluno1 = new Aluno("Maria da Silva",00012);
		Aluno aluno2 = new Aluno("Jose Pereira",00013);
		Aluno aluno3 = new Aluno("Raimundo Lopes",00014);
		Aluno aluno4 = new Aluno("Pedro Paulo",00015);
		//implementar a associação "professor ensina vários alunos, um aluno é 
		//ensinado por vários professores
		
		ArrayList<Ensina> aulas = new ArrayList<Ensina>();
		
		aulas.add(new Ensina(professor1, aluno1,"segunda-feira","19:40~22:00","A26"));
		aulas.add(new Ensina(professor1, aluno2,"terca-feira  ","19:40~20:30","A26"));
		aulas.add(new Ensina(professor1, aluno3,"quarta-feira ","18:00~19:40","A25"));
		aulas.add(new Ensina(professor1, aluno4,"quinta-feira ","20:30~22:00","A25"));
		
		aulas.add(new Ensina(professor2, aluno1,"segunda-feira","18:00~20:30","A23"));
		aulas.add(new Ensina(professor2, aluno2,"terca-feira  ","19:40~20:30","A23"));
		aulas.add(new Ensina(professor2, aluno3,"quarta-feira ","20:30~22:10","A24"));
		aulas.add(new Ensina(professor2, aluno4,"quinta-feira ","18:00~21:30","A24"));
		
		//obter o agendamento de aulas 
		
		for(int i=0;i<aulas.size();i++){
			System.out.println("Aula"+i+": "+aulas.get(i).getDia()+" "+
					aulas.get(i).getHorário()+" "+
					aulas.get(i).getSalaDeAula()+" "+
					aulas.get(i).getProfessor().getNome());

		}
		System.out.println("--------------------------------------------------------");  
		
		
		//obter uma lista de alunos de um determinado professor
		
		    String professor;
		    System.out.printf("Alunos do professor Salvador \n");
		    for(int i=0;i<aulas.size();i++){
		     professor = aulas.get(i).getProfessor().getNome();
		     if (professor.equals("Salvador")){
		    	 System.out.println("Aluno:"+aulas.get(i).getAluno().getNome());
		     }
		  }
		
		  System.out.println("--------------------------------------------------------");
		//saber quantos professores um determinado aluno possui
		    String aluno = "";
		    int qtProfessor = 0;
		    
		    for(int i=0;i<aulas.size();i++){
		     aluno = aulas.get(i).getAluno().getNome();
		     if (aluno.equals("Maria da Silva")){
		    	 qtProfessor++;
		     }  
		    }
		    System.out.println("O aluno possui "+qtProfessor+" professores");
		
		
		
		
		
		
		

	}
}
