# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main ()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo, caro utilizador");
	
	float num1;
	
	printf("\nIntroduza o número:");
	scanf("%f",&num1);
	
	if (num1<0)
		printf("O número é negativo.");
			

	if(num1>0)
		printf("O número é positivo");
	
			
	if(num1==0)
		printf("O número é nulo");
}
