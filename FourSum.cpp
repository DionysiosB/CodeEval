#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stdlib.h>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

void arraySums(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			vector<int> data=splitCSV(line,',');
			
			unsigned total=0;
			for(unsigned first=0;first<data.size()-3;++first){
				for(unsigned second=first+1;second<data.size()-2;++second){
					for(unsigned third=second+1;third<data.size()-1;++third){
						for(unsigned fourth=third+1;fourth<data.size();++fourth){
							if(data[first]+data[second]+data[third]+data[fourth]==0){
								//cout <<"***"<< data[first]<<"  "<< data[second]<<"  "<< data[third]<<"  "<< data[fourth]<<"  "<<endl;
								++total;}
						}
					}
				}
			}
			cout << total<<endl;
		}
		inputFile.close();
	}
}

int main (int argc, char * const argv[]) {
	arraySums(argv[1]);
	return 0;
}