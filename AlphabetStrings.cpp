#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

string extractAlphabet(string input){
	sort(input.begin(), input.end());
	unsigned k=0;
	while(k<input.size()){
		if(input[k]==input[k+1]){input.erase(k+1,1);}
		else{++k;}
	}
	return input;
}

class counter {
	int base,length;vector<int> data;	
public:
	counter (int b,int l){
		base=b;length=l;
		for(int k=0;k<l;++k){data.push_back(0);}
	}
	
	int inc(){
		data[0]++;
		for(int k=0;k<length-1;++k){if(data[k]==base){data[k]=0;++data[k+1];}}
		if(data[length-1]>=base){data[length-1]=0;return 0;}
		return 1;
	}
	
	vector<int> queryData(){return data;}
};

void alphabetStrings(char* inputName) {
	string line;int commaPos;bool notdone;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			int stringLength=atoi(line.substr(0,commaPos).c_str());
			string alphabet=line.substr(commaPos+1);
			alphabet=extractAlphabet(alphabet);
			counter myCount(alphabet.size(),stringLength);
			do{
				vector<int> currentState=myCount.queryData();
				for(int k=stringLength-1;k>=0;--k){cout << alphabet[currentState[k]];}
				notdone=myCount.inc();
				if(notdone){cout<<",";}
				}while(notdone);			
			cout<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	alphabetStrings(argv[1]);
	return 0;
}