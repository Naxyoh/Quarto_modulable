#include "general.h"
#include "Piece.h"
#include <cmath>

using namespace std;

board::board() : m_sizeBoard(4), m_listeJoueur(), m_joueurActuel(0), m_pieceSelectiionnee(Piece()), m_listePieceJouable(creerToutePiece())
{
    for(int i = 0; i< m_sizeBoard*m_sizeBoard; i++)
    {
       m_listePieceBoard.push_back(Piece());
    }
}

board::~board()
{
    //dtor
}

void board::setListeJoueur(std::vector<joueur> listeJoueur)
{
    m_listeJoueur = listeJoueur;
}

void board::ajouterListeJoueur(joueur joueurAAjouter, int position)
{
    m_listeJoueur.insert(m_listeJoueur.begin()+position, joueurAAjouter);
}

std::vector<joueur> board::getListeJoueur()
{
    return m_listeJoueur;
}

void board::changementJoueur()
{
    if(m_joueurActuel == 1 && m_pieceSelectiionnee != Piece()) m_joueurActuel = 2;
    else if(m_joueurActuel == 2 && m_pieceSelectiionnee != Piece()) m_joueurActuel =1;
}

void board::setJoueurActuel(int numero)
{
    m_joueurActuel = numero;
}

int board::getJoueurActuel()
{
    return m_joueurActuel;
}

//Renvoie le vecteur des pièces présentes sur le plateau
std::vector<Piece> board::getListePieceBoard()
{
    return m_listePieceBoard;
}

void board::setPieceSelectionnee(Piece pieceSelec)
{
    m_pieceSelectiionnee = pieceSelec;
}

Piece board::getPieceSelectionnee()
{
    return m_pieceSelectiionnee;
}

//Permet d'insérer une pièce dans le vecteur des pièces présentes sur le plateau
void board::setListePieceBoard(Piece pieceAAjouter, int pos)
{
    m_listePieceBoard[pos] = pieceAAjouter;
}

//Renvoie la taille du plateau de jeu
int board::getSizeBoard()
{
    return m_sizeBoard;
}

//Renvoie le vecteur des pièces jouables
std::vector<Piece> board::getListePieceJouable()
{
    return m_listePieceJouable;
}

//Retire une pièce du vecteur des pièces jouables à partir de sa position
void board::eraseFromJouable(int indicePieceJouable)
{
    m_listePieceJouable.erase(m_listePieceJouable.begin()+indicePieceJouable);
}

//Renvoie true si il y a un quarto pour les couleurs
bool board::isQuartoCouleur()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard*m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+1].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+2].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+3].getCouleur())
           && (m_listePieceBoard[i].getCouleur() != zeroC))
        {
            return true;
        }
    }
    //On regarde colonne par colonne
    for(int i = 0; i < m_sizeBoard; i = i + 1)
    {
        if((m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+4].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+8].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+12].getCouleur()) && (m_listePieceBoard[i].getCouleur() != zeroC))
        {
            return true;
        }
    }
    //On regarde la diagonale directe
    if((m_listePieceBoard[0].getCouleur() == m_listePieceBoard[5].getCouleur()) && (m_listePieceBoard[0].getCouleur() == m_listePieceBoard[10].getCouleur()) && (m_listePieceBoard[0].getCouleur() == m_listePieceBoard[15].getCouleur()) && (m_listePieceBoard[0].getCouleur() != zeroC))
    {
        return true;
    }
    //On regarde la diagonale indirecte
    if((m_listePieceBoard[3].getCouleur() == m_listePieceBoard[6].getCouleur()) && (m_listePieceBoard[3].getCouleur() == m_listePieceBoard[9].getCouleur()) && (m_listePieceBoard[3].getCouleur() == m_listePieceBoard[12].getCouleur()) && (m_listePieceBoard[3].getCouleur() != zeroC))
    {
        return true;
    }
    return false;
}

//Renvoie true si il y a un quarto pour les tailles
bool board::isQuartoTaille()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard*m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+1].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+2].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+3].getTaille()) && (m_listePieceBoard[i].getTaille() != zeroT))
        {
            return true;
        }
    }
    //On regarde colonne par colonne
    for(int i = 0; i < m_sizeBoard; i = i + 1)
    {
        if((m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+4].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+8].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+12].getTaille()) && (m_listePieceBoard[i].getTaille() != zeroT))
        {
            return true;
        }
    }
    //On regarde la diagonale directe
    if((m_listePieceBoard[0].getTaille() == m_listePieceBoard[5].getTaille()) && (m_listePieceBoard[0].getTaille() == m_listePieceBoard[10].getTaille()) && (m_listePieceBoard[0].getTaille() == m_listePieceBoard[15].getTaille()) && (m_listePieceBoard[0].getTaille() != zeroT))
    {
        return true;
    }
    //On regarde la diagonale indirecte
    if((m_listePieceBoard[3].getTaille() == m_listePieceBoard[6].getTaille()) && (m_listePieceBoard[3].getTaille() == m_listePieceBoard[9].getTaille()) && (m_listePieceBoard[3].getTaille() == m_listePieceBoard[12].getTaille()) && (m_listePieceBoard[3].getTaille() != zeroT))
    {
        return true;
    }
    return false;
}


//Renvoie true si il y a un quarto pour les formes
bool board::isQuartoForme()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard*m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getForme() == m_listePieceBoard[i+1].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+2].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+3].getForme())
           && (m_listePieceBoard[i].getForme() != zeroF))
        {
            return true;
        }
    }
    //On regarde colonne par colonne
    for(int i = 0; i < m_sizeBoard; i = i + 1)
    {
        if((m_listePieceBoard[i].getForme() == m_listePieceBoard[i+4].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+8].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+12].getForme()) && (m_listePieceBoard[i].getForme() != zeroF))
        {
            return true;
        }
    }
    //On regarde la diagonale directe
    if((m_listePieceBoard[0].getForme() == m_listePieceBoard[5].getForme()) && (m_listePieceBoard[0].getForme() == m_listePieceBoard[10].getForme()) && (m_listePieceBoard[0].getForme() == m_listePieceBoard[15].getForme()) && (m_listePieceBoard[0].getForme() != zeroF))
    {
        return true;
    }
    //On regarde la diagonale indirecte
    if((m_listePieceBoard[3].getForme() == m_listePieceBoard[6].getForme()) && (m_listePieceBoard[3].getForme() == m_listePieceBoard[9].getForme()) && (m_listePieceBoard[3].getForme() == m_listePieceBoard[12].getForme()) && (m_listePieceBoard[3].getForme() != zeroF))
    {
        return true;
    }
    return false;
}

//Renvoie true si il y a un quarto pour les profondeurs
bool board::isQuartoProfondeur()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard*m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+1].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+2].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+3].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() != zeroP))
        {
            return true;
        }
    }
    //On regarde colonne par colonne
    for(int i = 0; i < m_sizeBoard; i = i + 1)
    {
        if((m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+4].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+8].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+12].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() != zeroP))
        {
            return true;
        }
    }
    //On regarde la diagonale directe
    if((m_listePieceBoard[0].getProfondeur() == m_listePieceBoard[5].getProfondeur()) && (m_listePieceBoard[0].getProfondeur() == m_listePieceBoard[10].getProfondeur()) && (m_listePieceBoard[0].getProfondeur() == m_listePieceBoard[15].getProfondeur()) && (m_listePieceBoard[0].getProfondeur() != zeroP))
    {
        return true;
    }
    //On regarde la diagonale indirecte
    if((m_listePieceBoard[3].getProfondeur() == m_listePieceBoard[6].getProfondeur()) && (m_listePieceBoard[3].getProfondeur() == m_listePieceBoard[9].getProfondeur()) && (m_listePieceBoard[3].getProfondeur() == m_listePieceBoard[12].getProfondeur()) && (m_listePieceBoard[3].getProfondeur() != zeroP))
    {
        return true;
    }
    return false;
}


//Renvoie vrai si il y a un quarto de n'importe quel type
bool board::isQuarto()
{
    return isQuartoCouleur() || isQuartoForme() || isQuartoProfondeur() || isQuartoTaille();
}

bool board::isDraw()
{
    if(m_listePieceJouable.size()==0) return true;
    else return false;
}
