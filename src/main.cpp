#include <cmath>
#include <SFML/Graphics.hpp>
#include "Perso.cpp"


int main()
{
	unsigned int largeurFenetre = 1200;
	unsigned int hauteurFenetre = 800;

	sf::RenderWindow window(sf::VideoMode({largeurFenetre, hauteurFenetre}), "Cercle");
 	window.setFramerateLimit(60);

	sf::Vector2f originPerso = {300, 600};

	jeu::Objet perso = creerPerso();
	perso.setPosition(originPerso);


	while (window.isOpen()){

		while (const std::optional event = window.pollEvent()){
      		if (event->is<sf::Event::Closed>()){
        	window.close();
      		}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && perso.getVitesseX() <= perso.getVitesseDeplacement() * 2){
			perso.activerEtatX("coursADroite", 1);
		}
		else {perso.activerEtatX("coursADroite", 0);}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && perso.getVitesseX() >= -perso.getVitesseDeplacement() * 2){
			perso.activerEtatX("coursAGauche", 1);
		}
		else {perso.activerEtatX("coursAGauche", 0);}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && perso.getPosition().y >= 600){
			perso.activerEtatY("saute", 1);
		}
		if (perso.getUnEtatY("saute").x == 1 && perso.getPosition().y < 600){
			perso.activerEtatY("saute", 0);
		}


		window.clear();
		perso.update();
		perso.move({perso.getVitesseX() * 1/60, perso.getVitesseY() * 1/60});
		window.draw(perso);
		window.display();
	}
	return 0;
}


