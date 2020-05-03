#ifndef CB_FINAL_PROJECT_GRAPHICS_LINK_H
#define CB_FINAL_PROJECT_GRAPHICS_LINK_H
#include "gameObj.h"

// This class is derived from GameObj and is meant to represent Link, the main character of Zelda 1
class LinkObj : public GameObj {
private:
    std::vector<char> controlKeys;
    std::vector<bool> keysPressed;

public:
    // Constructors
    LinkObj();
    LinkObj(int id, int x, int y, int scale);
    LinkObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite);
    LinkObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites);


    // Destructor
    virtual ~LinkObj() = default;

    // Getters
    std::vector<char> getControlKeys() const;
    std::vector<bool> getKeysPressed() const;

    // Non-trivial methods
    void kbd(unsigned char key, int x, int y) override;
    void kbdUp(unsigned char key, int x, int y) override;
    void readSpritesFromFiles();
    void assignControlKeys();

};

#endif //CB_FINAL_PROJECT_GRAPHICS_LINK_H
