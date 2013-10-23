#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void trailingStrings(char* inputName) {

	string line,first,second;
	int commaPos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			if(commaPos>0){
				first=line.substr(0,commaPos);second=line.substr(commaPos+1);
				if((first.size()>=second.size()) && first.find(second,first.size()-second.size())==first.size()-second.size()){cout<< 1;}
				else {cout << 0;}
				cout <<endl;
			}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	trailingStrings(argv[1]);
	return 0;
}


