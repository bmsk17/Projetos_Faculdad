
import javax.swing.JOptionPane;

public class CaixasDeDialogo {
  public static void main(String[] args) {
    String nome = null;
    nome = JOptionPane.showInputDialog("Qual é o seu nome?");
    JOptionPane.showConfirmDialog(null, "O seu nome é " + nome + "?");
  }
}
