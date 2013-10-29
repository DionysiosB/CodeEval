#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void balancedSmileys(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){	
		while(getline(inputFile,line)){
			int lowerBound=0,upperBound=0;
			
			if(line[0]=='('){++lowerBound;++upperBound;}
			else if(line[0]==')'){cout<<"NO"<<endl;continue;}
			
			for(unsigned k=1;k<line.size();++k){
				if(line[k]=='('){
					++upperBound;
					if(line[k-1] !=':'){++lowerBound;}
				}
				
				if(line[k]==')'){
					lowerBound=max(0,lowerBound-1);
					if(line[k-1] != ':'){--upperBound;}
					if(upperBound<0){break;}
				}
			}
			
			if(upperBound>=0 && lowerBound==0){cout << "YES"<<endl;}
			else{cout <<"NO"<<endl;}
		}
	}
}	

int main (int argc, char * const argv[]) {
	balancedSmileys(argv[1]);
	return 0;
}