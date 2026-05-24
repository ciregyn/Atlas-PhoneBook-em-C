#include <stdio.h>
#include <string.h>


#include "../include/contato.h"
#include "../include/validacao.h"
#include "../include/arquivo.h"

void removerContato(Contato contatos[], int *total) {
    int idProcurado, achou = 0;
    char confirmacao;

    printf("\n--- REMOVER CONTATO ---\n");
    printf("Digite o ID do contato que deseja excluir: ");
    scanf("%d", &idProcurado);

    for (int i = 0; i < (*total); i++) {
        if (contatos[i].id == idProcurado) {
            achou = 1;

            //  Mostrar o contato encontrado antes de apagar
            printf("\nContato Encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("CPF: %s\n", contatos[i].cpf);
            printf("Telefone: %s\n", contatos[i].telefone);

            //  Confirmar a remocao com o usuario
            printf("\nDeseja realmente excluir este contato? (S/N): ");
            scanf(" %c", &confirmacao); // Espaco antes do %c limpa o Enter do teclado

            if (confirmacao == 'S' || confirmacao == 's') {
                
                // Remover de fato (Logica de deslocamento)
                for (int j = i; j < (*total) - 1; j++) {
                    contatos[j] = contatos[j + 1];
                }
                
                (*total)--; // Diminui o contador geral na memoria RAM
                printf("Contato removido com sucesso!\n");
                
                // Salvar backup logo apos a exclusao (Funcao do modulo arquivo.h)
                sobrescreverArquivo(contatos, *total); 

            } else {
                printf("Remocao cancelada pelo usuario.\n");
            }
            break;
        }
    }
    if (!achou) printf("Contato com ID %d nao encontrado.\n", idProcurado);
}
