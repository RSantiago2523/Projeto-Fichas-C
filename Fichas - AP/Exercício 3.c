# include <stdio.h> // biblioteca para a entrada e saída de dados (obrigatório)
# include <locale.h> // biblioteca para a gramática de Português (opcional)

void main()

{ 

	setlocale(LC_ALL,"Portuguese");
	
	printf("Olá a todos!");
	
	int num1,num2,num3,maior; // declaração de variáveis do tipo inteiro
	
	printf("Escerva 3 números inteiros:\n");
	scanf("%d %d %d",&num1,&num2,&num3);
	
	if (num1>num2) // define maior entre num1 e num2
	maior=num1;
	
	else
	maior=num2;
	
	if(num3>maior)
	maior=num3;
	
	printf("Maior=%d",maior);
}
