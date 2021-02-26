#ifndef DEF_DECOR
#define DEF_DECOR

#include <iostream>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "constantes.h"
#include "varGlobales.h"

class Decor
{
public:
    Decor(sf::RenderWindow &fenetre);
    ~Decor();
    void chargementDecor();
    void deplacementCaisse(sf::Vector2f posCaisse,int direction);
    void changementEtatCaisse(sf::Vector2f posCaisse);
    void selectionTextures();
    void afficheDecor();
    std::vector<sf::Sprite> getMurs2();
    std::vector<Caisse> getCaisses();
    void setCaisses(std::vector<Caisse> caisses);




private:

    std::vector<sf::Sprite> m_murs1;
    std::vector<sf::Sprite> m_murs2;
    std::vector<Caisse> m_caisses;
    sf::Texture m_textures[5];
    std::vector<sf::Sprite> m_objectifs;
    sf::RenderWindow *m_fenetre;




};

#endif // DEF_DECOR
