#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

string intToString(int number){
	ostringstream oss;oss<< number;
	return oss.str();
}

void reverseArray(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			string output;
			int colonPos=line.find(";");
			vector<int> data=splitCSV(line.substr(0,colonPos),',');			
			int n=atoi(line.substr(colonPos+1).c_str());			
			int dataLength=data.size();int m=dataLength/n;
			for(int x=0;x<m;++x){for(int y=n-1;y>=0;--y){output+=intToString(data[x*n+y])+",";}}
			for(unsigned x=n*(dataLength/n);x<data.size();++x){output+=intToString(data[x])+",";}
			cout <<output.substr(0,output.size()-1)<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	reverseArray(argv[1]);
	return 0;
}