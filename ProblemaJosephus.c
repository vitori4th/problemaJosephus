#include<stdio.h>
#include<stdlib.h>

typedef struct No{
  int dado;
  struct No* prox;
} No;

typedef struct No * p_no;

p_no inserir_circular(p_no lista, int x){
	p_no novo;
	novo=malloc(sizeof(No));
	novo->dado=x;
	if(lista==NULL){
		novo->prox=novo;
	}else{
		novo->prox=lista->prox;
		lista->prox=novo;
	}
	return novo;
}
p_no criar_lista_circular(){
  return NULL;
}
int main(){
	p_no lista,temp;
	int i, N=5, M=2;
	lista=criar_lista_circular();
	for(i=0;i<N;i++)
		lista=inserir_circular(lista,i);
	while(lista!=lista->prox){
		for(i=0;i<M;i++)
			lista=lista->prox;
		temp=lista->prox;
		lista->prox=lista->prox->prox;
		free(temp);
}
	printf("%d\n",lista->dado);
	free(lista);
	return 0;
}
