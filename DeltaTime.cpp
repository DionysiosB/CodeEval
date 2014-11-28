#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

void DeltaTime(char * inputName) {

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            int startHour = 10 * (line[0] - '0') + (line[1] - '0');
            int startMin  = 10 * (line[3] - '0') + (line[4] - '0');
            int startSec  = 10 * (line[6] - '0') + (line[7] - '0');

            int endHour = 10 * (line[9] - '0') + (line[10] - '0');
            int endMin  = 10 * (line[12] - '0') + (line[13] - '0');
            int endSec  = 10 * (line[15] - '0') + (line[16] - '0');

            int diffSec = 3600 * (endHour - startHour) + 60 *(endMin - startMin) + (endSec - startSec);
            if(diffSec < 0){diffSec = -diffSec;}

            int deltaHour = diffSec / 3600;
            int deltaMin  = (diffSec - 3600 * deltaHour) / 60;
            int deltaSec  = diffSec - 3600 * deltaHour - 60 * deltaMin;

            if(deltaHour < 10){std::cout << '0';}
            std::cout << deltaHour << ":";
            if(deltaMin < 10){std::cout << '0';}
            std::cout << deltaMin << ":";
            if(deltaSec < 10){std::cout << '0';}
            std::cout << deltaSec << std::endl;

		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	DeltaTime(argv[1]);
	return 0;
}
