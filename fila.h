// fila.h 

#include <stdio.h>
#include <stdlib.h>

typedef struct eFila {
	int info;
	struct eFila *prox;
}eFila;

typedef	struct fila {
	eFila *ini;
	eFila *fim;
}Fila;

void cria_fila(Fila *f)
{
	f->ini = NULL;
	f->fim = NULL;
}

int fila_vazia(Fila *f)
{
	if(f->ini == NULL)
	return 1;
	else return 0;
}

int fila_insere(Fila *f, int ele)
{
	eFila *novo = (eFila *) malloc(sizeof(eFila));
	novo->info = ele; 
	novo->prox = NULL;
	
	if(!novo) return 0;
	
	if(f->ini == NULL) f->ini = novo;
	else f->fim->prox = novo;
	f->fim = novo;
	return 1;

}

int fila_retira(Fila *f)
{
	eFila *aux;
	int ele;
	if (fila_vazia(f)){
		printf("Fila vazia!\n"); 
		exit(1);
	}
	
	aux = f->ini;
	ele = aux->info;
	f->ini = aux->prox;
	if (f->ini == NULL)
		f->fim = NULL;
	free(aux);
	return ele;
}

void fila_imprime(Fila *f)
{
	eFila *aux;
	printf("Fila: ");
	if (fila_vazia(f)){
		printf("Lista Vazia\n");
	} else {
		aux = f->ini;
		while(aux!=NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
		printf("\n");
	}
}


