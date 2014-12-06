#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void BatsChallenge(char * inputName) {

    const int B = 6;
    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){
            std::istringstream buf(line);
            long L, D, N; buf >> L >> D >> N;

            std::vector<long> posVec(N);
            for(long p = 0; p < N; p++){buf >> posVec[p];}

            posVec.push_back(B - D);
            posVec.push_back(L + D - B);

            sort(posVec.begin(), posVec.end());

            long output(0);
            for(int p = 1; p < posVec.size(); p++){
                int temp = (posVec[p] - posVec[p - 1]) / D;
                if(temp > 0){--temp;}
                output += temp;
            }
            std::cout << output << std::endl;


		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	BatsChallenge(argv[1]);
	return 0;
}
