#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <syscall.h>
#include <unistd.h>
//#include <errors.h>

int count = 0;
int verdade = 1; //ignore este.
int vez;

void parteCritica(){
  //faz operações na parte crítica
  count++;
  printf("valor de count : %d\n", count);
}

void parteNaoCritica(){
  //faz nada revelante, como pedido
  printf("Reiniciando thread.\n");
}

void* P0(void* nada){
  //o modelo pedido de P0
  int este = 0;
  int outro = 1;
  while(verdade == 1){
    while(vez != este){}
    //um limitador, para eu não ter que CTRL+C toda vez
    if (count > 97) verdade = 0;
    //faz tudo o requisitado pelo exercício
    parteCritica();
    vez = outro;
    parteNaoCritica();
  }
  pthread_exit(NULL);
  return NULL;
}

void* P1(void* nada){
  //o modelo pedido de P1, e também a mesma coisa do P0
  int este = 1;
  int outro = 0;
  while(verdade == 1){
    while(vez != este){}
    //if (count > 97) verdade = 0;    
    parteCritica();
    vez = outro;
    parteNaoCritica();
  }
  pthread_exit(NULL);
  return NULL;
}

int main(void) {

  int err;

  pthread_t p1;
  pthread_t p2;
  //cria as threads
  err = pthread_create(&p1, NULL, &P0, NULL);
  if(err) return err;  
  err = pthread_create(&p2, NULL, &P1, NULL);
  if(err) return err;

  //faz as threads rodarem
  err = pthread_join(p1, NULL); 
  if(err) return err;
  err = pthread_join(p2, NULL); 
  if(err) return err;
  
  return 0;
}