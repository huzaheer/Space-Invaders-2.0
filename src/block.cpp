#include "block.hpp"
#include <raylib.h>

Block::Block(Vector2 position){
    this -> position = position;
}

Block::~Block(){

}

void Block::Draw(){
    DrawRectangle(position.x, position.y, 3, 3, {255, 248, 142, 255});
}

