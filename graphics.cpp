#include "circle.h"
#include "graphics.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
Circle c;
vector<Circle> snow;
vector<unique_ptr<Shape>> snowperson;
int snowpersonXDirection;

void populateSnowperson() {
    // Three white circles
    // red, green, blue, alpha, x, y, radius
    snowperson.push_back(make_unique<Circle>(1, 1, 1, 1, 100, 400, 100));
    snowperson.push_back(make_unique<Circle>(1, 1, 1, 1, 100, 250, 75));
    snowperson.push_back(make_unique<Circle>(1, 1, 1, 1, 100, 130, 50));
    // Black buttons
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 100, 230, 10));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 100, 260, 10));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 100, 290, 10));
    // Eyes
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 80, 120, 8));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 120, 120, 8));
    // Mouth
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 75, 145, 5));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 85, 155, 5));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 100, 160, 5));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 115, 155, 5));
    snowperson.push_back(make_unique<Circle>(0, 0, 0, 1, 125, 145, 5));
}

void init() {
    srand(time(0));
    width = 500;
    height = 500;
    c.setRadius(100);
    c.setCenter(250, 250);
    c.setColor(1, 0, 0, 1);
    snow.resize(100);
    for (Circle &s : snow) {
        s.setRadius((rand() % 5) + 1);
        s.setCenter(rand() % int(width), rand() % int(height));
        s.setColor(1, 1, 1, 1);
    }
    populateSnowperson();
    snowpersonXDirection = 0;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
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
    
    /*
     * Draw here
     */
    c.draw();
    for (Circle &s : snow) {
        s.draw();
    }
    // Draw the snowperson with ~polymorphism~
    for (unique_ptr<Shape> &s : snowperson) {
        s->draw();
    }
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    switch(key) {
        // escape
        case 27: {
            glutDestroyWindow(wd);
            exit(0);
            break;
        }
        case 's': {
            // Make the circle smaller
            c.changeRadius(-5.0);
            break;
        }
        case 'l': {
            // Make the circle larger
            c.changeRadius(5.0);
            break;
        }

    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            snowpersonXDirection = 0;
            break;
        case GLUT_KEY_LEFT:
            snowpersonXDirection = -1;
            break;
        case GLUT_KEY_RIGHT:
            snowpersonXDirection = 1;
            break;
        case GLUT_KEY_UP:
            
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {

    c.setCenter(x, y);
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // The left button has been pressed down
        c.setColor(0, 1, 0, 1);
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // The left button has been released
        c.setColor(1, 0, 0, 1);
    }
    
    glutPostRedisplay();
}

void timer(int dummy) {

    for (Circle &s : snow) {
        s.moveY(s.getRadius());
        if (s.getCenterY() > (height + s.getRadius())) {
            // snow fell off the bottom of the screen. Move to top.
            s.setCenter(rand() % int(width), -s.getRadius());
        }
    }
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

void timerSnowperson(int dummy) {

    if (snowpersonXDirection < 0) {
        // Move the snowperson left using ~polymorphism~
        for (unique_ptr<Shape> &s : snowperson) {
            s->moveX(-1);
        }
    } else if (snowpersonXDirection > 0) {
        // Move the snowperson right using ~polymorphism~
        for (unique_ptr<Shape> &s : snowperson) {
            s->moveX(1);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, timerSnowperson, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(250, 180); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Graphics Examples!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, timerSnowperson, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
