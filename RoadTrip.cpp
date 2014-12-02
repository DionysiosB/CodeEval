#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<int> readDistances(std::string input){

    std::vector<int> output;
    int distance(0);
    for(int p = 0; p < input.size(); p++){
        if('0' <= input[p] && input[p] <= '9'){distance = 10 * distance + (input[p] - '0');}
        else if(input[p] == ';'){output.push_back(distance); distance = 0;}
    }
    return output;
}

void RoadTrip(char * inputName) {

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            std::vector<int> distanceVec = readDistances(line);
            sort(distanceVec.begin(), distanceVec.end());

            int current = 0;

            for(int p = 0; p < distanceVec.size() - 1; p++){
                std::cout << (distanceVec[p] - current) << ",";
                current = distanceVec[p];
            }
            std::cout << (distanceVec[distanceVec.size() - 1] - current) << std::endl;
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	RoadTrip(argv[1]);
	return 0;
}
