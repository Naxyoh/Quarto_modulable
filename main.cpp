#include "general.h"

using namespace std;

int main()
{
    board monPlateau = board();
    AffichageConsole affich;
    ControleurConsole control;

    /*affich.drawBoard(monPlateau);
    Piece piece = Piece(noir, petit, carre, creux);
    monPlateau.setListePieceBoard(piece, 2);
    cout<<"\n\n";
    affich.drawBoard(monPlateau);*/
    while(monPlateau.isQuarto() != true)
    {
        Piece pieceSelectionne = Piece();
        affich.drawBoard(monPlateau);
        pieceSelectionne = control.selectionnerPiece(monPlateau);
        control.jouerPiece(monPlateau, pieceSelectionne);
    }
    affich.drawBoard(monPlateau);
    cout<<"Quarto !\n";
    return 0;
}
