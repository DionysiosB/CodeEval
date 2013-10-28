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

void findDupe(char* inputName) {

	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			int colonPos=line.find(";");if(colonPos<=0){continue;}
			int n=atoi((line.substr(0,colonPos)).c_str());
			vector<int> inputArray=splitCSV(line.substr(colonPos+1),',');
			int total=0;
			for(vector<int>::iterator myIter=inputArray.begin();myIter != inputArray.end();++myIter){total+=(*myIter);}
			cout << total-(n-1)*(n-2)/2<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	findDupe(argv[1]);
	return 0;
}


