g++ main.cpp spaceship.cpp game.cpp laser.cpp -o spacewars -I/opt/homebrew/Cellar/raylib/5.0/include -L/opt/homebrew/Cellar/raylib/5.0/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11 -arch arm64