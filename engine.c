#include "IHM.h"
#include "AI.h"

// Définition des constantes
#define ROWS 6
#define COLUMNS 7

#define EMPTY -1
#define J1 0
#define J2 1

// Var globale
int grille[COLUMNS][ROWS] = {0};
int current_player = J2;
int filled_case = 0;

// Réinitialise la grille
void reset_grille()
{
    int x, y;
    for (x = 0; x < COLUMNS; x++)
    {
        for (y = 0; y < ROWS; y++)
        {
            grille[x][y] = EMPTY;
        }
    }
}

// Renvoie la ligne à laquelle le pion peut tomber
// Renvoie -1 si la ligne est pleine
int last_pos_avaible(int colonne)
{
    int i = 0;
    if (grille[colonne][i] != EMPTY)
    {
        return -1;
    }
    for (i = 1; i < ROWS; i++)
    {
        if (grille[colonne][i] != EMPTY)
        {
            break;
        }
    }
    return i - 1;
}

int recherche_ord(int x, int y)
{
    int pieces = 0, i = 0;
    int y_min = (y - 3 < 0) ? 0 : y - 3;
    int y_max = (y + 3 > 5) ? 5 : y + 3;
    for (i = y_min; i < (y_max + 1); i++)
    {
        if (grille[x][i] == current_player)
        {
            pieces++;
        }
        else
        {
            pieces = 0;
        }

        if (pieces >= 4)
        {
            return 1;
        }
    }
    return 0;
}

int recherche_abs(int x, int y)
{
    int pieces = 0, i = 0;
    int x_min = (x - 3 < 0) ? 0 : x - 3;
    int x_max = (x + 3 > 6) ? 6 : x + 3;
    for (i = x_min; i < (x_max + 1); i++)
    {
        if (grille[i][y] == current_player)
        {
            pieces++;
        }
        else
        {
            pieces = 0;
        }

        if (pieces >= 4)
        {
            return 1;
        }
    }
    return 0;
}

int recherche_diag_inf(int x, int y)
{
    int pieces = 1, i = 1;

    while (grille[x - i][y - i] == current_player && x - i >= 0 && y - i >= 0)
    {
        pieces++;
        i++;
    }

    i = 1;

    while (grille[x + i][y + i] == current_player && x + i <= 7 && y + i <= 6)
    {
        pieces++;
        i++;
    }

    return pieces >= 4;
}

int recherche_diag_sup(int x, int y)
{
    int pieces = 1, i = 1;

    while (grille[x + i][y - i] == current_player && x + i >= 0 && x + i <= 7 && y - i >= 0 && y - i <= 6)
    {
        pieces++;
        i++;
    }

    i = 1;

    while (grille[x - i][y + i] == current_player && x - i >= 0 && x - i <= 7 && y + i >= 0 && y + i <= 6)
    {
        pieces++;
        i++;
    }

    return pieces >= 4;
}

// Renvoie 1 (vrai) si une ligne de 4 pions est détectée
int is_winning_line(int x, int y)
{
    return (recherche_ord(x, y) || recherche_abs(x, y) || recherche_diag_inf(x, y) || recherche_diag_sup(x, y));
}

void Demarre_puissance4()
{
    // Affiche la phrase d'accueil
    welcome_page();

    // Vide la grille et initialise des variables
    reset_grille();
    int selected_column = 0, last_row = 0;
    int exit = 0;
    int winner = -1;

    // Choix du mode (2 joueurs ou IA)
    int two_player = ask_two_players();

    while (exit == 0)
    {
        while (is_winning_line(selected_column, last_row) == 0 && filled_case != 42)
        {
            //Cette variable est utilisé dans la boucle suivante afin de savoir d'afficher le message d'information lorsque le joueur a saisi une colonne déjà pleine
            int state = 0;
            current_player = !current_player; // alternance entre le J1 et J2

            do
            {   

                if (two_player == 0 && current_player == 1)
                {
                    selected_column = play_move(0);
                }
                else
                {
                    display_grille(grille); // On affiche la grille seulement lorsque c'est un joueur et non l'IA
                    selected_column = ask_user_column(current_player);
                    state == 0 ? : no_more_space_avaible();
                }

                last_row = last_pos_avaible(selected_column);
                state = 1;
            } while (last_row == EMPTY);

            
            grille[selected_column][last_row] = current_player;
            filled_case++;
        }

        //Teste si la partie s'est terminée car il y a un vainqueur ou si la grille est pleine 
        filled_case == 42 ? display_full() : display_winner(current_player);

        //Demande si le joueur veut rejouer
        if (ask_play_again() == 0) {
            exit = 0;
            reset_grille();
            current_player = J2;
        }
        else
        {
            exit = 1;
            thanks_message();
        }
        
    }
}

/*
// Partie de teste
//les print ne sont pas inclus

// grille de test
int grille[COLUMNS][ROWS] = {-1, -1, 0, 0, 0, 0,
                             -1, -1, -1, 0, -1, -1,
                             -1, -1, 0, 0, -1, 1,
                             -1, -1, -1, 0, 1, -1,
                             -1, -1, -1, 1, 0, -1,
                             -1, -1, 1, -1, -1, 0,
                             -1, -1, -1, -1, -1, -1};

void test_grille()
{
    display_grille_debug(grille);
    is_winning_line(0, 2); //victoire verticale
    is_winning_line(1, 3); //victoire horizontale
    current_player = 1;
    is_winning_line(5, 2); //victoire diag sup
}
*/