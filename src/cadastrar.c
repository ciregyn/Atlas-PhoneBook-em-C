#include <stdio.h>

#include "../include/contato.h"
#include "../include/arquivo.h"
#include "../include/validacao.h"


/*
Função responsável por:
- cadastrar contato
- validar dados
- salvar backup no arquivo binário
*/

void cadastrarContato(Contato contatos[], int *total)
{
    Contato contato;

    printf("\n===== CADASTRO DE CONTATO =====\n");

    printf("Digite o ID: ");
    scanf("%d", &contato.id);

    printf("Digite o nome: ");
    scanf("%s", contato.nome);

    printf("Digite o CPF: ");
    scanf("%s", contato.cpf);

    while(!validarCPF(contato.cpf))
    {
        printf("CPF invalido. Digite novamente: ");
        scanf("%s", contato.cpf);
    }

    printf("Digite a idade: ");
    scanf("%d", &contato.idade);

    printf("Digite o email: ");
    scanf("%s", contato.email);

    while(!validarEmail(contato.email))
    {
        printf("Email invalido. Digite novamente: ");
        scanf("%s", contato.email);
    }

    printf("Digite o telefone: ");
    scanf("%s", contato.telefone);

    while(!validarTelefone(contato.telefone))
    {
        printf("Telefone invalido. Digite novamente: ");
        scanf("%s", contato.telefone);
    }

    /* ======================================
       ADICIONA O CONTATO NA MEMÓRIA RAM
    ====================================== */

    contatos[*total] = contato;

    (*total)++;

    /* ======================================
       SALVA NO ARQUIVO
    ====================================== */

    salvarContato(contato);

    printf("\nContato cadastrado com sucesso!\n");
}