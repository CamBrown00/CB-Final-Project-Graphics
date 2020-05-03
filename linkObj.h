#ifndef CB_FINAL_PROJECT_GRAPHICS_LINK_H
#define CB_FINAL_PROJECT_GRAPHICS_LINK_H
#include "gameObj.h"

class LinkObj : public GameObj {
private:
    int health;
public:
    // Constructors
    LinkObj();
    LinkObj(int id, int x, int y, int scale);
    LinkObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite);
    LinkObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites);


    // Destructor
    virtual ~LinkObj() = default;

    // Getters

    // Setters

    // Non-trivial methods
    void kbd(unsigned char key, int x, int y) override;
    void kbdUp(unsigned char key, int x, int y) override;
    void readSpritesFromFiles();

};

#endif //CB_FINAL_PROJECT_GRAPHICS_LINK_H
