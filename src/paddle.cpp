#include "../include/Paddle.hpp"


Paddle::Paddle(float x, float y) : posX(x), posY(y), speed(450.0f), width(15), height(100), direction(0)
{
    rect = { (int)posX, (int)posY, width, height };
}

void Paddle::update(float deltaTime)
{
    posY += direction * speed * deltaTime;

    // Empêcher la raquette de sortir de l'écran (0 à 600)
    if (posY < 0) posY = 0;
    if (posY > 600 - height)
        posY = 600 - height;

    rect.y = static_cast<int>(posY);
}

void Paddle::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}
