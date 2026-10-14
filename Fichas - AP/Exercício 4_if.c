# include <stdio.h>   //biblioteca com funçoes de entrada/saida(obrigatorio)
# include <locale.h>  //biblioteca para escrever Português(opcional)

void main()

{
	float valor, conversao;
	int opcao;
	setlocale(LC_ALL,"Portuguese");
	
	printf("Introduza em que unidade quer introduzir um valor para converter 1-cm, 2-kg, 3- L, 4- ºC\n");
	scanf("%d", &opcao);
	if (opcao == 1)
	{
		printf("Introduza o valor em centímetros que quer converter para polegadas\n");
		scanf("%f", &valor);
		conversao = valor/2.54;
		printf("%f centímetros convertido em polegadas é %f", valor, conversao);
	}
	else
		if (opcao == 2)
		{ 
			printf("Introduza o valor em quilos que quer converter para libras\n");
			scanf("%f", &valor);
			conversao = valor/0.4536;
			printf("%f quilos convertido em libras é %f", valor, conversao);
		}	
		else
			if (opcao == 3)
			{		
				printf("Introduza o valor em litros que quer converter para galões\n");
				scanf("%f", &valor);
				conversao = valor/2.785;
				printf("%f litros convertido em libras é %f", valor, conversao);
			}		
			else
				if (opcao == 4)
				{
					printf("Introduza o valor em graus celsius que quer converter para graus Fahrenheit\n");
					scanf("%f", &valor);
					conversao = valor*1.8+32;
					printf("%f graus celsius convertido em graus Fahrenheit é %f", valor, conversao);
				}
}
