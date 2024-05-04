import java.util.ArrayList;
public class Principal {

	public static void main(String[] args) {
		
		Pesquisador pesquisador = new Pesquisador("Ana Lung", 11 );
	    
		ArrayList<Projeto> projetos = new ArrayList<Projeto>();

		pesquisador.setProjetos(projetos);

	    pesquisador.getProjetos().add(new Projeto("Playstation N", 2));
	    pesquisador.getProjetos().add(new Projeto("Robo domestico", 4));
	    
	    
	   

	}

}
