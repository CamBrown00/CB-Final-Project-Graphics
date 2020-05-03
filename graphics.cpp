#include "graphics.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
#include "gameObj.h"
#include "LinkObj.h"
using namespace std;

GLdouble width, height;
int wd;
vector<unique_ptr<GameObj>> gameObjs;

void init() {

    srand(time(0));
    width = 500;
    height = 500;

    gameObjs.push_back(make_unique<LinkObj>(1, 0, 0, 2));

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.9882f, 0.84706f, 0.65882f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    for (unique_ptr<GameObj> &gObj : gameObjs) {
        gObj->draw();
    }
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // Call kbd functions for game objects
    for (unique_ptr<GameObj> &gObj : gameObjs) {
        gObj->kbd(key, x, y);
    }
    switch(key) {
        case 27: {
            glutDestroyWindow(wd);
            exit(0);
            break;
        }
    }
    glutPostRedisplay();
}

void kbdUp(unsigned char key, int x, int y) {
    // Call kbdUp functions for game objects
    for (unique_ptr<GameObj> &gObj : gameObjs) {
        gObj->kbdUp(key, x, y);
    }
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }
    glutPostRedisplay();
}

void cursor(int x, int y) {

    //c.setCenter(x, y);
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // The left button has been pressed down
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // The left button has been released
    }
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

void linkObjTimer (int dummy) {
    gameObjs[0]->moveX(gameObjs[0]->getHSpd());
    gameObjs[0]->moveY(gameObjs[0]->getVSpd());
    glutPostRedisplay();
    glutTimerFunc(30, linkObjTimer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(250, 180); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("The Legend of Zelda" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, linkObjTimer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
