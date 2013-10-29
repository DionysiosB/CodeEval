#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int numberOfPaths(string input){
	//cout<< "Entered with Input: "<<input <<endl;
	int length=input.size();
	if(length==0){return 1;}
	if(input[0]=='0'){return 0;}
	
	if(length==1){return 1;}
	
	else{
		if(input[0]=='1' || (input[0]=='2' && input[1]>='1' && input[1]<='6')  ){
			return (numberOfPaths(input.substr(1,length))+numberOfPaths(input.substr(2,length)) );
		}
		else {return numberOfPaths(input.substr(1,length));}
	}
	
	
}



void decodingWays(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			cout << numberOfPaths(line)<<endl;
		}
	}
}	

int main (int argc, char * const argv[]) {
	decodingWays(argv[1]);
	return 0;
}