# include <stdio.h>
# include <locale.h>

void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	printf("Olá, seja muito bem vindo!");
	
	float dinheiro,preco,troco;
	int quantidade;
	
	printf("\nIntroduza o dinheiro:\n");
	scanf("%f",&dinheiro);
	
	printf("\nIntroduza o preço:\n");
	scanf("%f",&preco);
	
	quantidade=dinheiro/preco;
	troco=dinheiro-preco*quantidade;
	
	printf("Quantidade=%d\n",quantidade);
	printf("Troco=%.2f",troco);
}
