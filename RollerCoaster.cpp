#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>


bool isLetter(char input){
    return ('a' <= input && input <= 'z') || ('A' <= input && input <= 'Z');
}


void RollerCoaster(char * inputName) {

    std::string line;
    const int caseDiff = 'A' - 'a';
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            int counter = 0;
            for(int p = 0; p < line.size(); p++){
                char current = line[p];
                if(!isLetter(current)){putchar(current); continue;}

                ++counter;
                if(counter % 2){putchar(toupper(current));}
                else{putchar(tolower(current));}
            } 
            std::cout << std::endl;
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	RollerCoaster(argv[1]);
	return 0;
}
