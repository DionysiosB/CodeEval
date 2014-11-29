#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

void LettercasePercentageRatio(char * inputName) {

    std::string line;
    const int caseDiff = 'A' - 'a';
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            double lowCount   = 0;
            double upperCount = 0;
            for(int p = 0; p < line.size(); p++){
                char current = line[p];
                if('a' <= current && current <= 'z'){++lowCount;}
                else if('A' <= current && current <= 'Z'){++upperCount;}
            } 

            double totalCount = lowCount + upperCount;

            printf("lowercase: %.2lf uppercase: %.2lf\n", 100.0 * lowCount / totalCount, 100 * upperCount / totalCount);

		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	LettercasePercentageRatio(argv[1]);
	return 0;
}
