/*
	TRABALHO AV2 - ESTRUTURA DE DADOS - UVA

	Prof:	Alfredo Boente
	Nomes:	Victor Dias Tavares Rocha, 20172101249
			Hênio Paiva, 20172103237

	Este código tem como objetivo estudar o funcionamento de uma pilha circular
	Para isso desenvolvemos um jogo onde structs que representam cartas e jogadores
	serão armazenadas em duas pilhas circulares
	(Todos os structs estão definidos no arquivo "Grafico.h")
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Grafico.h"

void criar_baralho(Baralho*, int);		// Cria um espaço na memória, onde as cartas serão armazenadas em pilha
void organizar(Baralho*);				// Armazena de forma ordenada 52 cartas em pilha
void embaralhar(Baralho*);				// Arranja as cartas de uma pilha aleatoriamente

void push_carta(Baralho*, int, char);	// Inclui uma carta no topo de uma pilha
Carta pop_carta(Baralho*);				// Remove uma carta no topo de uma pilha
void limpar_baralho(Baralho*);			// Remove todos os elementos de uma pilha

void criar_grupo(Grupo*, int);			// Cria um espaço na memória, onde jogadores serão armazenadas em pilha
int push_jogador(Grupo*, char*);		// Inclui um jogador no topo de uma pilha
int alterar_jogador(Grupo*, char*);		// Altera o nome de um jogador

void titulo();
void menu();

int main() {
	srand(time(NULL));

	Baralho baralho;
	Grupo grupo;
	Carta carta;
	int num, op, op2, pnts;
	char nome[12];

	criar_baralho(&baralho, 52);

	titulo();
	do {
		printf("Quantidade de jogadores (2 - 6):\n> ");
		scanf(" %d", &num);
	} while(num < 2 || num > 6);
	criar_grupo(&grupo, num);

	printf("Digite os nomes\n");
	for(int i = 0; i < num; i++) {
		do {
			printf("[%d]: ", i);
			scanf(" %s", nome);
		} while(!push_jogador(&grupo, nome));
	}

	do {
		system("cls");
		titulo();
		menu();
		scanf(" %d", &op);
		switch(op) {
		case 1: // Começar jogo

			// São realizadas 3 jogadas
			for(int jogadas = 1; jogadas < 4; jogadas++) {

				// Antes de distribuir as cartas para cada jogador o baralho é organizado e embaralhado
				organizar(&baralho);
				embaralhar(&baralho);

				// Um loop que irá distribuir 5 cartas por jogador em uma jogada
				for(int i = 0; i <= grupo.topo; i++) {
					system("cls");
					printf("Jogo %d", jogadas);

					// Caso falte cartas no baralho, ele será organizado e embaralhado novamente
					if(baralho.topo < 5) {
						organizar(&baralho);
						embaralhar(&baralho);
					}

					// Inclusão de 5 cartas na mão de um jogador
					for(int j = 0; j < 5; j++) {
						carta = pop_carta(&baralho);
						push_carta(&grupo.jogadores[i].mao, carta.num, carta.naipe);
					}
					printf("\n\xC4\xC4\xC4 %s\n", grupo.jogadores[i].nome);
					mostrar_cartas(&grupo.jogadores[i].mao);

					// Todos os jogadores têm a opção de mudar a mão apenas uma vez por jogada
					linha();
					printf("Deseja alterar a mao ?(Sim - 1|Nao - 0) \n");
					scanf(" %d", &op2);
					if(op2) {
						limpar_baralho(&grupo.jogadores[i].mao);
						for(int j = 0; j < 5; j++) {
							carta = pop_carta(&baralho);
							push_carta(&grupo.jogadores[i].mao, carta.num, carta.naipe);

						}
						mostrar_cartas(&grupo.jogadores[i].mao);
					}

					// A pontuação da jogada é feita manualmente
					printf("\nDigite quantidade de pontos:\n");
					printf("[%s]: ", grupo.jogadores[i].nome);
					scanf(" %d", &pnts);
					grupo.jogadores[i].pontos += pnts;
					limpar_baralho(&grupo.jogadores[i].mao);
				}
			}
			break;
		case 2: // Mostrar pontos

			// Mostra a lista de jogadores e o total de pontos que cada um recebeu em um jogo
			system("cls");
			printf("\tPontos dos Jogadores\n");
			for(int i = 0; i < grupo.capa; i++) {
				printf("[%s]: %d\n", grupo.jogadores[i].nome, grupo.jogadores[i].pontos);
			}
			break;
		case 3: // Aletrar jogador

			// Altera o nome de um jogador
			system("cls");
			printf("Digite nome atual do jogador: ");
			scanf(" %s", nome);
			alterar_jogador(&grupo, nome);
			break;
		case 0: // Sair
			printf("Saindo ...\n");
			break;
		default:
			printf("Operacao desconhecida\n");
		}
		system("pause");
	} while(op != 0);


	// Libera a memória que foi ocupada
	free(baralho.cartas);
	for(int i = 0; i <= grupo.topo; i++) {
		free(grupo.jogadores[i].mao.cartas);
	}
	free(grupo.jogadores);
	return 0;
}

void criar_baralho(Baralho* ptr, int cap) {
	ptr->capa = cap;
	ptr->topo = -1;
	ptr->cartas = (Carta*) malloc(cap * sizeof(Carta));
}

void organizar(Baralho* ptr) {
	ptr->topo = -1;
	char np; // naipe
	for(int i = 0; i < 4; i++) {
		switch(i) {
		case 0:
			np = 'C';
			break;
		case 1:
			np = 'O';
			break;
		case 2:
			np = 'E';
			break;
		default:
			np = 'P';
		}
		for(int j = 1; j <= 13; j++) {
			push_carta(ptr, j, np);
		}
	}
}

void embaralhar(Baralho* ptr) {
	// Cria um vetor estático do tipo Carta onde todas as suas posições são nulas
	Carta cartas[52] = { NULL };
	int r;

	for(int i = 0; i < 52; i++) {
		do {
			// cria um número aleatório de 0 até 51
			r = rand() % 52;

			// Quando a posição aleatória do vetor já está ocupada é realizado um loop até achar uma posição não preenchida
		} while(cartas[r].num);

		// Inclui numa posição aleatória do vetor uma carta que foi removida do topo do baralho referenciado
		cartas[r] = pop_carta(ptr);
	}

	// Inclui todas as cartas que foram embaralhadas de volta ao baralho
	for(int i = 0; i < 52; i++) {
		push_carta(ptr, cartas[i].num, cartas[i].naipe);
	}
}

void push_carta(Baralho* ptr, int num, char naipe) {
	if(ptr->topo < ptr->capa - 1) {
		ptr->topo++;
		ptr->cartas[ptr->topo].naipe = naipe;
		ptr->cartas[ptr->topo].num = num;
	} else {
		printf("Baralho cheio\n");
	}
}

Carta pop_carta(Baralho* ptr) {
	Carta aux = ptr->cartas[ptr->topo--];
	return aux;
}

void criar_grupo(Grupo* ptr, int cap) {
	ptr->capa = cap;
	ptr->topo = -1;
	ptr->jogadores = (Jogador*) malloc(cap * sizeof(Jogador));
}

int push_jogador(Grupo* ptr, char* nome) {

	for(int id = 0; id <= ptr->topo; id++) {
		if(!strcmp(ptr->jogadores[id].nome, nome)) {
			printf("Jogador já existe!\n");
			return 0;
		}
	}

	ptr->topo++;
	ptr->jogadores[ptr->topo].pontos = 0;
	strcpy(ptr->jogadores[ptr->topo].nome, nome);

	criar_baralho(&ptr->jogadores[ptr->topo].mao, 5);
	return 1;
}

int alterar_jogador(Grupo* ptr, char* nome) {
	char novo[12];

	for(int id = 0; id <= ptr->topo; id++) {
		if(!strcmp(ptr->jogadores[id].nome, nome)) {
			printf("Digite novo nome: ");
			scanf(" %s", novo);
			strcpy(ptr->jogadores[id].nome, novo);
			printf("Jogador alterado com sucesso!\n");
			return 1;
		}
	}

	printf("Jogador não encontrado\n");
	return 0;
}

void limpar_baralho(Baralho* ptr) {
	ptr->topo = -1;
}

void menu() {
	printf("\tMenu Principal\n\n");
	printf("(1) Comecar\n");
	printf("(2) Mostrar Pontos\n");
	printf("(3) Alterar Jogador\n");
	printf("(0) Encerrar\n> ");
}

void titulo() {
	printf("\tJogo de Cartas\n\n");
	linha();
}

