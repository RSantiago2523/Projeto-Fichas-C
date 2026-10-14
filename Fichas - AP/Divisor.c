# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void divisor(int n)
{
	int i;
	for(i=1;i<=n/2;i++)
		if(n%i==0)
			printf("%d é divisor\n",i);
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
	
	int num1;
	
	printf("\n\nIntroduza um número inteiro:");
	scanf("%d",&num1);
	
	divisor(num1);
}
