#include "IHM.h"
#include <stdio.h>

// Var globale
int grille[7][6];
int winner = -1;
int current_player = 0;
int filled_case = 0;

// Réinitialise la grille
void reset_grille()
{
    int x, y;
    for (x = 0; x < 7; x++)
    {
        for (y = 0; y < 6; y++)
        {
            grille[x][y] = -1;
        }
    }
}

// Renvoie la ligne à laquelle le pion peut tomber
// Renvoie -1 si la ligne est pleine
int last_pos_avaible(int colonne)
{
    int i = 0;
    if (grille[colonne][i] != -1)
    {
        return -1;
    }
    for (i = 1; i < 6; i++)
    {
        if (grille[colonne][i] != -1)
        {
            break;
        }
    }
    return i - 1;
}

int search_pieces_in_line(int x_min, int x_max, int y_min, int y_max, int inverse)
{
    /*
    Une boucle for à deux variables qui parcours tous les éléments
    Il faut que le code return vrai dès que 4 pieces sont détectés
    */
    int x, y;
    int pieces = 0;
    if (inverse == 0)
    {
        for (x = x_min, y = y_min; x < x_max && y < y_max; x++, y++)
        {
            if (grille[x][y] == current_player)
            {
                pieces++;
            }
            else
            {
                pieces = 0;
            }

            if (pieces == 4)
            {
                return 1;
            }
        }
    }
    else
    {
        for (x = x_min, y = y_min; x < x_max && y < y_max; x++, y--)
        {
            if (grille[x][y] == current_player)
            {
                pieces++;
            }
            else
            {
                pieces = 0;
            }

            if (pieces == 4)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Renvoie 1 (vrai) si une ligne de 4 pions est détectée
int is_winning_line(int x, int y)
{
    int x_min, x_max, y_min, y_max;
    int inverse = 0;
    // VEC1 [1,1] diag sup
    x_min = (x - 3 < 0) ? 0 : x - 3;
    x_min = (x + 3 > 6) ? 6 : x + 3;
    y_min = (y - 3 < 0) ? 0 : y - 3;
    y_max = (y + 3 > 5) ? 5 : y + 3;

    if (search_pieces_in_line(x_min, x_max, y_min, y_max, inverse) == 1)
    {
        return 1;
    }

    // VEC2 [0,1] ord
    x_min = x;
    x_max = x;
    y_min = (y - 3 < 0) ? 0 : y - 3;
    y_max = (y + 3 > 5) ? 5 : y + 3;

    if (search_pieces_in_line(x_min, x_max, y_min, y_max, inverse) == 1)
    {
        return 1;
    }

    // VEC3 [1,0] abs
    x_min = (x - 3 < 0) ? 0 : x - 3;
    x_min = (x + 3 > 6) ? 6 : x + 3;
    y_min = y;
    y_max = y;

    if (search_pieces_in_line(x_min, x_max, y_min, y_max, inverse) == 1)
    {
        return 1;
    }

    // VEC4 [1,-1] diag inf
    inverse = 1;
    x_min = (x - 3 < 0) ? 0 : x - 3;
    x_min = (x + 3 > 6) ? 6 : x + 3;
    y_min = (y + 3 > 5) ? 5 : y + 3;
    y_max = (y - 3 < 0) ? 0 : y - 3;

    if (search_pieces_in_line(x_min, x_max, y_min, y_max, inverse) == 1)
    {
        return 1;
    }

    return 0;
}

void Demarre_puissance4()
{
    reset_grille();
    int selected_column;
    int last_ligne;

    while (winner == -1 && filled_case != 42)
    {   
        printf("%d",filled_case);
        display_grille(grille);
        selected_column = ask_user_column(current_player);
        last_ligne = last_pos_avaible(selected_column);
        if (last_ligne != -1)
        {
            grille[selected_column][last_ligne] = current_player;
            filled_case++;
            if (is_winning_line(selected_column, last_ligne) == 1)
            {
                winner = current_player;
            }
            else
            {
                current_player = !current_player; // alternance entre le J1 et J2
            }
        }

        else
        {
            no_more_space_avaible();
        }
    }

    display_grille(grille);

    if (filled_case == 42)
    {
        printf("Plus de place !\nVous êtes à égalité !");
    }
    else
    {
        display_winner(current_player);
    }
}