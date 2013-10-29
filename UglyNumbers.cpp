#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class counter {
	int base,length;vector<int> data;	
public:
	counter (int D){
		base=3;length=D;
		for(int k=0;k<length;++k){data.push_back(0);}
	}
	
	int inc(){
		data[0]++;
		for(int k=0;k<length-1;++k){if(data[k]==base){data[k]=0;++data[k+1];}}
		if(data[length-1]>=base){data[length-1]=0;return 0;}
		return 1;
	}
	
	vector<int> queryData(){return data;}
};

bool uglyTest(string numberString, vector<int> count){
	
	int bound=numberString.size()-1;
	
	long outputNumber=(numberString[0]-'0');
	
	int index=0;
	while(index<bound){
		if(count[index]==0){
			outputNumber=10*outputNumber+(numberString[index+1]-'0');
			++index;
		}
		else{break;}
	}
		
	long temp=0;int lastIndex=count[index];
	while(index<bound){
		if(count[index]==0){temp=10*temp+(numberString[index+1]-'0');}
		if(count[index]==1 || count[index]==2 || index==bound-1){
			if(lastIndex==1){outputNumber+=temp;}
			if(lastIndex==2){outputNumber-=temp;}
			lastIndex=count[index];
			temp =(numberString[index+1]-'0');
		}
		++index;
	}
	if(lastIndex==1){outputNumber+=temp;}
	if(lastIndex==2){outputNumber-=temp;}
	
	if(outputNumber%2==0 || outputNumber%3==0 ||outputNumber%5==0 ||outputNumber%7==0){return 1;}
	else return 0;
}

void uglyNumbers(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			int stringLength=line.size();
			if(line.size()==0){continue;}
			if(stringLength==1){
				int oneDigit=atoi(line.c_str());
				if(oneDigit%2==0 || oneDigit%3==0 || oneDigit%5==0 || oneDigit%7==0){cout<<1<<endl;}
				else{cout << 0 <<endl;}
				continue;
			}
			
			int output=0;
			counter myCount(stringLength-1);bool notDone;
			do{
				vector<int> currentState=myCount.queryData();
				output+=uglyTest(line,currentState);
				notDone=myCount.inc();
			} while(notDone);
			cout <<line<<"--->"<<"Output: "<< output;			
			cout<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	uglyNumbers(argv[1]);
	return 0;
}