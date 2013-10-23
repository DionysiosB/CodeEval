#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void spiral(char* inputName) {

	string line,inputData;int firstPos,secondPos,nrows,ncols;
	int lowerLimitX;int upperLimitX;
	int lowerLimitY;int upperLimitY;
	string first; string second;

	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			nrows=0;ncols=0;
			firstPos=line.find(";");stringstream first(line.substr(0,firstPos));first>>nrows;
			secondPos=line.find(";",firstPos+1);stringstream second(line.substr(firstPos+1,secondPos));second>>ncols;
			inputData=line.substr(secondPos+1);istringstream dataStream(inputData);
			
			vector< vector<string> > inputMatrix(nrows, vector<string>(ncols,"0")); 
			for(int row=0;row<nrows;++row){
				for(int col=0;col<ncols;++col){
					dataStream >> inputMatrix[row][col];
				}
			}
						
			int x=0;int y=0;
			lowerLimitX=0;upperLimitX=ncols-1;
			lowerLimitY=0;upperLimitY=nrows-1;
			while((lowerLimitX<=upperLimitX) && (lowerLimitY<=upperLimitY)){
				
				if(x<upperLimitX){
					while(x<=upperLimitX && y<=upperLimitY) cout << inputMatrix[y][x++]<< " ";
					--x;y=++lowerLimitY;
				}
				else lowerLimitY=nrows;
				
				while(y<=upperLimitY && x<=upperLimitX) cout << inputMatrix[y++][x]<< " ";
				--y;x=--upperLimitX;

				while(x>=lowerLimitX && y>=lowerLimitY) cout << inputMatrix[y][x--]<< " ";
				++x;y=--upperLimitY;
				
				while(y>=lowerLimitY && x>=lowerLimitX) cout << inputMatrix[y--][x]<< " ";
				++y;x=++lowerLimitX;						
			}
			cout <<endl;			
		}
	}
	inputFile.close();
	return;
}

int main (int argc, char * const argv[]) {

	char * inputName=argv[1];
	spiral(inputName);
	
	return 0;
}