package cap03;
import javax.swing.*;
public class SwitchCase {
    public static void main(String args[]) {
        String diaDaSemana = JOptionPane.showInputDialog("Forneça um número inteiro entre 1 e 7:");
        if (diaDaSemana != null) {
            try {
                int dia = Integer.parseInt(diaDaSemana);
                String extenso = "";
                switch (dia) {
                    case 1:  extenso = "Domingo";  break;
                    case 2:  extenso = "Segunda";  break;
                    case 3:  extenso = "Terça";    break;
                    case 4:  extenso = "Quarta";   break;
                    case 5:  extenso = "Quinta";   break;
                    case 6:  extenso = "Sexta";    break;
                    case 7:  extenso = "Sábado";   break;
                    default: extenso = "Dia da Semana Desconhecido!";
                }
                JOptionPane.showMessageDialog(null, "Número fornecido: " + extenso);
            } catch (NumberFormatException erro) {
                JOptionPane.showMessageDialog(null, "Digite apenas valores numéricos inteiros!\n"
                        + erro.toString());
            }
        }
        System.exit(0);
    }
}








