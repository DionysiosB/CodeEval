#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void findSubstring(char* inputName) {

	string line,first,second;int commaPos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			first=line.substr(0,commaPos);second=line.substr(commaPos+1);
			bool isSubstr=0;
			for(unsigned k=0;k<first.size();++k){
				if(first[k]==second[0]){
					int counter=0;isSubstr=1;
					for(unsigned m=0;m<second.size();++m){
						if(first[k+counter]=='*' && second[m]=='\\' & second[m+1]=='*'){;++m;++counter;}
						else if(second[m]==first[k+counter]){++counter;}
						else if(second[m]=='*'){++counter;if(first[k+counter] != second[m+1]){--m;}}
						else {isSubstr=0;break;}	
					}	
				}
				if(isSubstr){cout <<"true"<<endl;break;}
			}
			if(!isSubstr){cout <<"false"<<endl;}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	findSubstring(argv[1]);
	return 0;
}


