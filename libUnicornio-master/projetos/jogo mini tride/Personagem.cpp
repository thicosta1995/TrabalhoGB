#include "Personagem.h"



Personagem::Personagem()
{
	x = 400;	
	y = 300;
	vel = 2;
	hp = 500;
	ataque =300;
	ataqueSemNada = 300;
	equipadoAtaque = 0;
}


Personagem::~Personagem()
{
}



void Personagem::inicializar()
{
}

void Personagem::setPosInicial(int x, int y)
{
	this->x = x;
	this->y = y;
}

Sprite Personagem::getSprite()
{
	return Sprite();
}

float Personagem::getRot()
{
	return 0;
}

void Personagem::setSpriteSheet()
{
}

void Personagem::atualisar()
{

}

void Personagem::atqueEspecial()
{
}





void Personagem::setX(int aux)
{
	x = aux;
}

void Personagem::setY(int aux)
{
	y = aux;
}

void Personagem::desenhar()
{
}

void Personagem::setVel(float vel)
{
}

void Personagem::mover()
{
	

	if (gTeclado.segurando[TECLA_D])
	{
		x += vel + 2;
		
		}
	else if (gTeclado.segurando[TECLA_A])
	{

		
			x -= vel + 2;
		
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		
			y -= vel + 2;
			
		
		}
	else if (gTeclado.segurando[TECLA_S])
	{
		
			y += vel + 2;
		
		
	}

}

void Personagem::moverAnim()
{
}


void Personagem::animacao()
{
}

int Personagem::getAtaque()
{
	return ataque;
}

void Personagem::pegouArma()
{
	vector<Itens>*lista_Item = inve.getAllItens();
	inve.personage = 1;
	if(inve.personage==1)
	{
		lista_Item->front();



		gDebug.depurar("ataque", equipadoAtaque);
	}
	else if(inve.personage==0)
	{
		ataque;
		gDebug.depurar("ataque", ataque);
	}
		

		
	
		
	
}

void Personagem::pegouEspada(int ataqueEspada)
{	   ataque = ataqueEspada;
	
	gDebug.depurar("ataque", ataque);
}

