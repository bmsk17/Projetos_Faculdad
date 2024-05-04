import javax.swing.JOptionPane;

public class SistemaLojaDigital {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Produto produto01 = new Produto();
				
		String produto = JOptionPane.showInputDialog(null, "Forneça o valor do produto:");
		if (produto == null) {
			System.exit(0);
		}else
		{
			float valorProduto = Float.parseFloat(produto);
			produto01.inserirValorDoProduto(valorProduto);
		}
	        
		String desconto = JOptionPane.showInputDialog(null, "Forneça o código do desconto:");
		if (desconto == null) {
			System.exit(0);
		}
		int codigoDesconto = Integer.parseInt(desconto);
		String valorDoDesconto = String.valueOf(produto01.obterDescontoDoProduto(codigoDesconto));
		
		JOptionPane.showMessageDialog(null, "Valor do produto: R$" + produto +
                "\nCódigo do Desconto: " + desconto +
                "\n" + "Valor do Desconto: R$" + valorDoDesconto);
	}

}
