rm *.o
g++ -o spacewars src/main.cpp src/spaceship.cpp -I/opt/homebrew/Cellar/raylib/5.0/include -L/opt/homebrew/Cellar/raylib/5.0/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11 -arch arm64
