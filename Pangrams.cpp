#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

void pangramCheck(char * inputName) {
	string line;	
	//ifstream inputFile (inputName);
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			unsigned k;	bool isPangram=1;
			bool letters[26];for(k=0;k<26;++k){letters[k]=0;}
			transform(line.begin(),line.end(),line.begin(),::tolower);
			for(k=0;k<line.size();++k){if(line[k]>='a' && line[k]<='z'){letters[line[k]-'a']=1;}}
			for(k=0;k<26;++k){if(!letters[k]){printf("%c",k+'a'); isPangram=0;}}
			if(isPangram){cout <<"NULL";}
			cout<<endl;
		}
	}
}	

int main (int argc, char * const argv[]) {
	pangramCheck(argv[1]);
	return 0;
}
