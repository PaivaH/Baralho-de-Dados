/*Baralho Versão pre Alpha 0.01*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct PilhaCircular {
	int num; // As = 1, ... , J = 11, Q = 12, K = 13
	char naipe; // Ouros = 'O', Copas = 'C', Espadas = 'E', Paus = 'P'
	int topo;
} Cartas;

typedef struct ListaJogadores {
	char nome[12];
	Cartas mao[5];
	int pont;
	struct s_jogadores *prox;
} Jogadores;

int criar_baralho(Cartas**);
int embaralhar(Cartas**);
int criar_jogador(Jogadores**);//Inclusao
int push_carta(Cartas**, int num, int naipe);//Inclusao
int pop_carta();//Remocao
int alterar_carta();//Alterar
void mostrar();//consulta
int excluir_cartas();//Remocao


void menu();

int main() {
	setlocale(LC_ALL,"portuguese");
	size_t num_jogs; // numero de jogadores (> 1 ou < 7)

	Cartas *baralho;
	criar_baralho(&baralho);

	Jogadores *grupo;
	grupo = NULL;

	


	return 0;
}

int criar_baralho(Cartas** topPtr) {
	topPtr = NULL;
	for(int i=0; i<4; i++){
		
		for(int j=1; j<=13; j++){
			push_carta(topPtr,j,i);
		}
	}
}

int push_carta(Cartas** topPtr, int num, int naipe) {
	Cartas *novo;
	novo = (Cartas*) malloc(sizeof(Cartas));
	if(novo != NULL) {

	}
}

void menu_iniciar(){
	Printf("----------------------Bem vindo-------------------\n\n");
	printf("1)Criar Jogador\n");
	printf("2)Alterar Jogador\n");
	printf("3)Excluir Jogador\n");
	printf("0)Encerrar Jogo\n");
}
