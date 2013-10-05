#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int maxBeauty(char * inputName) {
	
	string line;int maxB;int total=0;
	vector<int> output;vector<int>::iterator outIter;
	map<char,int> inputChars;map<char,int>::iterator findChar;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			inputChars.clear();output.clear();total = 0;
			
			transform(line.begin(),line.end(),line.begin(),::tolower);
			for(unsigned k=0;k<line.size();++k){
				if(line[k]>='a' && line[k]<='z'){
					findChar=inputChars.find(line[k]);
					if(findChar == inputChars.end()) inputChars[line[k]]=1;
					else inputChars[line[k]]++;
				}
			}
			
			for(findChar=inputChars.begin();findChar != inputChars.end(); ++findChar) output.push_back(findChar->second);
			sort(output.begin(),output.end(),greater<int>());
			for(outIter=output.begin(),maxB=26;outIter != output.end(); ++outIter,--maxB) total+=(*outIter)*maxB;
			
			cout <<total << endl;
		}
	}
	return 0;
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	maxBeauty(inputName);
	return 0;
}
