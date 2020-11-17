import java.lang.Thread;

class ThreadNova extends Thread{
	// Eu expandi a classe Thread para guardar seu ID, diferenciando cada Thread uma da outra
	int id;
	
	ThreadNova(int id){
		this.id = id;
	}
	
	public void run() {
		System.out.println("Esta � a thread de endere�o: " + id);
	}	
}

public class partiuFazerForks{
	
	public static void main(String[] args) {
		//quantas threads eu quero, por agora ser� est�tico
		int tamanho = 15;
		//algo para guardar os endere�os das threads
		ThreadNova[] listao = new ThreadNova[15];
		
		for(int i = 0; i<tamanho ; i++) {
			//crie 15 threads, salve seus endere�os
			ThreadNova n = new ThreadNova(i);
			listao[i] = n;
			//n.setPriority((int)Math.ceil(i/2 + 1));
		}
		for(int i = 0; i<tamanho ; i++) {
			//inicialize todas as threads
			listao[i].start();
		}
		
	}
}
