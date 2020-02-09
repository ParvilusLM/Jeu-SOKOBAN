#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR

#include "personnage.h"
#include "decor.h"
#include "info.h"
#include "menu.h"
#include "enums.h"
#include "constantes.h"
#include "varGlobales.h"

class Controleur
{
public:
    Controleur(sf::RenderWindow &fenetre);
    ~Controleur();
    void debutJeu();
    int chargementNiveau(int no_niveau);
    void changementNiveau(int niveau);
    void niveauPrecedent();
    void niveauSuivant();
    void rejouerPartie();
    void retourSurCoups();
    void gestionDeplPers(int directionP);
    void gestionDplSouris(sf::Vector2f posSouris);
    void gestionSelectionSouris();
    bool collisionPM(int directionP);
    bool collisionPC(int directionP);
    bool deplCaissePoss(int directionP);
    bool finPartie();
    void retourMenu();
    void afficheJeu();
    void afficheMenu();
    void demarrerHorl();
    void compteurTemps();


private:
    sf::RenderWindow *m_fenetre;

    Decor *m_decor;
    Info *m_info;
    Personnage *m_personnage;
    Menu *m_menu;

    std::vector<CaptureJeu> m_capturesJeu;

    sf::Sprite m_sFelicitations;
    sf::Texture m_tFelicitations;

    sf::Sprite m_sPerdu;
    sf::Texture m_tPerdu;



};

#endif // DEF_CONTROLEUR
