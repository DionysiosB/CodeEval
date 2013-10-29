#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <typeinfo>
using namespace std;

const int numDigits=7;

string stringFromDigit(char c){
	if(c=='0') return "0";
	if(c=='1') return "1";
	if(c=='2') return "abc";
	if(c=='3') return "def";
	if(c=='4') return "ghi";
	if(c=='5') return "jkl";
	if(c=='6') return "mno";
	if(c=='7') return "pqrs";
	if(c=='8') return "tuv";
	if(c=='9') return "wxyz";
	return "";
}

class counter {
	int base[numDigits];vector<int> data;	
public:
	counter (int baseArray[numDigits]){
		for(int k=0;k<numDigits;++k){base[k]=baseArray[k];}
		for(int k=0;k<numDigits;++k){data.push_back(0);}
	}
	
	int inc(){		
		data[0]++;
		for(int k=0;k<numDigits-1;++k){if(data[k]>=base[k]){data[k]=0;++data[k+1];}}
		if(data[numDigits-1]>=base[numDigits-1]){data[numDigits-1]=0;return 0;}
		return 1;
	}
	
	vector<int> queryData(){return data;}
};

void telephoneWords(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){

			vector<string> outputChars;
			int baseArray[numDigits];
			
			for(int k=numDigits-1;k>=0;--k){
				outputChars.push_back(stringFromDigit(line[k]));
				baseArray[numDigits-1-k]=stringFromDigit(line[k]).size();
				}
	
			counter index(baseArray);
			bool notdone=1;
			do{
				vector<int> currentState=index.queryData();
				for(int k=numDigits-1;k>=0;--k){cout <<outputChars[k][currentState[k]];}
				notdone=index.inc();
				if(notdone){cout<<",";}
			}while(notdone);			
			cout<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	telephoneWords(argv[1]);
	return 0;
}