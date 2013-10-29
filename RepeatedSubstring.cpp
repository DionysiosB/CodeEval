#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


void stringPerm(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){			
			int inputLength=line.size();
//			cout << "Total Length: "<<inputLength<<endl;
			string maxSubstring;int maxLength=0;
			for(int subLength=1;subLength<=inputLength;++subLength){
				for(int startPos=0;startPos<inputLength-subLength;++startPos){

					string currentSubstring=line.substr(startPos,subLength);
					if(currentSubstring==" "){continue;}
//					cout << "start:"<<startPos<<"  Length:"<<subLength<< "  CurrentSubstring: "<< currentSubstring<<endl;					
					
					int occurrences=0;
					int nextPos= line.find(currentSubstring,startPos);
			//		cout << currentSubstring << "  at " <<nextPos<< endl;
					
					while(nextPos>-1){
		//				cout << currentSubstring<<" found in "<<line << "  @ "<< line.find(currentSubstring) <<endl;
						nextPos=line.find(currentSubstring,nextPos+subLength);
						++occurrences;
										
					}
					if(occurrences>1 && subLength>maxLength){
						maxLength=subLength;
						maxSubstring=currentSubstring;
//						cout << "New Max:  "<<  maxSubstring<< "   "<<occurrences<<endl;	
					}		
			}
		}
		if(maxLength>0){cout << maxSubstring<<endl;}
		else{cout << "NONE" <<endl;}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	stringPerm(argv[1]);
	return 0;
}