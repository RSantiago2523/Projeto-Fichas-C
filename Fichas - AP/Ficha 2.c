# include <stdio.h>
# include <locale.h>

void main()
/*{
// Exercício 5
	int min,horas,minutos;
	
	printf("Introduza os minutos:\n");
	scanf("%d",&min);
	
	horas = min/60;
	minutos = min%60;
	
	if (horas<=12)
		printf("%d:%da.m",horas,minutos);
	else
		printf("%d:%dp.m",horas-12,minutos);
}/*

// Exercício 8

	/*setlocale(LC_ALL,"Portuguese");
 float a,b,c,delta,raiz1,raiz2;
 printf("\nIntroduza os coeficientes da equação:");
 scanf("%f%f%f",&a,&b,&c);
 
 delta= b*b-4*a*c;
if (delta<0)
 	printf("\nNão há raízes!");
else
	if(delta==0)
		printf("\nRaíz dupla %f", -b/(2*a));
	else
	{
		raiz1=(-b+sqrt(delta)/(2*a));
		raiz2=(-b-sqrt(delta)/(2*a));
		printf("\nRaízes %.2f %.2f",raiz1,raiz2);
	}*/
	
// Exercício 7 (for) Ficha 3
	
	/*setlocale(LC_ALL,"Portuguese");
	int n,m,mult,i;
	printf("Escreva um número inteiro:");
	scanf("%d",&m);
	
	printf("Escreva o número de múltiplos: ");
	scanf("%d",&n);
	
	printf("\nOs múltiplos de %d são:",m);
	mult=0;
	for(i=1;i<=n;i++)
	{
		mult=mult+m;
		printf("\n\t%d",mult);
	}*/
	
// Exercício Particular (do...while - validação de dados)
/*{
	int n;
	
	do{
		printf("\nEscreva um numero inteiro entre 0 e 9:");
		scanf("%d",&n);
      } while (n<0 || n>9);
}*/

