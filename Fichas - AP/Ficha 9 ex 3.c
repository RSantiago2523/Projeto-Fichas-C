# include <stdio.h> // biblioteca para a entrada e saída de dados

long tamanho(FILE * file)
{
	long size;
	
	size=ftell(file); // indica a posição em bytes
	printf("Posicao Inicial: %ld",size);
	
	fseek(file,0,SEEK_END);	// envia para o fim o ficheiro
	size=ftell(file);	// indica a posição em bytes
	
	return size;
}

int main()
{	
	char nome[30];
	FILE * f;
	
	printf("\nNome do Ficheiro: ");
	fseek(stdin,0,2);	// limpar o buffer de entrada (teclado) - faz o mesmo que o fflush(stdin)
	gets(nome);
	
	f=fopen(nome,"r"); // abre para a leitura
	
	if(f==NULL)
		fprintf(stderr,"\nProblemas na abertura do ficheiro");
	else
	{
		printf("\nTamanho do ficheiro (em bytes): %d",tamanho(f));
	}
}

