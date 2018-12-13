#include "Mago.h"



Mago::Mago()
{
	tipo = tMago;
}


Mago::~Mago()
{
}

void Mago::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("Mago"))
	{
		gRecursos.carregarSpriteSheet("Mago", "spritesheets/Mage.png", 4, 4);
		
		sprite.setSpriteSheet("Mago");

	}
}

void Mago::desenhar()
{
	sprite.desenhar(x, y);
}

void Mago::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Mago::ataqueSpecial()
{
}

void Mago::moverAnim()
{
	if (gTeclado.segurando[TECLA_D])
	{

		sprite.setAnimacao(Mdir);
		this->dir = true;
		this->esq = false;
		this->cima = false;
		this->baixo = false;
	
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		sprite.setAnimacao(Mesq);
		this->dir = false;
		this->esq = true;
		this->cima = false;
		this->baixo = false;
	
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		sprite.setAnimacao(Mcima);
		this->dir = false;
		this->esq = false;
		this->cima = true;
		this->baixo = false;
	
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		sprite.setAnimacao(Mbaixo);
		this->dir = false;
		this->esq = false;
		this->cima = false;
		this->baixo = true;
	
	}
}

void Mago::animacao()
{
	sprite.avancarAnimacao();
}

