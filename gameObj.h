#ifndef CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
#define CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H

#include "shape.h"
#include <vector>
#include <iostream>
#include <filesystem>

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
    int imageFrameIndex = 0;
    int id;
    int scale;
    int spriteIndex = 0;
    point2D center;

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
    point2D getCenter() const;
    std::vector<std::vector<imageFrame>> getSprites() const;


    //Setters
    virtual void setCenter(point2D center);
    virtual void setCenter(int x, int y);
    virtual void setCenterX(int x);
    virtual void setCenterY(int y);
    virtual void setId(int id);
    virtual void setScale(int scale);
    virtual void setImageFrameIndex(int imageFrameIndex);
    virtual void setSpriteIndex(int spriteIndex);
    virtual void addSprite(std::vector<imageFrame> sprite);
    virtual void setSprites(std::vector<std::vector<imageFrame>> sprites);

    //Non-Trivial Methods
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    void moveY(double deltaY);
    virtual void addSpriteFromFile(std::string directory);
    virtual void draw() const;

};

#endif //CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
