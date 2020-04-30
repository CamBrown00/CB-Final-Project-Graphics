#ifndef CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
#define CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H

#include "shape.h"
#include <vector>

struct imageFrame {
    std::vector<color> pixelColors;
    std::vector<point2D> pixelCoords;

    /* Constructors */
    imageFrame(std::vector<color> pixelColors, std::vector<point2D> pixelCoords);

};

class GameObj{
private:
    std::vector<imageFrame> sprite;
    int id;
    point2D center;

public:
    //Constructors
    GameObj();
    GameObj(int id, int x, int y, std::vector<imageFrame> sprites);

    //Destructor
    virtual ~GameObj() = default;

    //Getters
    int getId() const;
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
    virtual void setSprite(std::vector<imageFrame> sprite);

    //Non-Trivial Methods
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    void moveY(double deltaY);
    virtual void draw() const = 0;

};

#endif //CB_FINAL_PROJECT_GRAPHICS_GAMEOBJ_H
