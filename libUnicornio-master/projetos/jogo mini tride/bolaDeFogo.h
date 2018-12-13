#pragma once
#include "Mago.h"
class bolaDeFogo :
	public Mago
{
	enum animB {
		bola
	};

public:
	bolaDeFogo();
	~bolaDeFogo();




	void ataqueEspecial();
	void inicializar();
	void setSpriteSheet(string spiteSheet);
	Sprite getSpriteC() { return spriteB; };
	void desenhar(int x, int y);
	void setX(int x);
	void setY(int y);
	void avancarAnimaçao();
	void timeAnimacao();
	void paraAnimaçao(float time);
	void bolaFrente(int x, float vel);
	void bolaCima(int y, float vel);
	
	int getX() { return xb; };
	int getY() { return yb; };
	

		bool animacaoBolaFrente = false;
		bool animacaoBolaTraz = false;
		bool animacaoBolaBaixo = false;
		bool animacaoBolaCima = false;
		Sprite spriteB;
		void setAudio(string nome);
		

	int yb, xb;
		Personagem personagem;
		bool bolaAtiva;
		animB anim;
		Mago mago;
		int time = 0;
		float velB ;
		Som som;

}; 

