package entrada;
import java.io.IOException;

import javax.swing.JOptionPane;
public class EntradaComJOptionPane {
	public static void main(String[] args)  {
		String s = JOptionPane.showInputDialog("Identifique-se Padawan...");
		System.out.println(s);
		JOptionPane.showMessageDialog(null, "Seu nome � " + s);
		s = JOptionPane.showInputDialog("Entre com um n�mero inteiro...");
		int i = Integer.parseInt(s);
		// ou int i = new Integer(s);
		System.out.println(i);
		JOptionPane.showMessageDialog(null, "Seu n�mero inteiro � " + i);
		
		s = JOptionPane.showInputDialog("Entre com um n�mero real...");
		double d = new Double(s);		
		System.out.println(d);
		JOptionPane.showMessageDialog(null, "Seu n�mero real � " + String.format("%.2f", d));
	} // main
} // EntradaComJOptionPane
