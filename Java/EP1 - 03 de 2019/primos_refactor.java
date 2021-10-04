import java.lang.Math;
import java.util.Arrays;

public class primos_refactor {

    private int maior;
    private int menor;
    private boolean[] tabelaDePrimos;
    private int alcanceDaMultiplicacao;

    public void mudarPrimos(int m, int n){
        this.menor = Math.min(m,n);
        this.maior = Math.max(m,n);
        this.alcanceDaMultiplicacao = (int)Math.sqrt(maior)+1;
        this.tabelaDePrimos = new boolean[maior+1];  
        Arrays.fill(tabelaDePrimos, true);
        this.tabelaDePrimos[0] = false;
        this.tabelaDePrimos[1] = false;  
        
    }

    public primos_refactor(int m, int n){
        mudarPrimos(m,n);
    }

    public int contar(){ 
        if(maior < 2){
            return 0;
        }

        int contador = 0;

        for(int i = 2; i <= alcanceDaMultiplicacao; i++){
            if(tabelaDePrimos[i]){
                for (int j = 2*i; j < maior+1; j += i) {
                    tabelaDePrimos[j] = false;
                }
            }
        }

        for (int i = Math.max(menor,0); i <= maior; i++) {
            if (tabelaDePrimos[i]) {
                contador++;
            }
        }
        return contador;
    }

    public static void main(String[] args){
        primos_refactor contarPrimos = new primos_refactor(10, 100000);
        System.out.println(contarPrimos.contar());
        
        contarPrimos.mudarPrimos(1, 1000000000);
        System.out.println(contarPrimos.contar());
    }
    
}
