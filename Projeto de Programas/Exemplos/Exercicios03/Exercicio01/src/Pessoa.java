import javax.swing.JOptionPane;

public class Pessoa {

	float peso;
	float altura;
	String nome;
	float imc;
	
	void inserirPeso(float usuarioPeso){
		peso = usuarioPeso;
	}
	
	float obterPeso(){
		return peso;
	}
	
	void inserirAltura(float alturaUsuario){
		altura = alturaUsuario;
	}
	
	float obterAltura(){
		return altura;
	}
	
	void inserirNome(String nomeUsuario){
		nome = nomeUsuario;
	}
	
	String obterNome(){
		return nome;
	}
	
	float obterImc(){
		return peso/(altura*altura); 
	}
	
	
	
}
