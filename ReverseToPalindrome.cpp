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
		x=(x-mult*(x/mult))/10;
		mult /=100;
	}
	return 1;
}

unsigned reverseNumber(unsigned x){
	unsigned output=0;
	while(x>0){output=10*output+(x%10);x=x/10;}
	return output;
}

void reverseAndAdd(char* inputName) {
	string line;int n;int counter;
	int maxIterations=1000;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());
			counter=0;
			while(counter<maxIterations){
				if(isPalindrome(n)){cout << counter <<" "<<n<<endl;break;}
				n=n+reverseNumber(n);++counter;
			}
					
		}
	}
	inputFile.close();
}



int main (int argc, char * const argv[]) {
	reverseAndAdd(argv[1]);
	return 0;
}


