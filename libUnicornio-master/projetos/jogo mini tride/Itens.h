#pragma once
#include<string>
#include<iostream>
#include"libUnicornio.h"
class Itens
{
public:
	Itens();
	~Itens();
	void inicialisar();
	void desenharItemAletorio();
	Sprite  espadaSprite, cajado, faca;
	int ataqueEspada,ataqueCajado,ataqueFaca;
	int ataques;
	int armadura;
	int random ;
	
	float getEspX();
	float getEspY();
	float getRot();
	float getFacX();
	float getFacaY();
	float getFacaRot();
	void setDesenharEspada(float x,float y);
	float getCajRot();
	float getCajX();
	float getCajY();
	void incialisarEspada(float x,float y);
	Sprite setPositionEspada();
	void setPosXespada(float x);
	void setPosYespada(float y);
    
	Sprite getSpriteEspada();
	Sprite getSpriteFaca();
	Sprite getSpriteCajado();
	void setSpriteSheetEs(string sheet);
	void setPositionEspada(float x, float y);
	float espX, espY, espRot, facX, facaY, facaRot, cajX, cajY, cajrot;
	string itemInventario;
    std::string tipoitens[3];
	bool jaPegouEspada = false;
};

