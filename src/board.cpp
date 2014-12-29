#include "general.h"
#include "Piece.h"
#include <cmath>

using namespace std;

board::board() : m_sizeBoard(4), m_listeJoueur(), m_joueur(humain), m_joueurActuel(0), m_pieceSelectiionnee(Piece()), m_listePieceJouable(creerToutePiece())
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

typeUtils board::getType()
{
    return m_type;
}

void board::setType(typeUtils myType)
{
    m_type = myType;
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
    m_joueur = m_listeJoueur[m_joueurActuel-1];
}

void board::setJoueurActuel(int numero)
{
    m_joueurActuel = numero;
}

int board::getJoueurActuel()
{
    return m_joueurActuel;
}

void board::setJoueur(joueur monJoueur)
{
    m_joueur = monJoueur;
}

joueur board::getJoueur()
{
    return m_joueur;
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

std::list<int> board::genererNextCoup()
{
    std::list<int> positionPossible;
    for(size_t i = 0; i < m_listePieceBoard.size(); i++)
    {
        if(m_listePieceBoard[i] == Piece()) positionPossible.push_back(i);
    }
    return positionPossible;
}
int board::getConnexiteCouleur(int pos)
{
    int connexite = 0;
    //On regarde la ligne
    int posH = pos%4;
    if( (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) ||
        (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) ||
        (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+3].getCouleur()) ||
        (m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) ||
        (m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+3].getCouleur()) ||
        (m_listePieceBoard[posH+2].getCouleur() == m_listePieceBoard[posH+3].getCouleur()))
            connexite += 1;

    if( ((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) && (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+2].getCouleur())) ||
        ((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) && (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+3].getCouleur())) ||
        ((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) && (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+3].getCouleur())) ||
        ((m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) && (m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+3].getCouleur())))
                connexite += 2;

    //On regarde la colonne
    int posV = pos/4;
    if( (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+4].getCouleur()) ||
        (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) ||
        (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+12].getCouleur()) ||
        (m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) ||
        (m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+12].getCouleur()) ||
        (m_listePieceBoard[posV+8].getCouleur() == m_listePieceBoard[posV+12].getCouleur()))
            connexite += 1;

    if( ((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+4].getCouleur()) && (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+8].getCouleur())) ||
        ((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+4].getCouleur()) && (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+12].getCouleur())) ||
        ((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) && (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+12].getCouleur())) ||
        ((m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) && (m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+12].getCouleur())))
                connexite += 2;

    return connexite;

}
int board::getConnexite(int pos)
{
    int connexite = 0;
    //Horizontal
    int posH = pos%4;
        //Couleur
        if((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) ||
           (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) ||
           (m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+3].getCouleur()))
                connexite += 1;
        if(((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) && (m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+2].getCouleur())) ||
           ((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+1].getCouleur()) && (m_listePieceBoard[posH+1].getCouleur() == m_listePieceBoard[posH+3].getCouleur())) ||
           ((m_listePieceBoard[posH].getCouleur() == m_listePieceBoard[posH+2].getCouleur()) && (m_listePieceBoard[posH+2].getCouleur() == m_listePieceBoard[posH+3].getCouleur())))
                connexite += 2;
        //Forme
        if((m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+1].getForme()) ||
           (m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+2].getForme()) ||
           (m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+3].getForme()))
                connexite += 1;
        if(((m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+1].getForme()) && (m_listePieceBoard[posH+1].getForme() == m_listePieceBoard[posH+2].getForme())) ||
           ((m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+1].getForme()) && (m_listePieceBoard[posH+1].getForme() == m_listePieceBoard[posH+3].getForme())) ||
           ((m_listePieceBoard[posH].getForme() == m_listePieceBoard[posH+2].getForme()) && (m_listePieceBoard[posH+2].getForme() == m_listePieceBoard[posH+3].getForme())))
                connexite += 2;
        //Taille
        if((m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+1].getTaille()) ||
           (m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+2].getTaille()) ||
           (m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+3].getTaille()))
                connexite += 1;
        if(((m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+1].getTaille()) && (m_listePieceBoard[posH+1].getTaille() == m_listePieceBoard[posH+2].getTaille())) ||
           ((m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+1].getTaille()) && (m_listePieceBoard[posH+1].getTaille() == m_listePieceBoard[posH+3].getTaille())) ||
           ((m_listePieceBoard[posH].getTaille() == m_listePieceBoard[posH+2].getTaille()) && (m_listePieceBoard[posH+2].getTaille() == m_listePieceBoard[posH+3].getTaille())))
                connexite += 2;
        //Profondeur
        if((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+1].getProfondeur()) ||
           (m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+2].getProfondeur()) ||
           (m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+3].getProfondeur()))
                connexite += 1;
        if(((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+1].getProfondeur()) && (m_listePieceBoard[posH+1].getProfondeur() == m_listePieceBoard[posH+2].getProfondeur())) ||
           ((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+1].getProfondeur()) && (m_listePieceBoard[posH+1].getProfondeur() == m_listePieceBoard[posH+3].getProfondeur())) ||
           ((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+2].getProfondeur()) && (m_listePieceBoard[posH+2].getProfondeur() == m_listePieceBoard[posH+3].getProfondeur())))
                connexite += 2;

    //Vertical
    int posV = pos/4;
        //Couleur
        if((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+4].getCouleur()) ||
           (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) ||
           (m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+12].getCouleur()))
                connexite += 1;
        if(((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+4].getCouleur()) && (m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+8].getCouleur())) ||
           ((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+8].getCouleur()) && (m_listePieceBoard[posV+4].getCouleur() == m_listePieceBoard[posV+12].getCouleur())) ||
           ((m_listePieceBoard[posV].getCouleur() == m_listePieceBoard[posV+12].getCouleur()) && (m_listePieceBoard[posV+8].getCouleur() == m_listePieceBoard[posV+12].getCouleur())))
                connexite += 2;
        //Forme
        if((m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+1].getForme()) ||
           (m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+2].getForme()) ||
           (m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+3].getForme()))
                connexite += 1;
        if(((m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+4].getForme()) && (m_listePieceBoard[posV+4].getForme() == m_listePieceBoard[posV+8].getForme())) ||
           ((m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+4].getForme()) && (m_listePieceBoard[posV+4].getForme() == m_listePieceBoard[posV+12].getForme())) ||
           ((m_listePieceBoard[posV].getForme() == m_listePieceBoard[posV+8].getForme()) && (m_listePieceBoard[posV+8].getForme() == m_listePieceBoard[posV+12].getForme())))
                connexite += 2;
        //Taille
        if((m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+4].getTaille()) ||
           (m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+8].getTaille()) ||
           (m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+12].getTaille()))
                connexite += 1;
        if(((m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+4].getTaille()) && (m_listePieceBoard[posV+4].getTaille() == m_listePieceBoard[posH+8].getTaille())) ||
           ((m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+4].getTaille()) && (m_listePieceBoard[posV+4].getTaille() == m_listePieceBoard[posH+12].getTaille())) ||
           ((m_listePieceBoard[posV].getTaille() == m_listePieceBoard[posV+8].getTaille()) && (m_listePieceBoard[posV+8].getTaille() == m_listePieceBoard[posH+12].getTaille())))
                connexite += 2;
        //Profondeur
        if((m_listePieceBoard[posV].getProfondeur() == m_listePieceBoard[posV+4].getProfondeur()) ||
           (m_listePieceBoard[posV].getProfondeur() == m_listePieceBoard[posV+8].getProfondeur()) ||
           (m_listePieceBoard[posV].getProfondeur() == m_listePieceBoard[posV+12].getProfondeur()))
                connexite += 1;
        if(((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+1].getProfondeur()) && (m_listePieceBoard[posH+1].getProfondeur() == m_listePieceBoard[posH+2].getProfondeur())) ||
           ((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+1].getProfondeur()) && (m_listePieceBoard[posH+1].getProfondeur() == m_listePieceBoard[posH+3].getProfondeur())) ||
           ((m_listePieceBoard[posH].getProfondeur() == m_listePieceBoard[posH+2].getProfondeur()) && (m_listePieceBoard[posH+2].getProfondeur() == m_listePieceBoard[posH+3].getProfondeur())))
                connexite += 2;

    return connexite;
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
    if(m_listePieceJouable.size()==0 && isQuarto() == false) return true;
    else return false;
}

void initType(board& myBoard)
{
    int config = 0;
    do
    {
        std::cout<<"Voulez-vous utiliser la version console (1) ou SFML(2) ?"<<std::endl;
        std::cin>>config;
        if((config != 1 && config != 2) || std::cin.fail())
        {
            std::cout<<"Veuillez rentrer le numero lie a la configuration voulue :"<<std::endl<<"1) Console"<<std::endl<<"2) SFML"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while((config != 1 && config != 2) || std::cin.fail());
    typeUtils type = (typeUtils) config;
    myBoard.setType(type);
    system("cls");
}

void initJoueur(board& myBoard)
{
    joueur j1, j2;
    int indJ;
    do
    {
        std::cout<<"Joueur 1 :"<<std::endl<<"1) Humain"<<std::endl<<"2) IA Facile"<<std::endl;
        std::cin>>indJ;
        if((indJ != 1 && indJ != 2) || std::cin.fail())
        {
            std::cout<<"Veuillez rentrer le numero lie a la configuration voulue :"<<std::endl<<"1) Humain"<<std::endl<<"2) IA Facile"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while((indJ != 1 && indJ != 2) || std::cin.fail());
    j1 = (joueur) indJ;
    do
    {
        std::cout<<"Joueur 2 :"<<std::endl<<"1) Humain"<<std::endl<<"2) IA Facile"<<std::endl;
        std::cin>>indJ;
        if((indJ != 1 && indJ != 2) || std::cin.fail())
        {
            std::cout<<"Veuillez rentrer le numero lie a la configuration voulue :"<<std::endl<<"1) Humain"<<std::endl<<"2) IA Facile"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while((indJ != 1 && indJ != 2) || std::cin.fail());
    j2 = (joueur) indJ;
    myBoard.ajouterListeJoueur(j1,0);
    myBoard.ajouterListeJoueur(j2,1);
    myBoard.setJoueurActuel(1);
    myBoard.setJoueur(j1);
    system("cls");
    if(j1 != humain && j2 != humain) std::cout<<"Faites bouger votre souris pour faire jouer l'ordinateur"<<std::endl;
}

void init(board& myBoard)
{
    initType(myBoard);
    initJoueur(myBoard);
}
