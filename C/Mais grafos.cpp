//https://repl.it/@4n7hem/EvenHospitableMatter 8/10
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef enum { false, true } bool;

typedef struct {
	int bot_lin;
	int bot_col;
	int exit_lin;
	int exit_col;
	int box_col;
	int key_col;
  int key_lin;
	bool haskey;
}ESTADO;

typedef struct aux{
  int estado;
  char tipo;
  struct aux* prox;
}VERTICE;

typedef struct{
  ESTADO* est;  
  VERTICE* prox;
}NO;

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
int nroUSP1() {
    return 11208012;
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
int  nroUSP2() {
    return 0;
}

// ######### ESCREVA O NRO DO GRUPO CADASTRADO
int grupo() {
    return 7;
}

int chegarNoFinal(char* str){
  int i = 0;
  while(str[i] != '*') ++i;
  return i;
}

void inicializarString(char* str){
  str[0] = '*';
}

void finalizarString(char* str){
  int i = chegarNoFinal(str);
  str[i] = '\0';  
}

void pushString(char* str, char c){
  int i = chegarNoFinal(str);
  str[i] = c;
  str[i+1] = '*';
}

void popString(char* str){
  int i = chegarNoFinal(str);
  str[i] = '\0';
  str[i-1] = '*';  
}

void copiarEstado(ESTADO* s, ESTADO* estnovo){
    estnovo->key_lin = 1;
    estnovo->haskey = s->haskey;
    estnovo->key_col = s->key_col;
    estnovo->exit_lin = s->exit_lin;
    estnovo->exit_col = s->exit_col;
    estnovo->bot_lin = 3;
}

void inserirVertice(NO** lista, VERTICE* novo, int j){
  VERTICE* temp = lista[j]->prox;
  lista[j]->prox = novo;
  novo->prox = temp;
}

VERTICE* criarVertice(int i, char type){
  VERTICE* novo = (VERTICE*)malloc(sizeof(VERTICE));
  novo->tipo = type;
  novo->estado = i;  
  return novo;  
}

NO** criarEstados(ESTADO* s){
  int i, j;
  int contador = 0;
  NO** lista = (NO**)malloc(sizeof(NO*)*12);
  for(i = 1; i<4; i++){
    for(j = 1; j<4; j++){
      NO* novo = (NO*)malloc(sizeof(NO));      ;
      ESTADO* estnovo = (ESTADO*)malloc(sizeof(ESTADO));
      copiarEstado(s, estnovo);
      estnovo->bot_col = j;
      estnovo->box_col = i;
      novo->est = estnovo;
      lista[contador] = novo;
      contador++;
    }
    NO* emcima = (NO*)malloc(sizeof(NO));    
    ESTADO* estcima =(ESTADO*)malloc(sizeof(ESTADO));
    copiarEstado(s, estcima);
    estcima->bot_col = i;
    estcima->box_col = i;
    estcima->bot_lin = 2;
    emcima->est = estcima;
    lista[contador] = emcima;
    contador++;
  }
  for(i=0; i <12; i++){
    if(i%4 != 2 && i != 7 && i !=11 && i != 3){    
      //lista[i]->dir = nos[i+1];
      inserirVertice(lista, criarVertice(i+1,'r'), i);      
    }
    if(i%4 != 0 && i != 7 && i !=11 && i != 3){
      inserirVertice(lista, criarVertice(i-1,'l'), i);     
      //nos[i]->esq = nos[i-1];
    }
    if(i%4 == 3){
      inserirVertice(lista, criarVertice((5 * (i%3)),'d'), i); 
      //nos[i]->desce = nos[5 * (i%3)];
    }
    if(i%5 == 0){
      inserirVertice(lista, criarVertice(((4*(i/5))+3),'u'), i);
      //nos[i]->sobe = nos[(4*(i/5))+3];
      if(i != 10){
        inserirVertice(lista, criarVertice(i+5,'R'), i); 
        //nos[i]->pdir = nos[i+5];
      }
      if(i != 0){
        inserirVertice(lista, criarVertice(i-5,'L'), i);
        //nos[i]->pesq = nos[i-5];
      }
    }
  }
  return lista;
}

/*void imprimirLista(NO** lista){
  int i;
  int contador = 0;
  for(i=0; i<12; i++){    
    VERTICE* atual = lista[i]->prox;
    while(atual != NULL){
      contador++;
      printf("%d -> %d \n", i, atual->estado);
      atual = atual->prox;
    }
    printf("------------------------------\n");
  }
  printf("%d" ,contador);
}*/

bool checarAcoes(char ultacao, char acao){
  if(ultacao == 'd' && acao == 'u') return false;
  if(ultacao == 'R' && acao == 'L') return false;
  if(ultacao == 'R' && acao == 'R') return false;
  if(ultacao == 'L' && acao == 'L') return false;
  if(ultacao == 'r' && acao == 'l') return false;
  if(ultacao == 'L' && acao == 'R') return false;
  if(ultacao == 'l' && acao == 'r') return false;
  return true;
}

int compararEstados(ESTADO* s, NO** lista){
  int i;
  for(i = 0; i < 12; i++){
    if(lista[i]->est->bot_col == s->bot_col && lista[i]->est->bot_lin == s->bot_lin && lista[i]->est->box_col == s->box_col) return i;
  }
  return 0;
}

bool buscaPorProfundidade(NO** lista, int atual, char* resp, char ultacao, bool esquerda){   
  if(lista[atual]->est->haskey == true && lista[atual]->est->bot_col == lista[atual]->est->exit_col && lista[atual]->est->bot_lin == lista[atual]->est->exit_lin){
    pushString(resp, 'e');    
    return true;
  }
  if(lista[atual]->est->bot_col == lista[atual]->est->key_col && lista[atual]->est->bot_lin == 2 && lista[atual]->est->key_lin != 0){
    int i;
    pushString(resp, 'g');
    esquerda = false;
    for(i=0; i <12; i++){
      lista[i]->est->key_lin = 0;
      lista[i]->est->haskey = true;
    }
  }
  VERTICE* ponteiro = lista[atual]->prox;
  while(ponteiro){
    if(checarAcoes(ultacao, ponteiro->tipo) == true){
      pushString(resp, ponteiro->tipo);
      bool teste;
      if(ultacao == 'R') esquerda = true;
      if(!(esquerda == true && ponteiro->tipo == 'R')){
        if(buscaPorProfundidade(lista, ponteiro->estado, resp, ponteiro->tipo, esquerda) == true) return true;
        
      }
      popString(resp);      
    }
    ponteiro = ponteiro->prox;  
  }
  return false;
}

void caminhoValido(ESTADO* s, char* resp){
  inicializarString(resp);
  NO** lista = criarEstados(s);  
  buscaPorProfundidade(lista, compararEstados(s, lista) , resp, 'n', false);
  //imprimirLista(lista);
  finalizarString(resp);
  printf("resposta: %s", resp);

}

}