g++ -fsanitize=address -g main.cpp Spaceship.cpp game.cpp laser.cpp block.cpp obstacle.cpp alien.cpp mysteryship.cpp -o spacewars -I/opt/homebrew/Cellar/raylib/5.0/include -L/opt/homebrew/Cellar/raylib/5.0/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11 -arch arm64
