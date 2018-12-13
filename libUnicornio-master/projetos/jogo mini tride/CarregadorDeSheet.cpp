#include "CarregadorDeSheet.h"
#include<Global.h>


CarregadorDeSheet::CarregadorDeSheet()
{
}


CarregadorDeSheet::~CarregadorDeSheet()
{
}

bool CarregadorDeSheet::carregar(std::fstream & arquivo_incialisar)
{
	bool carregamento = true;
	std::string tipoAsset;
	std::string nomeAsset;
	std::string caminhoAsset;
	std::string numAnimAsset;
	std::string numMaxFrames;
	std::string::size_type sz;
	if (arquivo_incialisar)
	{
		char numAssts = arquivo_incialisar.get();
		this->numAsstes = numAssts - '0';
		while (!arquivo_incialisar.eof())
		{
			arquivo_incialisar >> tipoAsset >> nomeAsset >> caminhoAsset >> numAnimAsset >> numMaxFrames;
			
			if (!arquivo_incialisar.fail())
			{
				gDebug.depurar("erro leitura", arquivo_incialisar.fail())
				gDebug.depurar("tipo_asset", tipoAsset);
				gDebug.depurar("nomeAnim", nomeAsset);
				gDebug.depurar("caminho asset", caminhoAsset);
				gDebug.depurar("num anima", numAnimAsset);
				gDebug.depurar("num maximo frames", numMaxFrames);
				if (tipoAsset == "sprite_sheet")
				{
					gRecursos.carregarSpriteSheet(nomeAsset, caminhoAsset, std::stoi(numAnimAsset, &sz),
						std::stoi(numAnimAsset, &sz), QUALIDADE_ESCALA_BAIXA);
				}

				if (!gRecursos.carregouSpriteSheet(nomeAsset))
				{
					gDebug.erro("Nao carregou recurso");
					return false;
				}

			}



		}
		return true;
	}
}
