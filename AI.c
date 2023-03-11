#include "AI.h"

#include <stdlib.h>

int play_random()
{
    return rand()%7;
}

int play_attaque()
{
}

int play_defense()
{
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
        return play_attaque();
    }
    break;

    case 2:
    {
        return play_defense();
    }
    break;
    }
}