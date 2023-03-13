#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IHM.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void welcome_page()
{
    printf(RED "P" RESET);
    printf(YELLOW "U" RESET);
    printf(GREEN "I" RESET );
    printf(BLUE "S" RESET );
    printf(MAGENTA "S" RESET);
    printf(CYAN "A" RESET );
    printf(RED "N" RESET );
    printf(YELLOW "C" RESET );
    printf(GREEN "E" RESET );
    printf(" 4\n"); 
}

// tab est un tableau a deux dim
void display_grille(int tab[][6])
{
    printf("\n\n1 2 3 4 5 6 7\n");
    char line[13] = {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'};
    int x, y, i;
    for (y = 0; y < 6; y++)
    {
        for (x = 0, i = 0; x < 7, i < 13; x++, i = i + 2)
        {
            switch (tab[x][y])
            {
            case -1: // vide
            {
                line[i] = '#';
            }
            break;

            case 0: // Joueur 1
            {
                line[i] = 'X';
            }
            break;

            case 1: // Joueur 2
            {
                line[i] = 'O';
            }
            break;
            }
        }
        printf("%s\n", line);
    }
}

void display_grille_debug(int tab[][6])
{
    printf("\n\n0 1 2 3 4 5 6\n");
    char line[15] = {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '%'};
    int x, y, i;
    for (y = 0; y < 6; y++)
    {
        for (x = 0, i = 0; x < 7, i < 13; x++, i = i + 2)
        {
            switch (tab[x][y])
            {
            case -1: // vide
            {
                line[i] = '#';
            }
            break;

            case 0: // Joueur 1
            {
                line[i] = '0';
            }
            break;

            case 1: // Joueur 2
            {
                line[i] = '1';
            }
            break;
            }
        }
        line[15] = ("%s", 48 + y);
        printf("%s\n", line);
    }
}

int ask_user_column(int current_player)
{
    int selected_column = 0;
    printf("Joueur %d : a ton tour !\n", current_player + 1);
    do
    {
        printf("Choix de la colonne : ");
        scanf("%d", &selected_column);
    } while (selected_column < 1 || selected_column > 7);
    return selected_column - 1;
}

void column_out_of_range()
{
    printf("Veuillez choisir une colonne entre 1 et 7");
}

void no_more_space_avaible()
{
    printf("La colonne choisie est pleine!\nVeuillez en choisir une autre !");
}

void display_winner(int player)
{
    printf("\nBravo joueur %d !\nTu es vraiment intelligent.\nTiens, tu as gagne un cookie !\n\n", player + 1);
}

void display_full()
{
    printf("Plus de place !\nVous etes a egalite !\n\n");
}

int ask_two_players()
{
    int choice = -1;
    do
    {
        printf("Veux-tu jouer seul (choix 0) ou contre un adversaire (choix 1) ?\n");
        scanf("%d", &choice);
    } while (choice != 0 && choice != 1);
    return choice;
}

void AI_has_played(int column)
{
    printf("L'IA a joue la colonne %d", column);
}

int ask_play_again() {
    int choice = -1;
    do
    {
        printf("Souhaites-tu rejouer ?\n[0]Oui [1]Non\n");
        scanf("%d", &choice);
    } while (choice != 0 && choice != 1);
    return choice;
}

void thanks_message() {
    printf("\nNoooon, quel dommage !\nMerci d'avoir joue a\n");
    welcome_page();
}