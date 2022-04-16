#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESCOPO_H



typedef struct turma           
{                              
    int idTurma;
    char turnoTurma[20];
    char docenteTurma[20];
    char codigoDisciplina[15];
} tTurma;

tTurma Turma[50];

typedef struct disciplina      
{                              
    char nomeDisciplina[25];   
    char codigoDisciplina[15]; 
    int chDis;          
} tDis;

tDis Disciplina[30];

typedef struct historico 
{                        
    int numeroAluno;     
    float notaFinal;     
    int idTurma;
} tHistorico;

tHistorico Historico[100];

int qtdTur = 0, qtdDis = 0, qtdHis = 0, tam = 100;


void salvarArq(){

    FILE *arq = fopen("Database.dat", "w");
    int i;

    if (arq){
        fprintf(arq, "\n         DISCIPLINA");

        for (i = 1; i <= qtdDis; i++){
            fprintf(arq, "\nNome: %s\n", Disciplina[i].nomeDisciplina);
            fprintf(arq, "Codigo: %s\n", Disciplina[i].codigoDisciplina);
            fprintf(arq, "Carga Horaria: %d\n", Disciplina[i].chDis);
            fprintf(arq, "===========     ================      =============");
        }

        fprintf(arq, "\n\n            TURMA\n");
        for (i = 1; i <= qtdTur; i++){
            fprintf(arq, "\nID da Turma: %d\n", Turma[i].idTurma);
            fprintf(arq, "Turno: %s\nDocente: %s\n", Turma[i].turnoTurma, Turma[i].docenteTurma);
            fprintf(arq, "Codigo da Turma: %s\n", Turma[i].codigoDisciplina);
            fprintf(arq, "===========     ================      =============");
        }

        fprintf(arq, "\n\n           HISTORICO  \n");
        for (i = 1; i <= qtdHis; i++){

            fprintf(arq, "\nNumero do aluno: %d\n", Historico[i].numeroAluno);
            fprintf(arq, "ID da Turma: %d\nNota Final: %.2f\n",  Historico[i].idTurma, Historico[i].notaFinal);
            fprintf(arq, "===========     ================      =============");
        }
    } else{
        printf("ERROR: \n");
    }
    fclose(arq);
}

int cadastrar(){
    int op, len;

    puts("\n -Cadastrar-");
    printf("\n Deseja cadastrar:\n\n 1 -> Disciplina\n 2 -> Turma\n 3 -> Historico\n 0 -> Voltar\n");
    puts("====================================================");
    scanf("%d", &op);

    switch (op){

    case 1:

            fflush(stdin);

            tDis Dis;
            puts("-- Cadastrar Disciplina --\n\n Aperte Enter para continuar");
            scanf("%*c");                       
            printf("Nome da Disciplina: ");
            fgets(Dis.nomeDisciplina, 30, stdin);
            len = strlen(Dis.nomeDisciplina);
            if (Dis.nomeDisciplina[len - 1] == '\n')
                Dis.nomeDisciplina[len - 1] = '\0';
            printf("Digite o Codigo da Disciplina: ");
            scanf("%s", &Dis.codigoDisciplina);
            printf("Digite a carga horaria: ");
            scanf("%d", &Dis.chDis);
            qtdDis++;
            Disciplina[qtdDis] = Dis;
            puts("=========================================");
            salvarArq();
        break;

    case 2:

            puts("----- CADASTRO TURMA -----");
            tTurma Tur;
            puts("");
            scanf("%*c");
            printf("Codigo: ");
            scanf("%s", &Tur.codigoDisciplina);
            printf("Turno: ");
            scanf("%s", Tur.turnoTurma);
            printf("Doscente: ");
            scanf("%s", Tur.docenteTurma);
            printf("ID : ");
            scanf("%d", &Tur.idTurma);
            qtdTur++;
            Turma[qtdTur] = Tur;
            puts("======================================");
            salvarArq();
            return 1;
        break;

    case 3: 
            puts("----- CADASTRO HISTORICO -----");
            tHistorico His;
            puts("");
            scanf("%*c");
            printf("Numero do estudante: ");
            scanf("%d", &His.numeroAluno);
            printf("ID da Turma: ");
            scanf("%d", &His.idTurma);
            printf("Nota final: ");
            scanf("%f", &His.notaFinal);
            qtdHis++;
            Historico[qtdHis] = His;
            puts("--------------------------");
            salvarArq();
            return 1;
        break;
    case 0:
        break;
    default:
        puts("Opcao invalida");
    }
}

int alterar(){
    int op;

    puts("\n     ALTERACAO     ");
    printf("\n 1-> Disciplina\n 2-> Turma\n 3-> Historico\n 0-> Voltar\n");
    puts("========================");
    scanf("%d", &op);

    switch (op){

    int num, op2;
    case 1:
        puts("Disciplina selecionado");
        printf("Qual registro deseja alterar: ");
        scanf("%d", &num);
        if (num > qtdDis){
            printf("Disciplina nao encontrada.\n");
            break;
        }
        printf("Alterar:\n1-> Nome\n2-> Codigo\n3-> Carga horaria\n\n");
        scanf("%d", &op2);

        switch (op2){
            case 1:
                printf("Nome da Disciplina Atualizado: ");
                scanf("%s", &Disciplina[num].nomeDisciplina);
            break;

            case 2:
                printf("Codigo Atualizado: ");
                scanf("%s", &Disciplina[num].codigoDisciplina);
            break;

            case 3:
                printf("Carga Horaria Atualizada: ");
                scanf("%d", &Disciplina[num].chDis);
            break;

            default:
                puts("Opcao invalida!");
            break;
        }

        salvarArq();
        break;
    case 2:
        puts("Turma selecionado");
        printf("Qual registro deseja alterar: ");
        scanf("%d", &num);
        if (num > qtdTur){
            printf("Turma nao encontrada.\n");
            break;
        }
        printf("Deseja alterar qual campo:\n1-> ID\n2-> Codigo\n3-> Turno\n4-> Docente\n\n");
        scanf("%d", &op2);


        switch (op2){
            case 1:
                 printf("Id da Turma atualizado: ");
                scanf("%d", &Turma[num].idTurma);
            break;

            case 2:
                printf("Codigo da Turma atualizado: ");
                scanf("%s", &Turma[num].codigoDisciplina);
            break;

            case 3:
                printf("Turno da Turma atualizado: ");
                scanf("%s", &Turma[num].turnoTurma);
            break;

            case 4:
                printf("Docente da Turma atualizado: ");
                scanf("%s", &Turma[num].docenteTurma);
            break;

            default:
                puts("Opcao invalida!");
            break;
        }
        salvarArq();
        break;

    case 3:
        puts("Historico selecionado");
        printf("Qual registro deseja alterar: ");
        scanf("%d", &num);
        if (num > qtdHis)
        {
            printf("Historico nao encontrado.\n");
            break;
        }
        printf("\nAlterar:\n1-> N do aluno\n2-> ID\n3-> Nota final\n\n");
        scanf("%d", &op2);

        switch (op2){
            case 1:
                printf("Numero do aluno atualizado: ");
                scanf("%d", &Historico[num].numeroAluno);
            break;

            case 2:
                printf("ID da turma atualizado: ");
                scanf("%d", &Historico[num].idTurma);
            break;

            case 3:
                printf("Nota final atualiza: ");
                scanf("%f", &Historico[num].notaFinal);
            break;

            default:
                puts("Opcao invalida!");
            break;
        }
        salvarArq();
        break;

    case 0:
        puts("Voltando para o MENU");
    default:
        puts("Opção invalida!");
        return 1;
        break;
    }

    return 0;
}

void mostrarDis(){
    int op, i;

    do{
        puts("1-> Mostrar a tabela completa\n2-> Mostrar 1 atributo\n3-> Mostrar 2 atributos\n0-> Voltar");
        scanf("%d", &op);

        if (qtdDis == 0){
            printf("\nTabela Vazia!\n\n");
            break;
        }

        switch (op){
        case 1:
            printf("  Disciplina \n");
            for (i = 1; i <= qtdDis; i++){
                printf("\nNumero do Registro Disciplina: %d\n", i);
                printf("Nome: %s\nCodigo: %s\nCarga Horaria: %d\n\n", Disciplina[i].nomeDisciplina, Disciplina[i].codigoDisciplina, Disciplina[i].chDis);
                printf("================================\n");
            }
            break;
        case 2:
            printf("  Disciplina \n");
            for (i = 1; i <= qtdDis; i++){
                printf("\nNumero do Registro Disciplina: %d\n", i);
                printf("Nome: %s", Disciplina[i].nomeDisciplina);
                printf("==================================\n");
            }
            break;
        case 3:
            printf("  Disciplina \n");
            for (i = 1; i <= qtdDis; i++){
                printf("\nNumero do Registro Disciplina: %d\n", i);
                printf("Nome: %s", Disciplina[i].nomeDisciplina);
                printf("Codigo: %s\n", Disciplina[i].codigoDisciplina);
                printf("========================================\n");
            }
            break;
        case 0:
            break;
        default:
            puts("Opcao invalida!");
            break;
        }
    } while (op != 0);
}

void mostrarTur(){
    int op, i;
    do{
        puts("1-> Mostrar todos os dados das turmas\n2-> Mostrar 1 atributo\n3-> Mostrar 2 atributos\n4-> Mostrar 3 atributos\n0-> Voltar");
        scanf("%d", &op);
    
        switch (op){
            if (qtdTur == 0){
                printf("\nTabela Vazia!\n\n");
                op = 0;
            }
        case 1:
            puts(" Tabela Turma Todos Atributos\n");
            for (i = 1; i <= qtdTur; i++){

                printf("Numero do Registro de Turma: %d\n", i);
                printf("ID da Turma: %d\n", Turma[i].idTurma);
                printf("Codigo da Turma: %s\n", Turma[i].codigoDisciplina);
                printf("Docente: %s\nTurno: %s\n", Turma[i].docenteTurma, Turma[i].turnoTurma);

                printf("---------------------------------\n\n");
            }
            break;
        case 2:
            puts("------------- Tabela Turma 1 Atributos ---------");
            for (i = 1; i <= qtdTur; i++){
                printf("Numero do Registro de Turma: %d\n", i);
                printf("ID da Turma: %d\n", Turma[i].idTurma);
                printf("---------------------------------\n");
            }
            break;
        case 3:
            puts("------------ Tabela Turma 2 Atributos ------------");
            for (i = 1; i <= qtdTur; i++){

                printf("Numero do Registro de Turma: %d\n", i);
                printf("ID da Turma: %d\n", Turma[i].idTurma);
                printf("Turno: %s\n", Turma[i].turnoTurma);

                printf("---------------------------------\n");
            }
            break;
        case 4:
            puts("------------ Tabela Turma 3 Atributos ----------");
            for (i = 1; i <= qtdTur; i++){
                printf("Numero do Registro de Turma: %d\n", i);
                printf("ID da Turma: %d\n", Turma[i].idTurma);
                printf("Turno: %s\nDocente: %s\n", Turma[i].turnoTurma, Turma[i].docenteTurma);
                printf("---------------------------------\n");
            }
        case 0:
            break;
        default:
            puts("\nOpcao invalida!\n");
        }
    } while (op != 0);
}

void mostrarHis(){
    int op, i;
    do{
        puts("\n1-> Mostrar a tabela completa\n2-> Mostrar 1 atributo\n3-> Mostrar 2 atributos\n0-> Voltar");
        scanf("%d", &op);

        switch (op){
            if (qtdHis == 0){
                printf("\nTabela Vazia!\n\n");
                op = 0;
            }
        case 1:
            printf("--------- Tabela Historico Todos Atributos -----------\n");

            for (i = 1; i <= qtdHis; i++){
                printf("Numero do Registro de Historico: %d\nID da Turma: %d\n", i, Historico[i].idTurma);
                printf("Numero do aluno: %d\n", Historico[i].numeroAluno);
                printf("Nota Final: %.2f\n\n", Historico[i].notaFinal);
                printf("------------------------------------\n");
            }
            break;
        case 2:
            printf("--------- Tabela Historico 1 Atributo -----------\n");

            for (i = 1; i <= qtdHis; i++){
                printf("Numero do Registro de Historico: %d\n", i);
                printf("Numero do aluno: %d\n", Historico[i].numeroAluno);
                printf("------------------------------------\n");
            }
            break;
        case 3:
            printf("--------- Tabela Historico 2 Atributos -----------\n");

            for (i = 1; i <= qtdHis; i++){
                printf("Numero do Registro de Historico: %d\n", i);
                printf("Numero do aluno: %d\n", Historico[i].numeroAluno);
                printf("ID da Turma: %d\n\n", Historico[i].idTurma);
                printf("------------------------------------\n");
            }
            break;
        case 0:
            puts("Voltando para o menu 'Consultar'\n");
            break;
        default:
            puts("Opcao invalida!");
        }
    } while (op != 0);
}

void consultar(){

    int i, j, k;
    int op, o;

    do{
        puts("========== MENU Consultar ==========");
        printf("\nDeseja Consultar:\n1-> Disciplinas\n2-> Turmas\n3>- Historicos\n0-> voltar\n");
        puts("====================================");
        scanf("%d", &op);
        switch (op){
        case 1:
            mostrarDis();
            break;
        case 2:
            mostrarTur();
            break;
        case 3:
            mostrarHis();
            break;
        case 0:
            puts("Voltando para o MENU");
            break;
        default:
            puts("Opcao invalida");
            break;
        }
    } while (op != 0);
}

void remover(){
    puts("========== MENU REMOVER ==========");
    printf("|\t\t\t |");
    printf("\nDeseja Remover:\n1-> Disciplinas\n2-> Turmas\n3-> Historicos\n0-> voltar\n");
    puts("===================================");
    int i, op;
    int NR;
    tDis Dis;
    scanf("%d", &op);
    switch (op){
    case 1:
        puts("Entre com o numero do registro: ");
        scanf("%d", &NR);
        if (NR > qtdDis){
            puts("Registro de Disciplina nao encontrado!");
        }
        else{
            for (i = 1; i <= qtdDis - 1; i++){
                if (i >= NR){
                    Disciplina[i] = Disciplina[i + 1];
                }
            }
            qtdDis--;
            salvarArq();
        }
        break;
    case 2:
        puts("Entre com o numero do registro: ");
        scanf("%d", &NR);
        if (NR > qtdDis){
            puts("Registro de Turma nao encontrado!");
        }
        else{
            for (i = 1; i <= qtdDis - 1; i++){
                if (i >= NR){
                    Turma[i] = Turma[i + 1];
                }
            }
            qtdTur--;
            salvarArq();
        }
        break;
    case 3:
        puts("Entre com o numero do registro: ");
        scanf("%d", &NR);
        if (NR > qtdDis){
            puts("Registro nao encontrado!");
        }
        else{
            for (i = 1; i <= qtdDis - 1; i++){
                if (i >= NR){
                    Historico[i] = Historico[i + 1];
                }
            }
            qtdHis--;
            salvarArq();
        }
        break;
    case 0:
        puts("Voltando para o MENU");
        break;
    default:
        puts("Opcao invalida");
        break;
    }
}