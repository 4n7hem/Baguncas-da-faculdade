#include <stdio.h>
#include <malloc.h>

typedef struct{
  int num;
}REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* prox;
  struct aux* ant;
}ELEMENTO;

typedef struct{
  ELEMENTO* cabeca;
}LISTA;

typedef ELEMENTO* PONT ;

void inicializar(LISTA* l){
  l->cabeca = NULL;
}

void inserir(LISTA* l, ELEMENTO* e){
  if(l->cabeca == NULL){
    l->cabeca = e;
    e->prox = e;
    e->ant = e;
  }
  else{
    PONT temp = l->cabeca;
    if(e->reg.num <= temp->reg.num){      
      PONT temp2 = l->cabeca;
      l->cabeca = e;
      e->prox = temp2;
      e->ant = temp2->ant;
      temp2->ant = e;
      if(temp2->prox == temp2){
        temp2->prox = e;
      }
    }
    else{
      temp = temp->prox;
      while(temp != l->cabeca){        
        if(temp->reg.num >= e->reg.num){        
          break;
        } 
        temp = temp->prox;
      }        
      temp->ant->prox = e;
      e->ant = temp->ant;
      e->prox = temp;
      temp->ant = e;
    }
  }
}

int apagar(LISTA* l, int regis){
  if(l->cabeca == NULL) return -1;  
  PONT atual = l->cabeca;
  while(atual->prox != l->cabeca){
    if(atual->reg.num == regis) break;
    atual = atual->prox;
  }
  if(atual->reg.num == regis){
    if(atual == l->cabeca){
      PONT temp = l->cabeca;
      l->cabeca = temp->prox;
      temp->ant->prox = temp->prox;
      free(atual);
      return 1;
    }
    else{
    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    free(atual);
    }    
  }  
  return -1;
}

ELEMENTO* busca(LISTA* l, int regis){
  if(l->cabeca == NULL) return NULL;
  PONT res;
  PONT atual = l->cabeca;
  while(atual->prox != l->cabeca){
    if(atual->reg.num == regis) return res;
    atual = atual->prox;
  }
  return NULL;
}

void imprimir(LISTA* l){
  PONT atual = l->cabeca;
  printf("%i ", atual->reg.num);
  atual = atual->prox;
  while(atual != l->cabeca){
    printf("%i ", atual->reg.num);
    atual = atual->prox;
  }
  printf("\n");
}

int main(void) {
  LISTA lista1;
  ELEMENTO* e1 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e2 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e3 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e4 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e5 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e6 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e7 = (PONT) malloc(sizeof(ELEMENTO));
  ELEMENTO* e8 = (PONT) malloc(sizeof(ELEMENTO));
  e8->reg.num = 402;  
  e7->reg.num = 12;
  e6->reg.num = 2;
  e5->reg.num = 34;
  e4->reg.num = 11;
  e3->reg.num = 4;
  e2->reg.num = 7;
  e1->reg.num = 1;
  inicializar(&lista1);
  inserir(&lista1, e7);
  inserir(&lista1, e1);
  inserir(&lista1, e2);
  inserir(&lista1, e3);
  inserir(&lista1, e4);
  inserir(&lista1, e5);
  inserir(&lista1, e6);  
  inserir(&lista1, e8);
  apagar(&lista1, 12);         
  imprimir(&lista1);
  return 0;
}