#include "NomePlayer.h"

NomePlayer::NomePlayer()
{
}

NomePlayer::~NomePlayer()
{
}

void NomePlayer::inicializar()
{
	
	txt.setFonte("fonte");
	txt.setString("");
	gTeclado.inputTexto.habilitar();
}

void NomePlayer::atualizar()
{
	std::cout << " " << std::endl;
	
	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		gTeclado.inputTexto.apagar();
	}
	if (gTeclado.pressionou[TECLA_DELETE])
	{
		if (gTeclado.inputTexto.getTamanhoSelecao() != 0)
			gTeclado.inputTexto.apagar();
		else if (gTeclado.inputTexto.getPosCursor() < gTeclado.inputTexto.getString().size())
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
			gTeclado.inputTexto.apagar();
		}
	}
	if (gTeclado.segurando[TECLA_SHIFT_ESQ])
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverSelecaoParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverSelecaoParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverSelecaoParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverSelecaoParaFim();
		}
	}
	//		Mover o cursor do texto
	else
	{
	if (gTeclado.pressionou[TECLA_ESQ])
	{
		gTeclado.inputTexto.moverPosCursorParaEsq();
	}
	if (gTeclado.pressionou[TECLA_DIR])
	{
		gTeclado.inputTexto.moverPosCursorParaDir();
	}
	if (gTeclado.pressionou[TECLA_HOME])
	{
		gTeclado.inputTexto.moverPosCursorParaInicio();
	}
	if (gTeclado.pressionou[TECLA_END])
	{
		gTeclado.inputTexto.moverPosCursorParaFim();
	}
	}

	//	3) Passar a string do input para o texto
	txt.setString(gTeclado.inputTexto.getString());
}

void NomePlayer::desenhar()
{
	txt.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	//	Desenhar seleção
	int tamSelecao = gTeclado.inputTexto.getTamanhoSelecao();
	if (tamSelecao != 0)
	{
		Quad retan;
		retan.larg = 0;
		retan.alt = txt.getFonte()->getAlturaGlifos();
		retan.x = (gJanela.getLargura() / 2) - txt.getLargura() / 2;
		retan.y = (gJanela.getAltura() / 2) - retan.alt / 2;

		int posCursor = gTeclado.inputTexto.getPosCursor();
		int inicio = min(posCursor, posCursor + tamSelecao);
		int fim = max(posCursor, posCursor + tamSelecao);

		for (int i = inicio; i < fim; ++i)
			retan.larg += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

		for (int i = 0; i < inicio; ++i)
			retan.x += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

		gGraficos.desenharRetangulo(retan, 30, 200, 230);
	}

	//	Desenhar o cursor do texto
	int altCursor = txt.getFonte()->getAlturaGlifos();
	int xCursor = (gJanela.getLargura() / 2) - txt.getLargura() / 2;
	int yCursor = (gJanela.getAltura() / 2) - altCursor / 2;
	int pos = gTeclado.inputTexto.getPosCursor();
	for (int i = 0; i < pos; ++i)
		xCursor += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

	gGraficos.desenharLinha(xCursor, yCursor, xCursor, yCursor + altCursor);

}

void NomePlayer::finalizar()
{
	if (gTeclado.pressionou[TECLA_ENTER])
	{
		
		
		nomeJogador = txt.getString();
	
		cadastro.nomeP = txt.getString();

	/*	cadastro.nomeP = txt.getString();*/


		gTeclado.inputTexto.desabilitar();
		this->abrirNome.open("save.txt" ,ios::binary );
		if (!this->abrirNome)
		{
			gDebug.erro("nao abriu ");

			criarArquivo();
		/*	this->escrever.open("save.dat", ios::binary|ios::app);
			if (!this->escrever)
			{
				gDebug.erro("nAO ABRIU");
			}
			else
			{
			

				cadastro.contador = 1;
				this->cadastro1(this->escrever);
				this->escrever.close();

			}*/
			
		}
		else
		{
			this->carregar(this->abrirNome);
			this->abrirNome.close();
		}
		
		
		


		
		
		//abrirNome.open("binary.dat", ios::binary);
		//
		//if (abrirNome.is_open())
		//{
		//    cadastro.nomeP = nomeJogador;
		//	abrirNome.seekg(0);
		//	abrirNome.read(reinterpret_cast<char*>(&cadastro), sizeof(Cadastro));

		//}
		//abrirNome.close();

	/*	escrever.open("nomeArq.dat", ios_base::out| ios::binary|ios_base::app);


		escrever.write((char *)&cadastro ,sizeof(Cadastro));*/

		/*ifstream leitura("binary.dat", ifstream::binary |ios_base::in );
		if (leitura.is_open())
		{
			while (!leitura.eof())
			{
				getline(leitura, line);
				
			}
		}
		leitura.read(reinterpret_cast<char*>(&cadastro), sizeof(Cadastro));
		
		cadastro1(cadastro);
		*/
		


		
	



			/*ofstream outfile("binary.dat", ofstream::binary | ios_base::app);
			unsigned int size = armazenador.size();
			outfile.write(reinterpret_cast<char*>(&size), sizeof(size));
			outfile.write(armazenador.c_str(), armazenador.size());
			outfile.seekp(0, ios_base::beg);


			


				outfile.close();*/
				/*leitura.close();*/


				//ifstream infile("binary.dat", ifstream::binary);
				//size = 0;
				//infile.read(reinterpret_cast<char *>(&size), sizeof(size));

				//string buffer;
				//buffer.resize(size);

				//infile.read(&buffer[0], buffer.size());
				//infile.close();

				//txt.apagar();




			
		
	}
}

bool NomePlayer::cadastro1(std::ostream& os)

{
	if (os)
	{	
		
	 cadastro.nomeP = nomeJogador;
	
		
	/* os.write(cadastro.nomeP.c_str(), cadastro.nomeP.size());*/
		os.write(reinterpret_cast<char*>(&cadastro.nomeP), sizeof(Cadastro));
		
	}
	else
	{
		return false;
		gDebug.erro("falha na stream");
	}
	return true;
	
	/*if (candastro.nomeP ==armazenador)
	{
		txt.setString(cadastro.nomeP);
	}
	else
	{
		ofstream outfile("binary.dat", ofstream::binary | ios_base::app);
		unsigned int size = armazenador.size();
		outfile.write(reinterpret_cast<char*>(&size), sizeof(size));
		outfile.write(armazenador.c_str(), armazenador.size());
		outfile.seekp(0, ios_base::beg);





		outfile.close();
		
	}*/
}

bool NomePlayer::carregar(std::istream & is)
{
	if (is)
	{

		
		
			while (!is.eof())
			{
				
				is.read(reinterpret_cast<char*>(&cadastro), sizeof(Cadastro));

				
				/*if (cadastro.contador == 0)
				{
					cadastro.contador + 1;
				}
				else
				{
					
				}*/
				for (int i = 0; i <2; i++)
				{

					is >> cadastro.nomeP; /*>>cadastro.contador*/

					
				
					vec.push_back(Cadastro());
					vec[i].nomeP = cadastro.nomeP;
					/*vec[i].contador = cadastro.contador;
					*/
					
				}
				vector<Cadastro>::iterator listaNome;
				for (listaNome = vec.begin(); listaNome != vec.end(); ++listaNome)
				{
					
						vec[numero].nomeP;
						/*vec[numero].contador;*/
						listaNome->nomeP;
						
					/*	listaNome->contador;*/

						if (vec[numero].nomeP == nomeJogador)
						{
							nomeEncontrado = true;
						}
						else
						{
							tentaiva();
						}
						//if (vec[numero].nomeP != nomeJogador)
						//{
						//	
						//	this->escrever.open("save.dat", ios::binary | ios::app);
						//	this->cadastro1(this->escrever);
						//	this->escrever.close();
						//	break;
						//}
					
						//else
						//{
						//	gDebug.depurar("teste", nomeJogador);
						//	this->escrever.open("save.dat", ios::binary | ios::app);
						//	this->cadastro1(this->escrever);
						//	this->escrever.close();
						//	break;
						//}
						numero++;
					
				}
				int total = numero;
				if (getTentativa() == total)
				{
					criarArquivo();
					/*this->escrever.open("save.dat", ios::binary | ios::app);
					this->cadastro1(this->escrever);
					this->escrever.close();*/

				}
			/*	for (int i = numero; i > 0; --numero)
				{
					if(vec[numero].nomeP ==nomeJogador)   
					{
						nomeEncontrado = true;
					}
					else
					{
						tentativas++;
					}*/
					
			/*	}*/
				
			



			
				
			
			

				
			
			}

			
			

		
	}

	
	else
	{
		return false;
	}

	
	
	return true;
}

void NomePlayer::verficarNome(std::fstream & arquivoNome)
{/*
	carregamento_Nome = true;
	nomeP = txt.getString();
	if (arquivoNome)
	{

		while (!arquivoNome.eof())
		{
			nomeP;
		}

	}
*/
}

bool NomePlayer::retornouNome()
{
	return true;;
}

void NomePlayer::tentaiva()
{
	tentativas++;
}

int NomePlayer::getTentativa()
{
	return tentativas;
}

void NomePlayer::criarArquivo()
{
	this->escrever.open("save.txt", ios::binary | ios::app);
	if (!this->escrever)
	{
		gDebug.erro("nAO ABRIU");
	}
	else
	{


	/*	cadastro.contador = 1;*/
		this->cadastro1(this->escrever);
		this->escrever.close();
	}

}


