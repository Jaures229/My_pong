#include "../include/Ball.hpp"

Ball::Ball(float x, float y) : posX(x), posY(y), size(15)
{
    velX = 200.0f;
    velY = 200.0f;
    
    rect.w = size;
    rect.h = size;
}

void Ball::update(float deltaTime)
{
    posX += velX * deltaTime;
    posY += velY * deltaTime;

    rect.x = static_cast<int>(posX);
    rect.y = static_cast<int>(posY);
}

void Ball::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}



void Ball::reset(float x, float y)
{
    posX = x;
    posY = y;

    // redigirer la balle vers le coté opposé
    velX *= -1;
}