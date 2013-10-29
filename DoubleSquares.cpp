#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

void doubleSquares(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		long numCases;
		getline(inputFile,line);istringstream buf(line);buf >> numCases;
		for(int k=0;k<numCases;++k){
			long long N,squareSum=0;
			getline(inputFile,line);istringstream buf(line);buf >> N;
			int total=0;long L=0,R=round(sqrt(pow(2.0,31)));
			while(L<=R){
				squareSum=round(pow(1.0*L,2)+pow(1.0*R,2));
				if(squareSum==N){++total;++L;}
				else if(squareSum>N){--R;}
				else {++L;}
			}
			cout<<total<<endl;			
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	doubleSquares(argv[1]);
	return 0;
}


