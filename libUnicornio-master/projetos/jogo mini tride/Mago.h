#pragma once
#include "Personagem.h"
enum Manim {
	Mbaixo,
	Mesq,
	Mdir,
	Mcima

};
class Mago :
	public Personagem
{
public:
	Mago();
	~Mago();
	void inicializar();
	void  desenhar();
	Sprite getSprite() { return sprite; };
	void setSpriteSheet(string spritesheet);
	void ataqueSpecial();
	void moverAnim();
	void animacao();
	
};

