#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool compareLengths (const string& x,const string& y) { return (x.size()>y.size()); }

void longestLines(char* inputName) {
	string line;
	unsigned minLength,lengthBound=1000,currentLength,currentMin;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		getline(inputFile,line);
		unsigned howMany=atoi(line.c_str());
		vector<string> data(howMany,"");
		
		while(getline(inputFile,line)){
			currentLength=line.size();
			currentMin=0;minLength=lengthBound;
			for(unsigned k=0;k<howMany;++k){if(data[k].size()<minLength){minLength=data[k].size();currentMin=k;}}
			if(currentLength>minLength){data[currentMin]=line;}
		}
				
		sort(data.begin(),data.end(),compareLengths);
		for(unsigned k=0;k<howMany;++k){cout << data[k]<<endl;}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	longestLines(argv[1]);
	return 0;
}