#include "Itens.h"



Itens::Itens()
{
	this->espX = 100;
	this->espY = 200;
	this->facX = 500;
	this->facaY = 200;
	this->ataqueEspada = 30;
	this->ataqueCajado = 10;
	this->ataqueFaca = 20;
}


Itens::~Itens()
{
}


void Itens::inicialisar()
{

		

		if (!gRecursos.carregouSpriteSheet("espada"))
		{
			gRecursos.carregarSpriteSheet("espada", "spritesheets/espada.png");

			espadaSprite.setSpriteSheet("espada");
		}
		if (!gRecursos.carregouSpriteSheet("bastao"))
		{
			gRecursos.carregarSpriteSheet("bastao", "spritesheets/bastao.png");

			cajado.setSpriteSheet("bastao");
		}
		if (!gRecursos.carregouSpriteSheet("faca"))
		{
			gRecursos.carregarSpriteSheet("faca", "spritesheets/faca.png");

			faca.setSpriteSheet("faca");
		}
	
}

void Itens::desenharItemAletorio()
{
	
	if (gTeclado.pressionou[TECLA_0])
	{
		random = rand() % 3;
	}

		if (random == 0)
		{
			tipoitens[0] = "espada";
			espadaSprite.desenhar(espX,espY);
		}
		else if (random == 1)
		{
			tipoitens[1] = "faca";
			faca.desenhar(facX,facaY);
		}
		else if (random == 2)
		{
			tipoitens[2] = "cajado";
			cajado.desenhar( 200,  300);
			
		}

	


}

float Itens::getEspX()
{
	return espX;
}

float Itens::getEspY()
{
	return espY;
}

float Itens::getRot()
{
	return 0;
}

float Itens::getFacX()
{
	return facX;
}

float Itens::getFacaY()
{
	return facaY;
}

float Itens::getFacaRot()
{
	return 0;
}

void Itens::setDesenharEspada(float x, float y)
{
	espadaSprite.desenhar(x, y);
}

float Itens::getCajRot()
{
	return 0;
}

float Itens::getCajX()
{
	return cajX;
}

float Itens::getCajY()
{
	return cajY;
}

void Itens::incialisarEspada(float x,float y)
{
	if (!gRecursos.carregouSpriteSheet("espada"))
	{
		gRecursos.carregarSpriteSheet("espada", "spritesheets/espada.png");

		espadaSprite.setSpriteSheet("espada");


	}
	espadaSprite.desenhar(x, y);

}

void Itens::setPosXespada(float x)
{
	espX = x;
}

void Itens::setPosYespada(float y)
{
	espY = y;
}



Sprite Itens::getSpriteEspada()
{
	return espadaSprite;
}

Sprite Itens::getSpriteFaca()
{
	return faca;
}

Sprite Itens::getSpriteCajado()
{
	return cajado;
}

void Itens::setSpriteSheetEs(string sheet)
{
	espadaSprite.setSpriteSheet(sheet);
}

void Itens::setPositionEspada(float x, float y)
{
	this->espX = x;
	this->espY = y;
}
