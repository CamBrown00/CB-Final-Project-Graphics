#ifndef CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
#define CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H

#include "shape.h"
#include <vector>
#include <iostream>

struct imageFrame {
    std::vector<color> pixelColors;
    std::vector<std::vector<point2D>> pixelCoords;

    /* Constructors */
    imageFrame(std::vector<color> pixelColors, std::vector<std::vector<point2D>> pixelCoords);
    imageFrame(std::vector<color> pixelColors, std::vector<point2D> prc);

};

class GameObj{
private:
    std::vector<std::vector<imageFrame>> sprites;
    std::vector<int> spriteWidths;
    std::vector<int> spriteHeights;
    int imageFrameIndex = 0;
    int id;
    int scale;
    bool mirrorX = false;
    bool mirrorY = false;
    int spriteIndex = 0;
    point2D center;
    int hSpd = 0;
    int vSpd = 0;

public:
    //Constructors
    GameObj();
    GameObj(int id, int x, int y, int scale);
    GameObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite);
    GameObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites);

    //Destructor
    virtual ~GameObj() = default;

    //Getters
    int getId() const;
    int getScale() const;
    int getImageFrameIndex() const;
    int getCenterX() const;
    int getCenterY() const;
    int getSpriteIndex() const;
    bool getMirrorX() const;
    bool getMirrorY() const;
    int getHSpd() const;
    int getVSpd() const;
    point2D getCenter() const;
    std::vector<std::vector<imageFrame>> getSprites() const;
    std::vector<int> getSpriteWidths() const;
    std::vector<int> getSpriteHeights() const;


    //Setters
    virtual void setCenter(point2D center);
    virtual void setCenter(int x, int y);
    virtual void setCenterX(int x);
    virtual void setCenterY(int y);
    virtual void setHSpd(int hSpd);
    virtual void setVSpd(int vSpd);
    virtual void setId(int id);
    virtual void setScale(int scale);
    virtual void setImageFrameIndex(int imageFrameIndex);
    virtual void setSpriteIndex(int spriteIndex);
    virtual void addSprite(std::vector<imageFrame> sprite, int width, int height);
    virtual void setSprites(std::vector<std::vector<imageFrame>> sprites);

    //Non-Trivial Methods
    virtual void kbd(unsigned char key, int x, int y) = 0;
    virtual void kbdUp(unsigned char key, int x, int y) = 0;
    virtual void mirrorSpritesX();
    virtual void mirrorSpritesY();
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    void moveY(double deltaY);
    virtual void addSpriteFromFile(std::string directory, int frameCount);
    virtual void draw() const;

};

#endif //CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
