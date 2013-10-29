#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void eraseFromString(char* inputName) {
	string line,first,second;int commaPos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			commaPos=line.find(",");
			first=line.substr(0,commaPos);second=line.substr(commaPos+1);
			for(unsigned k=0;k<second.size();++k){
				if(second[k]==' '){continue;}
				bool done=0;unsigned m=0;
				while(!done){
					if(m>first.size()-1){done=1;break;}
					if(first[m]==second[k]){first.erase(m,1);}
					else{++m;}
				}				
			}
			cout << first<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	eraseFromString(argv[1]);
	return 0;
}


