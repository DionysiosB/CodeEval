#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class counter {
	int length;vector<char> data;	
public:
	counter(){length=1;data.push_back('0');}
	
	void inc(){
		data[0]++;bool allOnes=1;
		for(int k=0;k<length;++k){if(data[k]=='0'){allOnes=0;break;}}
		if(allOnes){++length;data.push_back('0');for(int k=0;k<length;++k){data[k]='0';}}
		else{for(int k=0;k<length-1;++k){if(data[k]=='2'){data[k]='0';++data[k+1];}}}
	}
	
	string queryData(){
		string output="";
		for(int k=0;k<length;++k){output=output+data[length-1-k];}
		return output;
		}
};


void decodeMessage(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
		//	cout << line<<endl;
			counter headerCounter;
			map<string,char> dict;
			
			int index=0;
			while( line[index]!='0' && line[index]!='1' ){
			//	cout << headerCounter.queryData()<<"===>"<< line[index] <<endl; 
				dict.insert(pair<string,char>(headerCounter.queryData(),line[index]));
				++index;headerCounter.inc();
			}
			
			int segmentLength=0;

			do{
				segmentLength=0;
				for(int k=0;k<3;++k){segmentLength=2*segmentLength+(line[index]-'0');++index;}
				
		//		cout << "Segment Length: "<< segmentLength<<endl;
				
				
				bool segmentEnd;string currentKey;
				do{
					currentKey="";
					for(int k=0;k<segmentLength;++k){currentKey+=line[index];++index;}
					
					segmentEnd=1;
					for(int k=0;k<segmentLength;++k){if(currentKey[k]=='0'){segmentEnd=0;}}
					
					if(!segmentEnd){cout <<dict[currentKey];}

					
				}while(!segmentEnd);
				
	//			cout << "End of Segment "<<endl;
				
			}while(segmentLength>0);
				
			cout <<endl;
			
			
			

			
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	decodeMessage(argv[1]);
	return 0;
}