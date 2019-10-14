//package test;
import java.util.*;
import java.lang.Math;
public class primos {
	
	public static void main (String [] args) {
		
		///variaveis variaveis variaveis
		Scanner entrada = new Scanner(System.in);
		int n = entrada.nextInt();
		int m = entrada.nextInt();
		int maior;
		int menor;
		int contador = 0;
		double alcance;
		
		if(n>m) {
			 maior = n;
			 menor = m;
		}
		
		else {
			maior = m;
			menor = n;
		}
		
		///condições especiais para burlar OutOfBounds	
		if (maior == 2) {
			System.out.println("1");		
		}
		
		else if(maior == 1 || maior == 0) {
			System.out.println(0);
		}
		
		else if(maior < 0) {
			System.out.println(0);
		}
		
		///caso geral
		else {
			boolean [] multi = new boolean [maior+1];
			Arrays.fill(multi, true);
			
			///define que números devem ser multiplicados dentre os números no alcance para serem checados
			alcance = Math.ceil(Math.sqrt(maior))+ 1;
			
			multi[0] = false;
			multi[1] = false;
			///calcula todos os números primos entre 1 e o maior
			for (int i = 0; i <= alcance; i++) {
				if (multi[i]) {
					for (int j = 2*i; j < maior+1; j += i) {
						multi[j] = false;
					}
				}
			}
			
			///condição especial para não quebrar o loop abaixo	
			if (menor < 0) {
				menor = 0;
			}
			
			///conta os trues da array começando pelo menor
			for ( int i = menor; i <= maior; i++) {
				if (multi[i]) {
					contador++;
				}
			}
		
		entrada.close();
		System.out.println(contador);
		}
		
	}
}

