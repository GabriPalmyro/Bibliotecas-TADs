// arvoreBB.h

#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
	int chave;
	struct aux *esq, *dir;
}NO;

typedef NO* ARV;

ARV inicializa(){
	
	printf("Arvore criada!\n");
	return NULL;
}

ARV criarNovoNo(int num){
	ARV novoNo = (ARV)malloc(sizeof(NO));
	if(!novoNo)
		return 0;
		
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = num;
	return novoNo;
}

ARV adiciona(ARV raiz, ARV no){
	if(raiz == NULL) return no;
	if(no->chave < raiz->chave){
		raiz->esq = adiciona(raiz->esq, no);
	} else {
		raiz->dir = adiciona(raiz->dir, no);
	}
	return raiz;
}

ARV procuraPai(ARV raiz, ARV no){
	if(raiz == NULL){
		printf("Numero nao encontrado!!\n");
		return NULL;
	}
	if(no->chave == raiz->dir->chave || no->chave == raiz->esq->chave){
		printf("Pai encontrado!!\n");
		return raiz;
	} else if(no->chave < raiz->chave){
		return procuraPai(raiz->esq, no);
	} else 
		return procuraPai(raiz->dir, no);		
}

ARV buscaArv(ARV raiz, int num){
	if(raiz == NULL){
		printf("Numero nao encontrado!!\n");
		return NULL;
	}
	if(num == raiz->chave){
		printf("Numero encontrado!!\n");
		return raiz;
	} else if(num < raiz->chave){
		return buscaArv(raiz->esq, num);
	} else 
		return buscaArv(raiz->dir, num);
}


void imprimirArv(ARV raiz){
	if(!raiz)
		return;
	
	imprimirArv(raiz->esq);
	printf("%d	", raiz->chave);
	imprimirArv(raiz->dir);
}

ARV buscaNo(ARV raiz, int num, ARV *pai){
	ARV atual = raiz;
	*pai = NULL;
	while(atual){
		if(atual->chave == num) return atual;
		*pai = atual;
		if(num < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}
	return NULL;
}

ARV removerNo(ARV raiz, int num){
	ARV pai, no, p, q;
	no = buscaNo(raiz, num, &pai);
	if(no == NULL) return raiz;
	if(!no->dir || !no->esq){
		if(!no->esq) q = no->dir;
		else q = no->esq;
	} else {
		p = no;
		q = no->esq;
		while(q->dir){
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
	if(!pai) {
		free(no);
		return q;
	}
	if(num < pai->chave) pai->esq = q;
	else pai->dir = q;
	free(no);
	return raiz;
}





