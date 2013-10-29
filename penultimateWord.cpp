#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

void penultimateWord(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			string penultimate,last,temp;
			getline(buf,last,' ');penultimate=last;
			while(getline(buf,temp,' ')){penultimate=last;last=temp;}
			cout <<penultimate<<endl;
		}
		inputFile.close();
	}
}	

int main (int argc, char * const argv[]) {
	penultimateWord(argv[1]);
	return 0;
}