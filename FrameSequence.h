/**
 *Tshegofatso Mokaa
 * March 2022
*/


#ifndef FrameSequence_h
#define FrameSequence_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

namespace MKXTSH013{
    class FrameSequence{
    private:
        std::vector<unsigned char **> imageSequence;
        int height; // height of frame
        int width; //width of frame
        int rows, columns;
        unsigned char** imageData;
        int x1, x2, y1, y2;

    public :

    FrameSequence(void); // default class constructor
    ~FrameSequence(); //class destructor used to clean up resourses
    bool readFile(std::string filename);
    void populateFrames(void);
    void setFrames(int w, int h);
    void setCoordinates(int x1, int x2, int y1, int y2);
    void invertFrames(std::string output);
    void reinvertFrames(std::string output);
    void None(std::string output);
    void Reverse(std::string output);



    };




}


#endif