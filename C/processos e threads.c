#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <syscall.h>
//#include <errors.h> aparentemente está incluido no ambiente, também não é reconhecido


void* helloWorld(void* nada){
  void* retval = NULL;
  //função que imprime o Hello World, só pode receber e retornar nada
  printf("Hello World - ID da Thread = %d\n", syscall(SYS_gettid));
  pthread_exit(retval);    
  return nada;
}

int main(void) {
  //uma array dinâmica das threads, para salvar seus endereços
  pthread_t* lista = (pthread_t*) malloc(sizeof(pthread_t)*15);
  pthread_t threadId; //usado para a criação, guarda o endereço da thread por iteração
  int err; // NULL, só usado se criar uma thread falhar (não vi acontecer)
  int i;
  for(i=0; i <15; i++){
    //crie um monte de threads, salve seus ponteiros
    err = pthread_create(&threadId, NULL, &helloWorld, NULL);
    if(err) return err;
    lista[i] = threadId;
  }
  for(i=0; i <15; i++){
    //execute todas as threads
    err = pthread_join(lista[i], NULL); 
    if(err){
     return err;
    }
  }  
  return 0;
}