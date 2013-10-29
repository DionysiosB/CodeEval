#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

void jollyJumpers(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			unsigned length;buf>> length;int data[length];
			for(unsigned k=0;k<length;++k){buf>>data[k];}
			bool diffs[length];
			for(unsigned k=0;k<length;++k){diffs[k]=0;}
			for(unsigned k=0;k<length-1;++k){
				unsigned absDiff=abs(data[k+1]-data[k]);
				if(absDiff<length){diffs[absDiff]=1;}
			}
			bool isJolly=1;
			for(unsigned k=1;k<length;++k){if(diffs[k]==0){isJolly=0;break;}}		
			if(isJolly){cout << "Jolly"<<endl;}
			else {cout <<"Not jolly"<<endl;}	
		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	jollyJumpers(argv[1]);
	return 0;
}