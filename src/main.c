#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/contato.h"
#include "../include/arquivo.h"
#include "../include/operacoes.h"



int main() {

    Contato contatos[MAX_CONTATOS];

    int total = 0;
    int opcao = 0;

    /* =========================
       CARREGAR BACKUP
    ========================== */

    total = carregarContatos(contatos);

    do {
        
        

        exibir_menu();

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        

        switch(opcao) {

            case 1:
                cadastrarContato(contatos, &total);
                pausar();
                limpar_tela();
                break;

            case 2:
                listarContato();
                 pausar();
                 limpar_tela();
                break;

            case 3:
                buscarContato();
                 pausar();
                 limpar_tela();
                break;

            case 4:
                editarContato(contatos, total);
                 pausar();
                 limpar_tela();
                break;

            case 5:
                removerContato(contatos, &total);
                 pausar();
                 limpar_tela();
                break;

            case 6:

                limpar_tela();

                printf("\n=====================================\n");
                printf("   Obrigado por utilizar o Atlas\n");
                printf("=====================================\n\n");

                pausar();

                break;

            default:

                printf("\nOpcao invalida!\n");

                pausar();

                break;
        }

    } while(opcao != 6);

    return 0;
}

/* =========================================
   IMPLEMENTAÇÃO DAS FUNÇÕES DO MENU
========================================= */

void exibir_menu() {

    printf("=====================================\n");
    printf("      Bem-vindo ao Atlas\n");
    printf("=====================================\n\n");

    printf("Escolha uma das seguintes opcoes\n\n");

    printf("1. Cadastrar\n");
    printf("2. Listar\n");
    printf("3. Consultar\n");
    printf("4. Editar\n");
    printf("5. Remover\n");
    printf("6. Sair\n");
}

void limpar_tela() {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void pausar() {

    int c;

    // limpa buffer do teclado
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nPressione ENTER para continuar...");
    getchar();
}