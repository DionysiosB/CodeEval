#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void matrixPath(char* inputName) {

	string line,currentInput;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			int n=atoi(line.c_str());
			int matrix[n][n];
			for(int row=0;row<n;++row){
				for(int col=0;col<n-1;++col){
					getline(inputFile,currentInput,',');
					matrix[row][col]=atoi(currentInput.c_str());
					}
				getline(inputFile,currentInput);matrix[row][n-1]=atoi(currentInput.c_str());				
			}
						
			for(int row=1;row<n;++row){matrix[row][0]+=matrix[row-1][0];}
			for(int col=1;col<n;++col){matrix[0][col]+=matrix[0][col-1];}
			for(int row=1;row<n;++row){
				for(int col=1;col<n;++col){
					matrix[row][col]+=min(matrix[row-1][col],matrix[row][col-1]);	
				}
			}
			cout << matrix[n-1][n-1]<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	matrixPath(argv[1]);
	return 0;
}


