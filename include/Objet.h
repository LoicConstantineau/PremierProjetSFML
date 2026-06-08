#include <SFML/Graphics.hpp>

namespace jeu {
class Objet : public sf::Drawable, public sf::Transformable{
public:
    Objet();
    ~Objet() override = default;

    void ajouterTriangles(sf::VertexArray p_triangles);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void update();

    float getVitesseDeplacement() const;
    void asgVitesseDeplacement(float p_vitesse);
    float getForcesX() const;
    void asgForcesX(float p_vitesse);
    float getForcesY() const;
    void asgForcesY(float p_vitesse);
    float getVitesseX() const;
    void asgVitesseX(float p_vitesse);
    float getVitesseY() const;
    void asgVitesseY(float p_vitesse);

    bool coursADroite();
    bool coursAGauche();
    void courirDroite();
    void courirGauche();

    void sauter();

private:
    sf::VertexArray m_triangles;
    float m_vitesseDeplacement;
    float m_vitesseX;
    float m_vitesseY;
    float m_gravite;
    float m_forcesX;
    float m_forcesY;
    bool m_parTerre;
    float m_masse;
    bool m_coursADroite;
    bool m_coursAGauche;
    bool m_courrait;
}; // Classe Objet
} //Namespace jeu