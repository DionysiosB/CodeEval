#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void armstrong(char * inputName) {
	
	string line;unsigned n;unsigned total;unsigned temp;int digits;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			digits=line.size();
			n=atoi(line.c_str());
			total=0;
			temp=n;
			while(temp>0){
				total+=int(pow(1.0*(temp%10),digits));
				temp /=10;
			}
			if(total==n) cout <<"TRUE"<<endl;
			else cout << "FALSE"<<endl;
		}

	}
}


int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	armstrong(inputName);
	return 0;
}
