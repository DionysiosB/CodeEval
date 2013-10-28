#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


void findInput(char * inputName) {
	
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			vector<int> stack;
			int inputLength=line.size();
			int first,second=0;
			for(int k=inputLength-1;k>=0;--k){
				if(line[k]>='0' && line[k]<='9'){stack.push_back(line[k]-'0');}
				if(line[k]=='+' || line[k]=='*' || line[k]=='/' || line[k]=='-'){
					first=stack.back();stack.pop_back();
					second=stack.back();stack.pop_back();
					if(line[k]=='+'){stack.push_back(first+second);}
					if(line[k]=='*'){stack.push_back(first*second);}
					if(line[k]=='/'){stack.push_back(first/second);}
					if(line[k]=='-'){stack.push_back(first-second);}
					}
			}
			cout<<stack.back()<<endl;
		}		
	}
}	

int main (int argc, char * const argv[]) {
	findInput(argv[1]);
	return 0;
}
