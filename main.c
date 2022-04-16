#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escopo.h"

int main(void)
{

    int op;

    do{
        puts("\n========== MENU ==========");
        puts("\n1 - Cadastrar\n2 - Consultar\n3 - Alterar Registro\n4 - Remover Registro\n0 - Sair");
        puts("============================");
        scanf("%d", &op);

        switch (op){
        case 0:
            puts("\n");
            break;
        case 1:
            cadastrar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            alterar();
            break;
        case 4:
            remover();
            break;
        default:
            puts("Opção Invalida.\n");
        }
    } while (op != 0);

    return 0;
}
