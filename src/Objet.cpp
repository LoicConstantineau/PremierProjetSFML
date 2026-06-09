#include "Objet.h"


namespace jeu {
Objet::Objet():
m_triangles(sf::PrimitiveType::Triangles),
m_vitesseX(0), m_vitesseY(0),
m_gravite(980),
m_forcesX(0), m_forcesY(m_gravite),
m_parTerre(false),
m_masse(10),
m_etatsX({}),
m_etatsY({})
{}

void Objet::ajouterTriangles(sf::VertexArray p_triangles){
    for (int i = 0; i < p_triangles.getVertexCount(); i+= 3){
        m_triangles.append(p_triangles[i]);
        m_triangles.append(p_triangles[i + 1]);
        m_triangles.append(p_triangles[i + 2]);
    }
}
void Objet::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(m_triangles, states);
}


float Objet::getVitesseDeplacement() const{
    return m_vitesseDeplacement;
}
void Objet::asgVitesseDeplacement(float p_vitesse){
    m_vitesseDeplacement = p_vitesse;
}

float Objet::getForcesX() const{
    return m_forcesX;
}
void Objet::asgForcesX(float p_force){
    m_forcesX = p_force;
}
float Objet::getForcesY() const{
    return m_forcesY;
}
void Objet::asgForcesY(float p_force){
    m_forcesY = p_force;
}

float Objet::getVitesseX() const{
    return m_vitesseX;
}
void Objet::asgVitesseX(float p_vitesse){
    m_vitesseX = p_vitesse;
}
float Objet::getVitesseY() const{
    return m_vitesseY;
}
void Objet::asgVitesseY(float p_vitesse){
    m_vitesseY = p_vitesse;
}

std::unordered_map<std::string, sf::Vector2f> Objet::getTousLesEtatsX(){
    return m_etatsX;
}
sf::Vector2f Objet::getUnEtatX(std::string p_nom){
    return m_etatsX.at(p_nom);
}
void Objet::ajouterEtatX(std::string p_nom, sf::Vector2f p_valeurs){
    m_etatsX.insert_or_assign(p_nom, p_valeurs);
}
std::unordered_map<std::string, sf::Vector2f> Objet::getTousLesEtatsY(){
    return m_etatsY;
}
sf::Vector2f Objet::getUnEtatY(std::string p_nom){
    return m_etatsY.at(p_nom);
}
void Objet::ajouterEtatY(std::string p_nom, sf::Vector2f p_valeurs){
    m_etatsY.insert_or_assign(p_nom, p_valeurs);
}

void Objet::activerEtatX(std::string p_nom, int p_activer){
    m_etatsX.at(p_nom).x = p_activer;
}
void Objet::activerEtatY(std::string p_nom, int p_activer){
    m_etatsY.at(p_nom).x = p_activer;
}

void Objet::update(){
    m_forcesX = 0;
    m_forcesY = 0;
    for (const auto etat : m_etatsX){
        if (etat.second.x == 1){
            m_forcesX += etat.second.y;
        }
    }
    for (const auto etat : m_etatsY){
        if (etat.second.x == 1){
            m_forcesY += etat.second.y;
        }
    }

    if (this->getPosition().y >= 600){
        m_parTerre = true;
    }
    else {m_parTerre = false;}
    if (!m_parTerre){
        m_forcesY += m_gravite;
    }
    if (m_parTerre){
        m_vitesseY = 0;
    }
    if ((m_vitesseY + m_forcesY/m_masse) * 1/60 > 600 - this->getPosition().y){
        m_forcesY = 0;
        m_vitesseY = (600 - this->getPosition().y) * 60;
    }

    m_forcesX -= 4 * m_vitesseX;

    m_vitesseX += m_forcesX/m_masse;
    m_vitesseY += m_forcesY/m_masse;
}

} // Namespace jeu