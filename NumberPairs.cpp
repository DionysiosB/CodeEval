#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
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

void numberPairs(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			int colonPos=line.find(";");
			vector<int> data=splitCSV(line.substr(0,colonPos),',');
			int N=atoi(line.substr(colonPos+1).c_str());
			int L=0,R=data.size()-1;int currentSum;string output="";bool found=0;
			while(L<R){
				currentSum=data[L]+data[R];
				if(currentSum==N){output=output+intToString(data[L])+","+intToString(data[R])+";";found =1;L++;}
				else if(currentSum<N){++L;}
				else{--R;}
			}
			if(found){cout << output.substr(0,output.size()-1)<<endl;}
			else {cout <<"NULL"<<endl;}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	numberPairs(argv[1]);
	return 0;
}
