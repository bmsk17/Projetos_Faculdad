
public class Ensina {
	Professor professor;
	Aluno aluno;
	String dia;
	String horário;
	String salaDeAula;
		
	public Ensina(Professor professor, Aluno aluno, String dia, String horario, String salaDeAula) {
		this.professor = professor;
		this.aluno = aluno;
		this.dia = dia;
		this.horário = horario;
		this.salaDeAula = salaDeAula;
	}
	
	public String getDia() {
		return dia;
	}

	public void setDia(String dia) {
		this.dia = dia;
	}

	public String getHorário() {
		return horário;
	}

	public void setHorário(String horário) {
		this.horário = horário;
	}

	public String getSalaDeAula() {
		return salaDeAula;
	}

	public void setSalaDeAula(String salaDeAula) {
		this.salaDeAula = salaDeAula;
	}

	public Professor getProfessor() {
		return professor;
	}


	public void setProfessor(Professor professor) {
		this.professor = professor;
	}


	public Aluno getAluno() {
		return aluno;
	}


	public void setAluno(Aluno aluno) {
		this.aluno = aluno;
	}
	
	

}
