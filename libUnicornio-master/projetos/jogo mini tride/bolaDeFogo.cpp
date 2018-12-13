#include "bolaDeFogo.h"



bolaDeFogo::bolaDeFogo()
{
}


bolaDeFogo::~bolaDeFogo()
{
}

void bolaDeFogo::ataqueEspecial()
{

	if (gTeclado.segurando[TECLA_ESPACO])
	{

		if (time == 0)
		{
			som.tocar();
			this->bolaAtiva = true;
			time = 300;
		}
	}
}

void bolaDeFogo::inicializar()
{
	this->bolaAtiva = false;
	if (!gRecursos.carregouSpriteSheet("Bola"))
	{
		gRecursos.carregarSpriteSheet("Bola", "spritesheets/bola.png", 1, 5);

		spriteB.setSpriteSheet("Bola");

	}
}

void bolaDeFogo::setSpriteSheet(string spiteSheet)
{
	spriteB.setSpriteSheet(spiteSheet);
}

void bolaDeFogo::desenhar(int x, int y)
{
	spriteB.desenhar(x, y);
	this->xb = x;
	this->yb = y;
	

	

}

void bolaDeFogo::setX(int x)
{
	this->xb = x;
}

void bolaDeFogo::setY(int y)
{
	this->yb = y;
}

void bolaDeFogo::avancarAnimaçao()
{
	spriteB.avancarAnimacao();
}

void bolaDeFogo::timeAnimacao()
{
}

void bolaDeFogo::paraAnimaçao(float time)
{
}

void bolaDeFogo::bolaFrente(int x,float vel)
{
	this->xb = x += vel;
	
}

void bolaDeFogo::bolaCima(int y, float vel)
{
	this->yb = y += vel;
}

void bolaDeFogo::setAudio(string nome)
{
	som.setAudio(nome);
	som.setVolume(50);
}
