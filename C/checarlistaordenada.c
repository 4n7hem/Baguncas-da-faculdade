#include <stdio.h>
#include <malloc.h>



typedef struct{
	int a[50];
}LISTA;

int main(){
	LISTA lista1;
	int i;
  //for(i = 0; i < 50; i++) lista1.a[i] = 50 - i;
  
	for(i = 0; i < 50; i++) lista1.a[i] = i+1;
	
  int res = verificadorOrdem(&lista1);
  printf("%i /n", res);
	return 0;
}

int verificadorOrdem(LISTA* l1){
	int anterior;
	int i = 1;
	anterior = l1->a[0];
	while(i < 50){
		if(anterior > l1->a[i]) return 0;
		anterior = l1->a[i];
		i++;
	}
	return 1;
}
