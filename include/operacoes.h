#ifndef OPERACOES_H
#define OPERACOES_H

#include "contato.h"

/* ============================
   FUNÇÕES DO MENU
============================ */

void exibir_menu();
void limpar_tela();
void pausar();

/* ============================
   OPÇÕES DO SISTEMA
============================ */

void cadastrarContato();
void listarContato();
void buscarContato();
void editarContato(Contato contatos[], int total);
void removerContato(Contato contatos[], int *total);

/* ============================
   FUNÇÕES AUXILIARES
============================ */

void exibirContato(Contato contato);

#endif