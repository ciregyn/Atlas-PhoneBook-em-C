#include <stdio.h>
#include <string.h>

#include "../include/arquivo.h"
#include "../include/contato.h"
#include "../include/operacoes.h"

/* ── exibirContato ───────────────────────────────────────── */
void exibirContato(Contato contato) {
    printf("\n  ID       : %d\n",  contato.id);
    printf("  Nome     : %s\n",   contato.nome);
    printf("  CPF      : %s\n",   contato.cpf);
    printf("  Idade    : %d\n",   contato.idade);
    printf("  Email    : %s\n",   contato.email);
    printf("  Telefone : %s\n",   contato.telefone);
}

/* ── listarContatos ──────────────────────────────────────── */
void listarContato() {

    Contato contatos[MAX_CONTATOS];

    int total = carregarContatos(contatos);

    if(total == 0) {

        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE CONTATOS =====\n");

    for(int i = 0; i < total; i++) {

        exibirContato(contatos[i]);
    }

    printf("\nTotal de contatos: %d\n", total);
}

/* ── buscarContato ───────────────────────────────────────── */
void buscarContato() {
    int opcao;

    while (1) {
        printf("\n--- CONSULTAR CONTATO ---\n");
        printf("1 - ID\n");
        printf("2 - Nome\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        Contato contatos[MAX_CONTATOS];
        int total = carregarContatos(contatos);

        if (opcao == 1) {

            int id;
            printf("ID: ");
            scanf("%d", &id);
            getchar();

            int encontrado = 0;
            for (int i = 0; i < total; i++) {
                if (contatos[i].id == id) {
                    exibirContato(contatos[i]);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
                printf("Contato nao encontrado.\n");

        } else if (opcao == 2) {

            char nome[MAX_NOME];
            printf("Nome: ");
            fgets(nome, MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            int encontrado = 0;
            for (int i = 0; i < total; i++) {
                if (strstr(contatos[i].nome, nome) != NULL) {
                    exibirContato(contatos[i]);
                    encontrado = 1;
                }
            }
            if (!encontrado)
                printf("Contato nao encontrado.\n");

        } else {
            printf("Opcao invalida.\n");
        }

        printf("\n1 - Nova consulta\n");
        printf("2 - Retornar ao Menu\n");
        printf("Opcao: ");

        int pos;
        scanf("%d", &pos);
        getchar();

        if (pos != 1)
            break;
    }
}
