#pragma once
#include <iostream>
#include "libUnicornio.h"
#include"Personagem.h"
#include"Corte.h"
#include"invisibilidade.h"
#include"bolaDeFogo.h"
#include"fstream"
#include"NomePlayer.h"
#include"Menu.h"
#include"Tela.h"
#include"Itens.h"
#include"Inventario.h"


class Jogo 
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void testarColisoes();
	void executar();

	
	Personagem* personagem[3];
	tClasse classe;
	int cla;
	Corte  corte;
	invisibilidade invi;
	int atk;
	int tempo;
	animG anG;
	int animadorGuerrero;
	bolaDeFogo bolaD;
	bool start = true;
	bool bolaMover = false;
	TileMap mapa;
	NomePlayer nome;
	Menu menu;
	Tela tela;
	
	Itens itens;
	Inventario inventario;

private:


	fstream f_stream;
	
};

