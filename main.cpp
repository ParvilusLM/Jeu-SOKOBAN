#include <iostream>
#include <SFML/Graphics.hpp>
#include "controleur.h"


using namespace sf;

bool jeuEnCours = false;
bool jeuGagne=false;
bool jeuPerdu=false;
int niveau=1;
int carte[14][14]={0};
Vector2f posSouris;

int main()
{
    RenderWindow fenetre(VideoMode(LARGEUR_F,HAUTEUR_F),"SOKOBAN");
    fenetre.setVerticalSyncEnabled(true);

    Controleur controleurJ(fenetre);

    while(fenetre.isOpen())
    {
        Event evenement;
        while(fenetre.pollEvent(evenement))
        {
            if(evenement.type==Event::Closed)
            {
                 fenetre.close();
                 break;
            }

            if(evenement.type==Event::MouseMoved && !jeuEnCours)
            {
                posSouris.x=evenement.mouseMove.x;
                posSouris.y=evenement.mouseMove.y;
                controleurJ.gestionDplSouris(posSouris);
            }

              if(evenement.type==Event::MouseButtonPressed && !jeuEnCours)
              {
                  Mouse::Button button = evenement.mouseButton.button;
                  if (button == Mouse::Left) // Bouton gauche
                  {
                      controleurJ.gestionSelectionSouris();

                      if(jeuEnCours)
                      {
                          controleurJ.debutJeu();
                      }
                  }

              }

            if(evenement.type==Event::KeyPressed && jeuEnCours && !jeuGagne)
            {
                switch(evenement.key.code)
                {
                case Keyboard::Left:
                    {
                        controleurJ.gestionDeplPers(GAUCHE);
                    }
                    break;

                case Keyboard::Right:
                    {
                        controleurJ.gestionDeplPers(DROITE);
                    }
                    break;

                case Keyboard::Up:
                    {
                        controleurJ.gestionDeplPers(HAUT);
                    }
                    break;

                case Keyboard::Down:
                    {
                        controleurJ.gestionDeplPers(BAS);
                    }
                    break;

                case Keyboard::A:
                    {
                        controleurJ.niveauPrecedent();
                    }
                    break;

                case Keyboard::S:
                    {
                        controleurJ.niveauSuivant();
                    }
                    break;

                case Keyboard::R:
                    {
                        controleurJ.rejouerPartie();
                    }
                    break;

                case Keyboard::Z:
                    {
                        controleurJ.retourSurCoups();
                    }
                    break;

                case Keyboard::Q:
                    {
                        controleurJ.retourMenu();
                    }
                    break;

                default:
                    break;

                }
            }



        }

        if(jeuEnCours)
        {
            controleurJ.compteurTemps();

            if(!jeuGagne && !jeuPerdu)
            {
                controleurJ.finPartie();

            }
            else
            {
                Time temps=seconds(5.0f);
                if(jeuGagne)
                {
                    sleep(temps);
                    controleurJ.niveauSuivant();
                    jeuGagne=false;
                }
                else
                {
                    sleep(temps);
                    controleurJ.retourMenu();
                    jeuPerdu=false;
                }

            }

        }
        else
        {

        }


         fenetre.clear(Color(179,189,155));

         if(jeuEnCours)
         {
             controleurJ.afficheJeu();
         }
         else
         {
             controleurJ.afficheMenu();
         }


         //affiche tout a l'ecran
         fenetre.display();
    }



    return EXIT_SUCCESS;
}

