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

void sudokuChecker(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			string output;
			int colonPos=line.find(";");		
			int n=atoi(line.substr(0,colonPos).c_str());
			vector<int> data=splitCSV(line.substr(colonPos+1),',');
			int total=n*(n+1)/2;bool isValid=1;
			
			int rowSum,colSum,boxSum;
			for(int row=0;row<n;++row){
				rowSum=0;
				for(int col=0;col<n;++col){rowSum+=data[n*row+col];}
				if(rowSum != total){isValid=0;}
			}
			
			for(int col=0;col<n;++col){
				colSum=0;
				for(int row=0;row<n;++row){colSum+=data[n*row+col];}
				if(colSum != total){isValid=0;}
			}
						
			for(int boxRow=0;boxRow<round(sqrt(n));++boxRow){
				for(int boxCol=0;boxCol<round(sqrt(n));++boxCol){
					boxSum=0;
					for(int row=0;row<round(sqrt(n));++row){
						for(int col=0;col<round(sqrt(n));++col){
							boxSum+=data[n*(boxRow*round(sqrt(n))+row)+boxCol*round(sqrt(n))+col];
						}
					}
					if(boxSum != total){isValid=0;}
				}
			}
			if(isValid){cout << "True"<<endl;}
			else{cout<<"False"<<endl;}
		}
		inputFile.close();
	}
}

int main (int argc, char * const argv[]) {
	sudokuChecker(argv[1]);
	return 0;
}