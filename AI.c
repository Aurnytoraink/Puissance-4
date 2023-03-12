#include "AI.h"

#include <stdlib.h>

int play_random()
{
    time_t t;
    srand((unsigned) time(&t)); // Initialisation du générateur
    return rand()%7;
}

int play_hard()
{
    //Utilisation de l'algorithme Minimax avec élagage alpha-beta
}

int play_move(int mode)
{
    switch (mode)
    {
    case 0:
    {
        return play_random();
    }
    break;

    case 1:
    {
        return play_hard();
    }
    break;
}