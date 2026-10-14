# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# include <malloc.h> // Alocação dinâmica da memória
// # define DIM 20 // const int DIM=20;

// Exercício Particular
/*
int * alocarVetor(int n)
{
	int *ptr;
	
	ptr=(int *) malloc(n*sizeof(int));
	
	if(ptr==NULL)
	{
		printf("Problemas na alocação de memória");
		return NULL;
	}
	
	else
		return ptr;
}

void main()
{
	setlocale(LC_ALL,"Portuguese"); // Português
	
	int dim,*p;
	
	printf("Introduza a dimensão do vetor");
	scanf("%d",&dim);
	
	p=alocarVetor(dim);
	
	free(p);
}
*/

// Ficha 8 ex 1
/*
typedef int tipo_dados; // definição do tipo de dados (int)

int * alocarMatriz()
{
	int *ptr,nl,nc;
	
	ptr=(int*)malloc(nl*nc*sizeof(int));
	
	if(ptr==NULL)
	{
		printf("Problemas na alocação de memória");
		return NULL;
	}
		else
			return ptr;
}

void lerMatriz(int nl,int nc,int*M)
{
	int i,j;
	for(i=0;i<nl;i++)
		for(j=0;j<nc;j++)
		{
			printf("\nA[%d][%d]=",i,j); // i-linha; j-coluna;
			scanf("%d",M);
			M++;
			// scanf("%d,M+i*nc+j);
		}
}

void escreverMatriz(int nl,int nc,int *M)
{
	int i,j;
	for(i=0;i<nl;i++)
		for(j=0;j<nc;j++)
	{
		printf("\nA[%d][%d]=%d",i,j,*M);
		M++;
	}
}

int simetrica(int n,int*M)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++);
			if(*(M+i*n+j) != *(M+j*n+i))
				return 0;
	
	return 1;
}

int traco(int n, int *M)
{
	int i,j,soma=0;
	for(i=0;i<n;i++)
		soma+=*(M+i*n+i);
	return soma;
}

void main()
{
	setlocale(LC_ALL,"Portuguese");

	int nl,nc,*A;

	do
	{
		printf("\nIntroduza o número de linhas da matriz: ");
		scanf("%d",&nl);
	}while(nl<1);
	
	do
	{
		printf("\n Introduza o número de colunas da matriz");
		scanf("%d",&nc);
	}while(nc<1);
	
	A=alocarMatriz(nl,nc);
	lerMatriz(nl,nc,A);
	escreverMatriz(nl,nc,A);
	
	if(nl==nc)
	{
		if(simetrica(nl,A))
			printf("\n A é simétrica!");
		else
			printf("\n A não é simétrica");
			
	printf("\nTraço: %d",traco(nl,A));
	}
	else
		printf("\n A não é quadrada");
	
	free(A);
}*/

// Ficha 7 ex 4

/*
typedef struct LIVRO
{
	char titulo[30];
	char autor[30];
	char area[20];
	int ano;
	int posOcup; // indica se a posição no vetor está ocupada (=1) ou não (=0)
}LIVRO;

void iniciarBiblioteca(LIVRO *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		(p+i)->posOcup=0; // inicializar as posições ocupadas a vetor a zero
}

void inserirLivro(LIVRO *p, int n)
{// insere a informação correspondente a um livro
	int i,encontra=0;
	
	for(i=0;i<n;i++)
		if((p+i)->posOcup==0)
		{
			printf("\nTítulo do livro: ");
			fflush(stdin);
			gets((p+i)->titulo);
			
			printf("\nAutor: ");
			fflush(stdin);
			gets((p+i)->autor);
			
			printf("\nÁrea: ");
			fflush(stdin);
			gets((p+i)->area);
			
			printf("\nAno: ");
			scanf("%d",&(p+i)->ano);
			
			(p+i)->posOcup=1;
			encontra=1;
		}
	
	if(encontra==0)
		printf("Toda a Biblioteca Ocupada");
}

void listarLivro(LIVRO *p,int n)
{// mostra a informação correspondente aos livros
	int i;

	for(i=0;i<n;i++)
		if((p+i)->posOcup)   //((p+i)->posOcup)==1)
			printf("\nTítulo do livro: %s \nAutor: %s \nÁrea: %s \nAno: %d \n",(p+i)->titulo,(p+i)->autor,(p+i)->area,(p+i)->ano);
}

void removerLivro(LIVRO *p, int n)
{// remover livro
	int i,encontra=0;
	
	printf("\Índice do Livro: ");
	scanf("%d",&i);
	
	if((p+i)->posOcup)
	{
		(p+i)->posOcup=0;
		printf("Livro Removido com sucesso !");
	}
}
void main()
{
	setlocale(LC_ALL,"Portuguese");
	
	//alocação estática
	LIVRO biblioteca[DIM]; // vetor de livros - cada elemento é uma estrutura LIVRO
	
	int opcao,tam;
	
	do
	{
		printf("\nIntroduza o número máximo de livros da biblioteca (<=20): ");
		scanf("%d",&tam);
	}while(tam<=0 || tam>DIM);
	
	// MENU
	do
	{
		printf("\n\n*****MENU*****");
		printf("\n\t1:Inserir livro \n\t2:Listar Livros \n\t3:Remover Livro \n\t4:Sair\n");
			printf("***************\n");
		scanf("%d",&opcao);
	
		switch(opcao)
		{
			case 1: inserirLivro(biblioteca,tam);break;
			case 2: listarLivro(biblioteca,tam); break;
			case 3: removerLivro(biblioteca,tam);break;
			case 4: break;
			default:printf("Opção Inválida!");
		}	
	}while(opcao!=4);
}
*/

// Ficha 8 ex 3

typedef struct lista
{
	char nome[15];
	int votos,mandatos;
}LISTA;

LISTA*alocarListas(int n_listas)
{
	LISTA * p;
	
	p=(LISTA *) malloc (n_listas*sizeof(LISTA));
	
	if(p==NULL)
	{
		fprintf(stderr, "Problemas na alocação de memória");
		return NULL;
	}
	else
	{
		return p;
	}
}

int maximoQuoc(int *q,LISTA *p,int n_lugares)
{
	int i,ind=0;
	
	for(i=1;i<n_lugares;i++)
	{
		if( (q[i]>q[ind]) || (q[i]==q[ind] && (p+i)->mandatos<(p+ind)->mandatos))
		{ind=i;}
	}
	return ind;
}
// Método Hondt
void metodoHondt(LISTA *p, int n_listas, int n_lugares)
{
	int lugares_atrib=0,i,ind_lista;
	int * quoc=(int *)malloc(n_listas*sizeof(int));
	
	for(i=0;i<n_listas;i++) // inicialização dos quocientes (=numero de votos)
		*(quoc+i)=(p+i)->votos;
		
	while(lugares_atrib<n_lugares)
	{
		ind_lista=maximoQuoc(quoc,p,n_listas); // indice da lista com o maior quociente
		
		lugares_atrib++;
		
		(p+ind_lista)->mandatos++;
		
		printf("\nMandato atribuído à lista: %s com quociente %d",(p+ind_lista)->nome,*(quoc+ind_lista));
		
		*(quoc+ind_lista)=(p+ind_lista)->votos/((p+ind_lista)->mandatos+1);
	}
	
}
void adicionarListas(LISTA *p,int n_listas)
{
	int i;
	for(i=0;i<n_listas;i++)
	{
		printf("\nLista %d",i+1);
		printf("\n\tNome: ");
		fflush(stdin);
		gets((p+i)->nome); // (p+i) aponta para o primeiro e para o próximo (i++)// (p+i)->nome equivale a *(p+i).nome
		
		printf("\nNúmero de Votos: ");
		scanf("%d",&(p+i)->votos);
		
		(p+i)->mandatos=0;
	}
}
void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
	
	int nc,nl;
	
	do
	{
		printf("\nNúmero de listas (partidos): ");
		scanf("%d",&nc);
	}while(nc<1);
	
	do
	{
		printf("\nNúmero de lugares:");
		scanf("%d",&nl);
	}while(nl<1);
	
	LISTA*listas;
	listas=alocarListas(nc);
	adicionarListas(listas,nl);
	metodoHondt(listas,nc,nl);
}
