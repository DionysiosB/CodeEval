#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int simpleSort(char * inputName) {
	
	string line;float temp;
	vector<float> output;vector<float>::iterator myIter;
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			istringstream buf(line);
			while(buf >> temp){
				output.push_back(temp);
			}
			sort(output.begin(),output.end());
			for(myIter=output.begin();myIter != output.end(); ++myIter){
				printf("%.3f ", *myIter);
			}
			output.clear();	
			cout <<endl;
		}
	}
	return 0;
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	simpleSort(inputName);
	return 0;
}
