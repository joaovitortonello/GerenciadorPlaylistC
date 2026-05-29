#include "Bibliotecas.h"

typedef struct ListaS {

    int id;
    char Titulo[50];
    char Artista[50];
    int Ano;
    char Album[50];
    char TipoVersao[50];
    int IdOriginal;

    struct ListaS* NoProx;

};

void Adicionar();

void Menu();
