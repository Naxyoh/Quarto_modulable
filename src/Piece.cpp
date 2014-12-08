#include "general.h"

using namespace std;

Piece::Piece() : m_couleur(zeroC), m_taille(zeroT), m_forme(zeroF), m_profondeur(zeroP)
{
    //ctor
}

Piece::Piece(couleur color, taille length, forme shape, profondeur depth)
{
	m_couleur = color;
	m_taille = length;
	m_forme = shape;
	m_profondeur = depth;
}

Piece::~Piece()
{
    //dtor
}

void Piece::setCouleur(couleur color)
{
    m_couleur = color;
}
couleur Piece::getCouleur()
{
    return m_couleur;
}

void Piece::setTaille(taille length)
{
    m_taille = length;
}
taille Piece::getTaille()
{
    return m_taille;
}

void Piece::setForme(forme shape)
{
    m_forme = shape;
}
forme Piece::getForme()
{
    return m_forme;
}

void Piece::setProfondeur(profondeur depth)
{
    m_profondeur = depth;
}
profondeur Piece::getProfondeur()
{
    return m_profondeur;
}

//Renvoie une chaîne de caractère correspondant à une pièce
string convertPieceToString(Piece piece)
{
    string pieceString = "";

    if(piece.getCouleur()== blanc) pieceString += "Blanc";
    else if(piece.getCouleur()== zeroC) pieceString += "        ";
    else pieceString += "Noir";

    if(piece.getTaille() == grand) pieceString += "Grand";
    else if(piece.getTaille() == zeroT) pieceString += " ";
    else pieceString += "Petit";

    if(piece.getForme()==rond) pieceString += "Rond";
    else if(piece.getForme()==zeroF) pieceString += " ";
    else pieceString+="Carre";

    if(piece.getProfondeur() == plein) pieceString += "Plein";
    else if(piece.getProfondeur() == zeroP) pieceString += "         ";
    else pieceString += "Creux";

    return pieceString;
}

//Renvoie un vecteur contenant toutes les pièces possibles
std::vector<Piece> creerToutePiece()
{
    std::vector<Piece> listePiece;
    for (size_t coul = 1; coul<3; coul++)
    {
        for (size_t form = 1; form<3; form++)
        {
            for (size_t tail = 1; tail<3; tail++)
            {
                for (size_t cre = 1; cre<3; cre++)
                {
                    listePiece.push_back(Piece((couleur)coul, (taille)tail, (forme)form, (profondeur)cre));
                }
            }
        }
    }
    return listePiece;
}

bool operator==(Piece a, Piece b)
{
    return ((int)a.getCouleur() == (int)b.getCouleur()) && ((int)a.getForme() == (int)b.getForme()) && ((int)a.getProfondeur() == (int)b.getProfondeur()) && ((int)a.getTaille() == (int)b.getTaille());
}

bool operator!=(Piece a, Piece b)
{
    return !(a==b);
}
