
Team Members: Cameron Brown (solo)
Required Installations: C++ 14, Python 3 (Recommended)
Starter Code Used: Graphics Starter Code

The program I created replicates the aesthetic of the first Legend of Zelda game on the NES, and features animated
sprites and movement similar to that of the original. The sprites are read in from csv files, that I wrote a python
script to produce from images when given a directory full of any number of image files. The python script isn't
necessary to run for the program to work in this version, but it can be run again to rewrite the csv files, or to
write csv files for any new sprites moved to the directories specified in the main method of the script. The overall
structure of the program is fairly simple. The gameObj class serves as a general class for any other objects in the
game to be derived from, such as the linkObj class. In graphics.cpp, a Link object is created and a pointer to it
it stored in a vector of pointers to GameObjs (for the polymorphism requirement). The idea is that all of the other
objects in the original game could be replicated here and pointers for them would be stored in that vector as well.
By iterating through the vector, linkObj is drawn to the screen, and updates its sprite and animates based on its
movement. There's no objective or way to win in this program, it's basically just a showcase for the animated sprites
and movement that was in the original game.

Instructions:
- If the csv files for the sprites can't be located, run the python script imageConverter to produce them.
- Run the graphics executable for the c++ program to begin.
- Use WASD to move Link.
- Press esc to close the window.
