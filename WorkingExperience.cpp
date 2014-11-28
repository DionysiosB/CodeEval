#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

std::vector<std::string> splitLine(std::string input,char delim){
    std::vector<std::string> output;
    std::stringstream lineStream(input);
    std::string temp;
	while(getline(lineStream,temp,delim)){output.push_back(temp);}
    return output;
}

void WorkingExperience(char * inputName) {
    const int Y = 31;
    const int M = 12;
    const int S = 1990;
    std::map<std::string, int> month;
    month.insert(std::pair<std::string, int>("Jan", 0));
    month.insert(std::pair<std::string, int>("Feb", 1));
    month.insert(std::pair<std::string, int>("Mar", 2));
    month.insert(std::pair<std::string, int>("Apr", 3));
    month.insert(std::pair<std::string, int>("May", 4));
    month.insert(std::pair<std::string, int>("Jun", 5));
    month.insert(std::pair<std::string, int>("Jul", 6));
    month.insert(std::pair<std::string, int>("Aug", 7));
    month.insert(std::pair<std::string, int>("Sep", 8));
    month.insert(std::pair<std::string, int>("Oct", 9));
    month.insert(std::pair<std::string, int>("Nov", 10));
    month.insert(std::pair<std::string, int>("Dec", 11));

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            std::vector<int> experience(Y * M, 0);
            std::vector<std::string> gigVec = splitLine(line, ';');

            for(int p = 0; p < gigVec.size(); p++){
                std::string gig = gigVec[p];
                if(gig[0] == ' '){gig = gig.substr(1, gig.size() - 1);}

                std::string firstMonth = gig.substr(0, 3);
                int startMonth = month[firstMonth];
                int startYear = 1000 * (gig[4] - '0') + 100 * (gig[5] - '0') + 10 * (gig[6] - '0') + (gig[7] - '0');
                std::string lastMonth = gig.substr(9, 3);
                int endMonth = month[lastMonth];
                int endYear = 1000 * (gig[13] - '0') + 100 * (gig[14] - '0') + 10 * (gig[15] - '0') + (gig[16] - '0');

                int startTime = M * (startYear - S) + startMonth;
                int endTime = M * (endYear - S) + endMonth;
                for(int k = startTime; k <= endTime; k++){experience[k] = 1;}
            }

            int total(0);
            for(int k = 0; k < experience.size(); k++){total += experience[k];}
            std::cout << total / M << std::endl;
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	WorkingExperience(argv[1]);
	return 0;
}
