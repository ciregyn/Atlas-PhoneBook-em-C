#ifndef CONTATO_H
#define CONTATO_H

#define MAX_NOME     50
#define MAX_CPF      15
#define MAX_IDADE    3
#define MAX_EMAIL   100
#define MAX_TELEFONE 20
#define MAX_CONTATOS 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int idade;
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
} Contato;


#endif