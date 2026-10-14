# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void pasParvalor(int n)
{
	n=150;
}
void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
/*	
	char nome1[6]={'M','a','r','i','a','\0'};
	// char nome[6];
	char nome2[6]="Maria";
	
	printf("\nTamanho: %d bytes",sizeof(nome1));
	printf("\nÚltimo caracter: %c",nome2[4]);
	printf("\nString nome1:%s",nome1);
	
	int i=0;
	while (nome2[i]!='\0')
	{
		printf("\n\t %c",nome1[i]);
		i++;
	}// introdução strings
}
*/
/*
char nome[20];
printf("\nIntroduza o nome:");
scanf("%s",&nome);
printf("Nome=%s",nome);

printf("\nIntroduza o nome:");
fflush(stdin);
gets(nome);
printf("Nome=%s",nome);
*/

// Algumas funções para o tratamento strings
/*
printf("\nVerifica se duas strings são iguais %d",strcmp(nome1,nome2));

strcpy(nome,"Maria"); // Função útil para inicializar strings
printf("Nome=%s",nome);
}*/
/*
int a=5;
int*ptr; // Declaração ponteiro
ptr=&a; // Inicialização ponteiro

printf("\nReferência memória de a = %d",ptr);
printf("\nValor da variável apontada pelo ponteiro = %d",*ptr);

a=35;
printf("\nValor de *ptr = %d",*ptr);

*ptr=50;
printf("\nValor da variável apontada pelo ponteiro = %d",a);

// Ponteiros e Vetores
int n=5;
int i=0;
int v[5]={1,7,9,3,2};
int *p; // declaração
p=v; // não é necessário colocar o & pois v é um vetor
printf("\n *p:%d",*p); // aponta para o 1º elemento do vetor

// p++; // avança sizeof(int)
//printf("\n *p: %d,*p);

printf("\n 4º Elemento do Vetor %d",v[3]);
printf("\n 4º Elemento do Vetor %d",p[3]);
printf("\n 4º Elemento do Vetor %d",*(p+3));
printf("\n 4º Elemento do Vetor %d",*(v+3));
*/
// Passagem parâmetros por valor e referência
int n=200;
pasParvalor(n);
printf("\nn=%d",n);
}
