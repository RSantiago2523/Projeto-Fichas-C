# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português
// Exercício 2 d)
/*
int primo(int n)
{
	int i;
	for(i=2;i<n/2;i++) // só é necessário ir até n/2
		if(n%i==0) // i é divisor de n - não é primo
			return 0;
	return 1; // não encontrou divisores
}

void main()
{	
	setlocale(LC_ALL,"Portuguese");
	int x;
	printf("\nIntroduza um inteiro:");
	scanf("%d",&x);
	
	if(primo(x))
		printf("\n%d é primo",x);
		else
		printf("\n%d não é primo",x);
}*/

// Exercício 3
/*
void classificarNumeros(int a, int b) // a<=b
{
	int num,soma,i,nreduzidos=0,nabundantes=0,nperfeitos=0;
	for(num=a;num<=b;num++);
	{
		soma=0; // calcula a soma dos divisores de num
		for(i=1;i<=num/2;i++)
		{
			if(num%i==0);
			soma+=i;
	
		if(soma<num)
		{
			printf("\n%d é reduzido",num);
			nreduzidos++;
		}
		else
		if(soma=num)
		{
			printf("\n%d é perfeito",num);
			nperfeitos++;
		}
		else
		if(soma>num)
		{
			printf("\n%d é abundante",num);
			nabundantes++;
		}
	}
	
	}
	
	printf("\nPerfeitos : %d",nperfeitos);
	printf("\nAbundantes: %d",nabundantes);
	printf("\nReduzidos: %d",nreduzidos);
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int num1,num2;
	do{
		printf("\nIntroduza dois inteiros:");
		scanf("%d%d",&num1,&num2);
	}while(num1>num2 || num1<1);
	classificarNumeros(num1,num2);
}*/

// Exercício 4
/*
int cuboNumero(int n)
{
	int cubo;
	cubo=n*n*n;
	return cubo;
}

int pedirNumero()
{	
	int num1;
	printf("Qual o número inteiro:");
	scanf("%d",&num1);
	return num1;
}
void main()
{
	int num1;
	setlocale(LC_ALL,"Portuguese");
	num1=pedirNumero ();
	printf("cubo=%d",cuboNumero(num1));
}
*/
// Exercício 5
/*
int maiornumero(int a, int b)
{
	if(a<b)
	{
		return b;
		//printf("O maior é %d",b);
	}
		else
			if(a>b)
			{
				return a;
				//printf("O maior é %d",a);
			}
				else
					if(a==b)
					{
						return a;
						//printf("São Iguais");
					}					
}
void main()
{
	int num1,num2;
	setlocale(LC_ALL,"Portuguese");
	printf("Insira dois números inteiros:");
	scanf("%d%d",&num1,&num2);
	printf("O maior é %d",maiornumero(num1,num2));
}
*/


