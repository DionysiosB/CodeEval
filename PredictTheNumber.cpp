#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void PredictTheNumber(char * inputName) {

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){
            std::istringstream buf(line);
            unsigned long n; buf >> n;
            int output = 0;
            while(n > 0){output += n % 2; n /= 2;}
            std::cout << (output % 3) << std::endl;
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	PredictTheNumber(argv[1]);
	return 0;
}
