#pragma once
#include "Guerreiro.h"

enum animC {
	cor
};
class Corte :
	public Guerreiro
{
public:
	Corte();
	~Corte();
	
	void ataqueEspecial();
	void inicializar();
	void setSpriteSheet(string spiteSheet);
	Sprite getSpriteC() { return spriteC; };
	void desenhar(int x,int y);
	void setX(int x);
	void setY(int y);
	void avancarAnimaçao();
	void timeAnimacao();
	void paraAnimaçao(float time);
	void corteAtivo();
	//void getanim() { return spriteC.setAnimacao(cor,false); };
	
	bool animacaoAtk = false;
	Sprite spriteC;
	int y, x;
	Personagem personagem;
	bool corteAtivar;
	animC anim;
	Guerreiro guerreiro;
	int time=0;
	void setAudio(string nome);
	Som som;
	
	
};

