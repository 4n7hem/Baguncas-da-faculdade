//package test;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
public class grafos {
	public static void main(String[] args) {
		
		Scanner entrada = new Scanner(System.in);
		
		String inicio = entrada.nextLine();
		//string com os nomes listados
		String [] nomes = inicio.split("\\|");
		//a matriz a ser impressa
		int [][]matriz = new int[nomes.length][nomes.length];
		for(int [] row: matriz) {
			Arrays.fill(row, 0);
		}	
		
		String [] arestas = entrada.nextLine().split("\\|");
		
		//onde checar quem segue quem
		String [][] conexoes = new String [(arestas.length)/2][2];
		int listIndex = 0;
		int somaLinhaMaior = 0;
		int somaLinhaMenor = nomes.length;
		int somaColunaMaior = 0;
		int somaColunaMenor = nomes.length;
		
		//listas a serem impressas
		List<String> maisSeguidos = new ArrayList<String>();
		List<String> menosSeguidos = new ArrayList<String>();
		List<String> maisSeguem = new ArrayList<String>();
		List<String> menosSeguem = new ArrayList<String>();
		List<String> mutuos = new ArrayList<String>();
	    
		//loop through each row
	    for (int row=0; row<conexoes.length; row++)
	    {
	        //loop through each column
	        for (int col=0; col<conexoes[row].length; col++)
	        {
	            //populate matrix with values from list
	            conexoes[row][col] = arestas[listIndex++];
	        }
	    }
	    
		//se o indice de nomes[] define as linhas e colunas da matriz e
	    //se conexoes[i][0] é a pessoa seguindo e conexoes[i][1] é a pessoa sendo seguida
	    //logo nomes[col] == conexoes [i][0] e nomes[lin] == conexoes[i][1]
	    for(int col = 0; col<nomes.length; col++) {
	    	for(int i = 0; i<conexoes.length; i++) {
	    		if(nomes[col].equals(conexoes[i][0])){
	    			for(int lin = 0; lin<nomes.length;lin++) {
	    				if(nomes[lin].contentEquals(conexoes[i][1])) {
	    					matriz[col][lin] = 1;
	    					//oops inverti mas ainda dá certo	    					
	    				}
	    			}	    			
	    		}
	    	}	    	
	    }
	    
		//para descobrir quem é o que segue mais e quem segue menos:
	    for (int i = 0; i < matriz.length; ++i){ 
	    	int sum = 0;
	        for (int j = 0; j < matriz.length; ++j){
	        	// Add the element 
	            sum = sum + matriz[i][j]; 
	        } 
	        if(sum>somaLinhaMaior){
            	somaLinhaMaior = sum;
	        }
		    
            if(sum<somaLinhaMenor) {
            	somaLinhaMenor = sum;
            }  
	        // Reinicie a soma
	        sum = 0; 
	    }
		
	 // para descobrir quem é o mais seguido e quem é o menos seguido:
	    for (int col = 0; col < matriz.length; col++) {
	        int colSum = 0;
	        for (int row = 0; row < matriz.length; row++) {
	            colSum = colSum + matriz[row][col];
	        }
	        if(colSum>somaColunaMaior){
            	somaColunaMaior = colSum;
	        }	
		    
            if(colSum<somaColunaMenor) {
            	somaColunaMenor = colSum;
            }
		    
         // Reinicie a soma
            colSum = 0;
	    }
	    MaisMenosSeguem(somaLinhaMaior, somaLinhaMenor, maisSeguem, menosSeguem, matriz, nomes);
	    MaisMenosSeguidos(somaColunaMaior, somaColunaMenor, maisSeguidos, menosSeguidos, matriz, nomes);
	    Mutualidade(mutuos, matriz, nomes);
	    entrada.close();
		for(int i = 0; i<matriz.length; i++){			
			for(int j = 0; j < matriz.length; j++) {
				System.out.print(matriz[i][j]);
				if(j<matriz.length - 1) {
				System.out.print(" ");	
				}
			}
			System.out.println();
		}
		//imprime as pessoas mais seguidas
		System.out.printf(somaColunaMaior + " ");
		for(int i = 0; i< maisSeguidos.size(); i++){
			System.out.printf(maisSeguidos.get(i));
			if(i+1<maisSeguidos.size()) {
				System.out.printf("|");
			}
		}
		System.out.println();
		//imprime as pessoas menos seguidas
		System.out.printf(somaColunaMenor + " ");
		for(int i = 0; i< menosSeguidos.size(); i++){
			System.out.printf(menosSeguidos.get(i));
			if(i+1<menosSeguidos.size()) {
				System.out.printf("|");
			}
		}
		System.out.println();
		//imprime as pessoas que mais seguem
		System.out.printf(somaLinhaMaior + " ");
		for(int i = 0; i< maisSeguem.size(); i++){
			System.out.printf(maisSeguem.get(i));
			if(i+1<maisSeguem.size()) {
				System.out.printf("|");
			}
		}
		System.out.println();
		//imprime as pessoas que menos seguem
		System.out.printf(somaLinhaMenor + " ");
		for(int i = 0; i< menosSeguem.size(); i++){
			System.out.printf(menosSeguem.get(i));
			if(i+1<menosSeguem.size()) {
				System.out.printf("|");
			}
		}
		System.out.println();
		//imprime as seguidas mutuas
		for(int i = 0; i< mutuos.size(); i++){
			System.out.printf(mutuos.get(i));
			if(i+1<mutuos.size()) {
				System.out.printf("|");
			}
		}
		System.out.println();				
	}
	public static void MaisMenosSeguem(int somaLinhaMaior, int somaLinhaMenor, List<String> maisSeguem, List<String> menosSeguem, int [][]matriz, String [] nomes) {
		 for (int i = 0; i < matriz.length; ++i){ 
		    	int sum = 0;
		        for (int j = 0; j < matriz.length; ++j){
		        	// Add the element 
		            sum = sum + matriz[i][j]; 
		        }
		        if(sum == somaLinhaMaior) {
		        	maisSeguem.add(nomes[i]);
		        }
		        if(sum == somaLinhaMenor) {
		        	menosSeguem.add(nomes[i]);
		        }
		        sum = 0;
		 }		
	}
	public static void MaisMenosSeguidos(int somaColunaMaior, int somaColunaMenor, List<String> maisSeguidos, List<String> menosSeguidos, int[][] matriz, String [] nomes) {
		for (int col = 0; col < matriz.length; ++col) {
	        int colSum = 0;
	        for (int row = 0; row < matriz.length; ++row) {
	            colSum = colSum + matriz[row][col];
	        }
	        if(colSum == somaColunaMaior){
	        	maisSeguidos.add(nomes[col]);
	        }
	        if(colSum == somaColunaMenor) {
	        	menosSeguidos.add(nomes[col]);
	        }
	        colSum = 0;
		}
	}
	public static void Mutualidade(List<String> mutuos, int[][]matriz, String []nomes) {
		for (int i = 0; i < matriz.length - 1; ++i){ 
			for (int j = i; j < matriz.length; ++j){
				if(matriz[i][j] == 1 && matriz[j][i] == 1) {
					mutuos.add(nomes[i]);
					mutuos.add(nomes[j]);
				}
			}
		}		
	}
}		
	
