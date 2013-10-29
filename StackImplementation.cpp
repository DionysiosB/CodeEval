#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void toyStack(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			istringstream buf(line);
			vector<int> data;int temp;
			while(buf >> temp){data.push_back(temp);}
			int length=data.size();
			for(int k=length-1;k>=0;k-=2){cout <<data[k];if(k>=2){cout <<" ";}}
			cout <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	toyStack(argv[1]);
	return 0;
}


