#ifndef VALIDACAO_H
#define VALIDACAO_H

#include "contato.h"

// Valida formato e dígitos do CPF
int validarCPF(char cpf[]);

// Valida se o email tem @ e ponto
int validarEmail(char email[]);

// Valida se o telefone está no formato (11)99999-0000
int validarTelefone(char telefone[]);

// Verifica se CPF já está cadastrado
int contatoExiste(Contato contatos[], int total, char cpf[]);

// Verifica se email já está cadastrado
int emailExiste(Contato contatos[], int total, char email[]);

// Verifica se telefone já está cadastrado
int telefoneExiste(Contato contatos[], int total, char telefone[]);

#endif