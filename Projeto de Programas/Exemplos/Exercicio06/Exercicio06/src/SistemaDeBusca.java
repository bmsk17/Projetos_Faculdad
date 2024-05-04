import javax.swing.JOptionPane;

public class SistemaDeBusca {
    public static void main(String args[]) {
        Pessoa pessoas[] = new Pessoa[3];
        String nomePessoa = "";
        int num = 1, resp = 0, i;
        while (num <= 3) {
        	
        	Pessoa pessoa = new Pessoa();
        	
            String nome = JOptionPane.showInputDialog("Digite o nome da pessoa " + num );
            pessoa.inserirNome(nome);
            pessoas[num-1] = pessoa;
            num++;
        }
        nomePessoa = JOptionPane.showInputDialog("Digite o nome da pessoa a localizar: ");
        for (i = 0; i < (pessoas.length - 1); i++) {
            if (nomePessoa.equals(pessoas[i].obterNome())) {
                resp = 1;
                break;
            }
        }
        if (resp == 1) {
            JOptionPane.showMessageDialog(null,"Pessoa encontrada");
        } else {
            JOptionPane.showMessageDialog(null,"Pessoa não encontrada");
        }
        System.exit(0);
    }
}
