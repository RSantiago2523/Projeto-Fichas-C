# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main ()
{
	setlocale(LC_ALL,"Portuguese");
	printf("Bem-Vindo");
	
	float area,per,base,altura,lado,raio;
	int fig;
	
	printf("\nEscolha a figura geométrica, 1-Retângulo, 2-Quadrado, 3-Círculo:");
	scanf("%d",&fig);
	
	if(fig == 1)
	{	
		printf("\nBase:");
		scanf("%f",&base);
		
		printf("\nAltura:");
		scanf("%f",&altura);
		
		area = base*altura;
		per = 2*base + 2*altura;
		
		printf("Perímetro=%.2f",per);
		printf("\nÁrea=%.2f",area);
	}
	else
	
		if(fig == 2)
		{
			printf("\nLado:");
			scanf("%f",&lado);
		
			area = lado*lado;
			per = 4*lado;
		
			printf("Perímetro=%.2f",per);
			printf("\nÁrea=%.2f",area);
		}
		else
			
			if(fig == 3)
			{
				printf("\nRaio:");
				scanf("%f",&raio);
				
				area = raio*raio;
				per = 2*raio;
				
				printf("Perímetro=%.2fPI",per);
				printf("Área=%.2fPI",area);
			}
}
