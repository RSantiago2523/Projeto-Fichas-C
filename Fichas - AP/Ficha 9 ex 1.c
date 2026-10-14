# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português
# include <string.h>
#define DIM 100

void escreverFicheiro()
{
	FILE *f;
	char str[DIM];
	
	f=fopen("strings.txt","w");
	
	if(f==NULL)
	{
		printf("Problema na abertura do ficheiro!");
		return;
	}
	else // não há problemas na abertura do ficheiro
	{
		do
		{
			if(strcmp(str,".")) // se as strings str e "." forem diferentes
			{
				printf("\nIntroduza uma string: ");
				fflush(stdin);
				gets(str);
				
				//fprintf(f,"%s",str);
				fputs(str,f); // escreve uma string no ficheiro
				fputc('\n',f); // escreve o caracter '\n' no ficheiro
			}
				
		}while(strcmp(str,".")); // verdadeiro (diferente de 0) quando str e "." são diferentes
		
		fclose(f);
	}
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	escreverFicheiro();
}
