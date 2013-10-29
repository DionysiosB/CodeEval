#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;


void nextPerm(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){			
			int inputLength=line.size();
			
			bool increasing=1;
			for(int k=0;k<inputLength-1;++k){if(line[k]<line[k+1]){increasing=0;break;}}
			if(increasing){line="0"+line;++inputLength;}
						
			for(int k=inputLength-2;k>=0;--k){				
				if(line[k]<line[k+1]){
					char currentMin=line[k+1];int currentMinPos=k+1;
					for(int m=inputLength-1;m>=k+1;--m){if(line[m]<currentMin && line[m]>line[k]){currentMin=line[m];currentMinPos=m;}}
					
					int temp=line[k];line[k]=line[currentMinPos];line[currentMinPos]=temp;
					
					sort(line.begin()+k+1,line.end());
					break;
				}
			}
			cout <<line <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	nextPerm(argv[1]);
	return 0;
}