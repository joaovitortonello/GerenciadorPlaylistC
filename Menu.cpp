/*

    	Exercício a ser entregue
    Obs.: Utilizar Listas Simples Dinâmicas. Nada de vetor, matriz ou outro tipo de
    estrutura.
    1) Criar um Gerenciador de músicas de uma playlist, mas com comportamento de
    edição livre, como um editor de playlist de DJ ou de streaming. Você criará um
    arquivo TXT contendo um ID único, título, Artista, Ano, Álbum, Tipo de Versão
    e ID_Original. Você poderá inserir outras músicas com os mesmos dados,
    sempre colocando na última posição do arquivo. No entanto, ao ser lido e
    colocado em uma lista, poderá inserir, remover, mover, buscar, embaralhar ou
    ordenar. Inclusive gravar outro arquivo com algum nome que desejar, por
    exemplo: Lista Por Ano ou Lista Por Álbum ou Lista Aleatória etc. Quando for
    abrir, poderá escolher qual arquivo TXT deseja. No entanto, o TXT original, com
    todas as músicas deve se manter intacto, na mesma sequência de criação.
    Portanto, o programa deve permitir inserir ou remover músicas no arquivo
    original. A partir dele, ao escolher criar uma lista Por Ano, deverá permitir gravar
    um outro arquivo contendo essas informações organizadas por ano. Isso
    também deve ser adotado para as outras formas de organização das listas
    dinâmicas.
    A ideia central é que o usuário pode:
    Inserir uma música em qualquer posição da lista, não só no início ou no fim,
    simulando quando você quer que uma faixa toque em um momento específico
    da playlist.
    Remover qualquer música pelo nome, posição ou artista, exigindo percurso e
    manipulação de ponteiros em pontos arbitrários.
    Mover uma música de uma posição para outra, o que é a operação mais rica,
    pois envolve remover o nó de um lugar e reinseri-lo em outro sem perder a
    cadeia.
    Buscar por artista e listar todas as faixas dele que aparecem na playlist,
    praticando percurso completo.
    Embaralhar a ordem de forma simulada, trocando posições de nós, o que é
    um exercício avançado de manipulação de ponteiros.
    Ordenar por Ordem Alfabética da Música: o intuito é montar uma playlist

*/

#include "TadLista.h"


void menu() {
	char op = '1';

	struct LISTAD* Inicio = NULL;
	struct LISTAD* Fim = NULL;

	while (op != '\x1b') {
		system("cls");
		printf("*****  MENU PRINCIPAL ******\n");
		printf("<I>nserir \n");
		printf("<R>emover\n");
		printf("<L>ocalizar\n");
		printf("<M>ostrar\n");
		printf("<ESC> Sair\n");
		printf("Informe a Opção Desejada: ");
		scanf("%c", &op);

		printf("\n");
		switch (op) {
		case 'i':
		case 'I':
			inserir(&Inicio, &Fim);
			break;
		case 'r':
		case 'R':
			if (Inicio == NULL) {
				printf("\nLista Ainda Nao Existe, Insira Elementos!!!\n");
			}
			else {
				remover(&Inicio, &Fim);
			}
			break;
		case 'm':
		case 'M':
			if (Inicio == NULL) {
				printf("\nLista Ainda Nao Existe, Insira um Elemento!!!\n");
			}
			else {
				int pos;
				if (Inicio == Fim) {
					pos = 0;
					mostrar(&Inicio, pos);
				}
				else {
					pos = 0;
					while (pos != 1 && pos != 2) {
						printf("Deseja iniciar por qual extremindade (1 - Inicio, 2 - Fim): ");
						scanf("%d", &pos);
						if (pos != 1 && pos != 2) {
							printf("Número incorreto, informe 1 ou 2\n");
						}
					}
					if (pos == 1) {
						mostrar(&Inicio, pos);
					}
					else {
						mostrar(&Fim, pos);
					}
				}
			}
			break;
		case 'l':
		case 'L':
			if (Inicio == NULL) {
				printf("Lista Nao Existe!!! Insira Elementos!!!\n");
			}
			else {
				int ch, pos = 0;
				struct LISTAD* RetornaElem = NULL;
				while (pos != 1 && pos != 2) {
					printf("Deseja iniciar por qual extremindade (1 - Inicio, 2 - Fim): ");
					scanf("%d", &pos);
					if (pos != 1 && pos != 2) {
						printf("Número incorreto, informe 1 ou 2\n");
					}
				}
				printf("Informe a Chave: ");
				scanf("%d", &ch);
				if (pos == 1) {
					localizar(&Inicio, pos, ch, &RetornaElem);
				}
				else {
					localizar(&Fim, pos, ch, &RetornaElem);
				}
			}
			break;
		case 27:
			printf("\n***** SAINDO DO PROGRAMA *****\n");
			break;
		default:
			printf("\nERRO!! Informe [i/I], [r/R],[b/B],[m/M] ou [ESC]\n");
		}//FIM Switch
		system("pause");
	}//FIM DO WHILE 1
}