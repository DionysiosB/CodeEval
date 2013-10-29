#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

vector<int> getNumbers(string input){
    vector<int> output;
	stringstream lineStream(input);
	int temp;
	while( lineStream >> temp ){ output.push_back( temp ); }
    return output;
}

void famousWriters(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			string output;
			int pipePos = line.find("|");		
			string input = line.substr(0,pipePos);
			vector<int> keys = getNumbers( line.substr( pipePos+1 ) );
			for(size_t n = 0; n < keys.size(); n++){cout << input[ keys[n] - 1 ]; };
			cout<<endl;		
		}
		inputFile.close();
	}
}

int main (int argc, char * const argv[]) {
	famousWriters(argv[1]);
	return 0;
}