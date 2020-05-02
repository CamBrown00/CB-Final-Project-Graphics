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
void LinkObj :: kbd(unsigned char key){
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

