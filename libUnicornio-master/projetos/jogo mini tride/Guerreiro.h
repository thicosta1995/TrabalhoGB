#pragma once
#include "Personagem.h"
enum animG {
	Gbaixo,
	Gesq,
	Gdir,
	Gcima

};
class Guerreiro :
	public Personagem
{
public:
	Guerreiro();
	~Guerreiro();
	
	void inicializar();
	void  desenhar();
	Sprite getSprite() { return sprite; };
	void setSpriteSheet(string spritesheet);
	void ataqueSpecial();
	Personagem personagem ;
	void moverAnim();
	void animacao();
	animG getAni() { return anim; };
	void setAni(animG ani);
	void setani();



	
	void desenharAtk();
	
	animG anim;
	Sprite spriteC;
	int ani;

};

