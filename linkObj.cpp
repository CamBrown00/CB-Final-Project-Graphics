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
void LinkObj :: kbd(unsigned char key, int x, int y){
    switch(key) {
        case 'w': {
            moveY(-5);
            setSpriteIndex(2);
            break;
        }
        case 'a': {
            moveX(-5);
            setSpriteIndex(1);
            if (!getMirrorX()) mirrorSpritesX();
            break;
        }
        case 's': {
            moveY(5);
            setSpriteIndex(0);
            break;
        }
        case 'd': {
            moveX(5);
            setSpriteIndex(1);
            if (getMirrorX()) mirrorSpritesX();
            break;
        }

    }
}

void LinkObj :: kbdUp(unsigned char key, int x, int y){
    switch(key) {
        case 'w': {
            break;
        }
        case 'a': {
            break;
        }
        case 's': {
            break;
        }
        case 'd': {
            break;
        }

    }
}

void LinkObj :: readSpritesFromFiles() {
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprFront/linkMoveSprFront", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprSide/linkMoveSprSide", 2);
    addSpriteFromFile("../Resources/Sprites/Link/MoveSprs/LinkMoveSprBack/linkMoveSprBack", 2);
}

