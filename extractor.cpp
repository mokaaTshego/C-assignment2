#include "FrameSequence.h"
#include <cstring>
int main(int argc, char *argv[]){

  MKXTSH013::FrameSequence framesequence;
  int x1, x2, y1,y2, width, height;
  std::string filename, out;
  if(argc <2){
    std::cout<<"Enter valid input"<<std::endl;
  }

  for(int i =1 ; i < argc ; i++){

    filename = std::string(argv[i]);
    bool suc = framesequence.readFile(filename);


    if(!suc){
        return -1;
    }
    else if(strcmp(argv[i], "-s") == 0){

        width = atoi(argv[i+1]);
        std::cout << width;
        height = atoi(argv[i+2]);
        framesequence.setFrames(width,height);
        i+=2;

    }

    else if(strcmp(argv[i], "-t") == 0){
        x1 = atoi(argv[i + 1]);
        y1 = atoi(argv[i + 2]);
        x2 = atoi(argv[i + 3]);
        y2 = atoi(argv[i + 4]);
        framesequence.setCoordinates(x1,x2,y1,y2);
        framesequence.populateFrames();
        i+=4; //skip all coordinates

     }



    else if(strcmp(argv[i], "-w") == 0){

        out = std::string(argv[i+2]);
         //check none,invert, reverse, reinvert

        if(strcmp(argv[i+1], "invert")==0){
            framesequence.invertFrames(out); //invert
        }
        else if(strcmp(argv[i+1], "reinvert")==0){
            framesequence.reinvertFrames(out);

        } //reinvert
        else if(strcmp(argv[i+1], "none")==0){

            framesequence.None(out);

        }//none
        else if (strcmp(argv[i+1], "reverse")==0){
           framesequence.Reverse(out);

        }//reverse

        i += 2;






    }
    else{
        std::cout <<"incorrect input"<<std::endl;
        return -1;
    }



  }//for loop
  return 0;


}

/*
    MKXTSH013::FrameSequence framesequence;
    std::string filename;
    std::string output;
    std::cout << "Enter filename" << std::endl;
    std::cin >> filename;
    bool suc = framesequence.readFile(filename);
    framesequence.invertFrames(output);

*/