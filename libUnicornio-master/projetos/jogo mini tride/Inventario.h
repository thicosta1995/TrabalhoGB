#pragma once
#include<vector>
#include"Inventario.h"
#include"Itens.h"
class Inventario
{
public:
	Inventario();
	~Inventario();
	std::vector<Itens>item;
	Itens *item1 = new Itens;
	Itens *item2 = new Itens;
	Itens * item3 = new Itens;
	std::vector<Itens>* getAllItens();
	void desenhar();
	void guardarEspada();
	void spritesDeItens();
	void guardarFaca();
	void guardarBastao();
	void aparecerItens();
	void inicialialisar();
	void setDesenhar(Sprite nome,float x,float y);
	
	bool inventarioAberto = false;
	bool pegouEspada;
	bool pegouFaca = false;
	bool  pegouCajado = false;
	bool inventarioF =false;
	bool gardouEspada = false;
	bool guardouAfaca = false;
	bool gardouCajado = false;
	bool ativaDesenho = false;
	int personage ;

	int tamanho = 0;
	int tamanhoEs =0;
	int tamanhoFa = 0;
	int tamanhoCaj = 0;
	int numerador = 0;       
	int quantidade = 0;
	Sprite inventario;
	Sprite EspadaInventario, FacaInventario,BastaoInventario;

};

