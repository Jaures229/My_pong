#include "../include/pong.hpp"
using namespace Pong;


int main()
{
    Game game;

    if (game.initialize()) {
        game.runLoop();
    }

    game.shutdown();
    return 0;
}
