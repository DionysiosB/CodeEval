#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void numberMultiples(char* inputName) {

	string line,firststr,secondstr;
	int commaPos,first,second;
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			firststr=line.substr(0,commaPos);first=atoi(firststr.c_str());
			secondstr=line.substr(commaPos+1);second=atoi(secondstr.c_str());
			int temp=1;
			while(first>(temp*second)){++temp;}
			cout << temp*second <<endl;
		}
	}
	inputFile.close();
}



int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	numberMultiples(inputName);
	return 0;
}


