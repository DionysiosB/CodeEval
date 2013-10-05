#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int matrixSize=256;

class board{
private:
	int matrix[matrixSize][matrixSize];
	
public:
	board(){ //constructor
		for(int row=0;row<matrixSize;++row)
			for(int col=0;col<matrixSize;++col)
				matrix[row][col]=0;
	}
	
	void print(){
		for(int row=0;row<matrixSize;++row){
			cout <<endl;
			for(int col=0;col<matrixSize;++col){
				cout << matrix[row][col] << "\t";
			}
		}
	}
	
	void setRow(int inputRow,int x){
		for(int col=0;col<matrixSize;++col)
			matrix[inputRow][col]=x;
	}
	void setCol(int inputCol,int x){
		for(int row=0;row<matrixSize;++row)
			matrix[row][inputCol]=x;
	}
	int queryRow(int inputRow){
		int total=0;
		for(int col=0;col<matrixSize;++col)
			total+=matrix[inputRow][col];
		return total;
	}
	int queryCol(int inputCol){
		int total=0;
		for(int row=0;row<matrixSize;++row)
			total+=matrix[row][inputCol];
		return total;
	}	
};


int boardOperations(char * inputName) {
	
	string line;string newOperation; int location;int number;
	board myBoard;
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			
			buf >> newOperation;
			buf >> location;
			if(newOperation=="SetRow" || newOperation=="SetCol") buf >> number;
			
			if(newOperation=="SetRow") myBoard.setRow(location,number); 
			if(newOperation=="SetCol") myBoard.setCol(location,number);
			if(newOperation=="QueryRow") cout << myBoard.queryRow(location) <<endl;
			if(newOperation=="QueryCol") cout << myBoard.queryCol(location) <<endl;
			
		}
	}
	return 0;
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	boardOperations(inputName);
	return 0;
}
