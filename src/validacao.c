#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/validacao.h"

// VALIDAR CPF
int validarCPF(char cpf[]) {
    char digits[12];
    int j = 0;

    // Aceita com ou sem formatação
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            digits[j++] = cpf[i];
        }
    }
    digits[j] = '\0';

    // Precisa ter exatamente 11 dígitos
    if (j != 11) return 0;

    // Rejeita CPFs com todos dígitos iguais (ex: 111.111.111-11)
    int todos_iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (digits[i] != digits[0]) {
            todos_iguais = 0;
            break;
        }
    }
    if (todos_iguais) return 0;

    // Calcula 1º dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (digits[i] - '0') * (10 - i);
    }
    int resto = soma % 11;
    int d1 = (resto < 2) ? 0 : 11 - resto;
    if (d1 != (digits[9] - '0')) return 0;

    // Calcula 2º dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (digits[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    int d2 = (resto < 2) ? 0 : 11 - resto;
    if (d2 != (digits[10] - '0')) return 0;
    //Ex: CPF: 529.982.247-25
    //9 dígitos base → cálculo → 1º verificador = 2 
    //10 dígitos (base + 1º) → cálculo → 2º verificador = 5 
    //CPF VÁLIDO!
    
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
    // Formato: (11)99999-0000 = 14 caracteres
    if (strlen(telefone) != 14) return 0;
    if (telefone[0] != '(' || telefone[3] != ')' ||
        telefone[9] != '-') return 0;
    for (int i = 0; i < 14; i++) {
        if (i == 0 || i == 3 || i == 9) continue;
        if (!isdigit(telefone[i])) return 0;
    }
    return 1;
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