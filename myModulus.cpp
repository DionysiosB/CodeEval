#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int myModulus(char * inputName) {
	
	string line;unsigned int a,b;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			sscanf (line.c_str(),"%u,%u",&a,&b);
			cout <<(a-(a/b)*b) <<endl;
		}
	}
	return 0;
}	


int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	myModulus(inputName);
	return 0;
}
