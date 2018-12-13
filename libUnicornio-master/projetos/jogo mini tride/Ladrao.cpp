#include "Ladrao.h"



Ladrao::Ladrao()
{
	tipo = tBandido;
}


Ladrao::~Ladrao()
{
}

void Ladrao::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("Bandido"))
	{
		gRecursos.carregarSpriteSheet("Bandido", "spritesheets/Thief.png",4,4);

		sprite.setSpriteSheet("Bandido");
}
}

void Ladrao::desenhar()
{
	sprite.desenhar(x, y);
}

void Ladrao::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Ladrao::ataqueSpecial()
{
}

void Ladrao::moverAnim()
{
	
	if (gTeclado.segurando[TECLA_D])
	{
	
		sprite.setAnimacao(Ldir);
		
		this->dir = true;
		this->esq = false;
		this->cima = false;
		this->baixo = false;

	}
	else if (gTeclado.segurando[TECLA_A])
	{
		sprite.setAnimacao(Lesq);
		this->dir = false;
		this->esq = true;
		this->cima = false;
		this->baixo = false;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		sprite.setAnimacao(Lcima);
		this->dir = false;
		this->esq = false;
		this->cima = true;
		this->baixo = false;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		sprite.setAnimacao(Lbaixo);
		this->dir = false;
		this->esq = false;
		this->cima = false;
		this->baixo = true;
	}
}

void Ladrao::animacao()
{
	sprite.avancarAnimacao();
}
