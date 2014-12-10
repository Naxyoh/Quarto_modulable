#include "general.h"

using namespace std;

int main()
{
    //Console
//    AffichageConsole affich;
//    ControleurConsole control;

    //SFML
    AffichageSFML affich;
    ControleurSFML control;



    board monPlateau = board();

//    affichSFML.drawBoard(monPlateau);

    if(typeid(affich) == typeid(AffichageConsole))
    {
        while(monPlateau.isQuarto() != true)
        {
            Piece pieceSelectionne = Piece();
            affich.drawBoard(monPlateau);
            pieceSelectionne = control.selectionnerPiece(monPlateau);
            control.jouerPiece(monPlateau, pieceSelectionne);
            system("clear");
        }
        affich.drawBoard(monPlateau);
        cout<<"Quarto !\n";
    }

    else if(typeid(affich) == typeid(AffichageSFML))
    {
        affich.setWindow();
        while (affich.getMainWindow().isOpen())
        {
            while(monPlateau.isQuarto() != true)
            {
                sf::Event event;
                control.setEvent(event);
                affich.drawBoard(monPlateau);
                while (affich.getMainWindow().pollEvent(control.getEvent()))
                {
                    if (control.getEvent().type == sf::Event::Closed) affich.getMainWindow().close();
                    if (control.getEvent().type == sf::Event::MouseButtonPressed)
                    {
                        Piece pieceSelectionne = Piece();
                        pieceSelectionne = control.selectionnerPiece(monPlateau);
                        control.jouerPiece(monPlateau, pieceSelectionne);
                    }
                }
            }
        }
    }
    return 0;
}
