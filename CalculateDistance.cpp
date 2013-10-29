#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

int diffDistance(double dX, double dY){return sqrt(dX*dX + dY*dY);}

void calculateDistance(char* inputName) {
	string line;
	FILE * inputFile = fopen(inputName,"r");
	if(inputFile){
		int firstX, firstY, secondX, secondY;
		while(fscanf(inputFile, "(%d, %d) (%d, %d)\n", &firstX, &firstY, &secondX, &secondY) == 4){
			printf("%d\n", diffDistance(firstX - secondX, firstY - secondY)  );
		}
		fclose(inputFile);
	}
}

int main (int argc, char * const argv[]) {
	calculateDistance(argv[1]);
	return 0;
}