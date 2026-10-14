# include <stdio.h>
# include <locale.h>

void main()

{
	setlocale(LC_ALL,"Portuguese");
	
	printf("OLÁ!");
	
	float base,altura,area;
	
	printf("\nIntroduza a base:\n");
	scanf("%f",&base);
	
	printf("\nIntroduza a altura:\n");
	scanf("%f",&altura);
	
	area = base*altura/2;
	
	printf("Área: %.2f.\n",area);
}
