# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // bilioteca para o Português

void main()

{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
	
	printf("\nTamanho de bytes short:%d\n", sizeof(short));
}
