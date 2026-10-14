# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português

// EX 1

/*
int somatorio()
{
	int i,soma=0,n;
	for(i=1;i<=n;i++)
		soma+=i;		// soma=soma+i
	return soma;
}

// Função recursiva
int somatorio_r1(int i)
{
	if (i==1)	// criterio paragem
 		return 1;
 	else
 		return i+somatorio_r1(i-1);
}

int somatorio_r2(int i,int n)
{	
	if(i==n)
		return n;
	else
		return i+somatorio_r2(i+1,n)
}

void main()
{
 	setlocale(LC_ALL,"Portuguese");
 	int n;
 	
 	do
 	{
 		printf("\nLimite superior do somatorio: ");
 		scanf("%d",&n);
 	}while(n<1);
 	
 	printf("\nSomatório= %d",somatorio(n));
 	printf("\nSomatório (recursiva): %d",somatorio_r1(n));
 	printf("\nSomatório (recursiva): %d",somatorio_r2(1,n);
}
*/

// Exercício 2

/*
// Função não recursiva
int fatorial(int n)
{
	int i,prod=1;
	for(i=1;i<=n;i++)
		prod=prod*i;
	return prod;
}

int fatorial_r1(int i)
{
	if(i==1) // criterio paragem da recursividade
		return 1;
	else
		return i*fatorial_r1(i-1);
}

int factorial_r2(int i,int n)
{
	if(i==n)
		return n;
	else
		return i*factorial_r2(i+1,n);
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int n;
	
	do
	{
		printf("\nNúmero que pretende calcular o fatorial: ");
		scanf("%d",&n);
	}while(n<0);
	
	printf("\nNão Recursivo->%d! = %d",n,fatorial(n));
	printf("\nRecursivo->%d = %d!",n,fatorial_r1(n));
	printf("\nRecursivo->%d = %d!",n,factorial_r2(1,n));
}
*/

// Exercício 3

// Função Não-Recursiva
float potencia(float x,int n)
{
	int i,prod=1;
	for(i=1;i<=n;i++)
		prod=prod*x;
	return prod;
}
// Função Recursiva //1
float potencia_r1(float x,int i)
{
	if(i==1)
		return x;
	else
		return x*potencia_r1(x,i-1);
}

// Função Recursiva //2
float potencia_r2(float x,int i,int n)
{
	if(i==n)
		return x;
	else
		return x*potencia_r2(x,i+1,n);
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");

	setlocale(LC_ALL,"Portuguese");
	int n;
	float x;

	printf("\nBase da Potência: ");
	scanf("%f",&x);

	do
	{
		printf("\nExpoente: ");
		scanf("%d",&n);
	}while(n<=0);
	
printf("\nNão Recursivo -> %.2f^%d =%.2f",x,n,potencia(x,n));
printf("\nRecursivo (forma 1)-> %.2f^%d= %.2f",x,n,potencia_r1(x,n));
printf("\nRecursivo (forma 2)-> %.2f^%d= %.2f",x,n,potencia_r2(x,1,n));
}


