// pilha.h 

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int info;
  struct no *prox;
}no;

typedef struct pilha {
  no *topo;
}Pilha;

void *cria_pilha(Pilha *p) {
  p->topo = NULL;
  printf("Pilha criada!\n");
}

int vazia_pilha (Pilha *p) {
  int boole;
  if (p->topo == NULL) {
    boole = 1;
  } else {
    boole = 0;
  }
  return boole;
}

void push (Pilha *p, int elem) {
  no *novo = (no *) malloc(sizeof(no));
  novo->info = elem;
  novo->prox = p->topo;
  p->topo = novo;
}

int pop (Pilha *p) {
  if (vazia_pilha(p)) exit(1);
  no *q = p->topo;
  p->topo = p->topo->prox;
  int valor = q->info;
  free(q);
  return valor;
}


void imprime_pilha(Pilha *p){
	no *aux;
	if(vazia_pilha(p)){
		printf("Pilha Vazia!\n");
	} else {
		aux = p->topo;
		while(aux){
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
}

