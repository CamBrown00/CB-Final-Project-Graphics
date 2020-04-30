#ifndef CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
#define CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H

#include "shape.h"
#include <vector>

struct imageFrame {
    std::vector<color> pixelColors;
    std::vector<std::vector<point2D>> pixelCoords;

    /* Constructors */
    imageFrame(std::vector<color> pixelColors, std::vector<std::vector<point2D>> pixelCoords);
    imageFrame(std::vector<color> pixelColors, std::vector<point2D> prc);

};

class GameObj{
private:
    std::vector<imageFrame> sprite;
    int imageFrameIndex = 0;
    int id;
    int scale;
    point2D center;

public:
    //Constructors
    GameObj();
    GameObj(int id, int x, int y, int scale);
    GameObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite);

    //Destructor
    virtual ~GameObj() = default;

    //Getters
    int getId() const;
    int getScale() const;
    int getImageFrameIndex() const;
    int getCenterX() const;
    int getCenterY() const;
    point2D getCenter() const;
    std::vector<imageFrame> getSprite() const;


    //Setters
    virtual void setCenter(point2D center);
    virtual void setCenter(int x, int y);
    virtual void setCenterX(int x);
    virtual void setCenterY(int y);
    virtual void setId(int id);
    virtual void setScale(int scale);
    virtual void setImageFrameIndex(int imageFrameIndex);
    virtual void setSprite(std::vector<imageFrame> sprite);

    //Non-Trivial Methods
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    void moveY(double deltaY);
    virtual void draw() const;

};

#endif //CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
