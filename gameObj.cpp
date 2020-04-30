#include "gameObj.h"
#include <iostream>
using namespace std;


/********************* Image Frame Struct ********************/

imageFrame::imageFrame(std::vector<color> pixelColors, std::vector<point2D> pixelCoords) : pixelColors(pixelColors), pixelCoords(pixelCoords) {}

/********************* GameObj Class *********************/

//Constructors
GameObj :: GameObj() {}
GameObj :: GameObj(int id, int x, int y, std::vector<imageFrame> sprite) {
    this->id = id;
    center = point2D(x, y);
    this->sprite = sprite;

}


//Getters
int GameObj :: getId() const {
    return id;
}

int GameObj :: getCenterX() const {
    return center.x;
}

int GameObj :: getCenterY() const {
    return center.y;
}

point2D GameObj :: getCenter() const {
    return center;
}

std::vector<imageFrame> GameObj :: getSprite() const {
    return sprite;
}

//Setters
void  GameObj ::setId(int id) {
    this->id = id;
}

void GameObj :: setSprite(std::vector<imageFrame> sprite) {
    this->sprite = sprite;
}

void GameObj :: setCenter(point2D center) {
    this->center = center;
}

void GameObj :: setCenter(int x, int y) {
    center = point2D(x, y);
}

void GameObj :: setCenterX(int x) {
    center.x = x;
}

void GameObj :: setCenterY(int y) {
    center.y = y;
}

void GameObj :: move(double deltaX, double deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void GameObj :: moveX(double deltaX) {
    center.x += deltaX;
}

void GameObj :: moveY(double deltaY) {
    center.y += deltaY;
}
