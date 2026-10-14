# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // bilioteca para o Português

void main ()
/*{

	setlocale (LC_ALL,"Portuguese");
	printf("Olá malta!");

	int N,soma,i;
	
	do
	{
		printf("\nIntroduza:");
		scanf("%d",&N);
	}while(N<=0);
	
	soma=0;
	for(i=1;i<=N;i++)
	{
	soma=soma + i;
	printf("\nIteração %d,soma=%d\n",i,soma);
	}

	printf("\n\nValor final soma=%d",soma);
}*/


/*
int i,fat,soma;

soma=0;

fat=1;

for(i=1;i<=5;i++)
{
	fat=fat*i;
	soma=soma + fat;
	printf("\nfat=%d, soma=%d", fat,soma);
}

printf("\nsoma=%d",soma);
*/

/*
int exp,i;
float base,pot;
printf("Introduza a base");
scanf("%f",&base);
do
{
	printf("\nIntroduza o expoente");
	scanf("%d",&exp);
}while(exp<0);

pot=1;
for(i=1; i<=exp; i++)
{
pot=pot*base;
printf("\n%.2f^%d=%.2f",base,exp,pot);
}*/

// Exercício 12
/*
int n,i;
float x,soma;

do
{
	printf("\nIntroduza o nº elementos que pretende efetuar a média");
	scanf("%d", &n);
}while (n<=0);

soma=0.0;
for (i=1; i<=n;i++)
{
	printf("\nValor:");
	scanf("%f",&x);
	
soma=soma + x;}

printf("\nMédia=%.2f",soma/n);*/

// Exercício 1
/*
int n,i,x;

do{
	printf("\nIntroduza o valor da tabuada:");
	scanf("%d",&n);
  } while (n<=0);
  
 printf("\nTabuada de %d até quanto:",n);
 scanf("%d",&x);
 
 for (i=1;i<=x;i++)
 {printf("\n\t%d x %d = %d",n,i,n*i);}*/
 /*
 int i,j;
 char car;
 
 for(i=2;i<=10; i++){
	printf("\nTabuada do %d:",i);
 	
	 for(j=1;j<=10;j++)
		printf("%d x %d = %d",i,j,i*j);
	
	printf("\nPrima uma tecla:");
	scanf("%c",&car);
}



*/
/*
int i,pot,fat,N;
float soma;

printf("Qual o número");
scanf("%d",&N);
soma=0;
fat=1;
pot=1;
for(i=1;i<=N;i++)
{
	pot=pot*2;
	fat=fat*i;
	soma=soma+pot*1.0/fat;
	printf("\nPotência=%d, Fatorial=%d, Soma=%.2f",pot,fat,soma);
}*/

// Exercício 8
/*
{
int N,i,j;
do
{
	printf("\nIntroduza o número de ramos (linhas):");
	scanf("%d",&N);
}while(N<1);

for(i=1;i<=N;i++) // ramos linhas
{
	for(j=1;j<=N-i;j++) // espaços em branco
		printf("%c",' ');

	for (j=1;j<=i;j++) // asteriscos
		printf("%c",'*');
	printf("\n");
}

}
*/

/*
int N,i,j;
do
{
	printf("\nIntroduza o número de ramos (Linhas):");
	scanf("%d",&N);
}while(N<1 || N>10);

for(i=1;i<=N;i++) // ramos linhas
{
	for(j=1;j<=N-i;j++) // espaços em branco
		printf("%c",' ');
	
	for(j=1;j<=i;j++)
	printf("%d",j);
	
	for(j=i-1;j>=1;j--)
	printf("%d",j);
	
	printf("\n");	
}*/

// Exercício 13 e 14
/*
int n,p,tent;

tent=0;

do{
	printf("\nIntroduza um número entre 0 e 100:");
	scanf("%d",&n);
}while(n<0 || n>100);

	system("CLS");
do{
	printf("\nQual o número que o Jogador 2 pensa que é:");
	scanf("%d",&p);
	
	if(p>n)
	
		printf("\nO número que o Jogador 2 escolheu é maior que o do Jogador 1");
		
		else
		
			if(p<n)
		
				printf("\nO número que o Jogador 2 escolheu é menor que o do Jogador 1");
				
					else{
						if(p=n)
							printf("\nAcertou");
						}
						
						tent++;
	}while(n!=p);
						
   printf("\nTentou %dx",tent);
*/
						
						
						






