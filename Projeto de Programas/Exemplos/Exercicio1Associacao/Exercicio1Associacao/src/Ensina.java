
public class Ensina {
	Professor professor;
	Aluno aluno;
	String dia;
	String hor�rio;
	String salaDeAula;
		
	public Ensina(Professor professor, Aluno aluno, String dia, String horario, String salaDeAula) {
		this.professor = professor;
		this.aluno = aluno;
		this.dia = dia;
		this.hor�rio = horario;
		this.salaDeAula = salaDeAula;
	}
	
	public String getDia() {
		return dia;
	}

	public void setDia(String dia) {
		this.dia = dia;
	}

	public String getHor�rio() {
		return hor�rio;
	}

	public void setHor�rio(String hor�rio) {
		this.hor�rio = hor�rio;
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
