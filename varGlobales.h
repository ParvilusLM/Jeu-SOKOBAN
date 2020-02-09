#ifndef DEF_VARGLOBALES
#define DEF_VARGLOBALES

#include <SFML/Graphics.hpp>

extern int carte[14][14];
extern int niveau;
extern bool jeuEnCours;
extern bool jeuGagne;
extern bool jeuPerdu;
extern sf::Vector2f posSouris;

struct Caisse
    {
        int etat;
        sf::Sprite m_caisse;
    };

struct CaptureJeu
    {
        std::vector<Caisse> caisses;
        sf::Vector2f posPersonnage;

    };

#endif // DEF_VARGLOBALES


