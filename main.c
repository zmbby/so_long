#include "so_long.h"
#include "map/map.h"
#include "game/game.h"

int main(int ac, char **av)
{
    t_game  game;
    if (!start(&game, ac, av))
        return (0);
    return (0);
}