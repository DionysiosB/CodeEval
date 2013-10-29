#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
//using namespace std;


std::vector<int> splitLine(std::string input,char delim){
    std::vector<int> output;
	std::stringstream lineStream(input);
	std::string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}


void findLowestUnique(char* inputName) {

	const int upperBound = 9;
	std::string line;
	//std::ifstream inputFile (inputName);	
	std::ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			std::vector<int> inputArray=splitLine(line,' ');
			int freq[upperBound + 1] = {0};
			for(unsigned k = 0; k < inputArray.size(); k++ ){++freq[inputArray[k]];}
			int unique(0), uniquePos(0);
			for(int k = 1; k <= upperBound; k++){if(freq[k] == 1){unique = k; break;}}
			if(unique > 0){for(unsigned k = 0; k < inputArray.size(); k++){if(inputArray[k] == unique){uniquePos = k + 1; break;}}}
			std::cout << uniquePos << std::endl;			
		}
	}
	inputFile.close();
}


int main (int argc, char * const argv[]) {
	findLowestUnique(argv[1]);
	return 0;
}


