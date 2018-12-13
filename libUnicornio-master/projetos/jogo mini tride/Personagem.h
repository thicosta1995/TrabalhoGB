#pragma once
#include"Inventario.h"
#include"libUnicornio.h"
#include<iostream>
enum tClasse
{
	tGuerreiro, tMago, tBandido
};
class Personagem
{
public:
	Personagem();
	~Personagem();

	
	virtual void inicializar();
	void setPosInicial(int x, int y);
	virtual Sprite getSprite();
	float getRot();
	virtual void setSpriteSheet();
	virtual void atualisar();
	virtual void atqueEspecial();
	int getX() { return x; };
	int getY() { return y; };
	void setX(int aux);
	void setY(int aux);
	virtual void desenhar();
	 void setVel(float vel);
	void mover();
	virtual void moverAnim();
	void desenharAtk(); 
	virtual void animacao();
	int getAtaque();
	string itenInventario;
	void pegouArma();
	void pegouEspada(int ataqueEspada);
	tClasse tipo;
	Inventario inve;
	int hp, mp, ataque, equipadoAtaque,ataqueSemNada;
	 int x, y;
	float vel;
	
	bool esq = false;
	bool dir = false;
	bool cima = false;
	bool baixo = false;
	Sprite sprite;
	

	
	  
	
	
	
};

