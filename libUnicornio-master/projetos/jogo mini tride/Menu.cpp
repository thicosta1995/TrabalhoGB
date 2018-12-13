#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::alteraçaoDeTela()
{
}

void Menu::incialisar()
{
	/*gRecursos.carregarSpriteSheet("botaoJogar", "imagens/jogar.png");
	gRecursos.carregarSpriteSheet("botaoSair", "imagens/sair.png");

	botaoJogar.setSpriteSheet("botaoJogar");
	botaoSair.setSpriteSheet("botaoSair");

	botaoJogar.setPos(gJanela.getLargura() / 2, 440);
	botaoSair.setPos(gJanela.getLargura() / 2, 640);
	if(botaoJogar.estaClicado())*/
	//botaoSair.atualizar();
	//botaoJogar.desenhar()*/;
	///*botaoSair.atualizar();
	
	//botaoSair.desenhar();*/
	tela[0].tipoTela[0] = tTelaMenu;
	tela[0].botoes[0] = "jogar";
	tela[0].opções[0] = 0;

	tela[0].botoes[1] = "Sair";
	tela[0].opções[1] = 1;
	

	tela[1].tipoTela[1] = tTelaJogo;
	tela[1].comecarJogo = true;
	tela[2].tipoTela[2] = tTelaOpcoes;
	tela[2].opções[0] = 0;
	tela[3].tipoTela[3] = tTelaCreditos;
	tela[3].opções[0] = 0;
	pilha_tela.push(&tela[0]);
	
	
}

void Menu::atualisar()
{
	pilha_tela.top()->Atualizar();
	if (tela[ordem].bJclicou == true)
	{
		ordem++;
		pilha_tela.push(&tela[ordem]);
		pilha_tela.top()->Atualizar();
	}
	else if (tela[ordem].bSclicou == true)
	{
		ordem == 0;
		pilha_tela.push(&tela[ordem]);
		pilha_tela.top()->Atualizar();
	}
	else if (tela[2].bSclicou == true)
	{
		ordem == 0;
		pilha_tela.push(&tela[ordem]);
	}
	else if (tela[3].bSclicou == true)
	{
		ordem == 0;
		pilha_tela.push(&tela[ordem]);
		pilha_tela.top()->Atualizar();
	}
	

}
