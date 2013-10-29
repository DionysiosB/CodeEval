#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findNextPerm(vector<int> input, int inputLength){
				
	for(int k=inputLength-2;k>=0;--k){				
		if(input[k]<input[k+1]){
			int currentMin=input[k+1];int currentMinPos=k+1;
			for(int m=inputLength-1;m>=k+1;--m){if(input[m]<currentMin && input[m]>input[k]){currentMin=input[m];currentMinPos=m;}}
			
			int temp=input[k];input[k]=input[currentMinPos];input[currentMinPos]=temp;
			
			sort(input.begin()+k+1,input.end());
			return input;
		}
	}	
	return input;
}

void stringPerm(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){			
			int inputLength=line.size();
			vector<int> stringCounter;for(int k=0;k<inputLength;++k){stringCounter.push_back(k);}
			sort(line.begin(),line.end());
			
			bool notDone=1;
			do{
				for(int m=0;m<inputLength;++m){cout <<line[stringCounter[m]];}
				
				if(stringCounter ==findNextPerm(stringCounter,inputLength)){notDone=0;}
				else{stringCounter=findNextPerm(stringCounter,inputLength);cout<<",";}
				
			}while(notDone);
			cout <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	stringPerm(argv[1]);
	return 0;
}