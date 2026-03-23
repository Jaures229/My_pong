#ifndef PONG_HPP_
    #define PONG_HPP_
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
    #include "Ball.hpp"
    #include <iostream>
    #include "Paddle.hpp"
    namespace Pong
    {
        class Game {
            private:
                SDL_Window* window;
                SDL_Renderer* renderer;
                bool isRunning;
                float deltaTime;
                Uint32 lastFrameTime;

                Paddle leftPaddle, rightPaddle;
                Ball ball;

                int leftScore = 0;
                int rightScore = 0;
                TTF_Font* font;
                SDL_Texture* scoreTexture;
                SDL_Rect scoreRect;
            public:
                Game();
                ~Game();
                
                bool initialize();
                void runLoop();
                void processInput();
                void update();
                void render();
                void shutdown();
                void calculateDelatime();
                void updateScore();
            };
    };
#endif /* !PONG_HPP_ */
