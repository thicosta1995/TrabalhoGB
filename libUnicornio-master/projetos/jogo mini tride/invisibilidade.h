#pragma once
#include "Ladrao.h"
class invisibilidade :
	public Ladrao
{
public:
	invisibilidade();
	~invisibilidade();
	void ataqueEspecial();
	Ladrao ladrao;
	bool estaInvisivel = false;
	
};

