#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void lastOccurence(char* inputName) {
	string line,searchString;char searchChar;
	int output;int commaPos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");searchString=line.substr(0,commaPos);searchChar = *(line.rbegin());
			output=searchString.find_last_of(searchChar);
			cout << output<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	lastOccurence(inputName);
	return 0;
}


