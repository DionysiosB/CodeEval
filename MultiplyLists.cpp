#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<long> splitCSV(std::string input,char delim){
    std::vector<long> output;
    std::stringstream lineStream(input);
    std::string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

void MultiplyLists(char * inputName) {

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            std::stringstream lineStream(line);
            std::string first; getline(lineStream, first, '|');
            std::string second; getline(lineStream, second);
            if(second[0] == ' '){second = second.substr(1, second.size() - 1);}

            std::vector<long> firstVec  = splitCSV(first, ' ');
            std::vector<long> secondVec = splitCSV(second, ' ');

            for(int p = 0; p < firstVec.size(); p++){std::cout << firstVec[p] * secondVec[p] << " ";}
            std::cout << std::endl;
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	MultiplyLists(argv[1]);
	return 0;
}
