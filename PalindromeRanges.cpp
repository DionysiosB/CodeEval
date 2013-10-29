#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool isPalindrome(unsigned x){
	unsigned mult=1;
	while(x>=10*mult){mult *= 10;};
	while(mult>0){
		if((x/mult)%10 != x%10 ){return 0;}
		x=(x-mult*(x/mult))/10;mult /=100;
	}
	return 1;
}


void palindromeRanges(char* inputName) {
	string line;int lower,upper,length,spacePos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			spacePos=line.find(" ");
			lower=atoi(line.substr(0,spacePos).c_str());upper=atoi((line.substr(spacePos+1)).c_str());
			length=upper-lower+1;
			unsigned palSoFar[length];unsigned total=0;
			for(int k=0;k<length;++k){
				if(isPalindrome(lower+k)){++total;}
				palSoFar[k]=total;
			}
			
			int interesting = 0;
			for(int m=0;m<length;++m){if(palSoFar[m]%2==0){++interesting;}}
			
			for(int m=0;m<length-1;++m){
				for(int n=m+1;n<length;++n){
					if((palSoFar[n]-palSoFar[m])%2==0){++interesting;}
				}
			}
			cout <<interesting<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	palindromeRanges(argv[1]);
	return 0;
}