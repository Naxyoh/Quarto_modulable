#include "general.h"

Piece ControleurConsole::selectionnerPiece(board &myBoard)
{
    int position = -1;
    do
    {
        std::cout<<"Rentrer le numero de la piece que vous souhaitez donner (Veuillez rentrer un numero entre 1 et 16)\n";
        std::cin>>position;
        if(position<1 || position>16) std::cout<<"Numéro de piece invalide\n";
    }while(position<1 || position>16);

    Piece pieceSelectionne = myBoard.getListePieceJouable()[position-1];
    std::cout<<"Vous avez selectionne "<<convertPieceToString(pieceSelectionne)<<std::endl;
    return pieceSelectionne;
}

void ControleurConsole::jouerPiece(board &myBoard, Piece pieceAJouer)
{
    int pos = -1;
    do
    {
        std::cout<<"Quelle position ? (Veuillez rentrer une position entre 1 et 16)\n";
        std::cin>>pos;
        if(pos<1 || pos>16 || (myBoard.getListePieceBoard()[pos-1] != Piece())) std::cout<<"Position invalide\n";
    } while(pos<1 || pos>16 || (myBoard.getListePieceBoard()[pos-1] != Piece()));

    myBoard.setListePieceBoard(pieceAJouer, pos-1);
    myBoard.eraseFromJouable(pos-1);
}

Piece ControleurSFML::selectionnerPiece(board &monPlateau)
{
    int position = -1;
    sf::Event event;
    if (event.type == sf::Event::MouseButtonPressed){
        sf::Mouse::Button button = event.mouseButton.button;
        if (button == sf::Mouse::Left)
        {
            if (event.mouseButton.y < 70 && event.mouseButton.y > 10)
            {
                if (event.mouseButton.x < 170 && event.mouseButton.x > 100) position = 0;
                else if (event.mouseButton.x < 240 && event.mouseButton.x > 170) position = 1;
                else if (event.mouseButton.x < 310 && event.mouseButton.x> 240) position = 2;
                else if (event.mouseButton.x < 380 && event.mouseButton.x > 310) position = 3;
                else if (event.mouseButton.x < 450 && event.mouseButton.x > 380) position = 4;
                else if (event.mouseButton.x < 520 && event.mouseButton.x > 450) position = 5;
                else if (event.mouseButton.x < 590 && event.mouseButton.x > 520) position = 6;
                else if (event.mouseButton.x < 660 && event.mouseButton.x > 590) position = 7;
            }
            else if (event.mouseButton.y < 140 && event.mouseButton.y > 80)
            {
                if (event.mouseButton.x < 170 && event.mouseButton.x > 100) position = 8;
                else if (event.mouseButton.x < 240 && event.mouseButton.x > 170) position = 9;
                else if (event.mouseButton.x < 310 && event.mouseButton.x> 240) position = 10;
                else if (event.mouseButton.x < 380 && event.mouseButton.x > 310) position = 11;
                else if (event.mouseButton.x < 450 && event.mouseButton.x > 380) position = 12;
                else if (event.mouseButton.x < 520 && event.mouseButton.x > 450) position = 13;
                else if (event.mouseButton.x < 590 && event.mouseButton.x > 520) position = 14;
                else if (event.mouseButton.x < 660 && event.mouseButton.x > 590) position = 15;
            }
        }
    }
	Piece pieceSelectionne = monPlateau.getListePieceJouable()[position];
	return pieceSelectionne;
}


void ControleurSFML::jouerPiece(board& myBoard, Piece pieceAJouer)
{

}
