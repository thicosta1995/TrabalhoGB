#pragma once
#include "Personagem.h"
enum anim {
	Lbaixo,
	Lesq,
	Ldir,
    Lcima

};
class Ladrao :
	public Personagem
{
public:
	Ladrao();
	~Ladrao();
	void inicializar();
	void  desenhar();
	Sprite getSprite() { return sprite; };
	void setSpriteSheet(string spritesheet);
	void ataqueSpecial();
	void moverAnim();
	void animacao();


	anim lad;
};

