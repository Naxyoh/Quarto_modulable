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
        int etape = 0;
        bool selectionValidee = false, joueeValidee = false;
        Piece pieceSelectionne = Piece();
        while (affich.getMainWindow().isOpen())
        {
            while(monPlateau.isQuarto() != true)
            {
                sf::Event event;

                control.setEvent(event);
                affich.drawBoard(monPlateau);
                while (affich.getMainWindow().pollEvent(control.getEvent()))
                {

                    selectionValidee = false;
                    joueeValidee = false;
                    if (control.getEvent().type == sf::Event::Closed) affich.getMainWindow().close();

                    if (control.getEvent().type == sf::Event::MouseButtonPressed)
                    {
                        if(etape == 0)
                        {
                            pieceSelectionne = control.selectionnerPiece(monPlateau);
                            selectionValidee = true;

                        }

                        //std::cout<<"piece a jouer : "<<convertPieceToString(pieceSelectionne)<<" a placer a la position : "<<std::endl;
                        if(etape == 1)
                        {
                            control.jouerPiece(monPlateau, pieceSelectionne); // Y'a un pb de synchro, on fait selection et jeu à partir du meme click
                            joueeValidee = true;
                        }

//                        for(size_t j = 0; j<monPlateau.getListePieceBoard().size(); j++)
//                        {
//                            cout<<j+1<<") ";
//                            cout<<convertPieceToString(monPlateau.getListePieceBoard()[j]);
//                            cout<<"\n";
//                        }
                        if(etape == 0 && selectionValidee)
                        {
                            etape = 1;
                        }
                        if(etape == 1 && joueeValidee)
                        {
                            etape = 0;
                        }

                    }
                }
            }
        }
    }
    return 0;
}
