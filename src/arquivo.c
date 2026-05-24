#include <stdio.h>
#include "arquivo.h"

#define PHONEBOOK "PhoneBook.dat"

/* ── salvarContato ───────────────────────────────────────── */
/* Anexa um registro binario ao final do arquivo             */
void salvarContato(Contato contato) {
    FILE *f = fopen(PHONEBOOK, "ab");
    if (!f) {
        printf("Erro: nao foi possivel abrir o arquivo.\n");
        return;
    }
    fwrite(&contato, sizeof(Contato), 1, f);
    fclose(f);
}

/* ── carregarContatos ────────────────────────────────────── */
/* Le todos os registros e retorna a quantidade lida         */
int carregarContatos(Contato contatos[]) {
    FILE *f = fopen(PHONEBOOK, "rb");
    if (!f) return 0;

    int total = 0;
    while (total < MAX_CONTATOS &&
           fread(&contatos[total], sizeof(Contato), 1, f) == 1)
        total++;

    fclose(f);
    return total;
}

/* ── sobrescreverArquivo ─────────────────────────────────── */
/* Regrava o arquivo inteiro a partir do vetor atualizado    */
void sobrescreverArquivo(Contato contatos[], int total) {
    FILE *f = fopen(PHONEBOOK, "wb");
    if (!f) {
        printf("Erro: nao foi possivel abrir o arquivo.\n");
        return;
    }
    fwrite(contatos, sizeof(Contato), total, f);
    fclose(f);
}



