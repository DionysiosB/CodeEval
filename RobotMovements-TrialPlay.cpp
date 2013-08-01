#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int gridSize=4;

void printMatrix(bool inputMatrix[gridSize][gridSize]){
	for(int row=0;row<gridSize;++row){
		cout <<endl;
		for(int col=0;col<gridSize;++col){
			cout << inputMatrix[row][col] << " ";
		}
	}
	cout <<endl;
}


int robotMovements(bool inputMatrix[gridSize][gridSize],int positionX,int positionY) {
	
	//cout <<"Start Position: "<< positionX << "   "<< positionY << endl;
	
	bool tempMatrix[gridSize][gridSize];
	for(int row=0;row<gridSize;++row)
		for(int col=0;col<gridSize;++col)
			tempMatrix[row][col]=inputMatrix[row][col];
			
	if(tempMatrix[positionX][positionY]==0) tempMatrix[positionX][positionY]=1;
//	else cout << "ERROR!!! " <<endl;
	
//	printMatrix(tempMatrix);
	//cout << "***\n";
	
	if((positionX==gridSize-1) && (positionY==gridSize-1)) {
	//	cout <<"FinalRound++++++++++++++++++++++++++++++++++++++++++++1"<<endl;
		return 1;
	}
	
	int output=0;
	if(positionX>0 && tempMatrix[positionX-1][positionY]==0){
		//cout <<"Calling -0  "<<positionX-1 << "   "<< positionY <<endl;
		output+=robotMovements(tempMatrix,positionX-1,positionY);
	}


	if(positionX<gridSize-1 && tempMatrix[positionX+1][positionY]==0){
		//cout <<"Calling +0   "<<positionX+1 << "   "<< positionY <<endl;
		output+=robotMovements(tempMatrix,positionX+1,positionY);
	}
	
	
	if(positionY>0 && tempMatrix[positionX][positionY-1]==0){
		//cout <<"Calling 0- "<<positionX << "   "<< positionY-1 <<endl;	
		output+=robotMovements(tempMatrix,positionX,positionY-1);	
	}
	
	if(positionY<gridSize-1 && tempMatrix[positionX][positionY+1]==0){
		//cout <<"Calling 0+   "<<positionX << "   "<< positionY+1 <<endl;
		output+=robotMovements(tempMatrix,positionX,positionY+1);		
	}
	
//	cout <<"*****\n";
//	printMatrix(tempMatrix);
//	cout <<"End Position: "<< positionX << "   "<< positionY<< endl;
	
	return output;

}

int main (int argc, char * const argv[]) {
	
	bool inputMatrix[gridSize][gridSize];
	for(int row=0;row<gridSize;++row){
		for(int col=0;col<gridSize;++col){
			inputMatrix[row][col]=0;
		}
	}
	
	cout << robotMovements(inputMatrix,0,0)<< endl;
	
	return 0;
}


