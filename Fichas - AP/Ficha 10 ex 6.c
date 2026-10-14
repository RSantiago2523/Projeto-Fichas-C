# include <stdio.h> // biblioteca para a entrada e saida de dados
# include <locale.h> // biblioteca para o Português
#include <time.h>
#include <sys/time.h>

// Versão Recursiva
int fibonacci(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

// Versão Iterativa
int fibonacci_it(int n)
{
	int i,a,b,f;
	
	a=0;
	b=1;
	for(i=2;i<=n;i++)
	{
		f=a+b;
		a=b;
		b=f;
	}	
	return f;
}

// versão recursiva melhorada
int fibonacci(int n,int v[])
{
	if(n==0)
		v[0]=0;
	else
		if(n==1)
			v[1]=1;
		else
		{
			if(v[n-2]==-1)
				v[n-2]=fibonacci_pro(n-2,v);
			if(v[n-1]==-1);
				v[n-1]=fibonacci_pro(n-1,v);
			v[n]=v[n-2]+v[n-1];
		}
		return v[n];
}

void main()
{

setlocale(LC_ALL,"Portuguese");

struct timeval t1, t2;
double elapsedTime;

int i,n,v[DIM];

do
{
	printf("\nIntroduza o nº: ");
	scanf("%d",&n);
}while(n<0);

// Versão Recursiva - alínea a ----------------------------
// Iniciar o cronómetro
gettimeofday(&t1,NULL);
printf("Recursiva simples: f(%d)=%d",n,fibonacci(n));
// Finalizar o cronómetro
gettimeofday(&t2,NULL);

// Calcular e mostrar o tempo decorrido em milisegundos
elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;	// s para ms
elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;	//us para ms
printf("\nTempo (ms): %f",elapsedTime);

// Versão Iterativa --------------------
// Iniciar o cronómetro
gettimeofday(&t1,NULL);
printf("\n\nVersão iterativa: f(%d)= %d",n,fibonacci_it(n));
// Finalizar o cronómetro
gettimeofday(&t2,NULL);

// Calcular e mostrar o tempo decorrido em milisegundos
elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;	// s para ms
elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;	//us para ms
printf("\nTempo (ms): %f",elapsedTime);

// Versão Recursiva Melhorada - alínea c)
// Inicialização do vetor dos números de fibonacci
for(i=0;i<DIM;i++)
	v[i]=-1;

// Iniciar cronómetro
gettimofday(&t1,NULL);

}
