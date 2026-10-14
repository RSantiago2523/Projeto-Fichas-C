# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# include <malloc.h>
# include <stdlib.h>
# define DIM 10 // const int DIM=10;

typedef struct cadeira
{
	char nome[30];
	int paga; // =0 (não está paga); =1(está paga)
	int ocupada;  // =0 (não está reservada); =1 (está reservada)
}CADEIRA;

CADEIRA * alocarSala(int n_filas, int n_cad) // aloca dinamicamente memória para uma matriz 
{
	CADEIRA *p;
	p=(CADEIRA*)malloc(n_filas*n_cad*sizeof(CADEIRA));
	
	if(p==NULL)
	{
		fprintf(stderr,"Erro de Alocação de memória!");
		return NULL;
	}
	else
		return p;
}

void iniciarSala(CADEIRA *p,int n_filas,int n_cad)
{
	int i,j;
	for(i=0;i<n_filas;i++)
	{
		for(j=0;i<n_cad;j++)
		{
			p->nome[0]='\0';
			p->ocupada = 0;
			p->paga=0;
			p++;
		}
	}
}

void adicionarReserva(CADEIRA *p,int n_filas,int n_cad)
{
	int ind,fila,cadeira;
	char car;
			
	printf("\nFila a Reservar: ");
	scanf("%d",&fila);
			
	printf("\nCadeira a Reserva: ");
	scanf("%d",&cadeira);
			
	fila--;
	cadeira--;
			
		ind=fila*n_cad+cadeira;
		
		if((p+ind)->ocupada==0)
		{ // ocupada //=1 
			printf("Adicionar Reserva");
			printf("\n\tNome:\n");
			scanf("%s",(p+ind)->nome);
			
			do{
				printf("Reserva Paga? (S/N)");
				scanf("%c",&car);
			}while(car!='S' && car!='s' && car!='N' && car!='n');
			
			if(car=='s' || car=='S')
				(p+ind)->paga=1;
			else
				{
				(p+ind)->paga=0;
				}
	
			(p+ind)->ocupada=1;
			printf("Reservada com sucesso");		
		}
		
		else
			printf("\nLugar Ocupado");
}

void eliminarReserva(CADEIRA * p, int n_filas, int n_cad)
{	
	int fila,cadeira,ind;
	
	printf("\nEliminar Reserva: ");
	printf("\nFila:");
	scanf("%d",&fila);
	
	printf("\nCadeira: ");
	scanf("%d",&cadeira);
	
	fila--;
	cadeira--;
	
	ind=fila*n_cad+cadeira;
	if((p+ind)->ocupada==1)
	{
		(p+ind)->nome[0]='\0';
		(p+ind)->ocupada=0;
		(p+ind)->paga=0;
		printf("\nReserva eliminada com sucesso");
	}
}
void main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
	
	int nf,nc,opcao;
	
	// CADEIRA sala[DIM][DIM]; // Alocação estática de memória
	
	// Alocação dinâmica de memória
	do
	{
		printf("\nIntroduza o nº de filas: ");
		scanf("%d",&nf);
	}while(nf<0);
	
	do
	{
		printf("\nIntroduza o nº de cadeiras: ");
		scanf("%d",&nc);
	}while(nc<0);
	
	CADEIRA *sala;
	sala=alocarSala(nf,nc);
	iniciarSala(sala,nf,nc);
	
	//MENU
	
	
	do {
		printf("Menu");
		printf("\n\t1: Adicionar Reserva \nt2: Eliminar Reserva");
		printf("\n\t3: Listar Reserva \nt4 Mapa ocupação da sala" "\nt5 Sair\n");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:adicionarReserva(sala,nc,nf); break;
			case 2: eliminarReserva(sala,nc,nf); break;
			case 5:break;
			default:printf("Operação Inválida");
		}
	
	}while(opcao!=5);
} 

