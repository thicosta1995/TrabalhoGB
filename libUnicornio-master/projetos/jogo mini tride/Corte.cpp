#include "Corte.h"



Corte::Corte()
{
	tipo = tGuerreiro;
}


Corte::~Corte()
{
	
}

void Corte::ataqueEspecial()
{

	if (gTeclado.pressionou[TECLA_ESPACO])
	{

		if (time == 0)
		{
			som.tocar();
			this->corteAtivar = true;
			time = 100;
		}
	}
}

void Corte::inicializar()
{
	this->corteAtivar = false;
	if (!gRecursos.carregouSpriteSheet("Corte"))
	{
		gRecursos.carregarSpriteSheet("Corte", "spritesheets/slash.png", 1, 4);

		spriteC.setSpriteSheet("Corte");
	
	}
}

void Corte::setSpriteSheet(string spiteSheet)
{
	spriteC.setSpriteSheet(spiteSheet);
}

void Corte::desenhar(int x,int y)
{
	spriteC.desenhar(x,y);
	
	

	


}

void Corte::setX(int x)
{
}

void Corte::setY(int y)
{
	
}

void Corte::avancarAnimaçao()
{
	spriteC.avancarAnimacao();
}

void Corte::timeAnimacao()
{
	if (time > 0)
	{

		spriteC.desenhar(guerreiro.getX() + 100, guerreiro.getY());
		spriteC.avancarAnimacao();
		time--;
	}
	else if (time == 0)
	{
		if(spriteC.terminouAnimacao())
		{
			sprite.~Sprite();
		}

	}

	gDebug.depurar("time2", time);
}

void Corte::paraAnimaçao(float time)
{
	while (time > 0)
	{
		time--;
		gDebug.depurar("time", time);
		//this->avancarAnimaçao();
	}
	if (time == 0)
	{
		this->corteAtivar = false;
	}
	
}

void Corte::corteAtivo()
{
	if (corteAtivar == true)
	{
		
		if (time<=0)
		{
			spriteC.~Sprite();
			time == 0;
		}
	}
}

void Corte::setAudio(string nome)
{
	som.setAudio(nome);

	som.setVolume(50);
}
	


