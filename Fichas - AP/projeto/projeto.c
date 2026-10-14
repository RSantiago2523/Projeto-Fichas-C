#include <stdio.h>
#include <locale.h>
#include <string.h>
#define DimExames 50
#define DimUC 50
#define DimAlunos 2500
#define DimSalas 100

typedef struct data // estrutura geral para o programa
{
    int dia;
    char mes[10];
    int ano;
} DATA;

typedef struct salasexame {
    int lugares[100];
    int IDalunos[100];
}EXSALA;
EXSALA* ex;
int nsalas;
//ex = malloc(nsalas * sizeof(EXSALA));
typedef struct salas {
    struct salasexame lugares;
    char salaDisponivel[10]; //para inscrição dos exames
    char designacao[10];
    int lugaresTOTAL;
    int lugaresOCUP;
    int posOcup;
    int IDexameOcup; //Quando estiver inscrita num exame


} SALAS;

typedef struct exame {

    int ID;
    int codigoUC;
    char epoca[30];
    char hora[7]; // hh:mm (se o valor ocupar o valor total, por algum motivo n //
    // listarExames, os dois aparecem juntos)
    int duracao;  // duração do exame em minutos
    int posOcup;
    struct data dtex; // dtex é a variavel para as datas dos exames (estruturas conectadas)
    int numSalas;
    struct salas salasDisp[10]; //salas é a pariavel para a estrutura salas disponiveis dos exames

} EXAME;

typedef struct alunos {
    char nome[50]; // por enqunto usa-se o '_' em vez do espaço
    //depois, talvez, ter 3 variaveis de nome(visto que no ficheiro tem até 3) e ter um if caso o terceiro nome = 0 então não escreve nada
    char regime[30]; //trabalhador-estudante, atletas, dirigentes associativos ou alunos que frequentem o último ano (3º)
    int ID;
    int ano;
    char curso[10]; //sigla (ex:EI, EM...)
    int posOcup;
    int acessoEspecial;
}ALUNO;

typedef struct uc {
    int codigoUC;
    char nome[30];
    char anoLetivo[10]; //2022/2023
    int semestre;
    char docente[60];
    int posOcup;
} UC;

void iniciarBiblUC(UC* uc, int n) //NECESSÁRIO PARA SABER SE  A POSIÇÃO i ESTÁ OCUPADA
{
    int i;
    for (i = 0; i < n; i++)
        uc[i].posOcup = 0; //inicializar as posições ocupadas do vetor a zero
}

void menuAlterarUC(UC* uc, int procuraCOD)
{
    int op;
    printf("\nNOTA: Use '_' em vez de espaço!\n");

    do
    {
        printf("\nALTERAR EXAMES");
        printf("\n\t***Menu***");
        printf("\n\t1-Alterar Código\n\t2-Alterar Nome da UC\n\t3-Alterar Ano Letivo\n\t4-Alterar Semestre\n\t5-Alterar Docente\n\t0-Cancelar/Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nCódigo atual: %d", uc[procuraCOD].codigoUC);
            printf("\nNovo código: ");
            scanf("%d", &uc[procuraCOD].codigoUC);
        }break;
        case 2:
        {
            printf("\nNome da UC atual: %s", uc[procuraCOD].nome);
            printf("\nNovo nome: ");
            scanf("%s", uc[procuraCOD].nome);
        }break;
        case 3:
        {
            printf("\nAno Letivo atual: %s", uc[procuraCOD].anoLetivo);
            printf("\nNovo Ano Letivo(aaaa/aaaa): ");
            scanf("%s", uc[procuraCOD].anoLetivo);
        }break;
        case 4:
        {
            printf("\nSemestre atual: %dº\n", uc[procuraCOD].semestre);
            printf("\nNovo Semestre: ");
            scanf("%d", &uc[procuraCOD].semestre);
        }break;
        case 5:
        {
            printf("\nDocente atual: %s", uc[procuraCOD].docente);
            printf("\nNovo Docente: ");
            scanf("%s", uc[procuraCOD].docente);
        }break;
        }

    } while (op != 0);
}

int menuUC(UC* uc)
{
	int r=0;
    int op, listUC = 0, adicUC, elimUC, alterarUC;
    int i = 0, x = 0; //variaveis posição

    while (uc[x].posOcup == 1)
    {
        x++;
    }//vai contar as posições ocupadas
    listUC = x; //caso existam posições ocupadas, o listUC receberá a informação de quantos existem

    do
    {
        printf("\nUNIDADES CURRICULARES");
        printf("\n\t***Menu***");
        printf("\n\t1-Inserir UC\n\t2-Listar UCs\n\t3-Apagar UC\n\t4-Alterar Dados\nt5-Guardar num ficheiro \n\t6-Mostrar dados ficheiro \n\t7-Apagar dados ficheiro\n\t0-Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nNOTA: Use '_' em vez de espaço!\n");

            printf("\nUC a adicionar (max %d):", DimUC - listUC);
            scanf("%d", &adicUC);
            if (listUC + adicUC > DimUC)
                printf("\nSuperou o máximo!");
            else
            {
                if (adicUC < 1)
                    printf("\nTem de adicionar pelo menos 1 Unidade Curricular!\n");
                else
                {
                    listUC = listUC + adicUC;

                    for (i = 0; i < listUC; i++)
                    {
                        if (uc[i].posOcup == 1)//vai verificar se a posição já está ocupada
                        {
                            do
                                i++;
                            while (uc[i].posOcup == 1);
                        }
                        printf("\nNOVA UC\n");

                        printf("\nCódigo da UC: ");
                        scanf("%d", &uc[i].codigoUC);
                        fflush(stdin);
                        printf("\nNome: ");
                        scanf("\n%s", uc[i].nome);
                        fflush(stdin);
                        printf("\nAno Letivo (aaaa/aaaa): ");
                        scanf("\n%s", uc[i].anoLetivo);
                        fflush(stdin);
                        do
                        {
                            printf("\nSemestre: ");
                            scanf("\n%d", &uc[i].semestre);
                            fflush(stdin);
                        } while (uc[i].semestre != 1 && uc[i].semestre != 2);
                        printf("\nDocente: ");
                        scanf("\n%s", uc[i].docente);
                        fflush(stdin);
                        uc[i].posOcup = 1;
                    }
                }
            }
        }break;
        case 2:
        {
            for (i = 0; i < listUC; i++)
            {
                printf("\nUC Nº%d\n", i + 1);

                printf("\nCódigo UC: %d", uc[i].codigoUC);
                printf("\nNome: %s", uc[i].nome);
                printf("\nAno Letivo: %s", uc[i].anoLetivo);
                printf("\nSemestre: %dº", uc[i].semestre);
                printf("\nDocente: %s", uc[i].docente);
                printf("\n");
            }
        }break;
        case 3:
        {
            int procuraCOD, naoExiste = 0;
            printf("\Escreva o código da UC a apagar: ");
            scanf("%d", &elimUC);
            for (procuraCOD = 0; procuraCOD < listUC; procuraCOD++) //vai procurar se o exame existe
            {
                if (elimUC == uc[procuraCOD].codigoUC)
                {
                    int apagarUC;
                    for (apagarUC = procuraCOD; apagarUC < DimUC; apagarUC++)
                        uc[apagarUC] = uc[apagarUC + 1];
                    listUC = listUC - 1; //remover 1 ao numero de exames
                    printf("\nUC apagada!");
                    naoExiste = 1;
                }
            }
            if (naoExiste == 0)
                printf("\nNão existe nenhuma Unidade Curricular com esse código!");
        }break;
        case 4:
        {
            if (listUC == 0)
            {
                printf("\nNão existem UCs para alterar!\n");
            }
            else
            {
                printf("\nEscreva o código da Unidade Curricular a alterar: ");
                scanf("%d", &alterarUC);
                int procuraCOD, naoExiste = 0;
                for (procuraCOD = 0; procuraCOD < listUC; procuraCOD++)
                {
                    if (alterarUC == uc[procuraCOD].codigoUC)
                    {
                        menuAlterarUC(uc, procuraCOD);
                        naoExiste = 1;
                    }
                }
                if (naoExiste == 0)
                    printf("\nNão existe nenhuma UC com esse código!\n");
            }
        }break;      
        case 5:{
        	
            //ver se existe
           	FILE *abrir = fopen("ucs.txt","r"); 
           	if(abrir == NULL ){
           		FILE *ucs = fopen("ucs.txt","a");
           		fprintf(ucs,"ID	Nome anoletivo semestres docente \n");		
				fclose(ucs);
			}
			 fclose(abrir);	
				 		    
		   //acrescentar dados
			FILE *ucs = fopen("ucs.txt","a");
			for(i=0 ;i<listUC;i++){
				fprintf(ucs, "%d\t%s\t%s\t%d\t%s\n", uc[i].codigoUC, uc[i].nome, uc[i].anoLetivo , uc[i].semestre , uc[i].docente );	    
			}
			fclose(ucs);
			
		}break;
		case 6:{
					FILE *ucs = fopen("ucs.txt","r");
					i = 1;
					char *result;
					char Linha[100];
					  while (!feof(ucs))
					  {
						// Lê uma linha (inclusive com o '\n')
					      result = fgets(Linha, 100, ucs);  // o 'fgets' lê até 99 caracteres ou até o '\n'
					      if (result)  // Se foi possível ler
						  printf("Linha: %d : %s",i,Linha);
					      i++;
					  }		
				fclose(ucs);
		}break;
		case 7:{
				FILE *original = fopen("ucs.txt", "r"); //Arquivo de entrada.
				FILE *temporario = fopen("temporario.txt", "w"); //Arquivo de saída.
				int linha_apagar;
				int linha_atual = 1;
				char texto[100] = ""; //Uma string larga o suficiente para extrair o texto total de cada linha.
				printf("Linha para apagar: ");
				scanf("%d",&linha_apagar);
				
				while(fgets(texto, 100, original) != NULL){
				    if(linha_atual != linha_apagar){
				        fputs(texto, temporario);
				       }
				       linha_atual += 1;
				    }
				    fclose(original);
				    fclose(temporario);
				    remove("ucs.txt");
                    rename("temporario.txt", "ucs.txt");
			
		}break;
        }
    } while (op != 0);
    return listUC;
}

void iniciarBiblExam(EXAME* exames, int n) //NECESSÁRIO PARA SABER SE  A POSIÇÃO i ESTÁ OCUPADA
{
    int i;
    for (i = 0; i < n; i++)
        exames[i].posOcup = 0; //inicializar as posições ocupadas do vetor a zero
}

void menuAlterarExame(EXAME* exames, int procuraID, int listUC, UC* uc, int listSalas, SALAS* salas)
{
    int op;
    do
    {
        printf("\nALTERAR EXAMES");
        printf("\n\t***Menu***");
        printf("\n\t1-Alterar ID\n\t2-Alterar Código da UC\n\t3-Alterar Epoca\n\t4-Alterar Data\n\t5-Alterar Hora\n\t6-Alterar Duração\n\t7-Alterar Salas\n\t0-Cancelar/Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nID atual: %d", exames[procuraID].ID);
            printf("\nNovo ID: ");
            scanf("%d", &exames[procuraID].ID);
        }break;
        case 2:
        {
            printf("\nCódigo UC atual: %d", exames[procuraID].codigoUC);
            printf("\nNovo código: ");
            scanf("%d", &exames[procuraID].codigoUC);
        }break;
        case 3:
        {
            printf("\nÉpoca atual: %s", exames[procuraID].epoca);
            printf("\nNova Época: ");
            scanf("%s", exames[procuraID].epoca);
        }break;
        case 4:
        {
            int dataExiste = 0;
            printf("\nData atual: %d de %s de %d\n", exames[procuraID].dtex.dia, exames[procuraID].dtex.mes, exames[procuraID].dtex.ano);
            do
            {
                printf("\nDia: ");
                scanf("%d", &exames[procuraID].dtex.dia);
                fflush(stdin);
                printf("\nMês (ex:outubro): ");
                scanf("%s", exames[procuraID].dtex.mes);
                fflush(stdin);
                printf("\nAno: ");
                scanf("%d", &exames[procuraID].dtex.ano);
                fflush(stdin);
                printf("\n");

                int procuraCOD, semestreUC;
                for (procuraCOD = 0; procuraCOD < listUC; procuraCOD++) //vai procurar o semestre na estrutura uc
                {
                    if (exames[procuraID].codigoUC == uc[procuraCOD].codigoUC)
                        semestreUC = uc[procuraCOD].semestre; //descobre o semestre
                }

                if (strcmp(exames[procuraID].epoca, "normal") == 0 || strcmp(exames[procuraID].epoca, "Normal") == 0)
                {
                    if (semestreUC == 1)
                    {
                        if ((strcmp(exames[procuraID].dtex.mes, "janeiro") == 0 && (exames[procuraID].dtex.dia < 2 || exames[procuraID].dtex.dia > 31)) || ((strcmp(exames[procuraID].dtex.mes, "fevereiro") == 0 && (exames[procuraID].dtex.dia < 1 || exames[procuraID].dtex.dia > 3))))
                            printf("\nEsse dia não pertence à Época Normal do 1ºsemestre!\n");
                        else
                            dataExiste = 1;
                    }
                    else
                    {
                        if ((strcmp(exames[procuraID].dtex.mes, "junho") == 0 && (exames[procuraID].dtex.dia < 2 || exames[procuraID].dtex.dia > 30)) || ((strcmp(exames[procuraID].dtex.mes, "julho") == 0 && (exames[procuraID].dtex.dia < 1 || exames[procuraID].dtex.dia > 2))))
                            printf("\nEsse dia não pertence à Época Normal do 2ºsemestre!\n");
                        else
                            dataExiste = 1;
                    }
                }
                else
                {
                    if (strcmp(exames[procuraID].epoca, "recurso") == 0 || strcmp(exames[procuraID].epoca, "Recurso") == 0)
                    {
                        if (semestreUC == 1)
                        {
                            if (strcmp(exames[procuraID].dtex.mes, "fevereiro") == 0 && (exames[procuraID].dtex.dia < 9 || exames[procuraID].dtex.dia > 24))
                                printf("\nEsse dia não pertence à Época de Recurso do 1ºsemestre!\n");
                            else
                                dataExiste = 1;
                        }
                        else
                        {
                            if (strcmp(exames[procuraID].dtex.mes, "julho") == 0 && (exames[procuraID].dtex.dia < 9 || exames[procuraID].dtex.dia > 24))
                                printf("\nEsse dia não pertence à Época de Recurso do 2ºsemestre!\n");
                            else
                                dataExiste = 1;
                        }
                    }
                    else
                    {
                        if (strcmp(exames[procuraID].epoca, "especial") == 0 || strcmp(exames[procuraID].epoca, "Especial") == 0)
                        {
                            if (strcmp(exames[procuraID].dtex.mes, "setembro") == 0 && (exames[procuraID].dtex.dia < 1 || exames[procuraID].dtex.dia > 16))
                                printf("\nEsse dia não pertence à Época Especial!\n");
                            else
                                dataExiste = 1;
                        }
                        else
                        {
                            printf("\nVerifique se escreveu a Época corretamente! Exemplos:");
                            printf("\n'Normal' ou 'normal'\n");
                            dataExiste = 1;
                        }

                    }
                }
            } while (dataExiste == 0);
        }break;
        case 5:
        {
            printf("\nHora atual: %s", exames[procuraID].hora);
            printf("\nNova hora (hh:mm): ");
            scanf("%s", exames[procuraID].hora);
        }break;
        case 6:
        {
            printf("\nDuração atual: %d", exames[procuraID].duracao);
            printf("\nNova Duração: ");
            scanf("%d", &exames[procuraID].duracao);
        }break;
        case 7:
        {
            printf("\nSalas atuais: ");
            int i = 0, adiRem, j, naoExisteSala = 0;
            char salaEsc[10];
            do
            {
                printf("%s ", exames[procuraID].salasDisp[i].salaDisponivel);
                i++;
            } while (i < exames[procuraID].numSalas);
            //adicionar ou remover sala
            printf("\nQuer remover(0) ou adicionar(1)?");
            scanf("%d", &adiRem);
            if (adiRem == 0)
            {
                int naoExiste = 0;
                printf("\nSala a remover:");
                scanf("%s", salaEsc);
                for (j = 0; j < exames[procuraID].numSalas; j++) //vai procurar se o exame existe
                {
                    if (strcmp(salaEsc, exames[procuraID].salasDisp[j].salaDisponivel) == 0)//FUNÇÃO PARA COMPARAR 2 CHAR
                    {
                        int procuraSALA;
                        for (procuraSALA = 0; procuraSALA < listSalas; procuraSALA++)
                        {
                            if (salas[procuraSALA].IDexameOcup == exames[procuraID].ID)
                                salas[procuraSALA].IDexameOcup = 0;
                        }
                        int apagarSala;
                        for (apagarSala = j; apagarSala < exames[procuraID].numSalas - 1; apagarSala++)
                            exames[procuraID].salasDisp[apagarSala] = exames[procuraID].salasDisp[apagarSala + 1];
                        exames[procuraID].numSalas = exames[procuraID].numSalas - 1; //remover 1 ao numero de salas
                        printf("\nSala removida!");
                        naoExiste = 1;

                    }
                }
                if (naoExiste == 0)
                    printf("\nEssa sala não existe!");
            }
            else
            {
                if (adiRem == 1)
                {
                    j = exames[procuraID].numSalas;
                    if (j >= 10)
                        printf("Foi atingido o número máximo de salas por exame!");
                    else
                    {
                        char novaSala[10];
                        exames[procuraID].numSalas = exames[procuraID].numSalas + 1;
                        printf("\nNova Sala: ");
                        scanf("%s", novaSala);//posição será igual ao numero de salas (já com a nova) - 1 porque a posição começa em zero
                        int w;
                        for (w = 0; w < exames[procuraID].numSalas; w++)
                        {
                            int s;
                            for (s = 0; s < listSalas; s++)
                            {
                                if (strcmp(salas[s].designacao, novaSala) == 0)//FUNÇÃO PARA COMPARAR 2 CHAR
                                {
                                    if (salas[s].IDexameOcup == 0)
                                    {
                                        printf("\nA sala foi adiciona!");
                                        salas[s].IDexameOcup = exames[w].ID;
                                    }
                                    else
                                        printf("\nA sala já está a ser usada! (ID exame: %d)\n", salas[s].IDexameOcup);
                                    naoExisteSala = 1;
                                }
                            }
                        }
                        if (naoExisteSala == 0)
                            printf("\nA sala %s não existe!\n", exames[j].salasDisp[i].salaDisponivel);
                    }
                }
                else
                    printf("\nOpção inválida!");

            }

        }break;

        }

    } while (op != 0);
}

int menuExame(EXAME* exames, int listUC, UC* uc, int listSalas, SALAS* salas) { //menu para inserir, listar, apagar e alterar exames
    int listExames = 0, op, naoExisteSala = 0;
    int elimExam, adicExam = 1, alterarExam; //vaiaveis exame
    int i, j, k, x = 0, l; //variaveis para posição estrutura, começar em zero SEMPRE!
    int r =0;
     
    while (exames[x].posOcup == 1)
    {
        x++;
    }//vai contar as posições ocupadas
    listExames = x; //caso existam posições ocupadas, o listExames receberá a informação de quantos existem

    do
    {
        printf("\nEXAMES");
        printf("\n\t***Menu***");
         printf("\n\t1-Inserir Exame\n\t2-Ver Exame\n\t3-Apagar Exame \n\t4-Alterar Dados \n\t5-Guardar num ficheiro \n\t6-Mostrar dados ficheiro \n\t7-Apagar dados ficheiro \n\t0-Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nExames a adicionar (max %d):", DimExames - listExames);
            scanf("%d", &adicExam);
            if (listExames + adicExam > DimExames)
                printf("\nSuperou o máximo!");
            else
            {
                if (adicExam < 1)
                    printf("\nTem de adicionar pelo menos 1 exame!\n");
                else
                {
                    listExames = listExames + adicExam;

                    for (j = 0; j < listExames; j++)
                    {
                        int ucExiste = 0, dataExiste = 0;

                        if (exames[j].posOcup == 1)//vai verificar se a posição já está ocupada
                        {
                            do
                                j++;
                            while (exames[j].posOcup == 1);
                        }
                        printf("\nNOVO EXAME\n");

                        //ID
                        printf("\nID: ");
                        scanf("%d", &exames[j].ID);
                        fflush(stdin);
                        //Código da UC
                        do
                        {
                            printf("\nCódigo da UC: ");
                            scanf("%d", &exames[j].codigoUC);
                            fflush(stdin);
                            int procuraCOD;
                            for (procuraCOD = 0; procuraCOD < listUC; procuraCOD++)
                            {
                                if (exames[j].codigoUC == uc[procuraCOD].codigoUC)
                                    ucExiste = 1;
                            }
                            if (ucExiste == 0)
                                printf("\nNão existe nenhuma UC com esse código!\n");
                        } while (ucExiste == 0);

                        //Época do Exame
                        printf("\nÉpoca do Exame: "); //Normal, Recurso, Especial
                        scanf("%s", exames[j].epoca);
                        fflush(stdin);
                        printf("\n");

                        //Dia do Exame
                        do
                        {
                            printf("\nDATA DO EXAME\n");
                            printf("\nDia: ");
                            scanf("%d", &exames[j].dtex.dia);
                            fflush(stdin);
                            printf("\nMês (ex:outubro): ");
                            scanf("%s", exames[j].dtex.mes);
                            fflush(stdin);
                            printf("\nAno: ");
                            scanf("%d", &exames[j].dtex.ano);
                            fflush(stdin);
                            printf("\n");

                            int procuraCOD, semestreUC;
                            for (procuraCOD = 0; procuraCOD < listUC; procuraCOD++) //vai procurar o semestre na estrutura uc
                            {
                                if (exames[j].codigoUC == uc[procuraCOD].codigoUC)
                                    semestreUC = uc[procuraCOD].semestre; //descobre o semestre
                            }

                            if (strcmp(exames[j].epoca, "normal") == 0 || strcmp(exames[j].epoca, "Normal") == 0)
                            {
                                if (semestreUC == 1)
                                {
                                    if ((strcmp(exames[j].dtex.mes, "janeiro") == 0 && (exames[j].dtex.dia < 2 || exames[j].dtex.dia > 31)) || ((strcmp(exames[j].dtex.mes, "fevereiro") == 0 && (exames[j].dtex.dia < 1 || exames[j].dtex.dia > 3))))
                                        printf("\nEsse dia não pertence à Época Normal do 1ºsemestre!\n");
                                    else
                                        dataExiste = 1;
                                }
                                else
                                {
                                    if ((strcmp(exames[j].dtex.mes, "junho") == 0 && (exames[j].dtex.dia < 2 || exames[j].dtex.dia > 30)) || ((strcmp(exames[j].dtex.mes, "julho") == 0 && (exames[j].dtex.dia < 1 || exames[j].dtex.dia > 2))))
                                        printf("\nEsse dia não pertence à Época Normal do 2ºsemestre!\n");
                                    else
                                        dataExiste = 1;
                                }
                            }
                            else
                            {
                                if (strcmp(exames[j].epoca, "recurso") == 0 || strcmp(exames[j].epoca, "Recurso") == 0)
                                {
                                    if (semestreUC == 1)
                                    {
                                        if (strcmp(exames[j].dtex.mes, "fevereiro") == 0 && (exames[j].dtex.dia < 9 || exames[j].dtex.dia > 24))
                                            printf("\nEsse dia não pertence à Época de Recurso do 1ºsemestre!\n");
                                        else
                                            dataExiste = 1;
                                    }
                                    else
                                    {
                                        if (strcmp(exames[j].dtex.mes, "julho") == 0 && (exames[j].dtex.dia < 9 || exames[j].dtex.dia > 24))
                                            printf("\nEsse dia não pertence à Época de Recurso do 2ºsemestre!\n");
                                        else
                                            dataExiste = 1;
                                    }
                                }
                                else
                                {
                                    if (strcmp(exames[j].epoca, "especial") == 0 || strcmp(exames[j].epoca, "Especial") == 0)
                                    {
                                        if (strcmp(exames[j].dtex.mes, "setembro") == 0 && (exames[j].dtex.dia < 1 || exames[j].dtex.dia > 16))
                                            printf("\nEsse dia não pertence à Época Especial!\n");
                                        else
                                            dataExiste = 1;
                                    }
                                    else
                                    {
                                        printf("\nVerifique se escreveu a Época corretamente! Exemplos:");
                                        printf("\n'Normal' ou 'normal'\n");
                                        dataExiste = 1;
                                    }

                                }
                            }
                        } while (dataExiste == 0);
                        //Informação do Exame
                        printf("\nINFORMAÇÃO SOBRE O EXAME\n");
                        printf("\nHorário do Exame (hh:mm): ");
                        scanf("%s", exames[j].hora);
                        fflush(stdin);
                        printf("\nDuração (em minutos): ");
                        scanf("%d", &exames[j].duracao);
                        fflush(stdin);
                        do
                        {
                            printf("\nSalas disponíveis (%d), máximo de 10 por exame: ", listSalas);
                            scanf("%d", &exames[j].numSalas);
                        } while ((exames[j].numSalas < 1 || exames[j].numSalas > 10) || exames[j].numSalas > listSalas);
                        for (i = 0; i < exames[j].numSalas; i++)
                        {
                            printf("\n%dº Sala Disponível: ", i + 1);
                            scanf("%s", exames[j].salasDisp[i].salaDisponivel);
                            int s;
                            for (s = 0; s < listSalas; s++) //vai procurar a sala
                            {
                                if (strcmp(salas[s].designacao, exames[j].salasDisp[i].salaDisponivel) == 0) //se encontrar
                                {
                                    if (salas[s].IDexameOcup == 0)
                                    {
                                        printf("\nInscrito na sala %s!", salas[s].designacao);
                                        salas[s].IDexameOcup = exames[j].ID;
                                    }
                                    else
                                        printf("\nA sala já está a ser usada! (ID exame: %d)\n", salas[s].IDexameOcup);
                                    naoExisteSala = 1;
                                }
                            }
                            if (naoExisteSala == 0)
                                printf("\nA sala %s não existe!\n", exames[j].salasDisp[i].salaDisponivel);

                        }
                        exames[j].posOcup = 1;
                    }
                }

            }
        }break;
        case 2:
        {
            if (listExames == 0)
                printf("\nNão existem exames!\n");
            else
            {
                for (k = 0; k < listExames; k++)
                {
                    printf("\nEXAME Nº%d", k + 1);
                    printf("\n");
                    printf("\nID: %d", exames[k].ID);
                    printf("\nCódigo UC: %d", exames[k].codigoUC);
                    printf("\nÉpoca: %s", exames[k].epoca);
                    printf("\nData: %d de %s de %d", exames[k].dtex.dia, exames[k].dtex.mes, exames[k].dtex.ano);
                    printf("\nHora: %s", exames[k].hora);
                    printf("\nDuração: %d minutos", exames[k].duracao);
                    printf("\nSalas Disponíveis: ");
                    for (l = 0; l < exames[k].numSalas; l++)
                        printf("%s ", exames[k].salasDisp[l].salaDisponivel);
                    printf("\n");
                }
            }

        }break;
        case 3:
        {
            int procuraID;
            printf("\Escreva o ID do exame a apagar: ");
            scanf("%d", &elimExam);
            for (procuraID = 0; procuraID < listExames; procuraID++) //vai procurar se o exame existe
            {
                if (elimExam == exames[procuraID].ID)
                {
                    int apagarExame;
                    for (apagarExame = procuraID; apagarExame < DimExames; apagarExame++)
                    {
                        int procuraSALA;
                        for (procuraSALA = 0; procuraSALA < listSalas; procuraSALA++)
                        {
                            if (salas[procuraSALA].IDexameOcup == exames[procuraID].ID)
                                salas[procuraSALA].IDexameOcup = 0;
                        }
                        exames[apagarExame] = exames[apagarExame + 1];
                    }
                    listExames = listExames - 1; //remover 1 ao numero de exames
                    printf("\nExame apagado!");
                }
            }
        }break;
        case 4:
        {
            if (listExames == 0)
            {
                printf("\nNão existem exames para alterar!\n");
            }
            else
            {
                printf("\nEscreva o ID do exame a alterar: ");
                scanf("%d", &alterarExam);
                int procuraID, naoExiste = 0;
                for (procuraID = 0; procuraID < listExames; procuraID++)
                {
                    if (alterarExam == exames[procuraID].ID)
                    {
                        menuAlterarExame(exames, procuraID, listUC, uc, listSalas, salas);
                        naoExiste = 1;
                    }
                }
                if (naoExiste == 0)
                    printf("\nNão existe nenhum exame com esse ID!\n");
            }
        }break;
         case 5:{
        	
            //ver se existe
           	FILE *abrir = fopen("exames.txt","r"); 
           	if(abrir == NULL ){
           		FILE *exames = fopen("exames.txt","a");
           		fprintf(exames,"ID COD_UC EPOCA HORA DURACAO DATA SALAS_DISPONIVEIS \n");		
				fclose(exames);
			}
			 fclose(abrir);	
				 		    
		   //acrescentar dados
			FILE *examestxt = fopen("exames.txt","a");
			for(j=0 ;j<listExames;j++){
				fprintf(examestxt, "\t%d\t%d\t%s\t%s\t%d\t%d de %s de %d\t%s \n", exames[j].ID, exames[j].codigoUC , exames[j].epoca , exames[j].hora , exames[j].duracao , exames[j].dtex.dia , 
				exames[j].dtex.mes ,exames[j].dtex.ano , exames[j].salasDisp );	    
			}
			fclose(examestxt);
			
		}break;
		case 6:{
					FILE *examestxt = fopen("exames.txt","r");
					i = 1;
					char *result;
					char Linha[100];
					  while (!feof(examestxt))
					  {
						// Lê uma linha (inclusive com o '\n')
					      result = fgets(Linha, 100, examestxt);  // o 'fgets' lê até 99 caracteres ou até o '\n'
					      if (result)  // Se foi possível ler
						  printf("Linha: %d : %s",i,Linha);
					      i++;
					  }		
				fclose(examestxt);
		}break;
		case 7:{
				FILE *original = fopen("exames.txt", "r"); //Arquivo de entrada.
				FILE *temporario = fopen("temporario.txt", "w"); //Arquivo de saída.
				int linha_apagar;
				int linha_atual = 1;
				char texto[100] = ""; //Uma string larga o suficiente para extrair o texto total de cada linha.
				printf("Linha para apagar: ");
				scanf("%d",&linha_apagar);
				
				while(fgets(texto, 100, original) != NULL){
				    if(linha_atual != linha_apagar){
				        fputs(texto, temporario);
				       }
				       linha_atual += 1;
				    }
				    fclose(original);
				    fclose(temporario);
				    remove("exames.txt");
                    rename("temporario.txt", "exames.txt");
			
		}break;
        }
    } while (op != 0);
    return listExames;
}

void iniciarBiblAlunos(ALUNO* alunos, int n) //NECESSÁRIO PARA SABER SE  A POSIÇÃO i ESTÁ OCUPADA
{
    int i;
    for (i = 0; i < n; i++)
        alunos[i].posOcup = 0; //inicializar as posições ocupadas do vetor a zero
}

void menuAlterarAluno(ALUNO* alunos, int procuraID)
{
    int op;
    do
    {
        printf("\nALTERAR ALUNOS");
        printf("\n\t***Menu***");
        printf("\n\t1-Alterar Nome\n\t2-Alterar Regime\n\t3-Alterar ID\n\t4-Alterar Ano\n\t5-Alterar Curso\n\t0-Cancelar/Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nNome atual: %s", alunos[procuraID].nome);
            printf("\nNovo nome: ");
            scanf("%s", alunos[procuraID].nome);
        }break;
        case 2:
        {
            printf("\nRegime atual: %s", alunos[procuraID].regime);
            printf("\nNovo regime: ");
            scanf("%s", alunos[procuraID].regime);
        }break;
        case 3:
        {
            printf("\nID atual: %d", alunos[procuraID].ID);
            printf("\nNovo ID: ");
            scanf("%d", &alunos[procuraID].ID);
        }break;
        case 4:
        {
            printf("\nAno atual: %d", alunos[procuraID].ano);
            printf("\nNovo ano: ");
            scanf("%d", &alunos[procuraID].ano);
        }break;
        case 5:
        {
            printf("\nCurso atual: %s", alunos[procuraID].curso);
            printf("\nNovo curso(Sigla): ");
            scanf("%s", alunos[procuraID].curso);
        }break;
        }

    } while (op != 0);
}

int menuAlunos(ALUNO* alunos) //menu para inserir, listar, apagar e alterar alunos
{
    int listAlunos = 0, op;
    int elimAluno, alterarAluno, adicAluno = 1; //variaveis alunos
    int i, j, k, x = 0, l; //variaveis para posição estrutura, começar em zero SEMPRE!
    int r=0;

    while (alunos[x].posOcup == 1) //TEMOS DE ARRANJAR UMA MANEIRA DE FAZER SEM ISTO, POR CAUSA DO FICHEIRO NÃO TER A INFORMAÇÃO
        //A MENOS QUE USEMOS O NÚMERO DE LINHAS!!! @MARCO
    {
        x++;
    }//vai contar as posições ocupadas
    listAlunos = x; //caso existam posições ocupadas, o listAlunos receberá a informação de quantos existem

    do
    {
        printf("\nALUNOS");
        printf("\n\t***Menu***");
        printf("\n\t1-Inserir Aluno\n\t2-Ver Aluno\n\t3-Remover Aluno \n\t4-Alterar Dados\n\t5-Guardar num ficheiro \n\t6-Mostrar dados ficheiro \n\t7-Apagar dados ficheiro\n\t0-Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nAlunos a adicionar (max %d):", DimAlunos - listAlunos);
            scanf("%d", &adicAluno);
            if (listAlunos + adicAluno > DimAlunos)
                printf("\nSuperou o máximo!");
            else
            {
                if (adicAluno < 1)
                    printf("\nTem de adicionar pelo menos 1 aluno!\n");
                else
                {
                    listAlunos = listAlunos + adicAluno;

                    printf("\nNOTA: Use '_' em vez de espaço!\n");
                    for (j = 0; j < listAlunos; j++)
                    {
                        if (alunos[j].posOcup == 1)//vai verificar se a posição já está ocupada
                        {
                            do
                                j++;
                            while (alunos[j].posOcup == 1);
                        }
                        printf("\nNOVO ALUNO\n");

                        //INFORMAÇÃO ALUNO
                        printf("\nNome:");
                        scanf("%s", alunos[j].nome);
                        fflush(stdin);
                        printf("\nRegime:");
                        scanf("%s", alunos[j].regime);
                        fflush(stdin);
                        if (strcmp("normal", alunos[j].regime) == 0 || strcmp("Normal", alunos[j].regime) == 0) //COMPARAÇÃO DE 2 STRINGS
                            alunos[j].acessoEspecial = 0;
                        else
                            alunos[j].acessoEspecial = 1; //Uma maneira de verificar se o aluno pode ou não inscrever-se na epoca especial
                        //pode ser feita aqui e na leitura do ficheiro
                        printf("\nID:");
                        scanf("%d", &alunos[j].ID);
                        fflush(stdin);
                        printf("\nAno:");
                        scanf("%d", &alunos[j].ano);
                        fflush(stdin);
                        if (alunos[j].ano == 3)
                            alunos[j].acessoEspecial = 1; //na lida do ficheiro temos de fazer algo para analizar cada linha e ver se pode ou não inscrever-se na epoca especial
                        //pode ser feita aqui e na leitura do ficheiro
                        printf("\nCurso (Sigla):");
                        scanf("%s", alunos[j].curso);
                        fflush(stdin);
                        alunos[j].posOcup = 1;
                    }
                }
            }
        }break;
        case 2:
        {
            if (listAlunos == 0)
                printf("\nNão existem alunos!\n");
            else
            {
                for (k = 0; k < listAlunos; k++)
                {
                    printf("\nALUNO Nº%d", k + 1);
                    printf("\n");
                    printf("\nNome: %s", alunos[k].nome);
                    printf("\nRegime: %s", alunos[k].regime);
                    printf("\nID: %d", alunos[k].ID);
                    printf("\nAno: %dº", alunos[k].ano);
                    printf("\nCurso: %s", alunos[k].curso);
                    printf("\n");
                }
            }
        }break;
        case 3:
        {
            int procuraID;
            printf("\nEscreva o ID do aluno a apagar: ");
            scanf("%d", &elimAluno);
            for (procuraID = 0; procuraID < listAlunos; procuraID++) //vai procurar se o exame existe
            {
                if (elimAluno == alunos[procuraID].ID)
                {
                    int apagarAluno;
                    for (apagarAluno = procuraID; apagarAluno < DimAlunos; apagarAluno++)
                        alunos[apagarAluno] = alunos[apagarAluno + 1];
                    listAlunos = listAlunos - 1; //remover 1 ao numero de exames
                    printf("Aluno removido!\n");
                }
            }
        }break;
        case 4:
        {
            if (listAlunos == 0)
            {
                printf("\nNão existem alunos para alterar!\n");
            }
            else
            {
                printf("\nEscreva o ID do aluno a alterar: ");
                scanf("%d", &alterarAluno);
                int procuraID, naoExiste = 0;
                for (procuraID = 0; procuraID < listAlunos; procuraID++)
                {
                    if (alterarAluno == alunos[procuraID].ID)
                    {
                        menuAlterarAluno(alunos, procuraID);
                        naoExiste = 1;
                    }
                }
                if (naoExiste == 0)
                    printf("\nNão existe nenhum aluno com esse ID!\n");
            }
        }break;

case 5:{
        	
            //ver se existe
           	FILE *abrir = fopen("alunos.txt","r"); 
           	if(abrir == NULL ){
           		FILE *alunostxt = fopen("alunos.txt","a");
           		fprintf(alunostxt,"NOME	REGIME	ANO	NÚMERO	CURSO \n");		
				fclose(alunostxt);
			}
			 fclose(abrir);	
				 		    
		   //acrescentar dados
			FILE *alunostxt = fopen("alunos.txt","a");
			for(j=0 ;j<listAlunos;j++){
				fprintf(alunostxt, "%s\t%s\t%d\t%d\t%s\n", alunos[j].nome,alunos[j].regime , alunos[j].ano ,alunos[j].ID , alunos[j].curso);	    
			}
			fclose(alunostxt);
			
		}break;
		case 6:{
					FILE *alunostxt = fopen("alunos.txt","r");
					i = 1;
					char *result;
					char Linha[100];
					  while (!feof(alunostxt))
					  {
						// Lê uma linha (inclusive com o '\n')
					      result = fgets(Linha, 100, alunostxt);  // o 'fgets' lê até 99 caracteres ou até o '\n'
					      if (result)  // Se foi possível ler
						  printf("Linha: %d : %s",i,Linha);
					      i++;
					  }		
				fclose(alunostxt);
		}break;
		case 7:{
				FILE *original = fopen("alunos.txt", "r"); //Arquivo de entrada.
				FILE *temporario = fopen("temporario.txt", "w"); //Arquivo de saída.
				int linha_apagar;
				int linha_atual = 1;
				char texto[100] = ""; //Uma string larga o suficiente para extrair o texto total de cada linha.
				printf("Linha para apagar: ");
				scanf("%d",&linha_apagar);
				
				while(fgets(texto, 100, original) != NULL){
				    if(linha_atual != linha_apagar){
				        fputs(texto, temporario);
				       }
				       linha_atual += 1;
				    }
				    fclose(original);
				    fclose(temporario);
				    remove("alunos.txt");
                    rename("temporario.txt", "alunos.txt");
			
		}break;
        }
    } while (op != 0);
    return listAlunos;
}

void iniciarBiblSalas(SALAS* salas, int n) //NECESSÁRIO PARA SABER SE  A POSIÇÃO i ESTÁ OCUPADA
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        salas[i].posOcup = 0; //inicializar as posições ocupadas do vetor a zero
        salas[i].lugaresOCUP = 0;
        salas[i].IDexameOcup = 0;
    }
}

void menuAlterarSala(SALAS* salas, int procuraSALA)
{
    int op;
    do
    {
        printf("\nALTERAR SALAS");
        printf("\n\t***Menu***");
        printf("\n\t1-Alterar Designação\n\t2-Alterar Número de Lugares\n\t0-Cancelar/Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nDesignação atual: %s", salas[procuraSALA].designacao);
            printf("\nNova Designação: ");
            scanf("%s", salas[procuraSALA].designacao);
        }break;
        case 2:
        {
            printf("\nNúmero de Lugares atual: %d", salas[procuraSALA].lugaresTOTAL);
            printf("\nNovo Número de Lugares: ");
            scanf("%d", &salas[procuraSALA].lugaresTOTAL);
        }break;
        }

    } while (op != 0);
}

int menuSala(SALAS* salas, int listExame, EXAME* exames, int listUC, UC* uc, int listAlunos, ALUNO* alunos) { //menu para inserir, listar, apagar e alterar exames
    int listSalas = 0, op;
    int adicSala = 1; //vaiaveis sala
    char elimSala[10], alterarSala[10];
    int j, k, x = 0; //variaveis para posição estrutura, começar em zero SEMPRE!

    while (salas[x].posOcup == 1)
    {
        x++;
    }//vai contar as posições ocupadas
    listSalas = x; //caso existam posições ocupadas, o listExames receberá a informação de quantos existem

    do
    {
        printf("\nSALAS");
        printf("\n\t***Menu***");
        printf("\n\t1-Criar Sala\n\t2-Ver Salas\n\t3-Remover Sala\n\t4-Alterar Dados\n\t5-Inscrever Alunos\n\t0-Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\nSalas a adicionar (max %d):", DimSalas - listSalas);
            scanf("%d", &adicSala);
            if (listSalas + adicSala > DimSalas)
                printf("\nSuperou o máximo!");
            else
            {
                listSalas = listSalas + adicSala;

                for (j = 0; j < listSalas; j++)
                {
                    if (salas[j].posOcup == 1)//vai verificar se a posição já está ocupada
                    {
                        do
                            j++;
                        while (salas[j].posOcup == 1);
                    }
                    printf("\nNOVA SALA\n");

                    //Designação
                    printf("\nDesignação: ");
                    scanf("%s", salas[j].designacao);
                    fflush(stdin);
                    //Lugares
                    printf("\nNúmero de Lugares: ");
                    scanf("%d", &salas[j].lugaresTOTAL);
                    fflush(stdin);


                    salas[j].posOcup = 1;
                }
            }
        }break;
        case 2:
        {
            if (listSalas == 0)
                printf("\nNão existem salas!\n");
            else
            {
                for (k = 0; k < listSalas; k++)
                {
                    printf("\nSALA Nº%d", k + 1);
                    printf("\n");
                    printf("\nDesignação: %s", salas[k].designacao);
                    printf("\nTotal de Lugares: %d", salas[k].lugaresTOTAL);
                    printf("\nLugares Ocupados: %d", salas[k].lugaresOCUP);
                    printf("\nID do Exame Inscrito: ");
                    if (salas[k].IDexameOcup == 0)
                        printf("Nenhum");
                    else
                    {
                        printf("%d", salas[k].IDexameOcup);
                    }
                    printf("\n");
                }
            }

        }break;
        case 3:
        {
            int procuraSALA;
            printf("\Escreva a Designação da sala a remover: ");
            scanf("%s", elimSala);
            for (procuraSALA = 0; procuraSALA < listSalas; procuraSALA++) //vai procurar se o exame existe
            {
                if ((strcmp(salas[procuraSALA].designacao, elimSala) == 0))
                {
                    int apagarSala;
                    for (apagarSala = procuraSALA; apagarSala < DimSalas; apagarSala++)
                        salas[apagarSala] = salas[apagarSala + 1];
                    listSalas = listSalas - 1; //remover 1 ao numero de exames
                    printf("\nSala removida!");
                }
            }
        }break;
        case 4:
        {
            if (listSalas == 0)
            {
                printf("\nNão existem salas para alterar!\n");
            }
            else
            {
                printf("\nEscreva a Designação da Sala a alterar: ");
                scanf("%s", alterarSala);
                int procuraSALA, naoExiste = 0;
                for (procuraSALA = 0; procuraSALA < listSalas; procuraSALA++)
                {
                    if (strcmp(alterarSala, salas[procuraSALA].designacao) == 0)
                    {
                        menuAlterarSala(salas, procuraSALA);
                        naoExiste = 1;
                    }
                }
                if (naoExiste == 0)
                    printf("\nNão existe nenhuma sala com essa designação!\n");
            }
        }break;

        case 5:
        {
            int IDalunos, mm, IDexame, mn, cadeira, nn;

            if (listAlunos > 0)
            {
                if (listExame > 0)
                {

                    printf("\nIndique o ID do aluno que quer inscrever:");
                    scanf("%d", &IDalunos);
                    for (mm = 0; mm < listAlunos; mm++)
                    {

                        if (alunos[mm].ID == IDalunos)
                        {
                            printf("\nIndique o ID do exame que quer inscrever:");
                            scanf("%d", &IDexame);
                            for (mn = 0; mn < listExame; mn++)
                            {

                                if (exames[mn].ID == IDexame)
                                {
                                    char sala[10];
                                    printf("\nDesignação da Sala:");
                                    scanf("%s", sala);
                                    for (nn = 0; nn < listSalas; nn++)
                                    {
                                        if (strcmp(salas[nn].designacao, sala) == 0)
                                        {

                                            printf("Diga um lugar de 1 a %d para realizar o seu exame:", salas[nn].lugaresTOTAL);
                                            scanf("%d", &cadeira);
                                            if (salas[nn].lugares.lugares[cadeira - 1] == 1)
                                                printf("\nEssa cadeira está ocupada!");
                                            else
                                            {
                                                salas[nn].lugares.lugares[cadeira - 1] = 1; //posição - 1
                                                salas[nn].lugares.IDalunos[cadeira - 1] = IDalunos;
                                                salas[nn].lugaresOCUP++;
                                                printf("\nO seu lugar no exame será o %d", cadeira);
                                            }



                                        }
                                    }


                                }

                            }
                        }
                    }





                }
            }


            break;
        }


        }
    } while (op != 0);
    return listSalas;
}

void main()
{
    EXAME* exa;
    exa = malloc(nsalas * sizeof(EXSALA));
    setlocale(LC_ALL, "Portuguese");
    // EXAMES
    int listExame = 0;
    EXAME exames[DimExames];
    iniciarBiblExam(exames, DimExames);

    // ALUNOS
    int listAlunos = 0, maxAlunos = 0;
    ALUNO alunos[DimAlunos];
    iniciarBiblAlunos(alunos, DimAlunos);

    // UC
    UC uc[DimUC];
    int listUC = 0;
    iniciarBiblUC(uc, DimUC);

    // SALAS
    int listSalas = 0;
    SALAS salas[DimSalas];
    iniciarBiblSalas(salas, DimSalas);

    int op;
    do
    {
        printf("\n\t***Menu***");
        printf("\n\t1-Exames\n\t2-Alunos\n\t3-Unidades Curriculares\n\t4-Salas\n\t0-Sair");
        printf("\n\tOpcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            if (listUC == 0)
                printf("\nAdicione pelo menos 1 Unidade Curricular!\n");
            else
            {
                if (listSalas == 0)
                    printf("\nAdicione pelo menos 1 Sala!\n");
                else
                    listExame = menuExame(exames, listUC, uc, listSalas, salas);
            }
        }break;
        case 2:
        {
            listAlunos = menuAlunos(alunos);
        }break;
        case 3:
        {
            listUC = menuUC(uc);
        }break;
        case 4:
        {
            listSalas = menuSala(salas, listExame, exames, listUC, uc, listAlunos, alunos);
        }break;
        }
    } while (op != 0);
}
