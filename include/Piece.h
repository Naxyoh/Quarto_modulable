#ifndef PIECE_H
#define PIECE_H

#include "general.h"

enum couleur{zeroC, blanc, noir}; //les zeros servent à initialiser
enum taille{zeroT, petit, grand};
enum forme{zeroF, rond, carre};
enum profondeur{zeroP, creux, plein};

class Piece
{
    public:
        Piece();
        Piece(couleur color, taille length, forme shape, profondeur depth);
        virtual ~Piece();

        void setCouleur(couleur);
		couleur getCouleur();
		void setTaille(taille);
		taille getTaille();
		void setForme(forme);
		forme getForme();
		void setProfondeur(profondeur);
		profondeur getProfondeur();

    protected:
        couleur m_couleur;
		taille m_taille;
		forme m_forme;
		profondeur m_profondeur;
    private:
};

std::string convertPieceToString(Piece); // traduit les pieces en string pour l'affichage
std::vector<Piece> creerToutePiece(); // creer un vecteur contenant toutes les pieces
std::string toString(int integer);

bool operator==( Piece a, Piece b);
bool operator!=( Piece a, Piece b);
#endif // PIECE_H
