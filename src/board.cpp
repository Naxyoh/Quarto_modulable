#include "general.h"
#include "Piece.h"
#include <cmath>

using namespace std;

board::board() : m_sizeBoard(4), m_listePieceJouable(creerToutePiece())
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

std::vector<Piece> board::getListePieceBoard()
{
    return m_listePieceBoard;
}

void board::setListePieceBoard(Piece pieceAAjouter, int pos)
{
    m_listePieceBoard[pos] = pieceAAjouter;
}

int board::getSizeBoard()
{
    return m_sizeBoard;
}

std::vector<Piece> board::getListePieceJouable()
{
    return m_listePieceJouable;
}

void board::deplacerPiece()
{
    int position =0;
    Piece pieceJouee = Piece();
    //Demande de la piece a jouer
    do
    {
        cout<<"Quelle piece ? (Donner le numero de la piece dans la liste ci-dessus)\n";
        cin>>position;
        if(position<=0 || position>16 || std::isnan(position))
            cout<<"La position rentrée est invalide\n";

    } while ((position<=0 || position>16 || std::isnan(position)));
    pieceJouee = m_listePieceJouable[position-1];
        position = 0;
    //Demande de la position
    do // on boucle tant que la position est invalide
    {
        cout<<"Quelle position ? (Rentrer un chiffre entre 1 et 16)\n";
        cin>>position;
        if(position<=0 || position>16 || std::isnan(position))
            cout<<"La position rentrée est invalide\n";
    } while (position<=0 || position>16 || std::isnan(position)); // faut regarder si il s'agit d'un nombre ou pas !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if(m_listePieceBoard[position-1] == Piece())

    {
        if(m_listePieceBoard[position-1] != Piece())
            cout<<"Case deja occupee !\n";
        int indicePieceJouable = 0;
        while(m_listePieceJouable[indicePieceJouable] != pieceJouee && indicePieceJouable<16)
        {
            cout<<"Indice piece : "<<indicePieceJouable<<"\n";
            indicePieceJouable++;
        }
        if(indicePieceJouable == 16)
        {
                cout<<"Piece deja jouee\n";
                board::deplacerPiece();
        }
        else
        {
            m_listePieceBoard[position-1] = pieceJouee;

            m_listePieceJouable.erase(m_listePieceJouable.begin()+indicePieceJouable);
        }

    }
    else // que ce passe t'il si c'est pas le cas ? On redemande une position, comment ? Appel recursif !
    {
        cout<<"Case deja occupee !\n";
        board::deplacerPiece();
    }
}

bool board::isQuartoCouleur()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+1].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+2].getCouleur()) && (m_listePieceBoard[i].getCouleur() == m_listePieceBoard[i+3].getCouleur()) && (m_listePieceBoard[i].getCouleur() != zeroC))
        {
            //std::cout<<"\nWouhou j'ai gagne ! A la ligne : "<<i/4+1;
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

bool board::isQuartoTaille()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+1].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+2].getTaille()) && (m_listePieceBoard[i].getTaille() == m_listePieceBoard[i+3].getTaille()) && (m_listePieceBoard[i].getTaille() != zeroT))
        {
            /*std::cout<<"\nWouhou j'ai gagne ! A la ligne : "<<i/4+1;
            std::cout<<"\n"<<m_listePieceBoard[i].getTaille();
            std::cout<<"\n"<<m_listePieceBoard[i+1].getTaille();
            std::cout<<"\n"<<m_listePieceBoard[i+2].getTaille();
            std::cout<<"\n"<<m_listePieceBoard[i+3].getTaille();*/
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

bool board::isQuartoForme()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getForme() == m_listePieceBoard[i+1].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+2].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+3].getForme()) && (m_listePieceBoard[i].getForme() != zeroF))
        {
            /*std::cout<<"\nWouhou j'ai gagne ! A la ligne : "<<i/4+1;
            std::cout<<"\n"<<m_listePieceBoard[i].getForme();
            std::cout<<"\n"<<m_listePieceBoard[i+1].getForme();
            std::cout<<"\n"<<m_listePieceBoard[i+2].getForme();
            std::cout<<"\n"<<m_listePieceBoard[i+3].getForme();*/
            return true;
        }
    }
    //On regarde colonne par colonne
    for(int i = 0; i < m_sizeBoard; i = i + 1)
    {
        if((m_listePieceBoard[i].getForme() == m_listePieceBoard[i+4].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+8].getForme()) && (m_listePieceBoard[i].getForme() == m_listePieceBoard[i+3].getForme()) && (m_listePieceBoard[i].getForme() != zeroF))
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

bool board::isQuartoProfondeur()
{
    //On regarde ligne par ligne
    for(int i = 0; i < m_sizeBoard; i = i + 4)
    {
        if((m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+1].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+2].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() == m_listePieceBoard[i+3].getProfondeur()) && (m_listePieceBoard[i].getProfondeur() != zeroP))
        {
            /*std::cout<<"\nWouhou j'ai gagne ! A la ligne : "<<i/4+1;
            std::cout<<"\n"<<m_listePieceBoard[i].getProfondeur();
            std::cout<<"\n"<<m_listePieceBoard[i+1].getProfondeur();
            std::cout<<"\n"<<m_listePieceBoard[i+2].getProfondeur();
            std::cout<<"\n"<<m_listePieceBoard[i+3].getProfondeur();*/
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

bool board::isQuarto()
{
    return isQuartoCouleur() || isQuartoForme() || isQuartoProfondeur() || isQuartoTaille();
}
