#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/*
vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}
*/

set<int> splitCSV(string input,char delim){
    set<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.insert(atoi(temp.c_str()));}
    return output;
}


void setIntersection(char* inputName) {

	string line,firststr,secondstr;
	int colonPos;
	set<int> firstSet,secondSet,intersectionSet;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			colonPos=line.find(";");firststr=line.substr(0,colonPos);secondstr=line.substr(colonPos+1);
			firstSet=splitCSV(firststr,',');secondSet=splitCSV(secondstr,',');
			set_intersection(firstSet.begin(),firstSet.end(),secondSet.begin(),secondSet.end(),inserter(intersectionSet,intersectionSet.end()));
			for(set<int>::iterator setIter=intersectionSet.begin();setIter != intersectionSet.end();++setIter){
				cout << (*setIter);
				++setIter;
				if(setIter == intersectionSet.end()){cout <<endl;}
				else {cout <<",";}
				--setIter;
				}
			intersectionSet.clear();
		}
	}
	inputFile.close();
}



int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	setIntersection(inputName);
	return 0;
}


