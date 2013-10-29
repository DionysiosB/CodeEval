#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


void mineSweeper(char* inputName) {

	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			int commaPos=line.find(",");int colonPos=line.find(";");
			int nrows=atoi((line.substr(0,commaPos)).c_str());
			int ncols=atoi((line.substr(commaPos+1,colonPos)).c_str());
			line=line.substr(colonPos+1);
//			cout <<endl<<nrows << "   "<< ncols << "  "<<line<<endl;
			
			char dataMatrix[nrows][ncols];
			int temp=0;
			for(int row=0;row<nrows;++row){for(int col=0;col<ncols;++col){dataMatrix[row][col]=line[temp++];}}
			
//			cout <<endl;
//			for(int row=0;row<nrows;++row){cout <<endl;for(int col=0;col<ncols;++col){cout << dataMatrix[row][col]<<"\t";}}
//			cout <<endl;
			
			char scoreMatrix[nrows][ncols];
			for(int row=0;row<nrows;++row){for(int col=0;col<ncols;++col){scoreMatrix[row][col]='0';}}
			int checkRow,checkCol;
			
			for(int row=0;row<nrows;++row){
				for(int col=0;col<ncols;++col){
					if(dataMatrix[row][col]=='*'){
						for(int offsetRow=-1;offsetRow<=1;++offsetRow){
							for(int offsetCol=-1;offsetCol<=1;++offsetCol){
								checkRow=row+offsetRow;checkCol=col+offsetCol;
								if(checkRow>=0 && checkRow<nrows && checkCol>=0 && checkCol<ncols && scoreMatrix[checkRow][checkCol]!='*'){
									scoreMatrix[checkRow][checkCol]++;
									}
							}
						}
						scoreMatrix[row][col]='*';
					}
				}
			}
			
			for(int row=0;row<nrows;++row){for(int col=0;col<ncols;++col){cout << scoreMatrix[row][col];}}
			cout<<endl;


		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	mineSweeper(argv[1]);
	return 0;
}


