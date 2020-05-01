from PIL import Image
import numpy as np
import os.path
from os import path

def main():
    sprPath = "Resources/Sprites/Link/"
    
    # Move Sprites
    readSpriteToFile(sprPath + "MoveSprs/LinkMoveSprFront/")
    readSpriteToFile(sprPath + "MoveSprs/LinkMoveSprSide/")
    readSpriteToFile(sprPath + "MoveSprs/LinkMoveSprBack/")

    #Attack Sprites

def readSubdirectorySpritesToFile(mainDirectory):
    print("test")
    

def readSpriteToFile(readPath):
    # Count number of image frames in directory, populate framePaths
    frameCount = 0
    framePaths = []
    for path in os.listdir(readPath):
        if os.path.isfile(os.path.join(readPath, path)):
            framePaths.append(str(os.path.join(readPath, path)))
            frameCount += 1
            
    # Record image dimensions and pixel color data to a csv file for each frame
    for framePath in framePaths:
        if ((os.path.splitext(framePath))[1] != ".csv"):
            spr = Image.open(framePath)
            sprArr = np.asarray(spr)
            
            #if os.path.exists(((os.path.splitext(framePath))[0] + ".csv")):
            #    writeFile = open(((os.path.splitext(framePath))[0] + ".csv"), "a")
            #else:
            writeFile = open(((os.path.splitext(framePath))[0] + ".csv"), "w")
            writeFile.write( str(len(sprArr[0])) + "," + str(len(sprArr)) + "\n")
            writeFile = open(((os.path.splitext(framePath))[0] + ".csv"), "a")
            for i in range(len(sprArr)):
                np.savetxt(writeFile, sprArr[i], delimiter=",")
            writeFile.close()
    
    
main()
