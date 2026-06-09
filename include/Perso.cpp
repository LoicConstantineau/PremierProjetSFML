#include "Objet.h"

jeu::Objet creerPerso(){
    jeu::Objet perso;

    sf::VertexArray tete(sf::PrimitiveType::Triangles, 6);
    tete[0].position = sf::Vector2f(0, 0);
    tete[1].position = sf::Vector2f(50, 0);
    tete[2].position = sf::Vector2f(0, 50);
    tete[3].position = sf::Vector2f(0, 50);
    tete[4].position = sf::Vector2f(50, 0);
    tete[5].position = sf::Vector2f(50, 50);

    perso.ajouterTriangles(tete);

    perso.asgVitesseDeplacement(400);
    perso.ajouterEtatX("coursADroite", {0, perso.getVitesseDeplacement() * 7});
    perso.ajouterEtatX("coursAGauche", {0, -perso.getVitesseDeplacement() * 7});
    perso.ajouterEtatY("saute", {0, -20000});

    return perso;
} // creerPerso
	