#include "linkObj.h"

// Constructors
LinkObj :: LinkObj() {
}

LinkObj :: LinkObj(int id, int x, int y, int scale) : GameObj(id, x, y, scale) {
    readSpritesFromFiles();
}

LinkObj :: LinkObj(int id, int x, int y, int scale, std::vector<imageFrame> sprite) : GameObj(id, x, y, scale, sprite){
    readSpritesFromFiles();
}

LinkObj :: LinkObj(int id, int x, int y, int scale, std::vector<std::vector<imageFrame>> sprites) : GameObj(id, x, y, scale, sprites) {
    readSpritesFromFiles();
}

//Non-Trivial Methods
void LinkObj :: kbd(unsigned char key, int x, int y) {
    int vSpd = 3;
    int hSpd = 3;
    switch(key) {
        case 'w': {
            setVSpd(-vSpd);
            setSpriteIndex(2);
            break;
        }
        case 'a': {
            setHSpd(-hSpd);
            setSpriteIndex(1);
            if (!getMirrorX()) mirrorSpritesX();
            break;
        }
        case 's': {
            setVSpd(vSpd);
            setSpriteIndex(0);
            break;
        }
        case 'd': {
            setHSpd(hSpd);
            setSpriteIndex(1);
            if (getMirrorX()) mirrorSpritesX();
            break;
        }

    }
}

void LinkObj :: kbdUp(unsigned char key, int x, int y) {
    switch(key) {
        case 'w': {
            setVSpd(0);
            break;
        }
        case 'a': {
            setHSpd(0);
            break;
        }
        case 's': {
            setVSpd(0);
            break;
        }
        case 'd': {
            setHSpd(0);
            break;
        }

    }
}

void LinkObj :: readSpritesFromFiles() {
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprFront/linkMoveSprFront", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprSide/linkMoveSprSide", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprBack/linkMoveSprBack", 2);
}

