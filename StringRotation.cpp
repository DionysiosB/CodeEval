#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void stringRotation(char* inputName) {
	string line,first,second;
	int commaPos,found;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			first=line.substr(0,commaPos);second=line.substr(commaPos+1);
			second=second+second;found=second.find(first);
			if(found>=0){cout << "True"<<endl;}
			else {cout <<"False"<<endl;}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	stringRotation(argv[1]);
	return 0;
}


