#include "Inventario.h"



Inventario::Inventario()
{
	
}


Inventario::~Inventario()
{
}

std::vector<Itens>* Inventario::getAllItens()
{
	return &item;
}

void Inventario::desenhar()
{
	if (inventarioAberto == false)
	{
		if (gTeclado.segurando[TECLA_I])
		{
			inventario.desenhar(400, 500);
			ativaDesenho = true;

		}


		if (gTeclado.soltou[TECLA_I])
		{
			inventario.~Sprite();
			ativaDesenho = false;

		}
	}
	
}

void Inventario::guardarEspada()
{
	if (pegouEspada == true)
	{
		if (gardouEspada == false)
		{


		item.push_back(*item1);
			


			tamanho++;

			
			quantidade++;
			tamanhoEs = quantidade;
			gardouEspada = true;
			personage = 1;
		}

		
	}
	

}

void Inventario::spritesDeItens()
{
}

void Inventario::guardarFaca()
{
	if (pegouFaca == true)
	{
		if (guardouAfaca == false)
		{
			numerador++;


			item.push_back(*item2);
			tamanho++;

			quantidade++;
			tamanhoFa = quantidade;
			guardouAfaca = true;
		}
}
}

void Inventario::guardarBastao()
{
	if (pegouCajado == true)
	{
		numerador++;
		if (gardouCajado == false)
		{
			item.push_back(*item3);
			tamanho++;
			quantidade++;
			tamanhoCaj = quantidade;
		}
		gardouCajado == true;
	
	}
}

void Inventario::aparecerItens()
{

	if (tamanho > 0)
	{
		
		
		vector<Itens>::iterator armazen;
		for (armazen = item.begin(); armazen != item.end(); ++armazen)
		{
			for (int i = quantidade; i < tamanho; i++)
			{

				armazen->ataques;




			}
			if (ativaDesenho == true)
			{

				if (armazen->itemInventario == "espada")
				{

					/*if (tamanho == 1)
					{*/




					setDesenhar(EspadaInventario, tamanhoEs * armazen->espX, armazen->espY);



					/*setDesenhar(armazen->espadaSprite, armazen->espX, armazen->espY);*/

				/*setDesenhar(EspadaInventario, armazen->espX, armazen->espY);*/

				/*}
				else if (tamanho == 2)
				{

					armazen->espadaSprite.desenhar(250, 500);
				}
				else if (tamanho == 3)
				{
					armazen->espadaSprite.desenhar(350, 500);
				}*/
					armazen->jaPegouEspada = true;
				}
				if (armazen->itemInventario == "Faca")
				{


					setDesenhar(FacaInventario, tamanhoFa * armazen->facX, armazen->facaY);


					/*gRecursos.carregarSpriteSheet("faca", "spritesheets/faca.png");

					armazen->faca.setSpriteSheet("faca");
				*/

				}
				if (armazen->itemInventario == "Bastao")
				{
					{

						setDesenhar(armazen->cajado, 150, 500);
					}
				}
			}
		}



	}
}


void Inventario::inicialialisar()
{
	if (!gRecursos.carregouSpriteSheet("inventario"))
	{
		gRecursos.carregarSpriteSheet("inventario","spritesheets/inventario.png");

		inventario.setSpriteSheet("inventario");
		
	}
	if (!gRecursos.carregouSpriteSheet("Espada"))
	{
		gRecursos.carregarSpriteSheet("Espada", "spritesheets/espada.png");

		EspadaInventario.setSpriteSheet("Espada");
	}
	if (!gRecursos.carregouSpriteSheet("Faca"))
	{
		gRecursos.carregarSpriteSheet("Faca", "spritesheets/faca.png");

		FacaInventario.setSpriteSheet("Faca");
	}

	item1->itemInventario = "espada";
	item1->espadaSprite;
	item1->espX = 100.f;
	item1->espY = 500.f;
	/*item1->setPosXespada(50.f);
	item1->setPosYespada(500.f);*/
	item1->ataques = 500;
	
	item2->itemInventario = "Faca";
	item2->facX = 100.f;
	item2->facaY = 500.f;
	
	item2->ataques = 300;
	item3->itemInventario = "Bastao";
	item3->ataques = 200;

	
}
void Inventario::setDesenhar(Sprite nome, float x, float y)
{
	nome.desenhar(x,y);
}
vector<Itens>::iterator armazen;
