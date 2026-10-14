# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# include <string.h>
# define DIM 100

void lerFicheiro()
{
	FILE *f;
	char str[DIM];
	
	f=fopen("strings.txt","r"); // abre o ficheiro de texto para escrita
	
	if (f=NULL)
	{
		printf("Problema na abertura do ficheiro!");
		return;
	}
	else // não há problemas na abertura do ficheiro
	{
		while(!feof(f))
		{
			if(fgets(str,DIM,f) != NULL) // lê uma string do ficheiro
				printf("%s",str);
		}	
		
		fclose(f);
	}
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	lerFicheiro();
}
