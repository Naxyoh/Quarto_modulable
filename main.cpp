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

    if(type == Console)
    {
        while(monPlateau.isQuarto() != true)
        {
            Piece pieceSelectionne = Piece();
            affichConsole.drawBoard(monPlateau);
            pieceSelectionne = controlConsole.selectionnerPiece(monPlateau);
            controlConsole.jouerPiece(monPlateau, pieceSelectionne);
            system("clear");
        }
            affichConsole.drawBoard(monPlateau);
            cout<<"Quarto !\n";
    }



    else if(type == SFML)
    {
        affich.setWindow();
        Piece pieceSelectionne = Piece();
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
                        pieceSelectionne = control.selectionnerPiece(monPlateau);
                    }
                    if(pieceSelectionne != Piece() && (control.getEvent().mouseButton.y > 230 && control.getEvent().mouseButton.y < 550)
                       && (control.getEvent().mouseButton.x > 160 && control.getEvent().mouseButton.x < 480))
                    {
                        control.jouerPiece(monPlateau, pieceSelectionne);
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
