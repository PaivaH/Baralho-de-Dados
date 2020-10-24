#ifndef GRAFICO_H_
#define GRAFICO_H_

typedef struct s_carta {
	int num;    // As = 1, ... , J = 11, Q = 12, K = 13
	char naipe; // Ouros = 'O', Copas = 'C', Espadas = 'E', Paus = 'P'
} Carta;
typedef struct pilha_cartas {
	int topo;
	int capa;
	Carta *cartas;
} Baralho;
typedef struct s_jogador {
	char nome[12];
	Baralho mao;
	int pontos;
} Jogador;
typedef struct pilha_jogadores {
	int topo;
	int capa;
	Jogador *jogadores;
} Grupo;

static const char copas[5][13] = {
	{'\xBA', ' ', ' ', ' ', '\xB2', '\xB2', ' ', '\xB2', '\xB2', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB2', ' ', ' ', ' ', ' ', ' ', '\xBA'}
};
static const char ouros[5][13] = {
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB2', ' ', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', '\xB2', '\xB2', '\xB2', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', '\xB2', '\xB2', '\xB2', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB2', ' ', ' ', ' ', ' ', ' ', '\xBA'}
};
static const char espadas[5][13] = {
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB0', ' ', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', '\xB0', '\xB0', '\xB0', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB0', ' ', ' ', ' ', ' ', ' ', '\xBA'}
};
static const char paus[5][13] = {
	{'\xBA', ' ', ' ', ' ', ' ', '\xB0', '\xB0', '\xB0', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', '\xB0', '\xB0', '\xB0', ' ', ' ', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', ' ', ' ', '\xBA'},
	{'\xBA', ' ', ' ', ' ', ' ', ' ', '\xB0', ' ', ' ', ' ', ' ', ' ', '\xBA'}
};

void mostrar_cartas(Baralho*);

void p_copas(int);
void p_ouros(int);
void p_espadas(int);
void p_paus(int);

void linha();
void linha_ini();
void linha_ini_val(int);
void linha_fin();
void linha_fin_val(int);

#endif
