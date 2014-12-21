#include "general.h"
using namespace std;

enum typeUtils {Console, SFML};

int main()
{
    //Console
    AffichageConsole affichConsole;
    ControleurConsole controlConsole;
    //typeUtils type = Console;

    //SFML
    AffichageSFML affich;
    ControleurSFML control;
    typeUtils type = SFML;

    board monPlateau = board();
    monPlateau.setJoueur(1);

    if(type == Console)
    {
        //Avant de rentrer dans la boucle on demande au joueur 1 de selectionner une piece
        cout<<"Au tour du Joueur "<<monPlateau.getJoueur()<<endl;
        affichConsole.drawPieceJouable(monPlateau);
        controlConsole.selectionnerPiece(monPlateau);

        while(monPlateau.isQuarto() != true)
        {
            //Changement de joueur
            if(monPlateau.getJoueur() == 1) monPlateau.setJoueur(2);
            else if(monPlateau.getJoueur() == 2) monPlateau.setJoueur(1);
            system("cls");

            //Affichage du plateau
            affichConsole.drawBoard(monPlateau);

            //Renseignement sur le tour (joueur et piece a placer
            cout<<endl<<endl<<"Au tour du Joueur "<<monPlateau.getJoueur()<<endl<<endl;
            cout<<"Vous devez placer "<<convertPieceToString(monPlateau.getPieceSelectionnee())<<endl<<endl;

            //Playing of the piece
            controlConsole.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());

            //Si Quarto on sort de la boucle
            if(monPlateau.isQuarto()) break;

            //On efface le contenu de la console et on affiche le board et la liste de pieces jouables
            system("cls");
            affichConsole.drawBoard(monPlateau);
            affichConsole.drawPieceJouable(monPlateau);

            //on selectionne la piece
            cout<<endl<<endl<<"Joueur "<<monPlateau.getJoueur()<<endl<<endl;
            controlConsole.selectionnerPiece(monPlateau);

        }
        //Si quarto on affiche le board final
        affichConsole.drawBoard(monPlateau);
        cout<<"Quarto !\n";

                //Gestion (ou pas) du reset
//            //system("close");
//            string reset = "";
//            do{
//            cout<<"Voulez-vous recommencer ? (Y/N)"<<endl;
//            cin>>reset;
//            for(size_t k = 0; k<reset.size(); k++)
//            {
//                cout<<"Vous avez rentre "<<(int)reset[k]<<endl;
//                cout<<"taille de reset : "<<reset.size()<<endl;
//            }
//            if(reset != "Yes" || reset[0] != 'N')
//            {
//                cout<<"Veuillez rentrer Y ou N"<<endl; // y'a un souci meme quand l'input est bon il return false
//                cin.clear();
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            }
//            }while((int)reset[0] != 89 || reset[0] != 'N');
//            if (reset[0] == 'Y')
//            {
//               // system("close"); une instr pour fermer la premiere console
//                main();
//                return 0;
//            }

    }

    else if(type == SFML)
    {
        affich.setWindow();
        while (affich.getMainWindow().isOpen())
        {
            sf::Event event;
            affich.drawBoard(monPlateau);
            while (affich.getMainWindow().pollEvent(event))
            {

                control.setEvent(event);
                if (control.getEvent().type == sf::Event::Closed)
                {
                    affich.getMainWindow().close();
                }

                if (control.getEvent().type == sf::Event::MouseButtonPressed)
                {
                    if(control.getEvent().mouseButton.x>110 && control.getEvent().mouseButton.x<650
                       && control.getEvent().mouseButton.y >20 && control.getEvent().mouseButton.y < 170 && monPlateau.getPieceSelectionnee() == Piece() )
                    {
                        control.selectionnerPiece(monPlateau);
                        //Changement de joueur
                        if(monPlateau.getJoueur() == 1 && monPlateau.getPieceSelectionnee() != Piece()) monPlateau.setJoueur(2);
                        else if(monPlateau.getJoueur() == 2 && monPlateau.getPieceSelectionnee() != Piece()) monPlateau.setJoueur(1);
                    }
                    if(monPlateau.getPieceSelectionnee() != Piece() && (control.getEvent().mouseButton.y > 230 && control.getEvent().mouseButton.y < 550)
                       && (control.getEvent().mouseButton.x > 160 && control.getEvent().mouseButton.x < 480))
                    {
                        bool piecePlacee = control.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());
                        monPlateau.setPieceSelectionnee(Piece());
                        if(piecePlacee == false) //S'il y a eu un probleme lors du posage de la piece on redemande au joueur 2 de choisir une piece
                        {
                            if(monPlateau.getJoueur() == 1) monPlateau.setJoueur(2);
                            else if(monPlateau.getJoueur() == 2) monPlateau.setJoueur(1);
                        }
                    }
                }

                if(monPlateau.isQuarto() || monPlateau.isDraw())
                    if (control.getEvent().type == sf::Event::KeyPressed)
                {
                    affich.getMainWindow().close();
                    main();
                    return 0;
                }
                affich.drawBoard(monPlateau);
            }
        }
    }
    return 0;
}
