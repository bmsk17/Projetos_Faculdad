
public class Produto {
	
	float valor;
	Double desconto;
	
	
	void inserirValorDoProduto(float valorProduto){
		valor = valorProduto;
	}
	
	float obterValorDoProduto(){
		return valor;
	}
	
	
	Double obterDescontoDoProduto(int codigoDesconto){
		
		switch (codigoDesconto) {
		case 1:
			desconto = (valor * 0.95);
			break;
		case 2:
			desconto = (valor * 0.90);
			break;
		case 3:
			desconto = (valor * 0.80);
			break;
		case 4:
			desconto = (valor * 0.50);
			break;
		default:
			desconto = 0.0;
		}
		return desconto;
		
	}

}
