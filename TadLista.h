#include "Bibliotecas.h"

typedef struct LISTAD {
    int chave;
    struct LISTAD* noProx;
    struct LISTAD* noAnt;
};

#define true 1
#define false 0



void localizar(struct LISTAD** Localiza, int pos1, int codigo, struct LISTAD** RetornaELem);

void buscarPosicao(int cod, struct LISTAD** pAuxIni, struct LISTAD** pAuxFim);

void mostrar(struct LISTAD** Ini, int pos1);

void remover(struct LISTAD** Ini, struct LISTAD** Fim);

void inserir(struct LISTAD** Pri, struct LISTAD** Ult);


void Menu();