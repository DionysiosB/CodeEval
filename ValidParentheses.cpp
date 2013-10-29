#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void validParentheses(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			vector<char> data;bool isValid=1;
			for(unsigned k=0;k<line.size();++k){
				if(line[k]=='(' || line[k]=='[' || line[k]=='{'){data.push_back(line[k]);}
				else if(data.size()>0){
					if((line[k]==')'&&data.back()=='(')||(line[k]==']'&&data.back()=='[')||(line[k]=='}'&&data.back()=='{')){data.pop_back();}
					else {isValid=0;break;}
				}		
			}
			if(isValid){cout <<"True"<<endl;}
			else{cout <<"False"<<endl;}
		}
	}
}	

int main (int argc, char * const argv[]) {
	validParentheses(argv[1]);
	return 0;
}