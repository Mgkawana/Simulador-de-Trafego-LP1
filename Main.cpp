#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void SinalHorizontal(sf::Clock& tempo, sf::RectangleShape& sinal1);
void SinalVertical(sf::Clock tempo, sf::RectangleShape& sinal);

class Carro
{
private:
	sf::Texture TexturaCarro;
	sf::Vector2f velocidade, BackupVelocidade;
	sf::Sprite SpriteCarro;
	sf::Vector2f AreaFrenagem;
	bool colidir;

public: Carro(std::string CarroPath, sf::Vector2f Position, sf::Vector2f Direcao, sf::Vector2f area)
{
	TexturaCarro.loadFromFile(CarroPath);
	SpriteCarro.setTexture(TexturaCarro);
	SpriteCarro.setPosition(Position);
	velocidade = Direcao;
	BackupVelocidade = Direcao;
	AreaFrenagem = area;
	colidir = false;

	if (Direcao.x < 0)
	{
		SpriteCarro.rotate(180);
	}
	else if (Direcao.y > 0)
	{
		SpriteCarro.rotate(90);
	}
	else if (Direcao.y < 0)
	{
		SpriteCarro.rotate(270);
	}

	return;
}


	  void atualizar(sf::RectangleShape area, sf::RectangleShape area2, sf::RectangleShape area3, sf::RectangleShape area4, sf::RectangleShape sinal, sf::RectangleShape sinal2, std::vector <Carro> carros)
	  {
		  //Verificação de Colisão
		  for (int i = 0; i < carros.size(); i++)
		  {
			  if (this == &carros[i]) continue;

			  if ((BackupVelocidade.y < 0) && (carros[i].getBackup().y < 0))
			  {
				  if ((getPosition().y < carros[i].getPosition().y + 100) && (getPosition().y > carros[i].getPosition().y))
				  {
					  colidir = true;
					  break;
				  }
				  else
				  {
					  colidir = false;
				  }

			  }
			  if ((BackupVelocidade.y > 0) && (carros[i].getBackup().y > 0))
			  {
				  if ((getPosition().y > carros[i].getPosition().y - 100) && (getPosition().y < carros[i].getPosition().y))
				  {
					  colidir = true;
					  break;
				  }
				  else
				  {
					  colidir = false;
				  }

			  }
			  if ((BackupVelocidade.x > 0) && (carros[i].getBackup().x > 0))
			  {
				  if ((getPosition().x > carros[i].getPosition().x - 100) && (getPosition().x < carros[i].getPosition().x))
				  {
					  colidir = true;
					  break;
				  }
				  else
				  {
					  colidir = false;
				  }

			  }
			  if ((BackupVelocidade.x < 0) && (carros[i].getBackup().x < 0))
			  {
				  if ((getPosition().x < carros[i].getPosition().x + 100) && (getPosition().x > carros[i].getPosition().x))
				  {
					  colidir = true;

					  break;
				  }
				  else
				  {
					  colidir = false;
				  }

			  }

		  }

		  //Verificação no eixo y
		  if (BackupVelocidade.y != 0)
		  {

			  if ((AreaFrenagem.y == area.getPosition().y) && (getPosition().y > area.getPosition().y) && (getPosition().y < area.getPosition().y + 10) && ((sinal2.getFillColor() == sf::Color::Red) || (sinal2.getFillColor() == sf::Color::Yellow)))
			  {
				  velocidade.y = 0;
			  }
			  else if (AreaFrenagem.y == area2.getPosition().y && getPosition().y < area2.getPosition().y + 60 && getPosition().y > area2.getPosition().y && ((sinal2.getFillColor() == sf::Color::Red) || (sinal2.getFillColor() == sf::Color::Yellow)))
			  {
				  velocidade.y = 0;
			  }
			  else if (colidir == true)
			  {
				  velocidade.y = 0;
			  }
			  else
			  {
				  velocidade.y = BackupVelocidade.y;
			  }


			  if (getPosition().y + velocidade.y > 1000 && velocidade.y > 0)
			  {
				  SpriteCarro.setPosition(sf::Vector2f(425.f, 1000.f));
				  SpriteCarro.rotate(180);
				  velocidade.y = -velocidade.y;
				  BackupVelocidade.y = -BackupVelocidade.y;
				  AreaFrenagem.y = area2.getPosition().y;

			  }
			  else if (getPosition().y + velocidade.y < -100 && velocidade.y < 0)
			  {
				  SpriteCarro.setPosition(sf::Vector2f(475.f, -100.f));
				  SpriteCarro.rotate(180);
				  velocidade.y = -velocidade.y;
				  BackupVelocidade.y = -BackupVelocidade.y;
				  AreaFrenagem.y = area.getPosition().y;
			  }
		  }//Verificação no eixo x
		  else if (BackupVelocidade.x != 0)
		  {
			  if (AreaFrenagem.x == area3.getPosition().x && getPosition().x > area3.getPosition().x && getPosition().x < area3.getPosition().x + 10 && ((sinal.getFillColor() == sf::Color::Red) || (sinal.getFillColor() == sf::Color::Yellow)))
			  {
				  velocidade.x = 0;
			  }
			  else if (AreaFrenagem.x == area4.getPosition().x && getPosition().x < area4.getPosition().x + 40 && getPosition().x > area4.getPosition().x && ((sinal.getFillColor() == sf::Color::Red) || (sinal.getFillColor() == sf::Color::Yellow)))
			  {
				  velocidade.x = 0;
			  }
			  else if (colidir == true)
			  {
				  velocidade.x = 0;
			  }
			  else
			  {
				  velocidade.x = BackupVelocidade.x;
			  }

			  if (getPosition().x + velocidade.x > 1000 && velocidade.x > 0)
			  {
				  SpriteCarro.setPosition(sf::Vector2f(1000.f, 475.f));
				  SpriteCarro.rotate(180);
				  velocidade.x = -velocidade.x;
				  BackupVelocidade.x = -BackupVelocidade.x;
				  AreaFrenagem.x = area4.getPosition().x;

			  }
			  else if (getPosition().x + velocidade.x < -100 && velocidade.x < 0)
			  {
				  SpriteCarro.setPosition(sf::Vector2f(-100.f, 425.f));
				  SpriteCarro.rotate(180);
				  velocidade.x = -velocidade.x;
				  BackupVelocidade.x = -BackupVelocidade.x;
				  AreaFrenagem.x = area3.getPosition().x;
			  }
		  }


		  SpriteCarro.setPosition(SpriteCarro.getPosition() + velocidade);
	  }

	  sf::Vector2f getPosition()
	  {
		  return SpriteCarro.getPosition();
	  }

	  sf::Sprite getSprite()
	  {
		  return SpriteCarro;
	  }

	  sf::Vector2f getBackup()
	  {
		  return BackupVelocidade;
	  }
};




int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Projeto LP");

	// Direções dos carros & Spawn
	sf::Vector2f Direita(2.f, 0.f), Esquerda(-2.f, 0.f), Baixo(0.f, 2.f), Cima(0.f, -2.f);
	sf::Vector2f SpawnCarroDireita(-100.f, 425.f), SpawnCarroBaixo(475.f, -100.f), SpawnCarroCima(425.f, 1000.f), SpawnCarroEsquerda(1000.f, 475.f);

	//Background
	sf::Texture rua, carro, Background;
	rua.loadFromFile("./cruzamentro.png");
	Background.loadFromFile("./grama.jpg");
	sf::Sprite fundo(rua), Grama(Background);
	sf::Clock tempo;

	//sinais
	sf::RectangleShape sinal1(sf::Vector2f(50.f, 50.f)), sinal2(sf::Vector2f(50.f, 50.f)), sinal3(sf::Vector2f(50.f, 50.f)), sinal4(sf::Vector2f(50.f, 50.f));
	sinal1.setPosition(550.f, 525.f);
	sinal2.setPosition(550.f, 315.f);
	sinal3.setPosition(300.f, 310.f);
	sinal4.setPosition(300.f, 525.f);
	sf::Texture Semaforo;
	Semaforo.loadFromFile("./semaforo.png");
	sf::Sprite sinal_cima(Semaforo), sinal_baixo(Semaforo), sinal_direita(Semaforo), sinal_esquerda(Semaforo);
	sinal_cima.setPosition(sf::Vector2f(650.f, 400.f));
	sinal_cima.rotate(180);
	sinal_baixo.setPosition(sf::Vector2f(250.f, 490.f));
	sinal_direita.setPosition(sf::Vector2f(515.f, 625.f));
	sinal_direita.rotate(270);
	sinal_esquerda.setPosition(385.f, 265.f);
	sinal_esquerda.rotate(90);

	//Areas de Frenagem
	sf::Vector2f PosicaoDireita(280.f, 455.f), PosicaoBaixo(410.f, 280.f), PosicaoCima(462.f, 570.f), PosicaoEsquerda(580.f, 410.f);
	sf::RectangleShape AreaDireita(sf::Vector2f(50.f, 30.f)), AreaEsquerda(sf::Vector2f(50.f, 30.f)), AreaBaixo(sf::Vector2f(30.f, 50.f)),
		AreaCima(sf::Vector2f(30.f, 50.f));

	//Declaração dos Carros
	Carro Carro1("./Carro.png", SpawnCarroDireita, Direita, PosicaoDireita);
	Carro Carro2("./Carro.png", SpawnCarroDireita, Direita, PosicaoDireita);


	Carro Carro5("./Carro.png", SpawnCarroCima, Cima, PosicaoCima);
	Carro Carro6("./Carro.png", SpawnCarroCima, Cima, PosicaoCima);

	Carro Carro9("./Carro.png", SpawnCarroBaixo, Baixo, PosicaoBaixo);
	Carro Carro10("./Carro.png", SpawnCarroBaixo, Baixo, PosicaoBaixo);

	Carro Carro13("./Carro.png", SpawnCarroEsquerda, Esquerda, PosicaoEsquerda);
	Carro Carro14("./Carro.png", SpawnCarroEsquerda, Esquerda, PosicaoEsquerda);


	//Vetores de Carros
	std::vector <Carro> carros_horizontal({ Carro1, Carro13, Carro2, Carro14 });
	std::vector <Carro> carros_vertical({ Carro5, Carro9, Carro6, Carro10 });
	std::vector <Carro> carros_funcao, carros_funcao2;

	//Interatividade
	bool Pressionado = false;
	int Quantidade_Horizontal = 0, Quantidade_Vertical = 0, BCKP_H = 0, BCKP_V = 0;






	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.setKeyRepeatEnabled(false);

		//Interativa
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Pressionado == false)
		{
			BCKP_H++;
			Pressionado = true;
			Quantidade_Horizontal = BCKP_H;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Pressionado == false)
		{
			BCKP_V++;
			Pressionado = true;
			Quantidade_Vertical = BCKP_V;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Pressionado = false;
		}
		//Add Carros no eixo Horizontal
		switch (Quantidade_Horizontal)
		{
		case 1:
			carros_funcao.push_back(carros_horizontal[0]);
			Quantidade_Horizontal = 0;
			break;
		case 2:
			carros_funcao.push_back(carros_horizontal[1]);
			Quantidade_Horizontal = 0;
			break;
		case 3:
			carros_funcao.push_back(carros_horizontal[2]);
			Quantidade_Horizontal = 0;
			break;
		case 4:
			carros_funcao.push_back(carros_horizontal[3]);
			Quantidade_Horizontal = 0;
			break;
		}
		//Add Carros no eixo Verical
		switch (Quantidade_Vertical)
		{
		case 1:
			carros_funcao2.push_back(carros_vertical[0]);
			Quantidade_Vertical = 0;
			break;
		case 2:
			carros_funcao2.push_back(carros_vertical[1]);
			Quantidade_Vertical = 0;
			break;
		case 3:
			carros_funcao2.push_back(carros_vertical[2]);
			Quantidade_Vertical = 0;
			break;
		case 4:
			carros_funcao2.push_back(carros_vertical[3]);
			Quantidade_Vertical = 0;
			break;
		}





		//Funções Sinais
		SinalHorizontal(tempo, sinal1);
		SinalHorizontal(tempo, sinal3);
		SinalVertical(tempo, sinal2);
		SinalVertical(tempo, sinal4);

		//POSIÇÃO Areas de Frenagem Sinal
		AreaDireita.setPosition(PosicaoDireita);
		AreaEsquerda.setPosition(PosicaoEsquerda);
		AreaBaixo.setPosition(PosicaoBaixo);
		AreaCima.setPosition(PosicaoCima);



		window.clear();

		//Exibição dos elementos do Mapa
		window.draw(Grama);
		window.draw(fundo);
		window.draw(sinal1);
		window.draw(sinal2);
		window.draw(sinal3);
		window.draw(sinal4);
		window.draw(sinal_cima);
		window.draw(sinal_baixo);
		window.draw(sinal_direita);
		window.draw(sinal_esquerda);

		//Exibição dos Carros
		for (int i = 0; i < carros_funcao.size(); i++) {
			carros_funcao[i].atualizar(AreaBaixo, AreaCima, AreaDireita, AreaEsquerda, sinal1, sinal2, carros_funcao);
			window.draw(carros_funcao[i].getSprite());
		}

		for (int i = 0; i < carros_funcao2.size(); i++) {
			carros_funcao2[i].atualizar(AreaBaixo, AreaCima, AreaDireita, AreaEsquerda, sinal1, sinal2, carros_funcao2);
			window.draw(carros_funcao2[i].getSprite());
		}


		window.display();


	}

	return EXIT_SUCCESS;
}

void SinalHorizontal(sf::Clock& tempo, sf::RectangleShape& sinal)
{
	//std::cout << tempo.getElapsedTime().asSeconds() << "\n";
	if (tempo.getElapsedTime().asSeconds() < 8)
	{
		sinal.setFillColor(sf::Color::Green);
	}
	else if (tempo.getElapsedTime().asSeconds() > 8 && tempo.getElapsedTime().asSeconds() < 10)
	{
		sinal.setFillColor(sf::Color::Yellow);
	}
	else if (tempo.getElapsedTime().asSeconds() > 10 && tempo.getElapsedTime().asSeconds() < 20)
	{
		sinal.setFillColor(sf::Color::Red);

	}
	else {
		tempo.restart();
	}
}

void SinalVertical(sf::Clock tempo, sf::RectangleShape& sinal)
{
	if (tempo.getElapsedTime().asSeconds() < 10)
	{
		sinal.setFillColor(sf::Color::Red);
	}
	else if (tempo.getElapsedTime().asSeconds() > 10 && tempo.getElapsedTime().asSeconds() < 18)
	{
		sinal.setFillColor(sf::Color::Green);
	}
	else if (tempo.getElapsedTime().asSeconds() > 18 && tempo.getElapsedTime().asSeconds() < 20)
	{
		sinal.setFillColor(sf::Color::Yellow);

	}
}