#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stdlib.h>
using namespace std;

vector<int> splitCSV(string input,char delim){
    vector<int> output;stringstream lineStream(input);string temp;
	while(getline(lineStream,temp,delim)){output.push_back(atoi(temp.c_str()));}
    return output;
}

void findMin(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			vector<int> data=splitCSV(line,',');
			unsigned n=data[0],k=data[1],a=data[2],b=data[3],c=data[4],r=data[5];			
			deque<unsigned> sequence;
						
			unsigned temp=a;sequence.push_back(temp);
			for(unsigned u=1;u<k;++u){temp=(b*temp+c)%r;sequence.push_back(temp);}
			
			for(unsigned u=k;u<n;++u){
				bool state[k+1];for(unsigned x=0;x<=k;++x){state[x]=0;}
				for(unsigned p=0;p<k;++p){if(sequence[p]<=k){state[sequence[p]]=1;}}
				for(unsigned p=0;p<=k;++p){if(state[p]==0){sequence.push_back(p);sequence.pop_front();break;}}			
			}
			cout << sequence[k-1]<<endl;
		}
		inputFile.close();
	}
}


int main (int argc, char * const argv[]) {
	findMin(argv[1]);
	return 0;
}