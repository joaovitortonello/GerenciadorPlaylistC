#include "TadLista.h"

void mostrar(struct LISTAD** p_Inicio, int pos) {
    struct LISTAD* atual = *p_Inicio;
    printf("ANTERIOR \t\t CHAVE \t\t\t\t PRÓXIMO\n");
    if ((*atual).noAnt == NULL && (*atual).noProx == NULL) {
        printf("%p \t\t %d [%p] \t\t\t %p   <--- Primeiro e Último Nó\n", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
    }
    else {
        if (pos == 1) {  // Do primeiro para o último
            while (atual != NULL) {
                if ((*atual).noAnt == NULL) {
                    printf("%p \t\t  %d [%p] \t\t %p   <--- Primeiro Nó", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                else if ((*atual).noProx == NULL) {
                    printf("%p \t\t  %d [%p] \t\t %p   <--- Último Nó", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                else {
                    printf("%p \t\t  %d [%p] \t\t %p", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                printf("\n");
                atual = (*atual).noProx;
            }
        }
        else {  // Do último para o primeiro
            while (atual != NULL) {
                if ((*atual).noProx == NULL) {
                    printf("%p \t\t  %d [%p] \t\t %p   <--- Último Nó", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                else if ((*atual).noAnt == NULL) {
                    printf("%p \t\t  %d [%p] \t\t %p   <--- Primeiro Nó", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                else {
                    printf("%p \t\t  %d [%p] \t\t %p", (*atual).noAnt, (*atual).chave, atual, (*atual).noProx);
                }
                printf("\n");
                atual = (*atual).noAnt;
            }
        }
    }
}