# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português

// Função para calcular um somatório // iterativa
float somatorio(int n, float base)
{
	int i;
	
	float termo=1.0;
	float soma=0.0;
	
	for(i=1;i<=n;i++)
	{
		termo=termo*base/i; // termo=termo*r/i
		soma=soma+termo;	// soma=soma+termo
	}
	
	return soma;
}

// Função para calcular o somatorio de forma recursiva
float somatorio_rec(int i,int n,float base,float termo)
{
	if(i==n) // criterio paragem
		return termo;
	else
		return termo + somatorio_rec(i+1,n,base,termo*base/(i+1));
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");

	float r;
	int n;
	
	printf("\nIntroduza a base da potência: ");
	scanf("%f",&r);
	
	do
	{
		printf("\nIntroduza o limite superior do somatório: ");
		scanf("%d",&n);
	}while(n<1);
	
	printf("\n Versão Iterativa -> Somatório= %.2f",somatorio(n,r));
	printf("\n Versão Recursiva -> Somatório= %.2f",somatorio_rec(1,n,r,r/1));
}
