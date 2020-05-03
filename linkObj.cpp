#include "linkObj.h"

// Constructors
LinkObj :: LinkObj() {
    readSpritesFromFiles();
    assignControlKeys();
}

LinkObj :: LinkObj(int id, int x, int y, int scale) : GameObj(id, x, y, scale) {
    readSpritesFromFiles();
    assignControlKeys();
}

LinkObj :: LinkObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite) : GameObj(id, x, y, scale, sprite){
    readSpritesFromFiles();
    assignControlKeys();
}

LinkObj :: LinkObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites) : GameObj(id, x, y, scale, sprites) {
    readSpritesFromFiles();
    assignControlKeys();
}

//Non-Trivial Methods

// This function adjusts the speed and sprite for each key press
void LinkObj :: kbd(unsigned char key, int x, int y) {
    std::cout << key << std::endl;
    int vSpd = 1;
    int hSpd = 1;
    int animationSpeed = 1;
        if(key == 'w') {
            setVSpd(-vSpd);
            setSpriteIndex(2);
            keysPressed[0] = true;
        }
        if (key == 'a') {
            setHSpd(-hSpd);
            setSpriteIndex(1);
            keysPressed[1] = true;
            if (!getMirrorX()) {
                mirrorSpritesX();
            }
        }
        if (key == 's') {
            setVSpd(vSpd);
            setSpriteIndex(0);
            keysPressed[2] = true;
        }
        if (key == 'd') {
            setHSpd(hSpd);
            setSpriteIndex(1);
            keysPressed[3] = true;
            if (getMirrorX()) {
                mirrorSpritesX();
            }
        }

    if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
        setAnimationSpeed(animationSpeed);
    }
}

// This function updates the animation speed and movement speed for key releases
void LinkObj :: kbdUp(unsigned char key, int x, int y) {
        if(key == 'w') {
            setVSpd(0);
            keysPressed[0] = false;
        }
        if(key == 'a') {
            setHSpd(0);
            keysPressed[1] = false;
        }
        if(key == 's') {
            setVSpd(0);
            keysPressed[2] = false;
        }
        if(key == 'd') {
            setHSpd(0);
            keysPressed[3] = false;
        }
    if (keysPressed[0] == false && keysPressed[1] == false && keysPressed[2] == false && keysPressed[3] == false) {
        setAnimationSpeed(0);
    }
}

// This function just runs the addSpriteFromFile function for each of Link's sprites
void LinkObj :: readSpritesFromFiles() {
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprFront/linkMoveSprFront", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprSide/linkMoveSprSide", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprBack/linkMoveSprBack", 2);
}

// This function populates the controlKeys and keysPressed vectors
void LinkObj :: assignControlKeys() {
    controlKeys = {'w', 'a', 's', 'd'};
    for (int i = 0; i < controlKeys.size(); ++i) {
        keysPressed.push_back(false);
    }
}

