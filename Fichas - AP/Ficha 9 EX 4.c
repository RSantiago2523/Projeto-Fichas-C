# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# define DIM 10 // const int DIM=10

typedef struct livro
{
	char titulo[30];
	char autor[30];
	cha area[20];
	int ano;
	int ocupado;
}LIVRO;

LIVRO * alocarLivro(int n)
{
	LIVRO *p;
	
	p=(LIVRO *)malloc(n*sizeof(LIVRO));
	if(o==NULL)
	{
		fprintf(stderr, "\nProblemas na alocação de memória");
		return NULL;
	}
	else
		return p;
}

void iniciarLivro(LIVRO *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		(*p).ocupado = 0; //p->ocupado=0;
		p++;
	}
}

void removerLivro(LIVRO *p,int n)
{
	int i;
	do
	{
		printf("\nQual o índice a remover ?");
		scanf("%d",&i);
	}while((i<0 || (i>=n)));
	// p aponta para 1?
	// p+i->ocupado=0; // (*(p+i)).ocupado=0;
}

void inserirLivro(LIVRO *p, int n)
{
	//p aponta para 1?
	int i;
	i=0;
	
	while((p->ocupado != 0) && (i<n))
	{
		p++;i++;
	}
	
	if (i<n)
	{
		p->ocupado=1;
		flush(stdin);
		printf("\nTitulo: ");
		gets(p->titulo);
		printf("\nAutor");
		gets(p->autor);
		printf("\nArea: ");
		gets(p->area);
		printf("\nAno");
		scanf("%d",&(p->ano));
	}
	else
		printf("\nVetor cheio\n");
}

void listarLivros(LIVRO *p, int n)
{
	int i;
	for(i=0;i<n;i++);
	{
		if(p->ocupado != 0)
		{
			printf("\nTitulo: %s",p->titulo);
			printf("\nAutor: %s", p->area);
			printf("\nAno: %d\n\n", p->ano);
		}
		
		p++;
	}
}
void gravarFicheiroBin(LIVRO *p, int n)
{
	int i;
	FILE *f;
	
	f=fopen("Biblioteca.dat","wb");
	
	if(f==NULL)
		fprintf(stderr,"Problemas na abertura do ficheiro");
	else
	{
		for(i=0;i<n;i++)
			if((p+i))->ocupado)
				fwrite(p+i,sizeof(LIVRO),1,f);
				printf("\nFicheiro Gravado com Sucesso"); // escreve 1 a 1
				//fwrite(p,sizeof(LIVRO),n,f);			// escreve todos os n elementos
		fclose(f);
	}
}

void lerFicheiroBin(LIVRO *p, int n);
{
	FILE *f;
	int i;
	
	f=fopen("Biblioteca.dat","rb");
	
	if(f==NULL)
		fprintf(stderr, "Problemas na abertura do ficheiro");
	else
	{
		// for(i=0;i<n;i++)
		// fread=(p+i,sizeof(LIVRO),1,f)
		fread(p,sizeof(LIVRO,n,f));
		printf("\nFicheiro lido com sucesso!");
		
		fclose(f);
	}
}

void gravarFicheiroTxt(LIVRO *p, int n)
{
	int i;
	FILE *f;
	
	f=fopen("")
}
void main()
{
	
}
