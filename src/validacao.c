#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/validacao.h"

// VALIDAR CPF
int validarCPF(char cpf[]) {
    char aux[12];
    int j = 0;

    // Extrai apenas os números
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            aux[j++] = cpf[i];
        }
    }
    aux[j] = '\0';

    // Garante que possui 11 dígitos
    if (j != 11) return 0;

    sprintf(cpf, "%c%c%c.%c%c%c.%c%c%c-%c%c",
            aux[0], aux[1], aux[2],
            aux[3], aux[4], aux[5],
            aux[6], aux[7], aux[8],
            aux[9], aux[10]);
    return 1;
}

// VALIDAR EMAIL
int validarEmail(char email[]) {
    int tem_arroba = 0;
    int pos_arroba = -1;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            tem_arroba = 1;
            pos_arroba = i;
        }
    }

    if (!tem_arroba || pos_arroba == 0) return 0;

    int tem_ponto = 0;
    for (int i = pos_arroba; email[i] != '\0'; i++) {
        if (email[i] == '.') tem_ponto = 1;
    }

    return tem_ponto;
}

// VALIDAR TELEFONE
int validarTelefone(char telefone[]) {
  char aux[12];
    int j = 0;

    // Extrai apenas os números
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (isdigit(telefone[i])) {
            aux[j++] = telefone[i];
        }
    }
    aux[j] = '\0';

       // Telefone inválido
    if (j != 10 && j != 11) {
        return 0;
    }


    // Celular: (62) 99999-9999
    if (j == 11) {
        sprintf(telefone, "(%c%c) %c%c%c%c%c-%c%c%c%c",
                aux[0], aux[1],
                aux[2], aux[3], aux[4], aux[5], aux[6],
                aux[7], aux[8], aux[9], aux[10]);
    }

    // Fixo: (62) 3333-3333
    else if (j == 10) {
        sprintf(telefone, "(%c%c) %c%c%c%c-%c%c%c%c",
                aux[0], aux[1],
                aux[2], aux[3], aux[4], aux[5],
                aux[6], aux[7], aux[8], aux[9]);
    }
}

// CONTATO EXISTE (CPF)
int contatoExiste(Contato contatos[], int total, char cpf[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].cpf, cpf) == 0) 
        return 1;
    }
    return 0;
}

// EMAIL EXISTE
 int emailExiste(Contato contatos[], int total, char email[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].email, email) == 0) return 1;
    }
    return 0;
}

// TELEFONE EXISTE
int telefoneExiste(Contato contatos[], int total, char telefone[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) return 1;
    }
    return 0;
}