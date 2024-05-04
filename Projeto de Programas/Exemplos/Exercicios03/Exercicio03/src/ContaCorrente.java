
public class ContaCorrente {

	float saldo = 0;
	
	public ContaCorrente(){}
	
	void depositar(float deposito){
		saldo = saldo + deposito;
	}
	
	void retirar(float retirada){
		saldo = saldo - retirada;
	}
	
	float obterSaldo(){
		return saldo;
	}
	
}
