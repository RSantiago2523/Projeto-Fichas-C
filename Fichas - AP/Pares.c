# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main ()

{
	setlocale(LC_ALL,"Portuguese");
	printf("Boas-Vindas");
	
	int n,i;
	
	for(i=1;i<=10;i++)
	{
	printf("\nIntroduza um inteiro:\n");
	scanf("%d",&n);
	
	if(n%2 == 0)
		printf("%d é par!",n);
	else
		printf("%d não é par",n);
	}
}
