#include "general.h"
using namespace std;

int main()
{
    srand(time(NULL));
    board monPlateau = board();
    init(monPlateau); // se trouve dans board.cpp

//Pour jouer dans de bonnes condition il faut une console de largeur au moins 90 et hauteur 50

    //Si on lance la version console
    if(monPlateau.getType() == Console)
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
                affichConsole.drawPieceJouable(monPlateau); //affiche les piece jouables
                controlConsole.selectionnerPiece(monPlateau); //fonction permettant la selection d'une piece parmi les pieces jouables
            }

            if(monPlateau.isQuarto() != true)
            {
                nouveau = false;
                //Changement de joueur
                monPlateau.changementJoueur();
                system("cls");

                //Affichage du plateau
                affichConsole.drawBoard(monPlateau);

                //Renseignement sur le tour (joueur et piece a placer)
                cout<<endl<<endl<<"Au tour du Joueur "<<monPlateau.getJoueurActuel()<<endl<<endl;
                cout<<"Vous devez placer "<<convertPieceToString(monPlateau.getPieceSelectionnee())<<endl<<endl;

                //Fonction permettant de jouer une piece
                controlConsole.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());

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

    //Si on utilise la version SFML
    else if(monPlateau.getType() == SFML)
    {
        AffichageSFML affich;
        ControleurSFML control;
        affich.setWindow(); //création de la fenetre principale
        while (affich.getMainWindow().isOpen())
        {
            sf::Event event; // Evenement lié au fonctionnement de SFML
            affich.drawBoard(monPlateau); // affiche le plateau et les pieces jouables
            while (affich.getMainWindow().pollEvent(event)) // génération d'un evenement
            {
                control.setEvent(event);
                if (event.type == sf::Event::Closed) affich.getMainWindow().close(); // Si on clique sur la croix de la fenetre on ferme la fenetre

                    control.selectionnerPiece(monPlateau); // On selectionne une piece
                    control.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee()); // puis on la joue

                if (event.type == sf::Event::KeyPressed) control.restart(monPlateau); // si on appuie sur une touche du clavier on appelle la fonction de reset
            }
            affich.drawBoard(monPlateau); // on affiche le plateau final
        }
    }
    return 0;
}
