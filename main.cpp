#include "general.h"

using namespace std;

int main()
{
    AffichageConsole affich;
    ControleurConsole control;

    board monPlateau = board();


    while(monPlateau.isQuarto() != true)
    {
        Piece pieceSelectionne = Piece();
       affich.drawBoard(monPlateau);
        pieceSelectionne = control.selectionnerPiece(monPlateau);
        control.jouerPiece(monPlateau, pieceSelectionne);
    }
    //affich.drawBoard(monPlateau);
    cout<<"Quarto !\n";
    return 0;
}
