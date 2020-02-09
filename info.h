#ifndef DEF_INFO
#define DEF_INFO

#include <sstream>
#include "enums.h"
#include "varGlobales.h"
#include <SFML/Graphics.hpp>

class Info
{
public:
    Info(sf::RenderWindow &fenetre);
    ~Info();
    void initInfo();
    void reinitInfo();
    void reinitialiserH();
    void demarrerH();
    void pauseH();
    float getTemps();
    int getNbDplP();
    template <class T> std::string nbEnString(T nb);
    void indiquerNiveau();
    void compteurDeplacementP();
    void gestionTemps();
    void afficheInfo();



private:
    sf::Text m_txtNiveau;
    sf::Text m_txtTemps;
    sf::Text m_txtCompDepl;
    sf::Font m_fntTemps;
    sf::Font m_fntAutre;
    int m_nbDeplacementP;
    sf::Texture m_tCadre;
    sf::Sprite m_sCadre;
    EtatH m_etatH;
    sf::Clock m_horloge;
    float m_tempsEcoule;
    sf::RenderWindow *m_fenetre;

};

#endif // DEF_INFO
