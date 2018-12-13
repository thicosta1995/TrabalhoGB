#include "Jogo.h"
#include"Guerreiro.h"
#include"Ladrao.h"
#include"Mago.h"
#include"Inventario.h"





Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{

	uniInicializar(800, 600, false);

	//this->f_stream.open("..\\..\\Mapa.txt", ios::in);
	//if (!f_stream)
	//{
	//	gDebug.erro("nao abriu", this);
	//}
	
	itens.inicialisar();
	menu.incialisar();
	
	/*if (!gRecursos.carregouSpriteSheet("fundoTelaMenu"))
	{
		gRecursos.carregarSpriteSheet("fundoTelaMenu", "assets/spritesheets/telamenu.jpg");
		tela.fundoTelaMenus.setSpriteSheet("fundoTelaMenu");
	}*/
	inventario.inicialialisar();
	gRecursos.carregarFonte("fonte","assets/arial.ttf", 32);
	nome.inicializar();
	/*mapa.carregar("assets/tilemaps/tilemap.json");*/
	gRecursos.carregarAudio("corte", "assets/cut.wav");
	gRecursos.carregarAudio("magia", "assets/magic.wav");
	corte.setAudio("corte");
	bolaD.setAudio("magia");
	
	personagem[0] = new Guerreiro;
	personagem[0]->inicializar();
	personagem[1] = new Mago;
	personagem[1]->inicializar();
	personagem[2] = new Ladrao;
	personagem[2]->inicializar();

	
	bolaD.inicializar();
	corte.inicializar();

	cla = 1;
 
	animadorGuerrero = 1;
	
}


void Jogo::finalizar()
{
	mapa.descarregar();
	gRecursos.descarregarTudo();
	gRecursos.descarregarAudio("corte");
	nome.finalizar();
	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		menu.atualisar();
		nome.atualizar();
		nome.desenhar();
		nome.finalizar();
		uniIniciarFrame();
		if (menu.tela[0].comecarJogo==true)
		{
			itens.desenharItemAletorio();
	
			/*	mapa.desenhar();*/
				/*	personagem[0]->desenhar();
					personagem[0]->mover();*/
			testarColisoes();
			inventario.desenhar();
			inventario.guardarEspada();
			inventario.guardarFaca();
			inventario.aparecerItens();
			switch (cla)
			{
				
			case 0: classe = tGuerreiro;
			
				//troca de personagem do guerreiro
				if (gTeclado.pressionou[TECLA_2])
				{
					cla = 1;

					personagem[0]->atualisar();
					personagem[1]->setX(personagem[0]->getX());
					personagem[1]->setY(personagem[0]->getY());

				}
				if (gTeclado.pressionou[TECLA_3])
				{
					cla = 2;
					personagem[2]->setX(personagem[0]->getX());
					personagem[2]->setY(personagem[0]->getY());

				}
				//ataque guerreiro
				corte.ataqueEspecial();
				if (corte.time > 0)
				{
					
					if (personagem[0]->dir == true) {


						corte.spriteC.desenhar(personagem[0]->getX() + 100, personagem[0]->getY());
						corte.spriteC.setInverterX(true);
						corte.spriteC.avancarAnimacao();
						corte.time--;

					}
					if (personagem[0]->esq == true)
					{
						corte.spriteC.desenhar(personagem[0]->getX() - 100, personagem[0]->getY());
						corte.spriteC.setInverterX(false);

						corte.spriteC.avancarAnimacao();
						corte.time--;
					}
					if (personagem[0]->baixo == true)
					{
						corte.spriteC.desenhar(personagem[0]->getX(), personagem[0]->getY() + 100);


						corte.spriteC.avancarAnimacao();
						corte.time--;
					}
					if (personagem[0]->cima == true)
					{
						corte.spriteC.desenhar(personagem[0]->getX(), personagem[0]->getY() - 100);
						corte.spriteC.avancarAnimacao();
						corte.time--;
					}





				}
				else if (corte.time == 0)
				{
					if (corte.spriteC.terminouAnimacao())
					{
						corte.sprite.~Sprite();
					}
				}


				personagem[0]->animacao();
				personagem[0]->moverAnim();
				personagem[0]->desenhar();
				personagem[0]->mover();
				if (inventario.pegouEspada == true)
				{
					vector<Itens>*lista_Item = inventario.getAllItens();
					personagem[0]->pegouEspada(inventario.item1->ataques);
				}
				gDebug.depurar("ataque", personagem[0]->ataque);

				break;
			case 1: classe = tMago;
				//troca de personagens do mago
				if (gTeclado.pressionou[TECLA_1])
				{
					cla = 0;

					personagem[0]->desenhar();
					personagem[0]->setX(personagem[1]->getX());
					personagem[0]->setY(personagem[1]->getY());
				}
				if (gTeclado.pressionou[TECLA_3])
				{
					cla = 2;
					personagem[2]->setX(personagem[1]->getX());
					personagem[2]->setY(personagem[1]->getY());

				}
				//ataque mago
				bolaD.ataqueEspecial();
				if (bolaD.time > 0)
				{
					if (personagem[1]->dir == true)
					{


						if (bolaD.animacaoBolaTraz == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, -2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();


							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaTraz = false;

							}
						}
						if (bolaD.animacaoBolaBaixo == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, 2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaBaixo = false;
							}
						}
						if (bolaD.animacaoBolaCima == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, -2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaCima = false;
							}
						}

						if (bolaMover == false)
						{
							bolaD.spriteB.desenhar(personagem[1]->getX() + 100, personagem[1]->getY());

						}

						if (start == true)
						{
							bolaD.xb = personagem[1]->getX();
							bolaD.yb = personagem[1]->getY();
							start = false;
						}


						bolaD.spriteB.setInverterX(true);
						bolaD.spriteB.avancarAnimacao();

						if (bolaD.animacaoBolaTraz = false && bolaD.animacaoBolaBaixo == false && bolaD.animacaoBolaCima == false);
						{
							if (gTeclado.soltou[TECLA_ESPACO])
							{
								if (bolaD.animacaoBolaTraz = false);
								{
									bolaD.animacaoBolaFrente = true;
									bolaMover = true;

								}
							}
						}
						if (bolaD.animacaoBolaFrente == true)
						{

							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, 2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							gDebug.depurar("time", bolaD.getX());
							bolaD.spriteB.avancarAnimacao();


						}
						if (bolaD.time <= 0)
						{
							bolaD.spriteB.~Sprite();
							bolaMover = false;
							start = true;
						}
					}
					if (personagem[1]->esq == true)
					{

						if (bolaD.animacaoBolaFrente == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, 2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();

							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();

								bolaMover = false;
								start = true;
								bolaD.animacaoBolaFrente = false;

							}
						}

						if (bolaD.animacaoBolaBaixo == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, 2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaBaixo = false;
							}
						}
						if (bolaD.animacaoBolaCima == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, -2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaCima = false;
							}
						}



						if (bolaMover == false)
						{
							bolaD.spriteB.desenhar(personagem[1]->getX() - 100, personagem[1]->getY());

						}

						if (start == true)
						{
							bolaD.xb = personagem[1]->getX();
							bolaD.yb = personagem[1]->getY();
							start = false;
						}


						bolaD.spriteB.setInverterX(true);
						bolaD.spriteB.avancarAnimacao();


						if (bolaD.animacaoBolaFrente == false && bolaD.animacaoBolaCima == false && bolaD.animacaoBolaBaixo == false);
						{
							if (gTeclado.soltou[TECLA_ESPACO])
							{
								if (bolaD.animacaoBolaFrente = false);
								{
									bolaD.animacaoBolaTraz = true;
									bolaMover = true;
								}
							}
						}
						if (bolaD.animacaoBolaTraz == true)
						{

							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, -2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();


						}
						if (bolaD.time <= 0)
						{
							bolaD.spriteB.~Sprite();
							bolaMover = false;
							start = true;
							bolaD.animacaoBolaTraz = false;
						}
					}
					/*bolaD.spriteB.desenhar(personagem[1]->getX() - 100, personagem[1]->getY());
					bolaD.spriteB.setInverterX(false);

					bolaD.spriteB.avancarAnimacao();
					bolaD.time--;*/

					if (personagem[1]->baixo == true)
					{
						if (bolaD.animacaoBolaFrente == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, 2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();

							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();

								bolaMover = false;
								start = true;
								bolaD.animacaoBolaFrente = false;

							}
						}





						if (bolaD.animacaoBolaTraz == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, -2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();

							bolaMover = true;

							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();

								bolaMover = false;
								start = true;
								bolaD.animacaoBolaTraz = false;

							}
						}
						if (bolaD.animacaoBolaCima == true)
						{

							bolaD.time--;
							bolaD.bolaCima(bolaD.yb, -2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaCima = false;
							}
						}

						if (bolaMover == false)
						{
							bolaD.spriteB.desenhar(personagem[1]->getX(), personagem[1]->getY() + 100);

						}

						if (start == true)
						{
							bolaD.xb = personagem[1]->getX();
							bolaD.yb = personagem[1]->getY();
							start = false;
						}


						bolaD.spriteB.setInverterX(true);
						bolaD.spriteB.avancarAnimacao();


						if (bolaD.animacaoBolaFrente == false && bolaD.animacaoBolaTraz == false && bolaD.animacaoBolaCima == false);
						{
							if (gTeclado.soltou[TECLA_ESPACO])
							{

								bolaD.animacaoBolaBaixo = true;
								bolaMover = true;

							}
						}
						if (bolaD.animacaoBolaBaixo == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, 2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();


						}
						if (bolaD.time <= 0)
						{
							bolaD.spriteB.~Sprite();
							bolaMover = false;
							start = true;
							bolaD.animacaoBolaBaixo = false;
						}


					}

					if (personagem[1]->cima == true)
					{
						/*bolaD.spriteB.desenhar(personagem[1]->getX(), personagem[1]->getY() - 100);
						bolaD.spriteB.avancarAnimacao();
						bolaD.time--;*/
						if (bolaD.animacaoBolaFrente == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, 2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();

							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();

								bolaMover = false;
								start = true;
								bolaD.animacaoBolaFrente = false;

							}

						}



						if (bolaD.animacaoBolaTraz == true)
						{


							bolaD.time--;

							bolaD.bolaFrente(bolaD.xb, -2);
							bolaD.spriteB.desenhar(bolaD.getX(), bolaD.yb);
							bolaD.spriteB.avancarAnimacao();

							bolaMover = true;

							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();

								bolaMover = false;
								start = true;
								bolaD.animacaoBolaTraz = false;

							}
						}
						if (bolaD.animacaoBolaBaixo == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, 2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();



							if (bolaD.time <= 0)
							{
								bolaD.spriteB.~Sprite();
								bolaMover = false;
								start = true;
								bolaD.animacaoBolaBaixo = false;
							}
						}
						if (bolaMover == false)
						{
							bolaD.spriteB.desenhar(personagem[1]->getX(), personagem[1]->getY() - 100);

						}

						if (start == true)
						{
							bolaD.xb = personagem[1]->getX();
							bolaD.yb = personagem[1]->getY();
							start = false;
						}


						bolaD.spriteB.setInverterX(true);
						bolaD.spriteB.avancarAnimacao();


						if (bolaD.animacaoBolaFrente == false && bolaD.animacaoBolaTraz == false && bolaD.animacaoBolaBaixo == false);
						{
							if (gTeclado.soltou[TECLA_ESPACO])
							{
								if (bolaD.animacaoBolaFrente = false);
								{
									bolaD.animacaoBolaCima = true;
									bolaMover = true;
								}
							}
						}
						if (bolaD.animacaoBolaCima == true)
						{

							bolaD.time--;

							bolaD.bolaCima(bolaD.yb, -2);
							bolaD.spriteB.desenhar(bolaD.xb, bolaD.getY());
							bolaD.spriteB.avancarAnimacao();


						}
						if (bolaD.time <= 0)
						{
							bolaD.spriteB.~Sprite();
							bolaMover = false;
							start = true;
							bolaD.animacaoBolaCima = false;
						}


					}
				}


				personagem[1]->animacao();
				personagem[1]->moverAnim();

				personagem[1]->desenhar();
				personagem[1]->mover();
				break;
				
			case 2: classe = tBandido;
				//troca de personagem do ladrao
				if (gTeclado.pressionou[TECLA_2])
				{
					cla = 1;
					personagem[0]->atualisar();
					personagem[1]->setX(personagem[2]->getX());
					personagem[1]->setY(personagem[2]->getY());

				}
				if (gTeclado.pressionou[TECLA_1])
				{
					cla = 0;
					personagem[0]->setX(personagem[2]->getX());
					personagem[0]->setY(personagem[2]->getY());

				}
				// invisibilidade do bandido
				if (gTeclado.pressionou[TECLA_ESPACO])
				{
					invi.estaInvisivel = true;

					personagem[2]->sprite.setCorAlpha(100);

				}
				else if (gTeclado.soltou[TECLA_ESPACO])
				{
					invi.estaInvisivel = false;
					personagem[2]->sprite.setCorAlpha(-10000);
				}

				personagem[2]->animacao();
				personagem[2]->moverAnim();

				personagem[2]->desenhar();
				personagem[2]->mover();
				break;


			}

		}
			

			uniTerminarFrame();
		}
	}

	void Jogo::testarColisoes()
	{
		vector<Itens>*lista_Item = inventario.getAllItens();
		
		/*if (uniTestarColisao(itens.getSpriteEspada(), itens.getEspX(), itens.getEspY(), itens.getRot(), personagem[0]->getSprite(), personagem[0]->getX(), personagem[0]->getX(), personagem[0]->getRot()))
		{
			itens.espadaSprite.~Sprite();

		}*/
		if(uniTestarColisao(personagem[0]->getSprite(),personagem[0]->getX(), personagem[0]->getY(),personagem[0]->getRot(),itens.getSpriteEspada(), itens.getEspX(),itens.getEspY(),itens.getRot()))
		{
			
			

			inventario.pegouEspada = true;
			
			
		}
		if (uniTestarColisao(personagem[0]->getSprite(), personagem[0]->getX(), personagem[0]->getY(), personagem[0]->getRot(), itens.getSpriteFaca(), itens.getFacX(), itens.getFacaY(), itens.getFacaRot()))
		{
		inventario.pegouFaca = true;
		}
		if (uniTestarColisao(gMouse.x, gMouse.y, itens.getSpriteCajado(), itens.getCajX(), itens.getCajY(), itens.getCajRot()))
		{
			inventario.pegouCajado = true;
		}
	}
 
