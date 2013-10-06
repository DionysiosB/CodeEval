#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int FizzBuzz(char * inputName) {
	
	string line;int first;int second;int N;
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			buf >> first;buf >> second; buf>> N;
			for(int counter=1;counter<=N;++counter){
				if(counter%(first*second)==0) cout <<"FB";
				else if(counter%first==0) cout <<"F";
				else if(counter%second==0) cout <<"B";
				else cout << counter;
				if(counter<N) cout <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	FizzBuzz(inputName);
	return 0;
}
