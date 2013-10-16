#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

int maxSum(vector<int> input){
	int currentMax  = input[0], maxEnd = input[0];
	for(unsigned i=1;i<input.size();++i){
		if(maxEnd<0){maxEnd = input[i];}
		else {maxEnd += input[i];}
		if(maxEnd > currentMax ){currentMax = maxEnd;}
	}
	return currentMax ;
}


void maxSumSubarray(char* inputName) {
	string line;vector<int> numberVector;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			numberVector=splitCSV(line,',');
			cout << maxSum(numberVector)<<endl;			
		}
	}
	inputFile.close();
}



int main (int argc, char * const argv[]) {
	maxSumSubarray(argv[1]);
	return 0;
}


