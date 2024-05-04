import javax.swing.JOptionPane;

public class Imc {
	
	public static void main(String[] args) {
		
		Pessoa pessoa01 = new Pessoa();

		String nome = JOptionPane.showInputDialog("Digite seu nome");
		pessoa01.inserirNome(nome);

		String peso = JOptionPane.showInputDialog("Digite seu peso");
		float p = Float.parseFloat(peso);
		pessoa01.inserirPeso(p);

		String altura = JOptionPane.showInputDialog("Digite sua altura");
		float a = Float.parseFloat(altura);
		pessoa01.inserirAltura(a);

		JOptionPane.showMessageDialog(null, "Seu peso ="+pessoa01.obterPeso());


		float imc = pessoa01.obterImc();

		String descricao = "";
		if (imc < 18.5){
			descricao = "Peso abaixo do normal";
		}else if (imc >= 18.5 && imc <=24.4){
			descricao = "Peso ideall";
		}else if (imc >= 25.5 && imc <=29.9){
			descricao = "Pre-obesidade";
		}else if (imc >= 30 && imc <=34.9){
			descricao = "Obesidade classe I";
		}else if (imc >= 35 && imc <=39.9){
			descricao = "Obesidade classe II (severa)";
		}else if (imc >39.9){
			descricao = "Obesidade classe III (mórbida)";
		}

		JOptionPane.showMessageDialog(null, pessoa01.obterNome()+",seu IMC = " + String.format("%.2f", imc)+"\n"+" "+descricao);

	}

}
