#include "../include/pong.hpp"

using namespace Pong;

Game::Game() : window(nullptr), 
renderer(nullptr),
isRunning(false),
ball(250.0f, 250.0f),
leftPaddle(20.0f, 250.0f),
rightPaddle(765.0f, 250.0f),
leftScore(0),
rightScore(0),
scoreTexture(nullptr)
{

}

bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Error SDL_Init : %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1) {
        SDL_Log("Error initializing SDL_ttf: %s", TTF_GetError());
        return false;
    }

    font = TTF_OpenFont("../assets/font.TTF", 24);

    if (!font) {
        std::cout << "Failed to render text: " <<  TTF_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow(
        "Pong - GTECH2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 
        800,
        600, 
        0 
    );

    if (!window)
    {
        SDL_Log("Erreur Création Fenêtre : %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer) {
        SDL_Log("Erreur Création Renderer : %s", SDL_GetError());
        return false;
    }

    isRunning = true;
    updateScore();
    return true;
}


void Game::runLoop()
{
    lastFrameTime = SDL_GetTicks();
    while (isRunning) {
        calculateDelatime();
        processInput();
        update();
        render();
    }
}

void Game::processInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);


    // Joueur 1 (Gauche) : Touches W et S
    int leftDir = 0;
    if (state[SDL_SCANCODE_W]) leftDir -= 1;
    if (state[SDL_SCANCODE_S]) leftDir += 1;
    leftPaddle.setDirection(leftDir);

    // Joueur 2 (Droite) : Flèches Haut et Bas
    int rightDir = 0;
    if (state[SDL_SCANCODE_UP]) rightDir -= 1;
    if (state[SDL_SCANCODE_DOWN]) rightDir += 1;
    rightPaddle.setDirection(rightDir);
}

void Game::update()
{
    ball.update(deltaTime);
    leftPaddle.update(deltaTime);
    rightPaddle.update(deltaTime);
    // Collision simple avec les murs du haut et du bas pour test

    SDL_Rect lRect = leftPaddle.getRect();
    SDL_Rect bRect = ball.getRect();
    SDL_Rect rRect = rightPaddle.getRect();

    // Collision avec la raquette GAUCHE
    if (SDL_HasIntersection(&bRect, &lRect)) {
        ball.bounceX();
    } 

    // Collision avec la raquette DROITE
    if (SDL_HasIntersection(&bRect, &rRect)) {
        ball.bounceX();
    }

    // Rebond Haut/Bas
    if (bRect.y <= 0 || bRect.y >= 600 - bRect.h) {
        ball.bounceY();
    }

    // wGestion du Score
    if (bRect.x < 0) {
        rightScore++;
        updateScore();
        ball.reset(400.0f, 300.0f);
    }
    if (bRect.x > 800) {
        leftScore++;
        updateScore();
        ball.reset(400.0f, 300.0f);
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    ball.render(renderer);
    leftPaddle.render(renderer);
    rightPaddle.render(renderer);

    if (scoreTexture) {
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    }

    SDL_RenderPresent(renderer);
}


void Game::shutdown()
{
    if (scoreTexture) SDL_DestroyTexture(scoreTexture);
    if (font) TTF_CloseFont(font);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Game::calculateDelatime()
{
    // temps en millisecondes depuis le lancement
    Uint32 currentFrameTime = SDL_GetTicks();
    
    // Calcul du Delta Timen en secondes
    deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;


    lastFrameTime = currentFrameTime;
}

void Game::updateScore()
{
    std::string scoreStr = std::to_string(leftScore) + " - " + std::to_string(rightScore);

    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreStr.c_str(), white);
    
    if (scoreTexture) SDL_DestroyTexture(scoreTexture);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, surface);
    
    scoreRect.w = surface->w;
    scoreRect.h = surface->h;
    scoreRect.x = (800 - scoreRect.w) / 2;
    scoreRect.y = 20;

    SDL_FreeSurface(surface);
}

Game::~Game()
{

}
