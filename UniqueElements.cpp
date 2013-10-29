#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void uniqueElements(char* inputName) {

	string line; string buf;
	int previous,next;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			stringstream lineStream(line);
			
			getline(lineStream,buf,',');
			previous=atoi(buf.c_str());
			cout << previous;	
			while(getline(lineStream,buf,',')){
				next=atoi(buf.c_str());
				if(next != previous){cout <<","<< next;}
				previous = next;
			}
			cout <<endl;	
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	uniqueElements(inputName);
	return 0;
}


