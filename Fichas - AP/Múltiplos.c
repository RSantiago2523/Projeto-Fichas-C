# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main ()

{
	setlocale(LC_ALL,"Portuguese");
	
	printf("Bem-Vindo");
	
	int a,b;
	
	printf("\nEscreva dois inteiros\n");
	scanf("%d%d", &a,&b);
	
	if (a%b == 0)
	printf("%d multiplo de %d", a,b);
	
	else
	
	if (b%a == 0)
	printf("%d multiplo de %d",b,a);
	
	else
	
	printf("%d e %d nao sao múltiplos um do outro",a,b);
}


