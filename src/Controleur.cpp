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

        sf::Mouse::Button button = m_event.mouseButton.button;
        if (button == sf::Mouse::Left)
        {
            if (m_event.mouseButton.y < 80 && m_event.mouseButton.y > 20)
            {
                if (m_event.mouseButton.x < 170 && m_event.mouseButton.x > 100) position = 0;
                else if (m_event.mouseButton.x < 240 && m_event.mouseButton.x > 170) position = 1;
                else if (m_event.mouseButton.x < 310 && m_event.mouseButton.x> 240) position = 2;
                else if (m_event.mouseButton.x < 380 && m_event.mouseButton.x > 310) position = 3;
                else if (m_event.mouseButton.x < 450 && m_event.mouseButton.x > 380) position = 4;
                else if (m_event.mouseButton.x < 520 && m_event.mouseButton.x > 450) position = 5;
                else if (m_event.mouseButton.x < 590 && m_event.mouseButton.x > 520) position = 6;
                else if (m_event.mouseButton.x < 660 && m_event.mouseButton.x > 590) position = 7;
            }
            else if (m_event.mouseButton.y < 170 && m_event.mouseButton.y > 110)
            {
                if (m_event.mouseButton.x < 170 && m_event.mouseButton.x > 100) position = 8;
                else if (m_event.mouseButton.x < 240 && m_event.mouseButton.x > 170) position = 9;
                else if (m_event.mouseButton.x < 310 && m_event.mouseButton.x> 240) position = 10;
                else if (m_event.mouseButton.x < 380 && m_event.mouseButton.x > 310) position = 11;
                else if (m_event.mouseButton.x < 450 && m_event.mouseButton.x > 380) position = 12;
                else if (m_event.mouseButton.x < 520 && m_event.mouseButton.x > 450) position = 13;
                else if (m_event.mouseButton.x < 590 && m_event.mouseButton.x > 520) position = 14;
                else if (m_event.mouseButton.x < 660 && m_event.mouseButton.x > 590) position = 15;
            }
        }

        if(position == -1) return Piece();

	Piece pieceSelectionne = monPlateau.getListePieceJouable()[position];
	std::cout<<"Piece selec : "<<convertPieceToString(pieceSelectionne)<<" position : "<<position<<std::endl;

	return pieceSelectionne;
}


void ControleurSFML::jouerPiece(board& myBoard, Piece pieceAJouer)
{
    int position = -1;
    sf::Mouse::Button button = m_event.mouseButton.button;
    if (button == sf::Mouse::Left)
    {

            if (m_event.mouseButton.y > 230 && m_event.mouseButton.y < 310)
            {
                if (m_event.mouseButton.x > 160 && m_event.mouseButton.x > 240) position = 0;
                else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320 && myBoard.getListePieceJouable().size()>1) position = 1;
                else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400 && myBoard.getListePieceJouable().size()>2) position = 2;
                else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480 && myBoard.getListePieceJouable().size()>3) position = 3;
            }
            else if (m_event.mouseButton.y > 310 && m_event.mouseButton.y < 390)
            {
                if (m_event.mouseButton.x > 160 && m_event.mouseButton.x > 240 && myBoard.getListePieceJouable().size()>4) position = 4;
                else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320 && myBoard.getListePieceJouable().size()>5) position = 5;
                else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400 && myBoard.getListePieceJouable().size()>6) position = 6;
                else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480 && myBoard.getListePieceJouable().size()>7) position = 7;
            }
            else if (m_event.mouseButton.y > 390 && m_event.mouseButton.y < 470)
            {
                if (m_event.mouseButton.x > 160 && m_event.mouseButton.x > 240 && myBoard.getListePieceJouable().size()>8) position = 8;
                else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320 && myBoard.getListePieceJouable().size()>9) position = 9;
                else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400 && myBoard.getListePieceJouable().size()>10) position = 10;
                else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480 && myBoard.getListePieceJouable().size()>11) position = 11;
            }
            else if (m_event.mouseButton.y > 470 && m_event.mouseButton.y < 550)
            {
                if (m_event.mouseButton.x > 160 && m_event.mouseButton.x > 240 && myBoard.getListePieceJouable().size()>12) position = 12;
                else if (m_event.mouseButton.x > 240 && m_event.mouseButton.x < 320 && myBoard.getListePieceJouable().size()>13) position = 13;
                else if (m_event.mouseButton.x > 320 && m_event.mouseButton.x < 400 && myBoard.getListePieceJouable().size()>14) position = 14;
                else if (m_event.mouseButton.x > 400 && m_event.mouseButton.x < 480 && myBoard.getListePieceJouable().size()>15) position = 15;
            }

    }
    if(position == -1 || pieceAJouer == Piece())
    {
       return;
    }
    std::cout<<"piece a jouer : "<<convertPieceToString(pieceAJouer)<<" a placer a la position : "<<std::endl;
    myBoard.setListePieceBoard(pieceAJouer, position);
    myBoard.eraseFromJouable(position);
}

void ControleurSFML::setEvent(sf::Event myEvent)
{
    m_event = myEvent;
}

sf::Event &ControleurSFML::getEvent()
{
    return m_event;
}
