
#ifndef PADDLE_HPP_
    #define PADDLE_HPP_
    #include <iostream>
    #include <SDL2/SDL.h>
    class Paddle {
        private:
            float posX, posY;
            float speed;
            int width, height;
            int direction;
            SDL_Rect rect;

        public:
            Paddle(float x, float y);
            void setDirection(int dir) { direction = dir; }
            void update(float deltaTime);
            void render(SDL_Renderer* renderer);
            
            SDL_Rect getRect() const { return rect; }
    };
#endif /* !PADDLE_HPP_ */
