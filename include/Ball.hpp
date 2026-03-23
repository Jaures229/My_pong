#ifndef BALL_HPP_
    #define BALL_HPP_
    #include <SDL2/SDL.h>
    #include <iostream>
    class Ball
    {
        private:
            float posX, posY;
            float velX, velY;
            int size;
            SDL_Rect rect;
        public:
            Ball(float x, float y);
            void update(float deltaTime);
            void render(SDL_Renderer* renderer);
            SDL_Rect getRect() const { return rect; }
            
            // Inverser la vitesse lors d'un rebond
            void bounceX() { velX *= -1; }
            void bounceY() { velY *= -1; }
            void reset(float x, float y);
    };
#endif /* !BALL_HPP_ */