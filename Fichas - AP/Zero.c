# include <stdio.h>
# include <locale.h>

void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int n;
	
	printf("Escreva um numero inteiro positivo: ");
	scanf("%d", &n);
	if (n!=0)
		printf("%d não é zero!\n",n);
	else
		printf("%d é zero!\n",n);
}
