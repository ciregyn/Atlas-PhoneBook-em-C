#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include "contato.h"

/* ── Protótipos ──────────────────────────────────────────── */
void salvarContato(Contato contato);
int  carregarContatos(Contato contatos[]);
void sobrescreverArquivo(Contato contatos[], int total);
void listarArquivo();

#endif /* ARQUIVO_H */
