import java.util.Date;
public class Principal {

	public static void main(String[] args){
	    
	    TrabalharEm trabalharEm = new TrabalharEm();

	    trabalharEm.setDataEntrada(new Date());
	    trabalharEm.setCusto(100000.00f);
	    
	    trabalharEm.setPesquisador(new Pesquisador("Ana Lung", 11 ));	
	    trabalharEm.setProjeto(new Projeto("Playstation N", 2));	
	    
	  }
}
