#pragma once

enum TipoTela 
{
	tTelaMenu, tTelaJogo, tTelaCreditos, tTelaOpcoes

};

#include"libUnicornio.h"
class Tela
{
public:
	Tela();
	~Tela();

	void desenhar();
	void Atualizar();
	
	void iniciar();

	void telaJogo();
	void telaMenu();
	void telaCreditos();
	void telaOpcoes();
	void desenharBotoes(string botao);
	void verificadorBotao();
	void desenharJogar();
	void desenharSair();
	void tipoTelas(TipoTela tela);
	TileMap mapa;
	string botoes[4];
	TipoTela tipoTela[4];
	int telas =0;
	int opções[4];
	Sprite fundoTelaMenus, fundoTelaJogo;
	BotaoSprite botaoJogar, botaoSair;
	
	bool comecarJogo = false;
	bool bJclicou = false;
		bool bSclicou = false;
		int numeracao;



		
};

