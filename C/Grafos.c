#include <stdio.h>
#include <stdlib.h>

typedef struct aux{
  int num;
  struct aux* prox;

}NO;
typedef NO** GRAFO;

NO* criarNO(int x){
  NO* novo = (NO*) malloc(sizeof(NO));
  novo->num = x;
  return novo;
}

void inserirNoGrafo(GRAFO g, NO* n, int pai){
  int i;
  NO* temp;
  temp = g[pai];
  g[pai] = n;
  n->prox = temp;   
}

void zerarListas(GRAFO g, int tam){
  int i;
  for(i=0; i<tam; i++){
    g[i] = NULL;
  }
}

void visualizar(GRAFO g, int tam){
  int i;
  NO* j;
  for(i = 0; i<tam; i++){
    j = g[i];
    while(j){
      printf("%d -> %d\n",i, j->num);
      j = j->prox;
    }    
  }
}

NO* busca(GRAFO g, int x, int ini){
  NO* atual = g[ini];
  printf("%d -> ", ini);  
  if(atual){
    if(atual->num == x){
      printf("%d (vértice encontrado!)\n", atual->num);
      return atual;
    }
  }
  while(atual){
    NO* resposta = busca(g, x, atual->num);
    if(resposta) return resposta;
    printf("%d/n", atual->num);
    atual = atual->prox;
  }
  return NULL;
}

NO* buscaIni(GRAFO g, int x, int ini){
  printf("ordem da pesquisa: ");
  NO* temp = busca(g, x , ini);
  if (!temp)
    printf("(vértice não encontrado!)\n");
  return temp;
}

void contarRegioes(GRAFO g, int tam){
  int resposta = 0;
  int i;
  int flag[tam];
  for(i=0; i <tam; i++){
    flag[i] = 0;
  }
  flag[0] = 1;
  for(i=0; i <tam; i++){
    if(flag[i] == 0){ 
      flag[i] = 1;     
      NO* j = g[i];
      while(j){
        flag[j->num] = 1;
        if(j->prox){
          if(flag[j->prox->num == 1])
            resposta--;
            break;
        }        
        j = j->prox;                     
      }
       resposta++;                 
    }
  }
  printf("numero de regiões: %d", resposta);
}

int main(void) {
  GRAFO grafo = (NO**) malloc(10 * sizeof(NO*));
  zerarListas(grafo, 10);  
  inserirNoGrafo(grafo,criarNO(3), 1); 
  inserirNoGrafo(grafo,criarNO(3), 1); 
  inserirNoGrafo(grafo,criarNO(1), 3);
  inserirNoGrafo(grafo,criarNO(3), 1);      
  inserirNoGrafo(grafo,criarNO(4), 1);
  inserirNoGrafo(grafo,criarNO(1), 4);
  inserirNoGrafo(grafo,criarNO(2), 4);
  inserirNoGrafo(grafo,criarNO(4), 2); 
  inserirNoGrafo(grafo,criarNO(6), 5);
  inserirNoGrafo(grafo,criarNO(5), 6);   
  inserirNoGrafo(grafo,criarNO(7), 6);
  inserirNoGrafo(grafo,criarNO(6), 7);
  inserirNoGrafo(grafo,criarNO(5), 7);
  inserirNoGrafo(grafo,criarNO(7), 5);     
  inserirNoGrafo(grafo,criarNO(9), 8);
  inserirNoGrafo(grafo,criarNO(8), 9);   
  visualizar(grafo, 10);
  NO* resposta = buscaIni(grafo, 2, 3);
  contarRegioes(grafo, 10);
  return 0;
}