#include "Tela.h"
#include"Menu.h"


Tela::Tela()
{
}


Tela::~Tela()
{
}

void Tela::desenhar()
{
}

void Tela::Atualizar()
{



	for (int i = 0; i < 3; i++)
	{
		tipoTelas(tipoTela[i]);
		desenharBotoes(botoes[i]);






	}



}
	
	

	



void Tela::iniciar()
{
	

/*
	if (gRecursos.carregouSpriteSheet("botaoJogar"))
	{
		gRecursos.carregarSpriteSheet("botaoJogar", "spritesheet/jogar.png");
		botaoJogar.setSpriteSheet("botaoJogar");
		botaoJogar.setPos(gJanela.getLargura() / 2, 440);
	}
	if (!gRecursos.carregouSpriteSheet("botaoSair"))
	{
		gRecursos.carregarSpriteSheet("botaoSair", "spritesheet/sair.png");
		botaoSair.setSpriteSheet("botaoSair");
		botaoSair.setPos(gJanela.getLargura() / 2, 640);*/
	/*}*/
	
}

void Tela::telaJogo()
{
	
	if (!gRecursos.carregouSpriteSheet("fundoTelaJogo"))
	{
		gRecursos.carregarSpriteSheet("fundoTelaJogo", "assets/spritesheets/telajogo.jpg");
		fundoTelaJogo.setSpriteSheet("fundoTelaJogo");
	}
		
	fundoTelaJogo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void Tela::telaMenu()
{
	if(!gRecursos.carregouSpriteSheet("fundoTelaMenu"))
	{ 
	gRecursos.carregarSpriteSheet("fundoTelaMenu", "assets/spritesheets/telamenu.jpg");
	fundoTelaMenus.setSpriteSheet("fundoTelaMenu");
	}
	fundoTelaMenus.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	

}

void Tela::telaCreditos()
{
}

void Tela::telaOpcoes()
{
}

void Tela::desenharBotoes(string botao)
{
	if (botao == "jogar")
	{

		if (!gRecursos.carregouSpriteSheet("botaoJogar"))
		{
			gRecursos.carregarSpriteSheet("botaoJogar", "spritesheets/jogar.png");
			botaoJogar.setSpriteSheet("botaoJogar");
			botaoJogar.setPos(gJanela.getLargura() / 2, 440);


		}
		botaoJogar.atualizar();
		botaoJogar.desenhar();
	

		if (botaoJogar.estaClicado())
		{
			bJclicou = true;
			comecarJogo = true;
		}
	}


	 if (botao == "Sair")
	{
	
			if (!gRecursos.carregouSpriteSheet("botaoSair"))
			{
				gRecursos.carregarSpriteSheet("botaoSair", "spritesheets/sair.png");
				botaoSair.setSpriteSheet("botaoSair");
				botaoSair.setPos(gJanela.getLargura() / 2, 500);
			}

			botaoSair.atualizar();
			botaoSair.desenhar();
		

			if (botaoSair.estaClicado())
			{
				bSclicou = true;
			}

		
	}

}


void Tela::desenharJogar()
{
	{
		botaoJogar.desenhar();
		botaoJogar.atualizar();
		if (botaoJogar.estaClicado())
		{
			bJclicou = true;
		}


	}
}

void Tela::desenharSair()
{
	botaoSair.desenhar();
	botaoSair.atualizar();

	if (botaoSair.estaClicado())
	{
		bSclicou = true;
	}
}

void Tela::tipoTelas(TipoTela tela)
{
	if (tela == tTelaMenu)
	{
		telaMenu();
	}
	if (tela == tTelaJogo)
	{
		telaJogo();
	}
}
