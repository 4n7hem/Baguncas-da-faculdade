package ep3;

public class Carro {
	
	private String nome;
	private int direcao;
	private Motorista motoristaAtual;
	private int velocidade = 0;
	private int aceleracao = 0;
	private int posicaoX = 0;
	private int posicaoY = 0;
	
	Carro(String nome){
		this.nome = nome;
		posicaoX = 0;
		posicaoY = 0;
		direcao = 0;
	}
	Carro(String nome, int posicaoX, int posicaoY){
		this.nome = nome;
		this.posicaoX = posicaoX;
		this.posicaoY = posicaoY;
		direcao = 0;
	}	

	public void setMotoristaAtual(Motorista motoristaAtual) {
		this.motoristaAtual = motoristaAtual;
		
	}	
	
	public Motorista getMotoristaAtual() {
		return motoristaAtual;
	}	
	
	public void mover() {		
		if(motoristaAtual != null) {
			this.velocidade += aceleracao;
			if(velocidade < 0 ) {
				velocidade = 0;
				aceleracao = 0;
			}			
			if(direcao == 0){
				posicaoX += velocidade;
			}
			if(direcao == 1) {
				posicaoY += velocidade;
			}
			if(direcao == 2){
				posicaoX -= velocidade;
			}
			if(direcao == 3) {
				posicaoY -= velocidade;
			}
		}
	}
	
	public void mover(boolean progressivo) {
		if(progressivo == true) {
			mover();
		}
		else {
			velocidade = -(velocidade);
			mover();
		}
	}
	
	public void acelerar(int incremento) {
		aceleracao = incremento;
	}
	
	public void frear(int decremento) {
		aceleracao = -(decremento);		
	}
	
	public void virarAEsquerda(){
		if(direcao == 0) {
			direcao = 1;
		}
		else if(direcao == 1) {
			direcao = 2;
		}
		else if(direcao == 2) {
			direcao = 3;
		}
		else {
			direcao = 0;
		}
	}
	
	public void virarADireita() {
		if(direcao == 0) {
			direcao = 3;
		}
		else if(direcao == 1) {
			direcao = 0;
		}
		else if(direcao == 2) {
			direcao = 1;
		}
		else {
			direcao = 2;
		}
	}
	
	public String getNome(){
		return nome;
	}
	
	public int getVelocidade() {
		return velocidade;
	}
	
	public int getAceleracao() {
		return aceleracao;
	}
	
	public int getPosicaoX() {
		return posicaoX;
	}
	
	public int getPosicaoY() {
		return posicaoY;
	}
	
	public String toString() {
		if(motoristaAtual != null) {
			return nome + " (" + motoristaAtual.getNome()+")"+ " " + posicaoX + " " + posicaoY + " " + velocidade + " " + aceleracao; 
		}
		else {
			return nome + " " + posicaoX + " " + posicaoY + " " + velocidade + " " + aceleracao;
		}
	}

}
