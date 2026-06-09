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

    std::unordered_map<std::string, sf::Vector2f> getTousLesEtatsX();
    sf::Vector2f getUnEtatX(std::string p_nom);
    void ajouterEtatX(std::string p_nom, sf::Vector2f p_valeurs);
    std::unordered_map<std::string, sf::Vector2f> getTousLesEtatsY();
    sf::Vector2f getUnEtatY(std::string p_nom);
    void ajouterEtatY(std::string p_nom, sf::Vector2f p_valeurs);
    void activerEtatX(std::string p_nom, int p_activer); // nom de l'état et 0/1
    void activerEtatY(std::string p_nom, int p_activer);

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
    std::unordered_map<std::string, sf::Vector2f> m_etatsX; // Nom de l'état et vecteur avec 0/1 et ensuite vitesse
    std::unordered_map<std::string, sf::Vector2f> m_etatsY;
}; // Classe Objet
} //Namespace jeu