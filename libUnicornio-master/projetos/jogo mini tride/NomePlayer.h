#include"libUnicornio.h"
#include<fstream>
#include<string>
#include<vector>
#pragma once
struct Cadastro
{
	std::string nomeP;

};
class NomePlayer
{
public:
	NomePlayer();
	~NomePlayer();
	void inicializar();
	void atualizar();
	void desenhar();
	void finalizar();
	bool cadastro1(std::ostream& os);
	bool carregar(std::istream & is);
	void verficarNome(std::fstream & arquivoNome);
	bool retornouNome();
	void tentaiva();
	int getTentativa();
	void criarArquivo();
	std::vector<Cadastro> vec;
	int primeiroContador = 0;
	/*Cadastro *cadastros = new Cadastro;*/
	Texto txt;
	ifstream abrirNome;
	int numero=0;
	ofstream escrever;
	string nomeArq;
	std::string nomeJogador;
	bool nomeEncontrado;
	int i = 0;
	int tentativas =0;
	Cadastro cadastro;
	string armazenador;
	bool carregamento_Nome;
};

