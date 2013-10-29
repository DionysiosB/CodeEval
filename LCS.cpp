#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string LCS(string x, string y){
	
	int m=x.size();int n=y.size();
	int scores[m+1][n+1];int directions[m+1][n+1];
	for(int a=0;a<=m;++a){scores[a][0]=0;directions[a][0]=0;}
	for(int b=0;b<=n;++b){scores[0][b]=0;directions[0][b]=0;}
	
	for(int a=1;a<=m;++a){
		for(int b=1;b<=n;++b){
			if(x[a-1]==y[b-1]){scores[a][b]=scores[a-1][b-1]+1;directions[a][b]=0;}
			else{if(scores[a-1][b]>=scores[a][b-1]){scores[a][b]=scores[a-1][b];directions[a][b]=1;}
				 if(scores[a-1][b]< scores[a][b-1]){scores[a][b]=scores[a][b-1];directions[a][b]=-1;}
			}	
		}
	}

	int a=m;int b=n;string output;
	while(a>=1 && b>=1){
		if(directions[a][b]==0){output=x[a-1]+output;--a;--b;}
		else if (directions[a][b]==-1){--b;}
		else if (directions[a][b]==1){--a;}
	}

	return output;
}

void findSubstring(char* inputName) {

	string line,first,second;int colonPos;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			if(line.size()==0){continue;}
			colonPos=line.find(";");
			first=line.substr(0,colonPos);
			second=line.substr(colonPos+1);
			cout << LCS(first,second)<<endl;			
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	findSubstring(argv[1]);
	return 0;
}