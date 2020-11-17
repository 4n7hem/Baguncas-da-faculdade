#include <stdio.h>
#include <malloc.h>



typedef struct{
	int a[50];
}LISTA;

LISTA copiarLista(LISTA* l1){
  LISTA lista2;
  int i;
  for(i = 0; i < 50; i++) lista2.a[i] = l1->a[i];
  return lista2;
}

int main(){
	LISTA lista1;
	int i;  
	for(i = 0; i < 50; i++) lista1.a[i] = i+1;
	LISTA lista2 = copiarLista(&lista1);
  printf("%i /n" , lista2.a[3]);
  return 0;
}


