# include <stdio.h>

void resposta(int x)
{
	if (x > 0)
		printf("Verdadeiro");
	else
		printf("Falso");
}

void main()
{
	int n;
	printf("Nº:");
	scanf("%d",&n);
	
	resposta (n);
}
