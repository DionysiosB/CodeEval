#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
using namespace std;

string intToString(int number){
  ostringstream oss;oss<< number;
  return oss.str();
}

void findCycle(char * inputName) {
	
	string line;int temp;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			vector<int> data;
			istringstream buf(line);
			while(buf >> temp){data.push_back(temp);}			
			unsigned slow=0;unsigned fast=0;unsigned length; bool hasCycle=0;
			while(fast<data.size()){
				++slow;fast+=2;
				if(data[slow] == data[fast]){hasCycle=1;break;}
			}
			if(hasCycle){
				length=fast-slow;slow=0;
				string output="";
				while(data[slow] !=data[slow+length]){++slow;}
				for(unsigned k=slow;k<slow+length;++k){output=output+intToString(data[k])+" ";}
				cout << output.substr(0,output.size()-1)<<endl;
			}
		}
	}
}	

int main (int argc, char * const argv[]) {
	findCycle(argv[1]);
	return 0;
}