package cap03;
import javax.swing.JOptionPane;
public class If {
    public static void main(String[] args) {
        String resposta = JOptionPane.showInputDialog("Forneça sua resposta: S (SIM) ou N (NÃO)");
        String men = "Letra Fornecida: " + resposta;
        if (!resposta.equals("S") && !resposta.equals("N")){
            men = men + " é inválida! ";
        }
        JOptionPane.showMessageDialog(null, men);
        System.exit(0);
    }
}

