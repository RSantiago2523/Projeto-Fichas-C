# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# define DIM 20
// Exercício 1 a)
/*
int isDigit(char c)
{
	return(c>='0' && c<='9');
}

void main ()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Good Morning");
	
	char c;
	printf("\nIntroduza um caracter:");
	scanf("%c",&c);
	
	if(isDigit(c))
		printf("\n%c É numérico");
	else
		printf("\n%c Não é numérico");
		
}*/

// Exercício 6 a)
/*
void main ()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Olá a todos!");
	
	int v[6]={1,0,2,4,5,7};
	int w[6]={1,0,2};
	
	printf("\nO elemento na posição %d do vetor v é %d",6,v[5]);
	printf("\nO elemento na posição %d do vetor w é %d",6,w[5]);
}*/


// Exercício 6 b)
/*
void lerVetor(int vetor [],int n)
{
	// lê um vetor
	int i;
	for (i=0;i<n;i++)
	{
		printf("\nElemento na posição %d",i+1);
		scanf("%d",&vetor[i]);
	}
}

void escreverVetor (int vetor[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{	printf("\nv[%d]=%d",i,vetor[i]);
	}
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Olá e Muito Bem-Vindo");
	
	int vetor [20],tam;
	
	do{
		printf("\nIntroduza o nº elementos do vetor (máximo 20)");
		scanf("%d",&tam);
	} while(tam<=0 || tam>DIM);
	
	lerVetor(vetor,tam);
	escreverVetor(vetor, tam);
}*/

// Exercício
/*
void main ()
{
	setlocale(LC_ALL,"Portuguese");
	
int x;

printf("Introduza um inteiro:");
scanf("%d",&x);
if(x%2==1)
	printf("É Ímpar");
else
if(x%2==0)
	printf("É Par");
}*/

// Exercício 6
/*
void lerVetor(int v[], int n)
{ // ler vetor
	int i;
	printf("\nIntroduza os elementos do vetor\n\n");
	for(i=0;i<n;i++) // i<=n-1
	{
		printf("\n\tElemento na posição %d:",i+1);
		scanf("%d",&v[i]);
	}
}/*
// b)
void escrevervetor( int v[],int n)
{//escrever o vetor
	int i;
	for(i=0;i<n;i++) // i<=n-1
	{
		printf("\n\tv[%d]=%d",i,v[i]);
	}
}*/
//c
/*
int posmaior(int v[],int n)
{// escrever o vetor
	int i,indice,maior=v[0];
	for(i=1;i<n;i++)
		if(v[i]>maior)
		{
			maior=v[i];
			indice=i;
		}
	return indice;
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor[DIM],tam,indice;
	
	do
	{
		printf("\nIntroduza o número de elementos do vetor (no máximo 20):");
		scanf("%d",&tam);
	}while(tam<1 || tam>DIM);
	
	lerVetor(vetor,tam);
	escrevervetor(vetor,tam);
	indice=posmaior(vetor,tam);
	printf("\nPosição do maior elemento é: %d valor é: %d",indice,vetor[indice]);
}*/
// Exercício 7

void lerVetor(int v[], int n)
{ // ler vetor
	int i;
	printf("\nIntroduza os elementos do vetor\n\n");
	for(i=0;i<n;i++) // i<=n-1
	{
		printf("\n\tElemento na posição %d:",i+1);
		scanf("%d",&v[i]);
	}
}

int prodInt(int v1[], int v2[], int n)
{// calcula o produto interno
	int i,soma=0;
	for(i=0;i<n;i++)
		soma=soma+v1[i]*v2[i];
		return soma;
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor1[DIM],vetor2[DIM],tam;
	
	do
	{
		printf("\nIntroduza o número de elementos dos vetores (no máximo 20)");
		scanf("%d",&tam);
	}while(tam<1 || tam>DIM);
	
	lerVetor(vetor1,tam);
	lerVetor(vetor2,tam);
	printf("\nProduto interno = %d",prodInt(vetor1,vetor2,tam));
}

// Exercício 8
/*
void trocarPos(int v[], int p, int q)
{// troca o valor de duas posições
	int aux;
	
	aux=v[p];
	v[p]=v[q];
	v[q]=aux;
}

void escreverVetor( int v[],int n)
{//escrever o vetor
	int i;
	for(i=0;i<n;i++) // i<=n-1
	{
		printf("\n\tv[%d]=%d",i,v[i]);
	}
}

void lerVetor(int v[], int n)
{ // ler vetor
	int i;
	printf("\nIntroduza os elementos do vetor\n\n");
	for(i=0;i<n;i++) // i<=n-1
	{
		printf("\n\tElemento na posição %d:",i+1);
		scanf("%d",&v[i]);
	}
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int vetor[DIM],tam,p,q;
	
	do
	{
		printf("\nIntroduza o nº de elementos do vetor (no máximo 20):");
		scanf("%d",&tam);
	}while(tam<1 || tam>DIM);
	
	lerVetor(vetor,tam);
	
	do
	{
		printf("\nIntroduza as posições a trocar:");
		scanf("%d%d",&p,&q);
	}while(p<1 || p>DIM || q<1 || q>DIM || p==q);
	
	trocarPos(vetor,p-1,q-1); // índice=posição-1
	escreverVetor(vetor,tam);
}*/

// Exercício 9 Matrizes
/*

void lerMatriz(int A[DIM][DIM], int n) // ou A[][DIM]
{// lê a matriz

	int i,j;
	for (i=0;i<n;i++) // linhas
	for(j=0;j<n;j++)  // colunas
	{
		printf("A[%d][%d]",i,j);
		scanf("%d",&A[i][j]);
	}
}


void escreverMatriz(int A[DIM][DIM], int n) // ou A[][DIM]
{// lê a matriz

	int i,j;
	for (i=0;i<n;i++) // linhas
		for(j=0;j<n;j++)  // colunas
		{
			printf("\nA[%d][%d]=%d\n",i,j,A[i][j]);
			}
}

int simetrica(int A[DIM][DIM],int n)
{
int i,j;
for(i=1;i<n;i++)
	for(j=0;j<i;j++)
		if(A[i][j]!=A[j][i])
			return 0;
return 1;
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	int matriz [DIM][DIM]; // alecação de memória estática
	int tam;
	
	do{
		printf("\nIntroduza o número de linhas da matriz quadrada (no máximo 20)");
		scanf("%d",&tam);
	}while(tam<1 || tam>DIM);
	
	lerMatriz(matriz,tam);
	escreverMatriz(matriz,tam);
	if(simetrica(matriz,tam))
		printf("\n\n A matriz é simétrica !");
	else
		printf("\n\n A matriz não é simétrica");
}*/
