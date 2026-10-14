# include <stdio.h>
# include <locale.h>

void main ()
{
	setlocale(LC_ALL,"Portuguese");
	printf("OLÁ MUNDO!");
	
	char car;
	printf("\nIntroduza um caractere:\n");
	scanf("%c", &car);
	
    if(car>='A' && car<='Z')
	printf("Maiúscula");

	else
	
	if(car>='a' && car<='z')
	printf("minúscula");
	
	else
	
	if(car>='0' && car<='9')
	printf("dígito");
	
	else
	
	if(car ==',')
	printf("caracter de pontuação");
	
	else
	
	if(car =='.')
	printf("outro caracter");
}
