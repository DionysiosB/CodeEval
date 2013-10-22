#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

void flavius(char* inputName) {
	string line,outputString;
	unsigned commaPos,m,n,counter,currentPos,numAlive;
	
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){	
			ostringstream convert;
			commaPos=line.find(",");
			n=atoi(line.substr(0,commaPos).c_str());m=atoi((line.substr(commaPos+1)).c_str());
			int alive[n];
			for(unsigned k=0;k<n;++k){alive[k]=1;}
			
			currentPos=0;counter=0;numAlive=n;
			while(numAlive>0){
				counter=(counter+alive[currentPos])%m;
				if(counter==0 && alive[currentPos]==1){alive[currentPos]=0;numAlive--;convert<<currentPos<<" ";}
				++currentPos;currentPos=currentPos%n;
			}
			outputString=convert.str();
			cout <<outputString.substr(0,outputString.size()-1)<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	flavius(argv[1]);
	return 0;
}


