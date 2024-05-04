import javax.swing.JOptionPane;

public class SistemaBancario {


	public static void main(String[] args) {
		ContaCorrente conta01 = new ContaCorrente();

		String deposito = JOptionPane.showInputDialog(null, "Forneça o valor do deposito:");

		if (deposito == null) {
			System.exit(0);
		}else
		{
			float valorDeposito = Float.parseFloat(deposito);
			conta01.depositar(valorDeposito);
		}
		String retirada = JOptionPane.showInputDialog(null, "Forneça o valor da retirada:");

		if (retirada == null) {
			System.exit(0);
		}else
		{
			float valorRetirada = Float.parseFloat(retirada);
			conta01.retirar(valorRetirada);
		}
		
			
		JOptionPane.showMessageDialog(null, "Valor do saldo: R$" + String.format("%.2f", conta01.obterSaldo()));
		

	}
	
}