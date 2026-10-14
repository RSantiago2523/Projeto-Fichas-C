# include <stdio.h>
# include <locale.h>
# include <math.h>
# define DIM 20
// Exercício 1

typedef struct coord
{
	float x,y;
}coord;

void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	coord p1,p2;
	float area,diagonal,diagonal1;
	
	printf("\n Introduza as coordenadas do 1ºPonto");
	scanf("%f %f",&p1.x,&p1.y);
	
	printf("\n Introduza as coordenadas do 2º Ponto(abcissa ordenada)");
	scanf("%f %f",&p2.x,&p2.y);
	
	area=(p2.x-p1.x)*(p1.y-p2.y);
	diagonal=sqrt((p2.x-p1.x))*(p2.x-p1.x)+(p1.y-p2.y)*(p1.y-p2.y);
	diagonal1=sqrt(pow(p2.x-p1.x,2.0)+pow(p1.y-p2.y,2.0));
	
	printf("\nÁrea=%.2f; Diagonal=%.2f",area,diagonal1);
}

// Exercício 3
/*
typedef struct Alunos
{
	int numero;
	char nome[10];
	float nota;	
}Alunos;

void inserirAlunos(Alunos v[],int n)
{
	int i;
	printf("\nIntroduza a informação sobre os alunos");
	for(i=0;i<n;i++)
	{
		printf("Aluno: %d",i+1);
		printf("\n\t Número:");
		scanf("%d",&v[i].numero);
		
		printf("\n\t Nome: ");
		fflush(stdin);
		gets(v[i].nome);
		
		printf("\n\t Nota: ");
		fflush(stdin);
		scanf("%f",&v[i].nota);
	}
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	Alunos v[DIM];
	int tam;
	
do{
	printf("\nIntroduza o número de alunos");
	scanf("%d",&tam);
}while (tam<0 || tam>DIM);

inserirAlunos(v,tam);
}

// Exercicio 3
/*
void concatenar(char*str1,char*str2)
{
	while(*str1 != '\0')  // apontar para os restantes elementos da string s1
		str1++;
		
	while(*str2 != '\0')
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	
	*str1='\0'; // adinciona o caracter terminador à string s1
}
void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	char str1[20], str2[10];
	
	
	printf("Introduza uma string: ");
	fflush(stdin);
	gets(str1);
	
	printf("\n Introduza outra string: ");
	fflush(stdin);
	gets(str2);
	
	concatenar(str1,str2);
	printf("%s",str1);
}
*/

//Exercício 5
/*
void lerVetor(int *v,int n)
{// le o vetor
	int i;
	printf("\nIntroduza os elementos do vetor\n\n");
	for(i=0;i<n;i++)
	{
		printf("\n\tElemento na posição %d",i+1);
		scanf("%d",v+i);
	}
}

void escreverVetor(int *v,int n)
{// Escreve o vetor
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n\tv[%d]=%d",i,*(v+i)); // sem o asterisco indica as referências de memória
	}
}

int maximo(int *v,int n)
{// Determina o maior elemento do vetor
	int i,max;
	max=*v; //v[0]
	for(i=1;i<n;i++)
	{
		if(*(v+i)>max) //if (v[i]>max)
		max=*(v+i);
	}
	return max;
}

void escreverVetorOrdemInversa(int *v, int n)
{// Escreva o vetor por ordem inversa
	int i;
	//v=v+n-1;
	for(i=n-1;i>=0; i--)
	{
		printf("\n\tv[%d]=%d",i,*(v+i)); 
	}
}

int somaVetor(int*v,int n)
{// Determina a soma dos componentes do vetor
	int i,soma;
	soma=0;
	for(i=0;i<n;i++)
	{
		//soma+=*v
		//v++
		soma+=*(v+i);
	}
	
	return soma;
}

float mediaVetor(int *v, int n)
{// Determina a média do vetor (vamos usar a função soma implementada)
	
	int i,soma=0;
	for(i=0;i<n;i++)
	{
		soma+=*(v+i);
	}	
	return soma*1.0/n;
}

int infSupMediaVetor(int *v, int n, int *inf)
{// O número de elementos inferiores sai por referência (dai usarmos ponteiros)
// O número de elementos superiores sai pelo return

	int i,sup=0;
	*inf=0;
	float media=mediaVetor(v,n);
	
	for(i=0;i<n;i++)
		if(*(v+i)>media)
			sup++;
		else
		
		if(*(v+i)<media)
			(*inf)++;
	return sup;
	
}

void copia (int*v,int*copia,int n)
{// Copia o Vetor
	int i;
	for(i=0;i<n;i++)
	{
		*(copia+i)=*(v+i);
		// *copia=*v;
		// v++;
		// copia++;
	}
}

void intercalarVetores (int *v, int*copia, int*res, int n)
{// copia o vetor
	int i;
	copia=copia+n-1; // aponta para o ultimo elemento do vetor
	for(i=0;i<n;i++)
	{
		*res=*v;
		res++;
		v++;
		*res=*copia;
		res++;
		copia--;
		// v++;
		// copia++;
	}
}

void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int v[DIM],copia[DIM],n;
	
	do
	{
		printf("\nIntroduza o número de elementos do vetor(máximo 20): ");
		scanf("%d",&n);
	} while(n<1 || n>DIM);
	
	lerVetor(v,n);
	escreverVetor(v,n);
	escreverVetorOrdemInversa(v,n);
	intercalarVetores(v,copia,res,n);
	printf("\nMaior elemento do vetor: %d",maximo(v,n));
	printf("\nSoma dos elementos do vetor: %d",somaVetor(v,n));
	printf("\nMédia dos elementos do vetor: %.2f",mediaVetor(v,n));

	int inferiores=0;

	printf("\nNº elementos superiores à média: %d", infSupMediaVetor(v,n,&inferiores));
	printf("\nNº elementos inferiores à média: %d", inferiores);
	
	copia(v,n);
	escreverVetor(copia,n);
}
*/



 
