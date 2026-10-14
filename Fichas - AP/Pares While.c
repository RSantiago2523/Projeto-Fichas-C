# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main ()

{
	setlocale(LC_ALL,"Portuguese");
	printf("Olá a todos!");
	
	int x;
	
	printf("\nIntroduza um inteiro");
	scanf("%d", &x);
	
	while(x>=0)
	{		
		if(x%2 == 0);
			printf("par",x);
		
		printf("\nIntroduza um inteiro");
		scanf("%d", &x);
	}
}
