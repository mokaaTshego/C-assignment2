/**
 *Tshegofatso Mokaa
 * March 2022
*/

#include "FrameSequence.h"

namespace MKXTSH013 {

    FrameSequence::FrameSequence(void){} //constructor

    void FrameSequence::setFrames(int w, int h){
            this->width = w;
            this->height  = h;

    }//set frame size

    void FrameSequence::setCoordinates(int x1, int x2, int y1, int y2){

            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;

    }//set the coordinate


    void FrameSequence::invertFrames(std::string output){
        char temp;
        for(int i =0 ; i < imageSequence.size() ; i++){
            std::ofstream outFile(output, std::ios::binary);
            outFile << "P5" << "\n";
            outFile << "#by in FrameSequence.cpp\n" << width << " " << height  << "\n255\n";
             for(int j =0; j< height ; j++){
                for(int k=0; k<width ; k++){
                   temp = 255 - imageSequence[i][j][k]; //invert the frames
                   outFile.write(reinterpret_cast<char*>(&temp), 1);

                }

            }
            outFile.close();


        }


    }//invertFrames

    void FrameSequence::reinvertFrames(std::string output){
             char temp;
             for(int i =imageSequence.size()  ; i >=0 ; i--){
                 std::ofstream outFile(output, std::ios::binary);
                 outFile << "P5" << "\n";
                 outFile << "#by in FrameSequence.cpp\n" << width << " " << height  << "\n255\n";
                  for(int j =0; j< height ; j++){
                     for(int k=0; k<width ; k++){
                        temp = 255 - imageSequence[i][j][k]; //invert the frames
                        outFile.write(reinterpret_cast<char*>(&temp), 1);

                     }

                 }
                 outFile.close();

             }

    }//reinvert

    void FrameSequence::None(std::string output){

                for(int i =0 ; i < imageSequence.size() ; i++){
                    std::ofstream outFile(output, std::ios::binary);
                    outFile << "P5" << "\n";
                    outFile << "#by in FrameSequence.cpp\n" << width << " " << height  << "\n255\n";
                     for(int j =0; j< height ; j++){
                        for(int k=0; k<width ; k++){
                           outFile.write(reinterpret_cast<char*>(&imageSequence), 1);

                        }

                    }
                    outFile.close();


                }





    }//none

    void FrameSequence::Reverse(std::string output){

                     for(int i =imageSequence.size()  ; i >=0 ; i--){
                         std::ofstream outFile(output, std::ios::binary);
                         outFile << "P5" << "\n";
                         outFile << "#by in FrameSequence.cpp\n" << width << " " << height  << "\n255\n";
                          for(int j =0; j< height ; j++){
                             for(int k=0; k<width ; k++){
                                outFile.write(reinterpret_cast<char*>(&imageSequence), 1);

                             }

                         }
                         outFile.close();

                     }

    }




    //method to read the pgm image

    bool FrameSequence::readFile(std::string filename){

        unsigned char * rawImage;
        std::string header;

        std::ifstream file(filename, std::ios::in | std::ios::binary); //reading from file

        if(!file){return false;} //if file not open
        else{

            std::getline(file, header);
            std::getline(file, header);

            while(header[0] == '#'){
                std::getline(file, header);
            } //checkin comment

             columns = std::stoi( header.substr( 0, header.find(" ") ) ); //width
             rows = std::stoi( header.substr( header.find(" ") + 1 ) ); //height

             std::getline(file, header); // 255

             rawImage = new unsigned char [columns*rows];

             char * temp = new char [columns * rows];
             file.read(temp, columns*rows);
             rawImage = reinterpret_cast<unsigned char *>(temp);


             imageData = new unsigned char * [rows];
             for (int i = 0; i < rows; ++i){
                imageData[i] = new unsigned char [columns];
                for (int j = 0; j < columns; ++j){
                    imageData[i][j] = rawImage[i*columns + j];

                }
                }

                delete [] rawImage;
        }

            file.close();



        }//readfile
  void FrameSequence::populateFrames(void){

         //gradient
                     float ytop = y2 - y1;
                     float xbottom = x2 - x1;
                     float gradient = ytop / xbottom;

                     if(std::fabs(gradient)<1.0){
                        float ycordinate = y1;
                        int tempy;
                        for(int i = x1+1; i<x2;i++){
                            ycordinate += gradient;
                            unsigned char ** array1 = new unsigned char*[rows]; //array rows
                            for(int k =0; k<rows;k++){
                                unsigned char * array2 = new unsigned char[columns];
                                for(int l=0; l<columns;i++){
                                    tempy = std::round(ycordinate);
                                    array2[l] = imageData[i+k][tempy+l];
                                }
                                array1[k] =&array2[0];
                            }
                            imageSequence.push_back(&array1[0]);


                        }

                     }
                     else{
                        gradient = xbottom/ytop;
                        float xcordinate = x1;
                        int tempx;
                        for(int i = y1+1; i<y2; i++){
                            xcordinate += gradient;
                            unsigned char ** array1 = new unsigned char*[rows];
                            for(int k =0; k<rows;k++){
                                unsigned char * array2 = new unsigned char[columns];
                                    for(int l=0; l<columns;i++){
                                        tempx = std::round(xcordinate);
                                            array2[l] = imageData[tempx+k][i+k];
                                             }
                                             array1[k] =&array2[0];
                             }
                             imageSequence.push_back(&array1[0]);
                        }


                     }


  }

    FrameSequence::~FrameSequence(){

                for(int i=0; i<imageSequence.size();i++){
                    for(int j =0; j<height;j++){
                        delete [] imageSequence[i][j];
                    }
                    delete [] imageSequence[i];

                }


            } //destructor





    } //namespace



