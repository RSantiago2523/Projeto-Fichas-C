# include <stdio.h> // biblioteca para entrada e saída de dados
# include <locale.h> // biblioteca para o Português

void main()

{
	setlocale(LC_ALL,"Portuguese");
	printf("Olá, tudo bem!");
	
	
	int dia, mes, ano;
	printf("Data(dia,mês,ano)");
	scanf("%d%d%d",dia,mes,ano);
	
	switch (mes)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(dia<1 || dia>31)
					printf("Dia Inválido");
				else
					printf("Faltam %d para o final do mês",31-dia);
				break;
	
	
			case 2: if(ano%4==0 && ano%100!=0 || ano%400==0)
						
				{
						if(dia<1 || dia>29)
						printf("Dia Inválido");
						else
						printf("Faltam %d para o final do mês",29-dia);
				}
				else
				{
						if(dia<1 || dia>28)
						printf("Dia Inválido");
						else
						printf("Faltam %d para o final do mês",28-dia);
				}
				break;
				
		case 4:
		case 6:
		case 9:
		case 11: if(dia<1 || dia>30)
				 printf("Dia Inválido");
				 else
				 printf("Faltam %d para o final do mês",30-dia);
				 break;
	
		default: printf("Mês inválido!");  
	}
	
}
