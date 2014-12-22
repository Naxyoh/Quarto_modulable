#include "general.h"
using namespace std;

enum typeUtils {Console=1, SFML};

int main()
{
    cout<<"Voulez-vous utiliser la version console (1) ou SFML(2) ?"<<endl;
    int config;
    cin>>config;
    typeUtils type = (typeUtils) config;
    system("cls");
    srand(time(NULL));

    board monPlateau = board();
    joueur j1 = humain, j2 = humain;
    monPlateau.ajouterListeJoueur(j1,0);
    monPlateau.ajouterListeJoueur(j2,1);
    monPlateau.setJoueurActuel(1);

    if(type == Console)
    {
        AffichageConsole affichConsole;
        ControleurConsole controlConsole;
        bool nouveau = true;
        while(true)
        {

            //Avant de rentrer dans la boucle on demande au joueur 1 de selectionner une piece
            if(nouveau == true)
            {
                        cout<<"Au tour du Joueur "<<monPlateau.getJoueurActuel()<<endl;
            affichConsole.drawPieceJouable(monPlateau);
            controlConsole.selectionnerPiece(monPlateau);
            }

            if(monPlateau.isQuarto() != true)
            {
                nouveau = false;
                //Changement de joueur
                monPlateau.changementJoueur();
                system("cls");

                //Affichage du plateau
                affichConsole.drawBoard(monPlateau);
//            cout<<endl<<"Score board = "<<evalue(monPlateau)<<endl<<endl;

                //Renseignement sur le tour (joueur et piece a placer)
                cout<<endl<<endl<<"Au tour du Joueur "<<monPlateau.getJoueurActuel()<<endl<<endl;
                cout<<"Vous devez placer "<<convertPieceToString(monPlateau.getPieceSelectionnee())<<endl<<endl;

                //Playing of the piece
                controlConsole.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());

                //Si Quarto on sort de la boucle
                //if(monPlateau.isQuarto()) break;

                //On efface le contenu de la console et on affiche le board et la liste de pieces jouables
                system("cls");
                affichConsole.drawBoard(monPlateau);
                affichConsole.drawPieceJouable(monPlateau);

                //on selectionne la piece
                cout<<endl<<endl<<"Joueur "<<monPlateau.getJoueurActuel()<<endl<<endl;
                controlConsole.selectionnerPiece(monPlateau);

            }
            else
            {
                nouveau = true;
                //Si quarto on affiche le board final
                system("cls");
                affichConsole.drawBoard(monPlateau);
                cout<<"Quarto !"<<endl<<endl;
                system("pause");
                controlConsole.restart(monPlateau);
            }
        }
    }

    else if(type == SFML)
    {
        AffichageSFML affich;
        ControleurSFML control;
        affich.setWindow();
        while (affich.getMainWindow().isOpen())
        {
            sf::Event event;
            affich.drawBoard(monPlateau);
            while (affich.getMainWindow().pollEvent(event))
            {
                control.setEvent(event);
                if (control.getEvent().type == sf::Event::Closed) affich.getMainWindow().close();

                if (control.getEvent().type == sf::Event::MouseButtonPressed)
                {
                    control.selectionnerPiece(monPlateau); // On selectionne une piece
                    if(monPlateau.getPieceSelectionnee() != Piece() && (control.getEvent().mouseButton.y > 230 && control.getEvent().mouseButton.y < 550) && (control.getEvent().mouseButton.x > 160 && control.getEvent().mouseButton.x < 480)) // Necessaire pour synchroniser le jeu et le positionnement
                    {
                        control.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());
                    }
                }
                if (control.getEvent().type == sf::Event::KeyPressed) control.restart(monPlateau);
            }
            affich.drawBoard(monPlateau);
        }
    }

    return 0;
}
