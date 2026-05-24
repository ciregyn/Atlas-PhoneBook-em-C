#include <stdio.h>
#include <string.h>

// Includes obrigatórios exigidos pelo gerente do projeto:
#include "../include/contato.h"
#include "../include/validacao.h"
#include "../include/arquivo.h"

void editarContato(Contato lista[], int total)
{
    int idProcurado, achou = 0;
    printf("\n--- EDITAR CONTATO ---\n");
    printf("Digite o ID do contato que deseja alterar: ");
    scanf("%d", &idProcurado);

    for (int i = 0; i < total; i++)
    {
        if (lista[i].id == idProcurado)
        {
            printf("Contato encontrado! Insira os novos dados:\n");

            printf("Novo Nome: ");
            getchar(); // Limpa o buffer do teclado
            fgets(lista[i].nome, MAX_NOME, stdin); // Lê o nome com espaços
            lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0'; // Remove a nova linha do final

  // Validando o cpf do contato editado.     
            printf("Novo CPF: ");
            scanf("%s", lista[i].cpf);
                while (!validarCPF(lista[i].cpf)) {
                printf("CPF invalido. Digite novamente: ");
                scanf("%s", lista[i].cpf);
            }
//Editando Idade.
            printf("Nova Idade: ");
            scanf("%d", &lista[i].idade);

// Validando o email do contato editado.
            printf("Novo E-mail: ");
            scanf("%s", lista[i].email);
                 while (!validarEmail(lista[i].email)) {
                printf("Email invalido. Digite novamente: ");
                scanf("%s", lista[i].email);
            }

// Validando o telefone do contato editado.
            printf("Novo Telefone: ");
            scanf("%s", lista[i].telefone);
                while (!validarTelefone(lista[i].telefone)){
                    printf("Telefone invalido. Digite novamente:");
                    scanf("%s", lista[i].telefone);
                }

            printf("Contato atualizado com sucesso!\n");
            // Salvando alterações no arquivo.
            sobrescreverArquivo(lista, total);
            achou = 1;
            break;
        }
    }
    if (!achou)
        printf("Contato com ID %d nao encontrado.\n", idProcurado);
}
