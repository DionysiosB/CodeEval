#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

void rectangleOverlap(char* inputName) {
	string line;vector<int> points;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			points=splitCSV(line,',');
			//cout<<(points[0]<points[6])<<(points[2]>points[4])<<(points[1]<points[7])<<(points[3]>points[5])<<endl;
			//for(int k=0;k<8;++k){cout << k <<"--->"<<points[k]<<endl;}
			if(points[0]<points[6] && points[2]>points[4] && points[1]>points[7] && points[3]<points[5]) {cout << "True"<<endl;}
			else {cout<<"False" <<endl;}
		}
	inputFile.close();
	}
}



int main (int argc, char * const argv[]) {
	rectangleOverlap(argv[1]);
	return 0;
}


