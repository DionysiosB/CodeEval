#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double pointDistance(double dx,double dy){return sqrt(dx * dx + dy * dy);}

vector<double> splitCSV(string input,char delim){
    vector<double> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atof(temp.c_str()));}
    return output;
}

vector<int> findNextPerm(vector<int> input, int inputLength){
		
	for(int k=inputLength-2;k>=0;--k){				
		if(input[k]<input[k+1]){
			int currentMin=input[k+1];int currentMinPos=k+1;
			for(int m=inputLength-1;m>=k+1;--m){if(input[m]<currentMin && input[m]>input[k]){currentMin=input[m];currentMinPos=m;}}
			
			int temp=input[k];input[k]=input[currentMinPos];input[currentMinPos]=temp;
			
			sort(input.begin()+k+1,input.end());
			return input;
		}
	}	
	return input;
}

void TSP(char* inputName) {
	const double mult = 100000.0;
	string line;
	vector<double> currentPoint, Xlist,Ylist;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){	
			int inputLength=line.size();
			int currentPos=line.find("(");line=line.substr(currentPos+1,inputLength-currentPos-2);
			currentPoint=splitCSV(line,','); Xlist.push_back(mult*currentPoint[0]); Ylist.push_back(mult*currentPoint[1]);
		}
		
		unsigned numPoints=Xlist.size();double distanceMatrix[numPoints][numPoints];
		
		for(unsigned row=0;row<numPoints;++row){
			distanceMatrix[row][row]=0;
			for(unsigned col=row+1;col<numPoints;++col){
				distanceMatrix[row][col]=pointDistance(Xlist[row] - Xlist[col],Ylist[row] - Ylist[col]);
				distanceMatrix[col][row]=distanceMatrix[row][col];
			}
		}
				
		vector<int> permCounter;
		vector<int> minPerm;
		float minDistance=10000000000; //A large Number
		float pathDistance;
		
		for(unsigned k=0;k<numPoints-1;++k){permCounter.push_back(k);}
		bool notDone=1; vector<int> nextPerm;
		do{			
			pathDistance=distanceMatrix[0][1+permCounter[0]];
			for(unsigned p=0;p<numPoints-2;++p){pathDistance+=distanceMatrix[1+permCounter[p]][1+permCounter[p+1]];}
			
			if(pathDistance<minDistance){minDistance=pathDistance;minPerm=permCounter;}
			
			nextPerm=findNextPerm(permCounter,numPoints-1);
			if(permCounter == nextPerm){notDone=0;}
			else{permCounter=nextPerm;}
				
		}while(notDone);
			
		cout <<1<<endl;
		for(unsigned q=0;q<numPoints-1;++q){cout << 2+minPerm[q]<<endl;}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	TSP(argv[1]);
	return 0;
}