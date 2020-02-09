#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "constantes.h"
#include "varGlobales.h"

class Personnage
{
public:
    Personnage(sf::RenderWindow &fenetre);
    ~Personnage();
    void positionP();
    void deplacementP(int direction);
    void afficheP();
    sf::Sprite getApparenceP();
    void setApparenceP(sf::Vector2f apparenceP);
    void changementTextureP(int orientationP);


private:
    sf::Sprite m_personnage;
    sf::Texture m_textures[4];
    float m_depl_en_X=50.f;
    float m_depl_en_Y=50.f;
    sf::RenderWindow *m_fenetre;

};

#endif // DEF_PERSONNAGE
