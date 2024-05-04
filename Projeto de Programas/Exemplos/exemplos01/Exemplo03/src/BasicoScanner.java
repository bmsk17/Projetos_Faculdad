
import java.util.Scanner;

public class BasicoScanner {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner (System.in);
		System.out.println("Digite o nome: ");
		String testeStr = scanner.nextLine();
		System.out.println(testeStr);
		System.out.println("Digite a idade: ");
		int i = scanner.nextInt();
		System.out.println(i);
		System.out.println("Digite a Altura: ");
		float j = scanner.nextFloat();
		System.out.printf( "%.2f", j);
	} // main
}
