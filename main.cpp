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
    joueur j1 = humain, j2 = facile;
    monPlateau.ajouterListeJoueur(j1,0);
    monPlateau.ajouterListeJoueur(j2,1);
    monPlateau.setJoueurActuel(1);
    monPlateau.setJoueur(humain);

//Pour jouer dans de bonnes condition il faut une fenetre de largeur au moins 90 et hauteur 50
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
                if (event.type == sf::Event::Closed) affich.getMainWindow().close();

                    control.selectionnerPiece(monPlateau); // On selectionne une piece
                    control.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());

                if (event.type == sf::Event::KeyPressed) control.restart(monPlateau);
            }
            affich.drawBoard(monPlateau);
        }
    }
    return 0;
}
