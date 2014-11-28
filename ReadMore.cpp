#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

void ReadMore(char * inputName) {
    std::string line;
	//ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){
            if(line.size() <= 55){std::cout << line << std::endl;}
            else{
                const int N = 40;
                std::string trimmedLine = line.substr(0, N);
                size_t lastSpace = trimmedLine.rfind(' ');
                if(lastSpace != std::string::npos){trimmedLine = trimmedLine.substr(0, lastSpace);}
                trimmedLine += "... <Read More>";
                std::cout << trimmedLine << std::endl;
            }
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	ReadMore(argv[1]);
	return 0;
}
