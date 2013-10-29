#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> splitLine(std::string input,char delim){
    std::vector<std::string> output;
	std::stringstream lineStream(input);
	std::string temp;
	while(getline(lineStream,temp,delim)){output.push_back(temp);}
    return output;
}


void wordToDigit(char* inputName) {

	std::string line;
	std::map<std::string,int> numbersMap;
	
	numbersMap["zero"]  = 0;
	numbersMap["one"]   = 1;
	numbersMap["two"]   = 2;
	numbersMap["three"] = 3;
	numbersMap["four"]  = 4;
	numbersMap["five"]  = 5;
	numbersMap["six"]   = 6;
	numbersMap["seven"] = 7;
	numbersMap["eight"] = 8;
	numbersMap["nine"]  = 9;
	
	//std::ifstream inputFile (inputName);	
	std::ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			std::vector<std::string> inputNumbers=splitLine(line,';');
			for(unsigned k = 0; k < inputNumbers.size(); k++){std::cout << numbersMap[inputNumbers[k]];}
			std::cout << std::endl;
		}
	}
	inputFile.close();
}


int main (int argc, char * const argv[]) {
	wordToDigit(argv[1]);
	return 0;
}


