#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<int> splitCSV(std::string input,char delim){
    std::vector<int> output;
    std::stringstream lineStream(input);
    std::string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

void ReadMore(char * inputName) {
    std::string line;
	//ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){
            std::vector<int> data = splitCSV(line, ' ');

            int current = data[0];
            int counter = 1;
            for(int p = 1; p < data.size(); p++){
                if(data[p] == current){++counter;}
                else{
                    printf("%d %d ", counter, current);
                    current = data[p];
                    counter = 1;
                }
            }

            printf("%d %d\n", counter, current);

		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	ReadMore(argv[1]);
	return 0;
}
