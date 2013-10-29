#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

float pointDistance(int x1,int y1,int x2,int y2){
	return sqrt(pow(1.0*(x1-x2),2)+pow(1.0*(y1-y2),2));
}


void minDistancePoints(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			if(line.size()==1 && line[0]=='0'){break;}
			int spacePos=line.find(" ");
			if(spacePos==-1){
				int numPoints=atoi(line.c_str());
				int points[numPoints][2];
				for(int k=0;k<numPoints;++k){
					getline(inputFile,line);
					istringstream buf(line);
					buf >>points[k][0]>> points[k][1];
				}
				
				float minDistance=10000;
				float currentDistance;
				for(int k=0;k<numPoints-1;++k){
					for(int m=k+1;m<numPoints;++m){
						currentDistance=pointDistance(points[k][0],points[k][1],points[m][0],points[m][1]);
						if(currentDistance<minDistance){minDistance=currentDistance;}
					}
				}
				if(minDistance==10000){cout << "INFINITY" <<endl;}
				else{cout << minDistance<<endl;}
			}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	minDistancePoints(argv[1]);
	return 0;
}