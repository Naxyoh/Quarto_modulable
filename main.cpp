#include "general.h"

using namespace std;

int main()
{
    AffichageConsole affich;
    AffichageSFML affichSFML;
    ControleurConsole control;

    board monPlateau = board();

    affichSFML.drawBoard(monPlateau);
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
