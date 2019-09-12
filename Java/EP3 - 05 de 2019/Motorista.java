package ep3;

public class Motorista {
	
	private String nome;	
	private Carro carroAtual;
	
	public Motorista(String nome){
		this.nome = nome;
	}
	
	public void entrarNoCarro(Carro carro) {
		if(carro.getMotoristaAtual() == null && carroAtual == null) {
			carro.setMotoristaAtual(this);
			this.carroAtual = carro;
		}
		else {
			;
		}
	}
	
	public void sairDoCarro() {
		if(carroAtual.getVelocidade() == 0) {
			carroAtual.setMotoristaAtual(null);
			this.carroAtual = null;			
		}
		else {
			;
		}
	}
	
	public String getNome(){
		return nome;
	}
	
	public String toString() {
		if(carroAtual != null) {
			return nome + " (" + carroAtual.getNome() + " " + carroAtual.getPosicaoX() + " " + carroAtual.getPosicaoY() + " " + carroAtual.getVelocidade() + " " + carroAtual.getAceleracao() + ")";
		}
		else {
			return nome;
		}
	}
}
