#include "Guerreiro.h"



Guerreiro::Guerreiro()
{
	tipo = tGuerreiro;
}


Guerreiro::~Guerreiro()
{
}

void Guerreiro::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("guerreiro"))
	{
		gRecursos.carregarSpriteSheet("guerreiro", "spritesheets/Knight.png",4,4);

		sprite.setSpriteSheet("guerreiro");
	}
}

void Guerreiro::desenhar()
{
	sprite.desenhar(x,y);
}

void Guerreiro::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Guerreiro::ataqueSpecial()
{

	
}

void Guerreiro::moverAnim()
{
	if (gTeclado.segurando[TECLA_D])
	{

		sprite.setAnimacao(Gdir);
		
		this->dir = true;
		this->esq = false;
		this->cima = false;
		this->baixo = false;
	}   
	else if (gTeclado.segurando[TECLA_A])
	{
		sprite.setAnimacao(Gesq);
		this->esq = true;
		this->dir = false;
		this->baixo = false;
		this->cima = false;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		sprite.setAnimacao(Gcima);
		this->cima = true;
        this->dir = false;
		this->esq = false;
		this->baixo = false;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		sprite.setAnimacao(Gbaixo);
		this->baixo = true;
		this->dir = false;
		this->esq = false;
		this->cima = false;

	}
}


void Guerreiro::animacao()
{
	sprite.avancarAnimacao();

}
void Guerreiro::desenharAtk()
{
	
}

void Guerreiro::setAni(animG ani)
{
	ani = anim;
}

void Guerreiro::setani()
{
}





