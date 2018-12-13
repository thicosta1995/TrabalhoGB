#include"Tela.h"
#include<array>
#include<stack>
class Menu
{
public:
	Menu();
	~Menu();

	array<Tela,5>tela;
	stack<Tela*>pilha_tela;
	void alteraçaoDeTela();
	void incialisar();
	void atualisar();
	int  ordem = 0;
	/*BotaoSprite botaoJogar, botaoSair;*/
};
