#include "gameObj.h"
#include "graphics.h"
#include <iostream>
#include <fstream>
#include <string>


/********************* Color Struct ********************/

color::color() : red(0.0), green(0.0), blue(0.0), alpha(1.0) {
}

color::color(double r, double g, double b, double a) : red(r), green(g), blue(b), alpha(a) {
}

color::color(double r, double g, double b) : red(r), green(g), blue(b), alpha(1.0) {
}

std::ostream& operator << (std::ostream& outs, const color &c) {
    outs << "(" << c.red << ", " << c.green << ", " << c.blue << ")";
    return outs;
}

/********************* Point Struct ********************/

point2D::point2D() : x(0), y(0) {}

point2D::point2D(double x, double y) : x(x), y(y) {}

std::ostream& operator << (std::ostream& outs, const point2D &p) {
    outs << "(" << p.x << ", " << p.y << ")";
    return outs;
}

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

bool GameObj :: getMirrorX() const {
    return mirrorX;
}

bool GameObj :: getMirrorY() const {
    return mirrorY;
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

int GameObj :: getHSpd() const {
    return hSpd;
}

int GameObj :: getVSpd() const {
    return vSpd;
}

std::vector<std::vector<imageFrame>> GameObj :: getSprites() const {
    return sprites;
}

std::vector<int> GameObj :: getSpriteWidths() const {
    return spriteWidths;
}

std::vector<int> GameObj :: getSpriteHeights() const {
    return spriteHeights;
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

void GameObj :: addSprite(std::vector<imageFrame> sprite, int width, int height) {
    sprites.push_back(sprite);
    spriteWidths.push_back(width);
    spriteHeights.push_back(height);
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

void GameObj :: setVSpd(int vSpd) {
    this->vSpd = vSpd;
}

void GameObj :: setHSpd(int hSpd) {
    this->hSpd = hSpd;
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

// Mirrors sprite at current sprite index by swapping the pixels in each row of the sprite
void GameObj :: mirrorSpritesX() {
    if (sprites.size() > 0) {
        int width = spriteWidths[spriteIndex];
        int height = spriteHeights[spriteIndex];
        mirrorX = !mirrorX;
        std::vector<std::vector<point2D>> tempCoords = sprites[spriteIndex][imageFrameIndex].pixelCoords;
        std::vector<point2D> tempPixelBeginCoord;
        std::vector<point2D> tempPixelEndCoord;
        int count = 0;
        for (int i = 0; i < height; ++i) {
            ++count;
            for (int j = 0; j < width; j++) {
                if (j < width/2) {
                    if (width * count != (width * height)) {
                        tempPixelBeginCoord = tempCoords[(width * i) + j];
                        tempPixelEndCoord = tempCoords[(width * count) - j];
                        tempCoords[(width * count) - j] = tempPixelBeginCoord;
                        tempCoords[(width * i) + j] = tempPixelEndCoord;
                    }
                    else {
                        tempPixelBeginCoord = tempCoords[(width * i) + j];
                        tempPixelEndCoord = tempCoords[(width * height) - j - 1];
                        tempCoords[(width * height) - j - 1] = tempPixelBeginCoord;
                        tempCoords[(width * i) + j] = tempPixelEndCoord;
                    }
                }
            }
        }
        sprites[spriteIndex][imageFrameIndex].pixelCoords = tempCoords;
    }
}

void GameObj :: mirrorSpritesY() {
    mirrorY = !mirrorY;

}


void GameObj :: addSpriteFromFile(std::string directory, int frameCount) {
    std::vector<imageFrame> imageFrames;
    for (int i = 1; i <= frameCount; ++i) {
        std::ifstream inFile;
        inFile.open(directory + std::to_string(i) + ".csv");

        int width = 0, height = 0;
        int r, g, b, a, sum;
        char comma = ',';

        if (inFile){
            inFile >> width;
            inFile >> comma;
            inFile >> height;
        }

        //Update width and height
        spriteWidths.push_back(width);
        spriteHeights.push_back(height);

        //Read in the rbga values, construct coords and colors from them for an imageFrame
        std::vector<color> pixelColors;
        std::vector<point2D> coordinates;
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < width; ++k) {
                inFile >> r;
                inFile >> comma;
                inFile >> g;
                inFile >> comma;
                inFile >> b;
                inFile >> comma;
                inFile >> a;
                sum = r + g + b;
                if (sum == 0){
                    pixelColors.push_back(color(0.0, 0.0, 0.0, a/255));
                } else {
                    pixelColors.push_back(color(double(r)/255, double(g)/255, double(b)/255, double(a)/255));
                }
                coordinates.push_back(point2D(k, j));
            }
        }
        imageFrame tempFrame = imageFrame(pixelColors, coordinates);
        imageFrames.push_back(tempFrame);
    }
    sprites.push_back(imageFrames);
}

void GameObj :: draw() const {
    if (sprites.size() > 0) {
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
}
