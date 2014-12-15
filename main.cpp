#include "general.h"

using namespace std;

enum typeUtils {Console, SFML};

int main()
{

    //Console
    AffichageConsole affichConsole;
    ControleurConsole controlConsole;
    typeUtils type = Console;

    //SFML
    AffichageSFML affich;
    ControleurSFML control;
    //typeUtils type = SFML;


    board monPlateau = board();

    if(type == Console)
    {

        while(monPlateau.isQuarto() != true)
        {
            affichConsole.drawBoard(monPlateau);
            controlConsole.selectionnerPiece(monPlateau);
            controlConsole.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());
            system("cls");
        }
            affichConsole.drawBoard(monPlateau);
            cout<<"Quarto !\n";
            system("close");
            string reset = "";
            do{
            cout<<"Voulez-vous recommencer ? (Y/N)"<<endl;
            cin>>reset;
            if(reset[0] != 'Y' || reset[0] != 'N') cout<<"Veuillez rentrer Y ou N"<<endl; // y'a un souci meme quand l'input est bon il return false
            cin.clear();
            }while(reset[0] != 'Y' || reset[0] != 'N');
            if (reset[0] == 'Y')
            {
               // system("close"); une instr pour fermer la premiere console
                main();
                return 0;
            }

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
                       && control.getEvent().mouseButton.y >20 && control.getEvent().mouseButton.y < 170)
                    {
                        control.selectionnerPiece(monPlateau);
                    }
                    if(monPlateau.getPieceSelectionnee() != Piece() && (control.getEvent().mouseButton.y > 230 && control.getEvent().mouseButton.y < 550)
                       && (control.getEvent().mouseButton.x > 160 && control.getEvent().mouseButton.x < 480))
                    {
                        control.jouerPiece(monPlateau, monPlateau.getPieceSelectionnee());
                        monPlateau.setPieceSelectionnee(Piece());
                    }
                }

                if(monPlateau.isQuarto())
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
