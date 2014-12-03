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
    myBoard.getListePieceJouable().erase(myBoard.getListePieceJouable().begin()+position-1);
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

//    for(size_t j = 0; myBoard.getListePieceBoard().size(); j++)
//        std::cout<<convertPieceToString(myBoard.getListePieceBoard()[j]);
}
