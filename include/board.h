#ifndef BOARD_H
#define BOARD_H

#include "general.h"
#include "Piece.h"

enum typeUtils {Console=1, SFML}; // differentes versions du jeu
enum joueur{humain =1, facile, moyen, difficile}; // differentes options pour le joueur

class board
{
    public:
        board();
        virtual ~board();

        typeUtils getType();
        void setType(typeUtils);

        int getSizeBoard();

        void setListeJoueur(std::vector<joueur>);
        void ajouterListeJoueur(joueur, int); // ajoute un joueur � la liste de joueur du plateau
        std::vector<joueur> getListeJoueur();
        void changementJoueur(); // fonction de changement de joueur

        void setJoueurActuel(int);
        int getJoueurActuel();

        void setJoueur(joueur);
        joueur getJoueur();

        void setPieceSelectionnee(Piece);
        Piece getPieceSelectionnee();

        std::vector<Piece> getListePieceBoard();
        void setListePieceBoard(Piece, int);

        std::list<int> genererNextCoup(); // fonction pour obtenir les coups possibles � partir de l'�tat actuel

        int getConnexiteCouleur(int pos); // renvoie la connexite pour les couleurs, utilis� pour le MiniMax
        int getConnexite(int pos); // renvoie la connexite totale pour le MiniMax

        std::vector<Piece> getListePieceJouable();
        void eraseFromJouable(int); // enleve une piece du vecteur de pieces jouables
        bool isQuartoCouleur(); // renvoie s'il y a eu un quarto couleur
        bool isQuartoTaille(); // renvoie s'il y a eu un quarto taille
        bool isQuartoForme(); // renvoie s'il y a eu un quarto forme
        bool isQuartoProfondeur(); // renvoie s'il y a eu un quarto profondeur
        bool isQuarto(); // renvoie s'il y a eu un quarto
        bool isDraw(); // renvoie s'il y a eu match nul

    protected:
        typeUtils m_type; // version du jeu utilis�
        int m_sizeBoard; // taille du plateau
        std::vector<joueur> m_listeJoueur; //liste des joueurs du plateau
        joueur m_joueur; // categorie du joueur actuel
        int m_joueurActuel; // numero du joueur actuel
        Piece m_pieceSelectiionnee; // piece selectionnee
        std::vector<Piece> m_listePieceBoard; // liste des pieces jou�es
        std::vector<Piece> m_listePieceJouable; // liste des piece jouables
    private:
};

void initType(board& myBoard); // initialise la version du jeu utilis�e
void initJoueur(board& myBoard); // initialise les joueurs participant au jeu
void init(board&); // Sert � initialiser le jeu

#endif // BOARD_H
