#pragma once
#include<iostream>
#include<fstream>
class CarregadorDeSheet
{
public:
	CarregadorDeSheet();
	~CarregadorDeSheet();

	bool carregar(std::fstream & arquivo_incialisar);


private: 
	int numAsstes;
};

