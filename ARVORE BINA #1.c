#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
	int chave;
	struct aux *esq, *dir;
}NO;

typedef NO* ARV;

ARV inicializa(){
	return NULL;
}

ARV criarNovoNo(int num){
	ARV novoNo = (ARV)malloc(sizeof(NO));
	if(!novoNo)
		printf("Deu BO\n");
	else {
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		novoNo->chave = num;
	}
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

int contagemEle(ARV raiz){
	if(raiz == NULL) return 0;
	return (contagemEle(raiz->esq) + 1 + contagemEle(raiz->dir));
}

int semFilhos(ARV raiz){
	if(raiz->dir == NULL && raiz->esq == NULL)
		return 1;

	return 0;
}

ARV remover(ARV raiz, int num){
	ARV aux, auxP;
	aux = buscaArv(raiz,num);
	auxP = procuraPai(raiz, aux);
	if(semFilhos){
		free(aux);
		return raiz;
	} else if(aux->dir != NULL && aux->esq == NULL || aux->dir == NULL && aux->esq != NULL){
		if(auxP->esq->chave == aux->chave){
			auxP->esq = aux;
			aux->dir = aux;
		}
		return raiz;
	}
}

void imprimirArv(ARV raiz){
	if(!raiz)
		return;

	imprimirArv(raiz->esq);
	printf("%d	", raiz->chave);
	imprimirArv(raiz->dir);

}

int main(){
	ARV r = inicializa();
	int op = 0, num, cont;
	while(op!=7){
		system("PAUSE");
		system("cls");
		printf("Escolha a funcao que deseja executar\n1-Criar Arvore\n2-Inserir na arvore\n3-Buscar na Arvore\n4-Contar Elementos\n5-Remover Elemento\n6-Imprimir\n7-Sair\n");
		scanf("%d", &op);
		if(op == 2){
			printf("Qual numero deseja inserir: ");
			scanf("%d", &num);
			ARV no = criarNovoNo(num);
			r = adiciona(r, no);
		} else if (op == 1){
			printf("Arvore Criada\n");
		} else if(op == 3){
			printf("Qual numero deseja procurar: ");
			scanf("%d", &num);
			ARV p = buscaArv(r, num);
		} else if(op == 4){
			printf("A arvore r tem %d elementos\n", contagemEle(r));
		} else if(op == 5){
			printf("Qual numero deseja remover: ");
			scanf("%d", &num);
			r = remover(r, num);
		} else if(op == 6){
			imprimirArv(r);
		}
	}
	return 0;
}
