# include <stdio.h> // biblioteca para a entrada e saída de dados
# include <locale.h> // biblioteca para a gramática do Português

void main()

{
		setlocale(LC_ALL,"Português");
		printf("Bom Dia a todos!");
		
		char oper;
		float num1,num2;
		printf("\nIntroduza a operacao (+,-,*,/):\n");
		scanf("%c",&oper);
		printf("\nIntroduza dois numeros inteiros:\n");
		scanf("%f%f",&num1,&num2);
		switch (oper)																						
		{		case '+': printf("Resultado= %.2f\n",num1 + num2);break;
				
				case '-': printf("Resultado= %.2f\n",num1 - num2);break;
				
				case '*': printf("Resultado= %.2f\n",num1 * num2);break;
				
				case '/': if (num2 !=0)
						printf("Resultado=%.2f\n",num1 / num2);
						  else
						printf("Não se pode dividir por 0!\n");
				break;
					
					default: printf("Operacao invalida\n");}				
}
