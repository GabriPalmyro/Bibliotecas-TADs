#include<stdio.h>
#include<stdlib.h>



int main(void)
{
	Fila f1;
	
	int c, e;
	int op;
	
	
	f1 = criar_fila;
	
	
	
	do{
	
	printf("Digite\n1-para inserir na lista\n2-para remover da lista\n3 para imprimir a lista\n4-para sair\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("Digite o numero a ser inserido:\n");
			scanf(" %d",&c);
			if(push(c,&l1))
				printf("Sucesso\n")	;
			else
				printf("Overflow de memória\n");
			break;
		case 2:
			printf("O numero do inicio sera removido!\n");
			e = removerInt(&l1);
			printf("O elemento removido foi %d\n", e);
			break;
				
		case 3:
			imprimir(&l1);
			break;
		
			
		
	}
	}while(op!=4);
	
}

