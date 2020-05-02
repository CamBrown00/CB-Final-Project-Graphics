#include "gameObj.h"
#include <filesystem>


/********************* Image Frame Struct ********************/

imageFrame :: imageFrame(std::vector<color> pixelColors, std::vector<std::vector<point2D>> pixelCoords) : pixelColors(pixelColors), pixelCoords(pixelCoords) {}
imageFrame :: imageFrame(std::vector<color> pixelColors, std::vector<point2D> prc) {
    this->pixelColors = pixelColors;
    for (int i = 0; i < prc.size(); ++i) {
        this->pixelCoords.push_back({point2D(prc[i].x, prc[i].y), point2D(prc[i].x, (prc[i].y)+1), point2D((prc[i].x)+1, (prc[i].y)+1), point2D((prc[i].x)+1, prc[i].y)});

    }
}

/********************* GameObj Class *********************/

//Constructors
GameObj :: GameObj() {}

GameObj :: GameObj(int id, int x, int y, int scale) {
    this->id = id;
    this->scale = scale;
    center = point2D(x, y);
}

GameObj :: GameObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite) {
    this->id = id;
    center = point2D(x, y);
    sprites.push_back(sprite);
    this->scale = scale;
}

GameObj :: GameObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites) {
    this->id = id;
    center = point2D(x, y);
    this->sprites = sprites;
    this->scale = scale;
}



//Getters
int GameObj :: getId() const {
    return id;
}

int GameObj :: getScale() const {
    return scale;
}

int GameObj :: getImageFrameIndex() const {
    return imageFrameIndex;
}

int GameObj :: getSpriteIndex() const {
    return spriteIndex;
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

std::vector<std::vector<imageFrame>> GameObj :: getSprites() const {
    return sprites;
}

//Setters
void  GameObj :: setId(int id) {
    this->id = id;
}

void  GameObj :: setScale(int scale) {
    this->scale = scale;
}

void  GameObj :: setImageFrameIndex(int imageFrameIndex) {
    this->imageFrameIndex = imageFrameIndex;
}

void  GameObj :: setSpriteIndex(int spriteIndex) {
    this->spriteIndex = spriteIndex;
}

void GameObj :: addSprite(std::vector<imageFrame> sprite) {
    sprites.push_back(sprite);
}

void GameObj :: setSprites(std::vector<std::vector<imageFrame>> sprites) {
    this->sprites = sprites;
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


//Non-Trivial Methods
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


void GameObj :: addSpriteFromFile(std::string directory) {
    for (const auto & entry : filesystem::directory_iterator(directory))
        std::cout << entry.path() << std::endl;
}

void GameObj :: draw() const {
    std::vector<color> colors = sprites[spriteIndex][imageFrameIndex].pixelColors;
    std::vector<std::vector<point2D>> coords = sprites[spriteIndex][imageFrameIndex].pixelCoords;
    if (coords.size() == colors.size()) {
        for (int i = 0; i < sprites[spriteIndex][imageFrameIndex].pixelCoords.size(); ++i) {
            glBegin(GL_QUADS);
            glColor4f(colors[i].red, colors[i].green, colors[i].blue, colors[i].alpha);
            glVertex2i((coords[i][0].x + center.x) * scale, (coords[i][0].y + center.y) * scale);
            glVertex2i((coords[i][1].x + center.x) * scale, (coords[i][1].y + center.y) * scale);
            glVertex2i((coords[i][2].x + center.x) * scale, (coords[i][2].y + center.y) * scale);
            glVertex2i((coords[i][3].x + center.x) * scale, (coords[i][3].y + center.y) * scale);
            glEnd();
        }
    }
}
