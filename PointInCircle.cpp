#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

double checkCircle(double dX, double dY, double R){
	if(dX*dX + dY*dY < R*R){return 1;}
	else{return 0;}
}

void pointInCircle(char* inputName) {
	string line;
	FILE * inputFile = fopen(inputName,"r");
	if(inputFile){
		double centerX, centerY, pointX, pointY, radius, scanResult;
		while(true){
			scanResult = fscanf(inputFile, "Center: (%lf, %lf); Radius: %lf; Point: (%lf, %lf)\n", &centerX, &centerY, &radius, &pointX, &pointY);
			if(scanResult < 5){break;}
			if(checkCircle(centerX - pointX, centerY - pointY, radius)){printf("true\n");}
			else{printf("false\n");}		
		}
		fclose(inputFile);
	}
}

int main (int argc, char * const argv[]) {
	pointInCircle(argv[1]);
	return 0;
}