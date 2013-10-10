#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


void reverseStrings(char * inputName) {
	
	string line;string newWord;
	vector<string> inputVector;vector<string>::iterator myIter;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			while(buf>>newWord){inputVector.push_back(newWord);}
		 	while (!inputVector.empty()){
		    	cout << inputVector.back();
				inputVector.pop_back();
				if(inputVector.size()>0){cout <<" ";}
				else {cout<<endl;}
				}			
		}
	}
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	reverseStrings(inputName);
	return 0;
}
